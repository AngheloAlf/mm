WARNINGS_CHECK ?= 0

CC := gcc
CFLAGS := -Wall -Wextra -pedantic -std=c99 -g -O2
PROGRAMS := vtxdis

ABI := o32

WGET_FLAGS  ?=
ifneq ($(WARNINGS_CHECK), 0)
    WGET_FLAGS += --quiet
endif

LIBS_DIR            := libs
LIBGCC_VR4300       := $(LIBS_DIR)/libgcc_vr4300.a

LIBRARIES           := $(LIBGCC_VR4300)

all: $(PROGRAMS) $(LIBRARIES)
	$(MAKE) -C ZAPD
	$(MAKE) -C fado
	$(MAKE) -C buildtools
	$(MAKE) -C z64compress

clean:
	$(RM) $(PROGRAMS) $(LIBRARIES)
	$(MAKE) -C ZAPD clean
	$(MAKE) -C fado clean
	$(MAKE) -C buildtools clean
	$(MAKE) -C z64compress clean

vtxdis_SOURCES	   := vtxdis.c

define COMPILE =
$(1): $($1_SOURCES)
	$(CC) $(CFLAGS) $$^ -o $$@
endef

$(foreach p,$(PROGRAMS),$(eval $(call COMPILE,$(p))))

$(LIBGCC_VR4300): | $(LIBS_DIR)
	wget $(WGET_FLAGS) https://github.com/Decompollaborate/libgcc_vr4300/releases/latest/download/libgcc_vr4300-$(ABI).tar.gz
	tar xf libgcc_vr4300-$(ABI).tar.gz -C $(LIBS_DIR)
	$(RM) libgcc_vr4300-$(ABI).tar.gz

$(LIBS_DIR):
	mkdir -p $@
