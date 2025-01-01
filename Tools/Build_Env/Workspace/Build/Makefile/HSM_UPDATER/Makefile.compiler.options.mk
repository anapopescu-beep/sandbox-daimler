DERIVATIVE = TC3xx

COMP_DEFINES := BRS_COMP_TASKING=1                      \
                BRS_PLATFORM_ARM=1                      \
                _TASKING_C_CORTEXM3_=                   \
                ULLONG_MAX                              \
                DET_AR_RELEASE_MINOR_VERSION=0
                
ECLIPSE_DEFINES :=$(COMP_DEFINES)

CPP_DEFINES :=

AS_DEFINES :=

COMP_INCLUDES := $(foreach COMPONENT,$(COMPONENTS_LIST),$(foreach MODULE,$($(COMPONENT)_COMPONENTS_LIST),$(call $(COMPONENT)_INCLUDES_DIR,$(MODULE)))) 

COMP_OPT_BSW =  -CARMv7M                                        \
                -U__GNUC__                                      \
                --iso=99                                        \
                --keep-temporary-files                          \
                -Wa--emit-locals=+equ,+symbols                  \
                -Wa--section-info=+list,-console                \
                -Wa--debug-info=+asm,+hll,+local,+smart         \
                -Wc-O2                                          \
                -Wc--tradeoff=2                                 \
                -Wc--language=-gcc,+volatile,-strings,-comments \
                -c                                              \
                -g                                              \
                -o $(OBJ_DIR)/$(notdir $@)                      \
                $(addprefix -D,$(COMP_DEFINES))                 \
                $(addprefix -I,$(COMP_INCLUDES))

COMP_OPT_DGEN = $(COMP_OPT_BSW)

COMP_OPT_VSEC = -CARMv7M                                        \
                -U__GNUC__                                      \
                --iso=99                                        \
                --keep-temporary-files                          \
                -Wa--emit-locals=+equ,+symbols                  \
                -Wa--section-info=+list,-console                \
                -Wa--debug-info=+asm,+hll,+local,+smart         \
                -Wc-O1                                          \
                -Wc--tradeoff=2                                 \
                -Wc--language=-gcc,+volatile,-strings,-comments \
                -c                                              \
                -g                                              \
                -o $(OBJ_DIR)/$(notdir $@)                      \
                $(addprefix -D,$(COMP_DEFINES))                 \
                $(addprefix -I,$(COMP_INCLUDES))

DEP_OPT := -M                                   \
           -std=c99                             \
           -Wall                                \
           $(addprefix -I,$(COMP_INCLUDES))     \
           $(addprefix -D,$(COMP_DEFINES))      \
           -I"$(COMPILER_INC)"

ASM_OPT_BSW = $(COMP_OPT_BSW)

ASM_OPT_APP = $(ASM_OPT_BSW)
ASM_OPT_DGEN = $(ASM_OPT_BSW)

CPP_OPT_BSW =   -E                                  \
                -x assembler-with-cpp               \
                -Wno-unused-command-line-argument   \
                $(addprefix -I,$(COMP_INCLUDES))

CPP_OPT_APP := $(CPP_OPT_BSW)
CPP_OPT_DGEN := $(CPP_OPT_BSW)
                
LINK_CMD_XCL := $(TMP)/ilinkCommandLine.xcl
LINK_CMD_OPT = -o "$(OUT_DIR)/$(TARGET).$(BINARY_SUFFIX)"                   \
                "$(TARGET_KEY)/$(LINKER_FILE_STEM).$(LNK_SUFFIX)"           \
                -CARMv7M                                                    \
                -O2                                                         \
                --long-branch-veneers                                       \
                -lrtthumb                                                   \
                -Wl--user-provided-initialization-code                      \
                -Wl--output="$(OUT_DIR)/$(TARGET).$(HEX_SUFFIX)":IHEX       \
                -Wl--optimize=1                                             \
                -Wl--map-file="$(OUT_DIR)/$(TARGET).$(MAP_SUFFIX)":XML      \
                -Wl--map-file-format=2                                      \
			    -Wl--user-provided-initialization-code                      \
			    --no-default-libraries                                      \
                --verbose

LINK_OPT = -f "$(call getWinDir,$(LINK_CMD_XCL))"

LINK_LIB_OBJ =

LIB_OPT :=

CHEX_PRE_OPT :=
CHEX_POST_OPT = "$@"

DEP_PRE_OPT = $(DEP_OPT) -MT $(addsuffix .o, $(addprefix $(OBJ_DIR)/,$(notdir $(basename $(SOURCE_FILE)))))
DEP_POST_OPT :=
DEP_OUT_OPT = > $@
	
ELF_FILE_GENERATION := FALSE
PREPROCESS_AS_SUPPORT := TRUE
GENERATE_LINKER_CMD := TRUE

# filename    : Makefile.compiler.options
# description : Compiler/Assembler/Linker/Librarian options variable setup
# author      : Dan Dustinta
# copyright   : Copyright (c) 2018, Autoliv Electronic
# version     : 1.0.1
# email       : dan.dustinta@autoliv.com
# status      : Released
