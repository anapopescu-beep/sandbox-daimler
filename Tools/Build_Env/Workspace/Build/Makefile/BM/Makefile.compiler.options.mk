DERIVATIVE = TC332LP


CMD_ONLY_DEFINES := '__getbit(address,bitoffset)=__extru(*(address),bitoffset,1)' \
				'__crc32bw(b,a)=__crc32(b,a)' \
				'__putbit(value,address,bitoffset)=__imaskldmst(address,value,bitoffset,1)' \
				'__REG__(x)=reg\#\#x' \
				'__SFRFILE__(cpu)=<sfr/__REG__(cpu).sfr>'

ECLIPSE_DEFINES := BRS_COMP_TASKING=1 \
                AURIX2G_MCAL_DEMOAPP=1 \
                __ACCUM_BIT__=64 \
                __ACCUM_INT_BIT__=17 \
				__ATOMIC_INT_LOCK_FREE__=1 \
				__ATOMIC_LONG_LOCK_FREE__=1 \
				__CHAR_BIT__=8 \
				__CHAR_MAX=SCHAR_MAX \
				__CHAR_MIN=SCHAR_MIN \
				__CORE_TC162__=1 \
				__CPU__=tc33x \
                __CPU_TC33X__=1 \
				__CTC__=1 \
                __DSPC__=1 \
				__DSPC_VERSION__=200001L \
				__FPU__=1 \
                __FRACT_BIT__=32 \
                __INT_BIT__=32 \
				__INTPTR_BIT__=32 \
				__LACCUM_BIT__=64 \
				__LACCUM_INT_BIT__=17\
				__LFRACT_BIT__=32 \
				__LLONG_BIT__=64 \
				__LONG_BIT__=32 \
				__PROF_ENABLE__=0 \
				__PTRDIFF_BIT__=32 \
				__PTRDIFF_MAX=INT32_MAX \
				__PTRDIFF_MIN=INT32_MIN \
				__SACCUM_BIT__=64 \
				__SACCUM_INT_BIT__=17 \
				__SFRACT_BIT__=16 \
				__SHORT_BIT__=16 \
				__SINGLE_FP__=1 \
				__SIZE_BIT__=32 \
				__SIZE_MAX=UINT32_MAX \
				__SIZE_MIN=0 \
				__WCHAR_BIT__=16 \
				__WCHAR_MAX=INT16_MAX \
				__WCHAR_MIN=INT16_MIN \
				transpose_byte=__transpose_byte \
				transpose_hword=__transpose_hword 
                
COMP_DEFINES := $(ECLIPSE_DEFINES) \
               $(CMD_ONLY_DEFINES)

				
CPP_DEFINES := DUMMY_DEFINE=1

AS_DEFINES := DUMMY_DEFINE=1

COMP_INCLUDES := $(foreach COMPONENT,$(COMPONENTS_LIST),$(foreach MODULE,$($(COMPONENT)_COMPONENTS_LIST),$(call $(COMPONENT)_INCLUDES_DIR,$(MODULE)))) 
						   
COMP_OPT_BSW = -o $(OBJ_DIR)/$(notdir $@)                       \
               -c                                               \
               -Ctc33x                                          \
			   --core=tc1.6.2                                   \
			   --iso=99                                         \
               --keep-temporary-files                           \
               --integer-enumeration                            \
               -Wa--emit-locals=+equ,+symbols                   \
               -Wa--section-info=+list,-console                 \
               -Wa--optimize=+generics,+instr-size              \
               -Wa--debug-info=+asm,+hll,+local,+smart          \
               -Wc--debug-info=default                          \
               -Wc--align=4                                     \
               -Wc--default-a0-size=0                           \
               -Wc--default-a1-size=0                           \
               -Wc--default-near-size=0                         \
               -Wc--optimize=aceFgIklMnopRsUvwy,+predict        \
               -Wc--tradeoff=2                                  \
               -Wc--language=-gcc,+volatile,-strings,-comments  \
               $(addprefix -D,$(COMP_DEFINES))                  \
               $(addprefix -I,$(COMP_INCLUDES))

COMP_OPT_APP = $(COMP_OPT_BSW)
COMP_OPT_DGEN = $(COMP_OPT_BSW)

DEP_OPT := -M                               \
           -std=c99                         \
           -Wall                            \
           $(addprefix -I,$(COMP_INCLUDES)) \
           $(addprefix -D,$(COMP_DEFINES))  \
           -I"$(COMPILER_INC)"

ASM_OPT_BSW   = -ctc33x                             \
                --lsl-core=vtc                      \
                -t                                  \
                -Wa-H"sfr/regtc33x.def"             \
                -Wa-gAHLs                           \
                --emit-locals=-equs,-symbols        \
                -Wa-Ogs                             \
                -Wa--error-limit=42                 \
                $(addprefix -I,$(COMP_INCLUDES))    \
                $(addprefix -D,$(AS_DEFINES)) 

				
ASM_OPT_APP = $(ASM_OPT_BSW)
ASM_OPT_DGEN = $(ASM_OPT_BSW)

CPP_OPT_BSW =

CPP_OPT_APP := $(CPP_OPT_BSW)
CPP_OPT_DGEN := $(CPP_OPT_BSW)
                
LINK_CMD_XCL := $(TMP)/ilinkCommandLine.xcl
LINK_CMD_OPT = -o "$(OUT_DIR)/$(TARGET).$(BINARY_SUFFIX)"               \
               -Ctc33x                                                  \
			   --core=tc1.6.2                                           \
			   -Wl--user-provided-initialization-code                   \
               "$(TARGET_KEY)/$(LINKER_FILE_STEM).$(LNK_SUFFIX)"        \
               -Wl-o"$(OUT_DIR)/$(TARGET).$(HEX_SUFFIX)":IHEX           \
               --hex-format=S                                           \
               -Wl--map-file="$(OUT_DIR)/$(TARGET).$(MAP_SUFFIX)":XML   \
               -Wl-OcLtXY                                               \
               -Wl--map-file-format=2                                   \
               --no-default-libraries                                   \
               --verbose

LINK_OPT = -f "$(call getWinDir,$(LINK_CMD_XCL))"

LINK_LIB_OBJ =

LIB_OPT := -lrt -lcs_fpu -lfp_fpu

CHEX_PRE_OPT := --srec \
                --silent
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
