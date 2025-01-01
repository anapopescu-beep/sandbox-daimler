include Makefile.wers.mk
include gmsl

PROJECT_STEM := DAIMLER_MMA
PROJECT_NAME := $(PROJECT_STEM)_$(if $(call sne,Application,$(TARGET_KEY)),$(call uc,$(TARGET_KEY)),APPLICATION)

NB_OF_DISTR_SERVERS := 1 2
LIST_OF_DISTR_SERVERS := ART_OF_WD3158 ART_OF_WD3225

VERBOSE_COMPILING := TRUE
SHOW_SIZE := TRUE

ifeq ($(BUILD_MODE),RELEASE)
REPORT_GENERATION ?= TRUE
else
REPORT_GENERATION ?= FALSE
endif

ifeq ($(MAKECMDGOALS),$(TARGET)-eclipse)
PARSE_HEADER_FILES := TRUE
endif
ifeq ($(REPORT_GENERATION),TRUE)
PARSE_HEADER_FILES := TRUE
endif

LINKER_FILE_STEM := Linker_file

SOURCES_DIR := ../../../../../Components/Application
OUTPUT_DIR := ../../Outputs
TOOLS_DIR := ../../../../../Tools
ECLIPSE_WORKSPACE_DIR := $(TOOLS_DIR)/Eclipse/Workspace

COPY_TO_DELIVERIES_DIR := TRUE
ifeq ($(COPY_TO_DELIVERIES_DIR),TRUE)
DELIVERIES_DIR := ../../../../../Deliveries/$(APPL_VERSION_REV2)
endif

BASE_RELEASE_DIR := ../../../../../Release

RELEASE_DIR := $(BASE_RELEASE_DIR)/$(TARGET_KEY)

POST_PROSESSING_DIR = $(TOOLS_DIR)/Build_Env/Workspace/Build

DEP_DIR := $(OUTPUT_DIR)/$(TARGET)/Dep
ERR_DIR := $(OUTPUT_DIR)/$(TARGET)/Err
LST_DIR := $(OUTPUT_DIR)/$(TARGET)/Lst
OBJ_DIR := $(OUTPUT_DIR)/$(TARGET)/Obj
OUT_DIR := $(OUTPUT_DIR)/$(TARGET)/Out

# Sources section
COMPONENTS_LIST := BSW DGEN APP

BSW_SOURCES_DIR = $(SOURCES_DIR)/Supplier/$(1)

BSW_INCLUDES_DIR = $(SOURCES_DIR)/Supplier/$(1) \
                   $(SOURCES_DIR)/Supplier/Hwl/Sfr/TC33xA/_Reg

BSW_COMPONENTS_LIST := _Common BswM Can CanIf CanNm CanSM CanTp Com ComM Crc CryIf Crypto_30_LibCv Crypto_30_vHsm Csm Dio Dcm Dem Det Dma E2E E2EXf EcuM Fee Fls_17_Dmu Icu_17_TimerIp IpduM KeyM McalLib Mcal_Tc3xx Mcu MemIf Nm NvM Os PduR Port SecOC Spi Ssa Startup Stm vSecPrim Vstdlib WdgIf WdgM Wdg_17_Scu Adc AdcIf Pwm PwmIf SBC Gpt CanTSyn StbM Smu Rtm

BSW_IGNORE_SOURCES_LIST += 

APP_SOURCES_DIR =  $(SOURCES_DIR)/Autoliv/$(1)/Implementation/src

APP_INCLUDES_DIR = $(SOURCES_DIR)/Autoliv/$(1)/Implementation/inc

APP_COMPONENTS_LIST := BaseFunction BeltAdjFunction BeltTensionerFunction DiagFunction SsaAppl CIL BFS SFR MMG Nvp BFE TL_Lib PAL PMP DIA PRE  RCM EOL HWA BSR PRO ATM ERH BMM SCM

APP_IGNORE_SOURCES_LIST += 

# Generated Files
DGEN_SOURCES_DIR =  $(SOURCES_DIR)/Supplier/$(1)

DGEN_INCLUDES_DIR = $(SOURCES_DIR)/Supplier/$(1) 

DGEN_COMPONENTS_LIST := DaVinci_generated

DGEN_IGNORE_SOURCES_LIST += 

# Append Presence pattern section
APPEND_PP_SUPPORT := TRUE

APPEND_PP_ADDRESS_1 = 0xA00FFFC0
APPEND_PP_ADDRESS_2 = 0xA00FFF80
APPEND_PP_PATTERN = 736A293E

APPEND_PP_ARGUMENTS = /S /FR:$(APPEND_PP_ADDRESS_1),4:$(APPEND_PP_ADDRESS_2),4 /FP:$(APPEND_PP_PATTERN) /XI

#Merge Default Values
DEFAULT_VALUES_MERGE := TRUE

DEFAULT_VALUES_FILE_1 = $(OUTPUT_DIR)/nvp/Default.S00
DEFAULT_VALUES_FILE_2 = $(OUTPUT_DIR)/nvp/CalibrationFlash.S00

DEFAULT_VALUES_ARGUMENTS = /S /MO:$(DEFAULT_VALUES_FILE_1)+$(DEFAULT_VALUES_FILE_2) /XI

# filename    : Makefile.config
# description : Makefile contains project specific targets and module(source file) selection
# author      : Dan Dustinta
# copyright   : Copyright (c) 2018, Autoliv Electronic
# version     : 1.0.2
# email       : dan.dustinta@autoliv.com
# status      : Released
