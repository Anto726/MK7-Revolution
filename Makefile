.SUFFIXES:

ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM")
endif

TOPDIR 		?= 	$(CURDIR)
include $(DEVKITARM)/3ds_rules

CTRPFLIB	?=	$(DEVKITPRO)/libctrpf

TARGET		:= 	$(notdir $(CURDIR))
PLGINFO 	:= 	CTRPF.plgInfo

BUILD		:= 	build
INCLUDES	:= 	include \
				vendor/json/single_include \
				vendor/magic_enum/include \
				vendor/mk7-memory/include \
				vendor/mk7-memory/vendor/sead/include
SOURCES 	:= 	src \
				src/base \
				src/base/entries/item \
				src/base/entries/debug \
				src/base/entries/kart \
				src/base/entries/network \
				src/base/features/item \
				src/base/features/kart \
				src/base/features/mode \
				src/base/features/network \
				src/base/hook_types \
				src/base/hooks/Effect/KartEffect \
				src/base/hooks/Item/ItemDirector \
				src/base/hooks/Item/ItemObjBase \
				src/base/hooks/Item/ItemObjKouraR \
				src/base/hooks/Item/KartItem \
				src/base/hooks/Kart/Director \
				src/base/hooks/Kart/Unit \
				src/base/hooks/Kart/VehicleReact \
				src/base/hooks/Net/NetworkEngine \
				src/base/hooks/Net/NetworkSystemInfo \
				src/base/hooks/RaceSys/LapRankChecker \
				src/base/hooks/System/KDPadInputer \
				src/base/memory \
				vendor/mk7-memory/vendor/sead/modules/src/math \
				vendor/mk7-memory/vendor/sead/modules/src/random

#---------------------------------------------------------------------------------
# options for code generation
#---------------------------------------------------------------------------------
ARCH		:= -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft

CFLAGS		:= $(ARCH) -Os -mword-relocations -fomit-frame-pointer -ffunction-sections -fno-strict-aliasing -Wno-psabi -Wno-invalid-offsetof
CFLAGS		+= $(INCLUDE) -D__3DS__ -DMAGIC_ENUM_RANGE_MIN=0 -DMAGIC_ENUM_RANGE_MAX=255 #-D_DEBUG

CXXFLAGS	:= $(CFLAGS) -fno-rtti -fno-exceptions -std=gnu++23

ASFLAGS		:= $(ARCH)
LDFLAGS		:= -T $(TOPDIR)/3gx.ld $(ARCH) -Os -fno-lto -Wl,--gc-sections,--strip-discarded,--strip-debug

LIBS		:= -lctrpf -lctru
LIBDIRS		:= $(CTRPFLIB) $(CTRULIB) $(PORTLIBS)

#---------------------------------------------------------------------------------
# no real need to edit anything past this point unless you need to add additional
# rules for different file extensions
#---------------------------------------------------------------------------------
ifneq ($(BUILD),$(notdir $(CURDIR)))
#---------------------------------------------------------------------------------

export OUTPUT	:=	$(CURDIR)/$(TARGET)
export TOPDIR	:=	$(CURDIR)
export VPATH	:=	$(foreach dir,$(SOURCES),$(CURDIR)/$(dir)) \
					$(foreach dir,$(DATA),$(CURDIR)/$(dir))

export DEPSDIR	:=	$(CURDIR)/$(BUILD)

CFILES			:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
CPPFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))
SFILES			:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.s)))

export LD 		:= 	$(CXX)
export OFILES	:=	$(CPPFILES:.cpp=.o) $(CFILES:.c=.o) $(SFILES:.s=.o)
export INCLUDE	:=	$(foreach dir,$(INCLUDES),-I $(CURDIR)/$(dir) ) \
					$(foreach dir,$(LIBDIRS),-I $(dir)/include) \
					-I $(CURDIR)/$(BUILD)

export LIBPATHS	:=	$(foreach dir,$(LIBDIRS),-L $(dir)/lib)

.PHONY: $(BUILD) clean all

#---------------------------------------------------------------------------------
all: $(BUILD)

$(BUILD):
	@[ -d $@ ] || mkdir -p $@
	@$(MAKE) --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile

#---------------------------------------------------------------------------------
clean:
	@echo clean ... 
	@rm -fr $(BUILD) $(OUTPUT).3gx $(OUTPUT).elf

re: clean all

#---------------------------------------------------------------------------------

else

DEPENDS	:=	$(OFILES:.o=.d)

#---------------------------------------------------------------------------------
# main targets
#---------------------------------------------------------------------------------
$(OUTPUT).3gx : $(OFILES)

#---------------------------------------------------------------------------------
# you need a rule like this for each extension you use as binary data
#---------------------------------------------------------------------------------
%.bin.o	:	%.bin
#---------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(bin2o)

#---------------------------------------------------------------------------------
#.PRECIOUS: %.elf
%.3gx: %.elf
#---------------------------------------------------------------------------------
	@echo creating $(notdir $@)
	@3gxtool -s $(word 1, $^) $(TOPDIR)/$(PLGINFO) $@

-include $(DEPENDS)

#---------------------------------------------------------------------------------
endif
