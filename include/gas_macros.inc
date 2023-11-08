.include "include/macro.inc"

.macro .late_rodata
    .section .rodata
.endm

# no-op
.macro .late_rodata_alignment alignment
.endm
