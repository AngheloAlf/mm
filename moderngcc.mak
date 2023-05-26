MAKEFLAGS    += --no-builtin-rules

MIPS_BINUTILS_PREFIX ?= mips-linux-gnu-

CC           := $(MIPS_BINUTILS_PREFIX)gcc

CHECK_WARNINGS := -Wall -Wextra -Wno-format-security -Wno-unknown-pragmas -Wno-unused-parameter -Wno-unused-variable -Wno-missing-braces -Wno-int-conversion -Wno-unused-but-set-variable -Wno-unused-label -Wno-return-type -Wno-implicit-fallthrough

IINC         := -Iinclude -Isrc -Iassets -Ibuild -I.
CFLAGS       := -fexec-charset=euc-jp -G 0 -nostdinc -march=vr4300 -mfix4300 -mabi=32 -mno-abicalls -mdivide-breaks -fno-zero-initialized-in-bss -fno-toplevel-reorder -ffreestanding -fno-common -fno-merge-constants -mno-explicit-relocs -mno-split-addresses $(CHECK_WARNINGS) -funsigned-char
# OPTFLAGS     := -Os -ffast-math -fno-unsafe-math-optimizations
OPTFLAGS     := -Os
MIPS_VERSION := -mips3
# SANITIZER_FLAGS := -fsanitize=undefined -fno-sanitize=shift -fno-sanitize=alignment

# Only code for now
C_FILES  := $(shell grep --recursive --files-without-match 'GLOBAL_ASM' src/code src/gcc_fix)
O_FILES  := $(foreach f,$(C_FILES:.c=.o),build/$f)

all: $(O_FILES)

clean:
	rm -rf $(O_FILES)

build/%.o: %.c
	$(CC) -c $(IINC) $(CFLAGS) $(SANITIZER_FLAGS) $(MIPS_VERSION) $(OPTFLAGS) -o $@ $<

# Print target for debugging
print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
