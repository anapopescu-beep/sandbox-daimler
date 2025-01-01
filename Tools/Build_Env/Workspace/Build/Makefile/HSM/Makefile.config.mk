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

SOURCES_DIR := ../../../../../Components/HSM
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
COMPONENTS_LIST := BSW DGEN VSEC

BSW_SOURCES_DIR = $(SOURCES_DIR)/Supplier/$(1)

BSW_INCLUDES_DIR = $(SOURCES_DIR)/Supplier/$(1)	\
                   $(SOURCES_DIR)/Supplier/Hwl/Sfr/TC33xA/_Reg	\
				   $(SOURCES_DIR)/Supplier/_Common

BSW_COMPONENTS_LIST := _Common Hwl Mcal Crc CryIf Crypto_30_Hwa Crypto_30_KeyM Crypto_30_LibCv Csm HsmMem_Tc3xx KeyM MemIf NvM Os vHsm vHsm_Custom vHsm_Hal Fee Fls_17_Dmu VStdLib

BSW_IGNORE_SOURCES_LIST += 

VSEC_SOURCES_DIR = $(SOURCES_DIR)/Supplier/$(1)

VSEC_INCLUDES_DIR = $(SOURCES_DIR)/Supplier/$(1)

VSEC_COMPONENTS_LIST = vSecPrim

# Generated Files
DGEN_SOURCES_DIR =  $(SOURCES_DIR)/Supplier/$(1)

DGEN_INCLUDES_DIR = $(SOURCES_DIR)/Supplier/$(1) 

DGEN_COMPONENTS_LIST := DaVinci_generated

DGEN_IGNORE_SOURCES_LIST += 

#HSM Firmware prepare for HSM_Updater
HSM_FIRMWARE_PREPARE_FOR_HSMUPDATER := TRUE

# filename    : Makefile.config
# description : Makefile contains project specific targets and module(source file) selection
# author      : Dan Dustinta
# copyright   : Copyright (c) 2018, Autoliv Electronic
# version     : 1.0.2
# email       : dan.dustinta@autoliv.com
# status      : Released
