include Makefile.wers.mk
include gmsl

PROJECT_STEM := DAIMLER_MMA
PROJECT_NAME := $(PROJECT_STEM)_$(if $(call sne,Application,$(TARGET_KEY)),$(call uc,$(TARGET_KEY)),APPLICATION)

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

SOURCES_DIR := ../../../../../Components/FBLBM_UPDATER
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
COMPONENTS_LIST := APP BSW DGEN

BSW_SOURCES_DIR = $(SOURCES_DIR)/Supplier/$(1)

BSW_INCLUDES_DIR = $(SOURCES_DIR)/Supplier/$(1)

BSW_COMPONENTS_LIST := CryIf Crypto_30_LibCv Crypto_30_vHsm Csm Det Fbl FblAsrStubs FblBm FblBmHdr FblMio FblUpd Fee FlashDrv Fls_17_Dmu McalLib Mcal_Tc3xx Mcu TC33xA_Reg vMemAccM vSecPrim VStdLib WrapNv Spi Dma Dio Port
BSW_IGNORE_SOURCES_LIST += applvect.c fbl_protio.c flashdrv.c bm_main.c bm_shared.c BrsHwBMHD.c

APP_SOURCES_DIR =  $(SOURCES_DIR)/Autoliv/$(1)/Implementation/src

APP_INCLUDES_DIR = $(SOURCES_DIR)/Autoliv/$(1)/Implementation/inc

APP_COMPONENTS_LIST := FblUsr SBC

APP_IGNORE_SOURCES_LIST += 

# Generated Files
DGEN_SOURCES_DIR =  $(SOURCES_DIR)/Supplier/$(1)

DGEN_INCLUDES_DIR = $(SOURCES_DIR)/Supplier/$(1) 

DGEN_COMPONENTS_LIST := DaVinci_generated

DGEN_IGNORE_SOURCES_LIST += FblBm_Lcfg.c Fbl_Rst.c

# Append Presence pattern section
APPEND_PP_SUPPORT := FALSE

APPEND_PP_ADDRESS = 0xA005FFC0
APPEND_PP_PATTERN = 736A293E

APPEND_PP_ARGUMENTS = /S /FR:$(APPEND_PP_ADDRESS),4 /FP:$(APPEND_PP_PATTERN) /XI

#Post process FBL_UPDATER
POST_PROC_FBLBM_UPDATER := TRUE

POST_PROC_ARGUMENTS = /S /AD:0x20 /AL /AF:0x55 /XI

# Create vHSM validation structure for secure boot
VHSM_VALSTRUCT_SUPPORT := TRUE

VHSM_VALSTRUCT_ADDRESS = 0xA00D6E00
VHSM_VALSTRUCT_KEY_PATH = S:\Components\HSM\Supplier\Keys\cccv2_key_private.txt
VHSM_VALSTRUCT_INI_NAME = fbl
VHSM_VALSTRUCT_GROUP_ID = 12 			# Nachfragen! Default is 0. Can be hex or decimal.
VHSM_VALSTRUCT_MODE = 2					# Disabled = 0 (default), Parallel = 1, Sequentiel = 2
VHSM_VALSTRUCT_HASH_METHOD = 20 		# default is 20 (SHA256).
VHSM_VALSTRUCT_SIGNATURE_METHOD = 46	# Einstellung vom HSM klären -1=no signature 

VHSM_VALSTRUCT_ARGUMENTS = /S -v -e:vshsm_error.txt /p=$(VHSM_VALSTRUCT_INI_NAME).ini /vshsm:@$(VHSM_VALSTRUCT_ADDRESS) /XI

# filename    : Makefile.config
# description : Makefile contains project specific targets and module(source file) selection
# author      : Dan Dustinta
# copyright   : Copyright (c) 2018, Autoliv Electronic
# version     : 1.0.2
# email       : dan.dustinta@autoliv.com
# status      : Released
