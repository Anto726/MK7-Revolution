#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------

ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM")
endif

export TOPDIR ?= $(CURDIR)
include $(DEVKITARM)/3ds_rules

HASH 		:= $(shell git rev-parse --short HEAD)

NAME 		:= Revolution
ABOUT 		:= $(NAME) is a plugin for Mario Kart 7. Strictly for educational purposes.\n\nHash: HASH

CTRPFLIB	?=	$(DEVKITPRO)/libctrpf

TARGET		:= 	$(notdir $(CURDIR))
PLGINFO 	:= 	$(notdir $(TOPDIR)).plgInfo

INCLUDES	:= 	include \
				vendor/glaze/include \
				vendor/magic_enum/include \
				vendor/mk7-memory/include \
				vendor/mk7-memory/vendor/lms/Include \
				vendor/mk7-memory/vendor/nnheaders/include \
				vendor/mk7-memory/vendor/nw4c/include \
				vendor/mk7-memory/vendor/sead/include
SOURCES 	:= 	src \
				src/base \
				src/base/entries/base \
				src/base/entries/debug \
				src/base/entries/item \
				src/base/entries/kart \
				src/base/entries/network \
				src/base/entries/system \
				src/base/entries/ui \
				src/base/features \
				src/base/features/item \
				src/base/features/kart \
				src/base/features/mode \
				src/base/features/network \
				src/base/features/ui \
				src/base/game/system \
				src/base/hook_types \
				src/base/hooks/Effect/KartEffect \
				src/base/hooks/Item \
				src/base/hooks/Item/ItemDirector \
				src/base/hooks/Item/ItemObjBase \
				src/base/hooks/Item/ItemObjFlower \
				src/base/hooks/Item/ItemObjGesso \
				src/base/hooks/Item/ItemObjKiller \
				src/base/hooks/Item/ItemObjKouraB \
				src/base/hooks/Item/ItemObjKouraG \
				src/base/hooks/Item/ItemObjKouraR \
				src/base/hooks/Item/ItemObjStar \
				src/base/hooks/Item/ItemObjThunderDirector \
				src/base/hooks/Item/ItemSlot \
				src/base/hooks/Item/KartItem \
				src/base/hooks/Kart/Director \
				src/base/hooks/Kart/NetData \
				src/base/hooks/Kart/Rigid \
				src/base/hooks/Kart/Unit \
				src/base/hooks/Kart/VehicleMove \
				src/base/hooks/Kart/VehicleReact \
				src/base/hooks/Menu3D/GarageDirector \
				src/base/hooks/Net/NetworkDataManager \
				src/base/hooks/Net/NetworkEngine \
				src/base/hooks/Net/NetworkEventModule \
				src/base/hooks/Net/NetworkFriendsManager \
				src/base/hooks/Net/NetworkGameMgr \
				src/base/hooks/Net/NetworkItemSlotMgr/Buffer \
				src/base/hooks/Object/CharacterEngine \
				src/base/hooks/RaceSys/LapRankChecker \
				src/base/hooks/RaceSys/ModeManagerRace \
				src/base/hooks/sead/BufferedSafeString \
				src/base/hooks/sead/PtrArrayImpl \
				src/base/hooks/Sequence/BaseRacePage \
				src/base/hooks/Sequence/MenuMultiCourseVote \
				src/base/hooks/Sequence/RacePage \
				src/base/hooks/System/KDPadInputer \
				src/base/hooks/System/SystemSaveData \
				src/base/hooks/UI/BgRaceMapCharaControl \
				src/base/hooks/UI/BgRaceZoomMapControl \
				src/base/hooks/UI/RaceItemBoxControl \
				src/base/hooks/UI/TimeControl \
				src/base/memory \
				src/base/sead \
				src/base/sead/StringUtil \
				src/base/services \
				vendor/mk7-memory/vendor/sead/modules/src/container \
				vendor/mk7-memory/vendor/sead/modules/src/gfx \
				vendor/mk7-memory/vendor/sead/modules/src/math \
				vendor/mk7-memory/vendor/sead/modules/src/prim \
				vendor/mk7-memory/vendor/sead/modules/src/random
FILTERS 	:=	seadBitFlag.cpp \
				seadBoundBox.cpp \
				seadBitCamera.cpp \
				seadDrawLockContext.cpp \
				seadEndian.cpp \
				seadEnum.cpp \
				seadFrameBuffer.cpp \
				seadListImpl.cpp \
				seadMatrix.cpp \
				seadMemUtil.cpp \
				seadPrimitiveRenderer.cpp \
				seadPrimitiveRendererUtil.cpp \
				seadProjection.cpp \
				seadQuat.cpp \
				seadStringBuilder.cpp \
				seadStringUtil.cpp \
				seadTreeNode.cpp

#---------------------------------------------------------------------------------
# options for code generation
#---------------------------------------------------------------------------------
DEFINES 	:= -D__3DS__ -DNNSDK -DMAGIC_ENUM_RANGE_MIN=0 -DMAGIC_ENUM_RANGE_MAX=255 \
				-DHASH="\"$(HASH)\"" -DNAME="\"$(NAME)\"" -DABOUT="\"$(ABOUT)\""

ARCH		:= -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft

CFLAGS		:= $(ARCH) -Os -mword-relocations -fomit-frame-pointer -ffunction-sections -fno-strict-aliasing \
				-Wall -Wextra -Wfatal-errors -Wno-format -Wno-psabi -Wno-invalid-offsetof \
				$(BUILD_CFLAGS) $(INCLUDE) $(DEFINES)

CXXFLAGS	:= $(CFLAGS) -fno-rtti -fno-lto -fno-exceptions -std=gnu++23

ASFLAGS		:= $(ARCH)
LDFLAGS		:= -T $(TOPDIR)/3gx.ld $(ARCH) -Os -Wl,$(WL)--gc-sections

LIBS		:= $(BUILD_LIBS)
LIBDIRS		:= $(CTRPFLIB) $(CTRULIB) $(PORTLIBS)

#---------------------------------------------------------------------------------
# no real need to edit anything past this point unless you need to add additional
# rules for different file extensions
#---------------------------------------------------------------------------------
ifneq ($(BUILD),$(notdir $(CURDIR)))
#---------------------------------------------------------------------------------

export VPATH	:=	$(foreach dir,$(SOURCES),$(CURDIR)/$(dir)) \
					$(foreach dir,$(DATA),$(CURDIR)/$(dir))

export DEPSDIR	:=	$(CURDIR)/$(BUILD)

CFILES			:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
CPPFILES 		:= 	$(filter-out $(FILTERS), $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp))))
SFILES			:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.s)))

export LD 		:= 	$(CXX)
export OFILES	:=	$(CPPFILES:.cpp=.o) $(CFILES:.c=.o) $(SFILES:.s=.o)
export INCLUDE	:=	$(foreach dir,$(INCLUDES),-I $(CURDIR)/$(dir) ) \
					$(foreach dir,$(LIBDIRS),-I $(dir)/include) \
					-I $(CURDIR)/$(BUILD)

export LIBPATHS	:=	$(foreach dir,$(LIBDIRS),-L $(dir)/lib)

.PHONY: clean re all

#---------------------------------------------------------------------------------
all: release debug

release: produce_includes release_dir
	@$(MAKE) BUILD=release OUTPUT=$(CURDIR)/$(TARGET)-release.3gx BUILD_LIBS="-lctrpf -lctru" WL=--strip-discarded,--strip-debug, \
	DEPSDIR=$(CURDIR)/release \
	--no-print-directory --jobs=$(shell nproc) -C release -f $(CURDIR)/Makefile

debug: produce_includes debug_dir
	@$(MAKE) BUILD=debug OUTPUT=$(CURDIR)/$(TARGET)-debug.3gx BUILD_LIBS="-lctrpfd -lctrud" \
	DEPSDIR=$(CURDIR)/debug BUILD_CFLAGS="-D_DEBUG" \
	--no-print-directory --jobs=$(shell nproc) -C debug -f $(CURDIR)/Makefile

produce_includes:
	@$(MAKE) --no-print-directory -C vendor/mk7-memory

release_dir:
	@[ -d release ] || mkdir -p release

debug_dir:
	@[ -d debug ] || mkdir -p debug

#---------------------------------------------------------------------------------
clean:
	@echo clean ... 
	@rm -fr release debug *.3gx *.elf

re: clean all

#---------------------------------------------------------------------------------

else

#---------------------------------------------------------------------------------
# main targets
#---------------------------------------------------------------------------------

DEPENDS	:=	$(OFILES:.o=.d)

$(OUTPUT): $(basename $(OUTPUT)).elf
$(basename $(OUTPUT)).elf: $(OFILES)
#---------------------------------------------------------------------------------
# you need a rule like this for each extension you use as binary data
#---------------------------------------------------------------------------------
%.bin.o	:	%.bin
#---------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(bin2o)

#---------------------------------------------------------------------------------
%.3gx: %.elf
#---------------------------------------------------------------------------------
	@echo creating $(notdir $@)
	@3gxtool -d -s $^ $(TOPDIR)/$(PLGINFO) $@

-include $(DEPENDS)

#---------------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------------
