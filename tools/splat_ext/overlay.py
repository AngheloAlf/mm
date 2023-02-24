import typing
from collections import OrderedDict
from typing import Dict, List, Optional, Tuple, Set

import spimdisasm

from util import log, options
from util.range import Range
from util.symbols import Symbol
from util import options, symbols, log

from segtypes.common.group import CommonSegGroup
from segtypes.segment import Segment


from segtypes.common.code import CommonSegCode

from segtypes.n64.asm import N64SegAsm
from segtypes.common.data import CommonSegData
from segtypes.common.rodata import CommonSegRodata
from segtypes.common.bss import CommonSegBss

class N64SegOverlay(CommonSegCode):
    def __init__(
        self,
        rom_start: Optional[int],
        rom_end: Optional[int],
        type: str,
        name: str,
        vram_start: Optional[int],
        args: list,
        yaml,
    ):
        super().__init__(
            rom_start,
            rom_end,
            type,
            name,
            vram_start,
            args=args,
            yaml=yaml,
        )

        self.reloc_section: Optional[spimdisasm.mips.sections.SectionRelocZ64] = None

    def parse_subsegments(self, segment_yaml):
        self.section_boundaries = OrderedDict(
            (s_name, Range()) for s_name in options.opts.section_order
        )

        return []

    def scan(self, rom_bytes):
        if not isinstance(self.rom_start, int):
            log.error(
                f"Segment '{self.name}' (type '{self.type}') requires a rom_start. Got '{self.rom_start}'"
            )

        # Supposedly logic error, not user error
        assert isinstance(self.rom_end, int), self.rom_end

        # Supposedly logic error, not user error
        segment_rom_start = self.get_most_parent().rom_start
        assert isinstance(segment_rom_start, int), segment_rom_start

        if not isinstance(self.vram_start, int):
            log.error(
                f"Segment '{self.name}' (type '{self.type}') requires a vram address. Got '{self.vram_start}'"
            )

        self.reloc_section = spimdisasm.mips.sections.SectionRelocZ64(
            symbols.spim_context,
            self.rom_start,
            self.rom_end,
            self.vram_start,
            self.name,
            rom_bytes,
            segment_rom_start,
            self.get_exclusive_ram_id(),
        )

        self.reloc_section.analyze()
        self.reloc_section.setCommentOffset(self.rom_start)

        sub_start = self.rom_start
        sub_end = self.rom_start
        vram_start = self.vram_start
        # print(self.name)
        if self.reloc_section.textSize != 0:
            sub_end += self.reloc_section.textSize
            # print(f"{sub_start:07X}", f"{sub_end:07X}")
            sub = N64SegAsm(sub_start, sub_end, "asm", self.name, vram_start, [], {})
            sub.parent = self
            self.subsegments.append(sub)
            sub_start += self.reloc_section.textSize
            vram_start += self.reloc_section.textSize

        if self.reloc_section.dataSize != 0:
            sub_end += self.reloc_section.dataSize
            # print(f"{sub_start:07X}", f"{sub_end:07X}")
            sub = CommonSegData(sub_start, sub_end, "data", self.name, vram_start, [], {})
            sub.parent = self
            self.subsegments.append(sub)
            sub_start += self.reloc_section.dataSize
            vram_start += self.reloc_section.dataSize

        if self.reloc_section.rodataSize != 0:
            sub_end += self.reloc_section.rodataSize
            # print(f"{sub_start:07X}", f"{sub_end:07X}")
            sub = CommonSegRodata(sub_start, sub_end, "rodata", self.name, vram_start, [], {})
            sub.parent = self
            self.subsegments.append(sub)
            sub_start += self.reloc_section.rodataSize
            vram_start += self.reloc_section.rodataSize

        if self.reloc_section.bssSize != 0:
            sub_end += self.reloc_section.bssSize
            # print(f"{sub_start:07X}", f"{sub_end:07X}")
            sub = CommonSegBss(sub_start, sub_end, "bss", self.name, vram_start, [], {})
            sub.parent = self
            self.subsegments.append(sub)
            sub_start += self.reloc_section.bssSize
            vram_start += self.reloc_section.bssSize

        for sub in self.subsegments:
            sub.scan(rom_bytes)
