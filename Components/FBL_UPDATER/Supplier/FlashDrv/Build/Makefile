########################################################################################################################
# File Name  : Makefile
# Description: Local main project Makefile
# Project    : Vector Basic Runtime System
# Module     : BrsHw for platform Infineon Aurix/AurixPlus
#              and Compiler Tasking,
#              using Vector PES MakeSupport 4.1
# Template   : This Makefile is reviewed according to Brs_Template@MakeSupport[1.00.00]
#
#-----------------------------------------------------------------------------------------------------------------------
# COPYRIGHT
#-----------------------------------------------------------------------------------------------------------------------
# Copyright (c) 2020 by Vector Informatik GmbH.                                                  All rights reserved.
#
#-----------------------------------------------------------------------------------------------------------------------
# AUTHOR IDENTITY
#-----------------------------------------------------------------------------------------------------------------------
# Name                          Initials      Company
# ----------------------------  ------------  --------------------------------------------------------------------------
# Benjamin Walter               visbwa        Vector Informatik GmbH
# Torsten Schmidt               visto         Vector Informatik GmbH
# Sascha Mauser                 vismaa         Vector Informatik GmbH
#-----------------------------------------------------------------------------------------------------------------------
# REVISION HISTORY
#-----------------------------------------------------------------------------------------------------------------------
# Version   Date        Author  Description
# --------  ----------  ------  ----------------------------------------------------------------------------------------
# 01.00.00  2020-05-28  visto   Initial version based on Template for vBaseEnv 2.0
# 01.00.01  2020-06-16  visbwa  Changed to new compiler license server
# 01.00.02  2020-09-28  vismaa  CORE_SWITCH_TC49x
########################################################################################################################

########################################################################################################################
#    EXAMPLE CODE ONLY
#    -------------------------------------------------------------------------------------------------------------------
#    This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
#    The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
#    intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
#    implementations must be tested with diligent care and must comply with all quality requirements which are necessary
#    according to the state of the art before their use.
########################################################################################################################

#------------------------------------------------------------------------------
# Name of this project (directory under which the Appl directory resides)
# E.g.: TestSuit
#------------------------------------------------------------------------------
PROJECT_NAME = FlashDrv

#------------------------------------------------------------------------------
# Name of linker file
#------------------------------------------------------------------------------
LINKER_COMMAND_FILE = LinkerScript_FlashDrv.lsl

#------------------------------------------------------------------------------
# More static settings placed inside separate file
#------------------------------------------------------------------------------
include Makefile.static

#------------------------------------------------------------------------------
# Define Compiler path, e.g.
#   COMPILER_BASE_WIN = D:\uti\%vendor%\%platform%\%version% (\ can be used)
#   COMPILER_BASE    := $(subst \,/,$(COMPILER_BASE_WIN)) (\ is converted to /)
#   COMPILER_BIN      = $(COMPILER_BASE)/bin
#   COMPILER_INC      = $(COMPILER_BASE)/inc
#   COMPILER_LIB      = $(COMPILER_BASE)/lib
#------------------------------------------------------------------------------
# 6.2r1 is not working together with our OS. Use 6.2r2 instead.
COMPILER_BASE_WIN = D:\uti\Compiler\TASKING\TriCore\v6.3r1p3\ctc
COMPILER_BASE    := $(subst \,/,$(COMPILER_BASE_WIN))
COMPILER_BIN      = $(COMPILER_BASE)/bin
COMPILER_INC      = $(COMPILER_BASE)/include
COMPILER_LIB      = $(COMPILER_BASE)/lib

#------------------------------------------------------------------------------
# Build Options Selection: VECTOR / CUSTOMER
#------------------------------------------------------------------------------
ASFLAGS_SELECTOR  = VECTOR
CFLAGS_SELECTOR   = VECTOR
LDFLAGS_SELECTOR  = VECTOR

#------------------------------------------------------------------------------
# Path of MakeSupport folder relative to main Makefile
#------------------------------------------------------------------------------
MAKESUPPORT_DIR_MAK=make_support_var.mk
ifeq ($(MAKESUPPORT_DIR),)
  -include $(MAKESUPPORT_DIR_MAK)
endif

ifeq ($(MAKESUPPORT_DIR),)
  # Find first on Delivery structure and then in enhanced directory structure
  # Stop after first occurance
  $(info Looking for MakeSupport in current structure. This could take a while for first invocation.)
  MAKESUPPORT_DIR:=$(shell find ../.. ../../.. -name MakeSupport -print -quit)
  ifeq ($(MAKESUPPORT_DIR),)
    $(error No MakeSupport directory found. Please set 'MAKESUPPORT_DIR' environment variable manually.)
  endif
  $(info Found MAKESUPPORT_DIR='$(MAKESUPPORT_DIR)'. Save it to '$(MAKESUPPORT_DIR_MAK)' for next invocation.)
  $(file >$(MAKESUPPORT_DIR_MAK),MAKESUPPORT_DIR=$(MAKESUPPORT_DIR))
endif

distclean::
	@echo "DISTCLEAN  $(MAKESUPPORT_DIR_MAK)"
	$(Q)$(RM) $(MAKESUPPORT_DIR_MAK)

#------------------------------------------------------------------------------
# $(ERR_OUTPUT) defines the way how to generate error files
# It should be one of:
#     PIPE    - Error will be printed to sterr/stdout and redirected to
#               $(ERR_PATH)
#     FLAGS   - Compiler supports error file generation with or without path
#               definition. Therefore, e.g. $(CFLAGS_VECTOR_MAKESUPPORT)
#               and $(LDFLAGS_VECTOR_MAKESUPPORT) have to be adjusted.
#               It depends on compiler flags whether output is written to
#               console as well.
#     CONSOLE - No compiler flags handling in MakeSupport (default).
#------------------------------------------------------------------------------
ERR_OUTPUT = CONSOLE

#------------------------------------------------------------------------------
# Default license server and port
#------------------------------------------------------------------------------
LICENSE_SERVER      = vistrlic7
LICENSE_SERVER_PORT = 9090

#------------------------------------------------------------------------------
# Define Emulator path
# E.g.: EMU_PATH = C:/UTI/HITOPWIN/P6811
#------------------------------------------------------------------------------
EMU_PATH =

#------------------------------------------------------------------------------
# Set $(NANT_USED) to '1', to enable the usage of NAnt support within
# Global Makefile. If this is enabled, the MakeSupport will include the
# NAnt support from an internal link and the NAnt build targets can be used.
#------------------------------------------------------------------------------
#NANT_USED = 1

#------------------------------------------------------------------------------
# Set MKVERBOSE to a various value, to enable enhanced debug output from
# MakeSupport. To disable this afterwards, set MKVERBOSE to nothing
# (comment out this line and type "set MKVERBOSE=" in command window)
#------------------------------------------------------------------------------
#MKVERBOSE = 1

#------------------------------------------------------------------------------
# Set $(BRSVINFO_USED) to 1 to enable the generation of BrsVInfo.h within the
# GenData folder by the MakeSupport.
# The BrsVInfo.h will contain e.g. kBrsCompilerVersion, to use this
# information within the embedded code.
#------------------------------------------------------------------------------
#BRSVINFO_USED = 1

#------------------------------------------------------------------------------
# Functions used within Assembler/Compiler/Linker options.
# 
# Common functionality is encapsulated in the following functions:
# - obj2err
# - obj2lst
# 
# Example:
# --list-file=$(call obj2lst,$@)
# --error-file=$(call obj2err,$@)
# 
# Please have a look at Makefile_functions.mk for further detailed information.
#------------------------------------------------------------------------------
CORE_SWITCH_TC21x = tc1.6.x
CORE_SWITCH_TC22x = tc1.6.x
CORE_SWITCH_TC23x = tc1.6.x
CORE_SWITCH_TC24x = tc1.6.x
CORE_SWITCH_TC26x = tc1.6.x
CORE_SWITCH_TC27x = tc1.6.x
CORE_SWITCH_TC29x = tc1.6.x

CORE_SWITCH_TC32x = tc1.6.2
CORE_SWITCH_TC33x = tc1.6.2
CORE_SWITCH_TC35x = tc1.6.2
CORE_SWITCH_TC36x = tc1.6.2
CORE_SWITCH_TC37x = tc1.6.2
CORE_SWITCH_TC38x = tc1.6.2
CORE_SWITCH_TC39x = tc1.6.2
CORE_SWITCH_TC49x = tc1.8

ifeq ($(CORE_SWITCH_$(DERIVATIVE)),)
 $(warning COMPILERFLAGERROR: The compiler option (--core=<value>) is not defined!)
endif

#------------------------------------------------------------------------------
# Extra dependency defines
# The DEPEND tool which is normally a preprocessor
# is called with $(EXTRA_DEPENDFLAGS) and $(CPPFLAGS).
#
# The cross compiler adds its own defines which DEPEND
# doesn't know.
#
# Add cross options set by compiler and other options
# for the preprocessor here.
# e.g.: EXTRA_DEPENDFLAGS += -D__CTC__
#
# For normal build defines use $(CPPFLAGS_VECTOR_MAKESUPPORT).
#------------------------------------------------------------------------------
EXTRA_DEPENDFLAGS += -D__CTC__

#------------------------------------------------------------------------------
# $(AS_ENV) is the environment necessary to run the assembler
# $(AS) defines the path to the assembler
# $(ASFLAGS_VECTOR_MAKESUPPORT) defines all assembler switches, mandatory for
#                               the Vector build environment (MakeSupport/BrsHw)
# $(ASFLAGS_VECTOR_OPTIONS) defines the Vector default assembler switches
# $(ASFLAGS_CUSTOMER_OPTIONS) defines the customer requested assembler switches
# Depending of ASFLAGS_SELECTOR, ASFLAGS_VECTOR_OPTIONS or ASFLAGS_CUSTOMER_OPTIONS
# are used together with $(ASFLAGS_VECTOR_MAKESUPPORT) for build.
#------------------------------------------------------------------------------
AS_ENV = $(CC_ENV)
AS     = $(CC)

#------------------------------------------------------------------------------
# NOTE on assembler options: the makefile uses the "--create=object" option.
# This means that the control program (cctc.exe) invokes the compiler and
# assembler internally within one build step.
# As a consequence assembler options are specified within the compiler options
# and should be prefixed "-Wa".
# The control program passes such options to the assembler.
#------------------------------------------------------------------------------

#------------------------------------------------------------------------------
# Please add only absolutely mandatory options below
ASFLAGS_VECTOR_MAKESUPPORT = 

#------------------------------------------------------------------------------
# $(ASFLAGS_VECTOR_PREPROCESS) defines the options in preprocessing
# just before assembler starts. This flag is used only if 
# AS_VECTOR_PREPROCESS (located in Makefile.static) is enabled.
#
# $(CPPFLAGS_CORE) can be added here.
#------------------------------------------------------------------------------
ASFLAGS_VECTOR_PREPROCESS = 

#------------------------------------------------------------------------------
# Please add any other option below (Vector default options)
#
# Use $(ASFLAGS_VECTOR_OPTIONS) if assembler supports preprocessing by default.
# In case of assembler does not support preprocessing and preprocessing is
# enabled by $(ASFLAGS_VECTOR_PREPROCESS) in a prestep
# $(CPPFLAGS_CORE) must be set in $(ASFLAGS_VECTOR_PREPROCESS)
#------------------------------------------------------------------------------
ASFLAGS_VECTOR_OPTIONS = 

#------------------------------------------------------------------------------
# Please enter all customer options below
#------------------------------------------------------------------------------
ASFLAGS_CUSTOMER_OPTIONS = 

#------------------------------------------------------------------------------
# $(ASVERSION) defines the assembler switch for version report.
# E.g.: ASVERSION = -V
#------------------------------------------------------------------------------
ASVERSION = -Wa-V dummy.asm

#------------------------------------------------------------------------------
# $(AS_LC) defines the number of lines used for assembler version information.
# $(AS_OFF) defines the offset of lines used for assembler version information
# in BrsVinfo.h and Deliverydescription (default is 5).
#------------------------------------------------------------------------------
AS_OFF = $(CC_OFF)
AS_LC  = $(CC_LC)

#------------------------------------------------------------------------------
#------------------------- MUST be filled out ---------------------------------
# $(CC_ENV) is the environment necessary to run the compiler
# $(CC) defines the path to the C-Compiler
# $(CFLAGS_VECTOR_MAKESUPPORT) defines all compiler switches, mandatory for
#                              the Vector build environment (Makesupport/BrsHw)
# $(CFLAGS_VECTOR_OPTIONS) defines the Vector default compiler switches
# $(CFLAGS_CUSTOMER_OPTIONS) defines the customer requested compiler switches
# Depending $(CFLAGS_SELECTOR), $(CFLAGS_VECTOR_OPTIONS) or
# $(CFLAGS_CUSTOMER_OPTIONS) is used together with $(CFLAGS_VECTOR_MAKESUPPORT)
# for build.
#
#  Avoid $(OBJ_SUFFIX) to filter use $(basename $@) because
#  ECO has a preprocess using CFLAGS_xx and the target is of type source.
#------------------------------------------------------------------------------
CC_ENV = LM_LICENSE_FILE=$(LM_LICENSE)
CC     = $(COMPILER_BIN)/cctc

#------------------------------------------------------------------------------
# Please add only absolutely mandatory options below
#
#  BRS values:
#    -DBRS_COMP_$(COMPILER_MANUFACTURER)
#    -DBRS_PLATFORM_$(PLATFORM)
#
#  Avoid $(OBJ_SUFFIX) to filter. Use $(basename $@) because
#  ECO has a preprocess using CFLAGS_xx and the target is of type source.
#------------------------------------------------------------------------------
CPPFLAGS_VECTOR_MAKESUPPORT = -DBRS_PLATFORM_$(PLATFORM) \
                              -DBRS_COMP_$(COMPILER_MANUFACTURER)

CFLAGS_VECTOR_MAKESUPPORT = --create=object \
                            -o $@

clean::
	@$(ECHO) "CLEAN      temporary compiler files"
	$(Q)$(LS) cc* 2>/dev/null | $(SED) -nE '/cc[0-9a-f]+/p' | xargs $(RM)

#------------------------------------------------------------------------------
#  Add depend options here.
#  It is separated because of the option to overwrite
#  $(COMPILER_SUPPORTS_DEPEND) or have different compile without
#  path length problem in command line.
#
#  Pay attention below if $(MAKESUPPORT_POST_COMPILE_CMD) is
#  used in context of depend file creation.
#
#  Example:
#    CFLAGS_VECTOR_MAKESUPPORT    += -MMD -MF $(@:.o=.dt)
#    MAKESUPPORT_POST_COMPILE_CMD += $(SED) -Ef $(MAKESUPPORT_DIR_U)/util/fix_dos_dep_file.sed < $(@:.o=.dt) > $(@:.o=.d);
#    MAKESUPPORT_POST_COMPILE_CMD += $(RM) $(@:.o=.dt);
#------------------------------------------------------------------------------
ifeq ($(COMPILER_SUPPORTS_DEPEND),1)
  #  First create the dependency file with suffix .dq
  #  with --dep-file - option.
  #  Then fix " and move in one step to the destination.
  #
  #  This avoids include wrong dependency file in case of
  #  CTRL-C the compile process.
  #
  CFLAGS_VECTOR_MAKESUPPORT += --dep-file=$(basename $@).dq --make-target=$@
  #
  #  parser docu
  #  - dos->unix
  #  - erase "file" which goes to system header
  #  - erase empty rules " : "
  #  - erase empty target rules ( no sources )
  #  - convert '\' -> '/'
  #  - grep erase empty lines
  #  - 'sort' to use 'uniq' to reduce rules which should be faster parsed by make
  #
  # remark: It is *NOT* possible to use a single sed, because output from one
  # is input of another sed-script.
  #
  MAKESUPPORT_POST_COMPILE_CMD  = tr -d '\r' < $(basename $@).dq
  MAKESUPPORT_POST_COMPILE_CMD += | sed 's/"[^"]*"//g'
  MAKESUPPORT_POST_COMPILE_CMD += | sed 's/^[[:blank:]]*:[[:blank:]]*$$//g'
  MAKESUPPORT_POST_COMPILE_CMD += | sed 's/^[^:]*:[[:blank:]]*$$//g'
  MAKESUPPORT_POST_COMPILE_CMD += | tr '\\' "/"
  MAKESUPPORT_POST_COMPILE_CMD += | grep -v "^$$"
  MAKESUPPORT_POST_COMPILE_CMD += | sort | uniq > $(basename $@).d
  MAKESUPPORT_POST_COMPILE_CMD += ; rm $(basename $@).dq

  #-----------------------------------------------------------------------------
  # If $(CC) shall create dependency file as well, fill the following variables.
  # Otherwise, 'clang' does the task without using a floating license.
  #-----------------------------------------------------------------------------
  #DEPEND = $(CC_ENV) $(CC)
  #DEPENDFLAGS = 
endif

#------------------------------------------------------------------------------
#  $(REUSE_CPP_DEPEND) is set because compiler has a path length problem
#------------------------------------------------------------------------------
#REUSE_CPP_DEPEND = 1
ifeq ($(COMPILER_SUPPORTS_DEPEND)+$(REUSE_CPP_DEPEND),1+1)
  $(error Can not set both: COMPILER_SUPPORTS_DEPEND and REUSE_CPP_DEPEND
endif

#------------------------------------------------------------------------------
#  Post compile command to cleanup anything during compilation process
#
#  Calling convention:
#    $(MAKESUPPORT_POST_COMPILE_CMD,$@$<)
#------------------------------------------------------------------------------
MAKESUPPORT_POST_COMPILE_CMD +=

#------------------------------------------------------------------------------
# Please add any other option below (Vector default options)
#  Avoid $(OBJ_SUFFIX) to filter use $(basename $@) because
#  ECO has a preprocess using CFLAGS_xx and the target is of type source.
#------------------------------------------------------------------------------
CFLAGS_VECTOR_OPTIONS = --core=$(CORE_SWITCH_$(DERIVATIVE))       \
                        --iso=99                                  \
                        --keep-temporary-files                    \
                        --integer-enumeration                     \
                        -Wa--emit-locals=+equ,+symbols            \
                        -Wa--section-info=+list,-console          \
                        -Wa--optimize=+generics,+instr-size       \
                        -Wa--debug-info=+asm,+hll,+local,+smart   \
                        -Wc--debug-info=default                   \
                        -Wc--align=4                              \
                        -Wc--default-a0-size=0                    \
                        -Wc--default-a1-size=0                    \
                        -Wc--default-near-size=0                  \
                        -Wc--optimize=aceFgIklMnopRsUvwy,+predict \
                        -Wc--tradeoff=2                           \
                        -Wc--language=-gcc,+volatile,-strings,-comments

#------------------------------------------------------------------------------
# Please enter all customer options below
#  Avoid $(OBJ_SUFFIX) to filter use $(basename $@) because
#  ECO has a preprocess using CFLAGS_xx and the target is of type source.
#------------------------------------------------------------------------------
CFLAGS_CUSTOMER_OPTIONS =

#------------------------------------------------------------------------------
# $(CVERSION) defines the compiler switch for version report
# E.g.: CVERSION = -V
#------------------------------------------------------------------------------
CVERSION = -Wc-V dummy.c

#------------------------------------------------------------------------------
# $(CC_LC) defines the number of lines used for compiler version information
# $(CC_OFF) defines the offset of lines used for compiler version information
# in BrsVinfo.h and Deliverydescription (default is 5)
#------------------------------------------------------------------------------
CC_OFF = 1
CC_LC  = 1

#------------------------------------------------------------------------------
#------------------------- MUST be filled out ---------------------------------
# $(CXX_ENV) is the environment necessary to run the compiler
# $(CXX) defines the path to the C-Compiler
# $(CFLAGS_VECTOR_MAKESUPPORT) defines all compiler switches, mandatory for
#                              the Vector build environment (MakeSupport/BrsHw)
# $(CXXFLAGS_VECTOR_OPTIONS) defines the Vector default compiler switches
# $(CXXFLAGS_CUSTOMER_OPTIONS) defines the customer requested compiler switches
# Depending of CXXFLAGS_SELECTOR, CXXFLAGS_VECTOR_OPTIONS or CXXFLAGS_CUSTOMER_OPTIONS
# are used together with CXXFLAGS_VECTOR_MAKESUPPORT for Build.
#------------------------------------------------------------------------------
CXX_ENV  = $(CC_ENV)
CXX      = $(COMPILER_BIN)/cptc

#------------------------------------------------------------------------------
# Please add only absolutely mandatory options below
#------------------------------------------------------------------------------
CXXFLAGS_VECTOR_MAKESUPPORT = -c \
                              -o $@

#------------------------------------------------------------------------------
# Please add any other option below (Vector default options)
#------------------------------------------------------------------------------
CXXFLAGS_VECTOR_OPTIONS = -Wall \
                          -O0   \
                          -g3   \
                          -std=c++14

#------------------------------------------------------------------------------
# Please enter all customer options below
#------------------------------------------------------------------------------
CXXFLAGS_CUSTOMER_OPTIONS = 

#------------------------------------------------------------------------------
# $(CXXVERSION) defines the compiler switch for version report
# E.g.: CXXVERSION = -V
#------------------------------------------------------------------------------
CXXVERSION = $(CVERSION)

#------------------------------------------------------------------------------
# $(CXX_LC) defines the number of lines used for compiler version information
# $(CXX_OFF) defines the offset of lines used for compiler version information
# in BrsVinfo.h and Deliverydescription (default is 5)
#------------------------------------------------------------------------------
CXX_OFF = $(CC_OFF)
CXX_LC  = $(CC_LC)

#------------------------------------------------------------------------------
#  Filter out section
#  Add flags which must be filtered out for specific files
#
#  Examples:
#    FILTER_Os=-g              # no debug option for file Os.c
#    FILTER_COMPONENT_Det=-g   # no debug option for component Det
#------------------------------------------------------------------------------
#FILTER_<file_without_extension> = 
#FILTER_COMPONENT_<module_name>  = 

#------------------------------------------------------------------------------
# Additional file specific compiler options
#------------------------------------------------------------------------------
#CFLAGS_<file_without_extension>   = 
#CXXFLAGS_<file_without_extension> = 
#CFLAGS_COMPONENT_<module_name>    = 

#------------------------------------------------------------------------------
#------------------------- MUST be filled out ---------------------------------
# $(LD_ENV) is the environment necessary to run the linker
# $(LD) defines the path to the linker
# $(LDFLAGS_VECTOR_MAKESUPPORT) defines all linker switches, mandatory for the
#                               Vector build environment (MakeSupport/BrsHw)
# $(LDFLAGS_VECTOR_OPTIONS) defines the Vector default linker switches
# $(LDFLAGS_CUSTOMER_OPTIONS) defines the customer requested linker switches
# Depending on $(LDFLAGS_SELECTOR), $(LDFLAGS_VECTOR_OPTIONS) or 
# $(LDFLAGS_CUSTOMER_OPTIONS)is used together with $(LDFLAGS_VECTOR_MAKESUPPORT)
# for build.
#------------------------------------------------------------------------------
LD_ENV = $(CC_ENV)
LD     = $(CC)

#------------------------------------------------------------------------------
# Please add only absolutely mandatory options below
#
#  Please use $(PROJECT_NAME).$(BINARY_SUFFIX) or $(TARGET) instead of $@ and 
#  $(PROJECT_NAME) instead of $* because flags
#  are used in delivery description.
#
#  Linker script file name : $(LINKER_COMMAND_FILE)
#------------------------------------------------------------------------------
LDFLAGS_VECTOR_MAKESUPPORT = -o $(TARGET)                           \
                             -Wl--user-provided-initialization-code \
                             --no-default-libraries                 \
                             --lsl-file=$(LINKER_COMMAND_FILE)

#------------------------------------------------------------------------------
# Set $(PREPROCESS_LINKER_COMMAND_FILE) to 1 to preprocess
# linker command file. $(USER_LINKER_COMMAND_FILE) can be set manually
# but is $(PROJECT_NAME).$(LNK_SUFFIX) by default.
#------------------------------------------------------------------------------
#PREPROCESS_LINKER_COMMAND_FILE = 1

#------------------------------------------------------------------------------
# Please add any other option below (Vector default options)
#
#  Please use $(PROJECT_NAME).$(BINARY_SUFFIX) or $(TARGET) instead of
#  $@ and $(PROJECT_NAME) instead of $* because flags
#  are used in delivery description.
#
#  Linker script file name : $(LINKER_COMMAND_FILE)
#------------------------------------------------------------------------------
LDFLAGS_VECTOR_OPTIONS = --core=$(CORE_SWITCH_$(DERIVATIVE))  \
                         -Wl--output=$(PROJECT_NAME).hex:IHEX \
                         -Wl-OcLtXY                           \
                         -Wl--map-file=$(PROJECT_NAME).map    \
                         -Wl--map-file-format=2

clean::
	@$(ECHO) "CLEAN      hex"
	$(Q)$(RM) $(PROJECT_NAME).hex

#------------------------------------------------------------------------------
# Please enter all customer options below
#
#  Please use $(PROJECT_NAME).$(BINARY_SUFFIX) instead of $@ and 
#  $(PROJECT_NAME) instead of $*, because flags
#  are used in delivery description.
#------------------------------------------------------------------------------
LDFLAGS_CUSTOMER_OPTIONS =

#------------------------------------------------------------------------------
# Please add additional system libraries below
#
#  For some compilers, it is necessary to add additional system libraries.
#  E.g. the ARM GCC Gnu compiler may need libc for memcpy or libgcc for modulo
#
#  To add additional libraries use:
#  -lgcc  (libgcc: e.g. support for modulo operation)
#  -lc    (libc:   e.g. support for memcpy function)
#------------------------------------------------------------------------------
SYSLIBS += 

#------------------------------------------------------------------------------
# $(LDVERSION) defines the linker switch for version report
# E.g.: LDVERSION = -v
#------------------------------------------------------------------------------
LDVERSION = -Wl-V dummy.o

#------------------------------------------------------------------------------
# $(LD_LC) defines the number of lines used for linker version information
# $(LD_OFF) defines the offset of lines used for linker version information
# in BrsVinfo.h and Delivery Description (default is 5)
#------------------------------------------------------------------------------
LD_OFF = $(CC_OFF)
LD_LC  = $(CC_LC)

#------------------------------------------------------------------------------
#------------------------- MUST be filled out if used -------------------------
# $(HEX_ENV) is the environment necessary to run the hexfile generator
# $(HEX) defines the path to the linker, e.g. $(COMPILER_BIN)/gsrec
# $(HEXFLAGS) contains options for HEX tool, e.g. -nos5 -skip .tdata $< -o $@
#------------------------------------------------------------------------------
#HEX_ENV  = $(CC_ENV)
#HEX      = $(COMPILER_BIN)/gsrec
#
#HEXFLAGS = -nos5 -skip .tdata $< -o $@

#------------------------------------------------------------------------------
#------------------------- MUST be filled out if used -------------------------
# $(AR_ENV) is the environment necessary to run the librarian
# $(AR) defines the path to the C-librarian
# $(ARFLAGS) defines all librarian switches
#
# Don't add $@. It is added in rule because AR rule is dynamically generated.
#------------------------------------------------------------------------------
AR_ENV = 
AR     = $(COMPILER_BIN)/artc

ARFLAGS = -cr

#------------------------------------------------------------------------------
# $(ARVERSION) defines the archiver switch for version report
# E.g.: ARVERSION = -v
#------------------------------------------------------------------------------
ARVERSION = -V

#------------------------------------------------------------------------------
# $(AR_LC) defines the number of lines used for librarian version information
# $(AR_OFF) defines the offset of lines used for archiver version information
# in BrsVinfo.h
#------------------------------------------------------------------------------
AR_OFF = 1
AR_LC  = 1

#------------------------------------------------------------------------------
# Additional includes essentially for compilation
#------------------------------------------------------------------------------
ADDITIONAL_INCLUDES +=

#------------------------------------------------------------------------------
# Additional objects essentially for linking
# E.g.: ADDITIONAL_OBJECTS = $(OBJ_PATH)/myobject.$(OBJ_SUFFIX)
#------------------------------------------------------------------------------
ADDITIONAL_OBJECTS +=

#------------------------------------------------------------------------------
# List of assembler source files
# E.g.: ASM_SOURCES = source/startup.$(ASM_SUFFIX)
#------------------------------------------------------------------------------
ASM_SOURCES +=

#------------------------------------------------------------------------------
# Add Startup code to application source list
# E.g.: APP_SOURCE_LST += source/startup.c
#------------------------------------------------------------------------------
APP_SOURCE_LST +=

#------------------------------------------------------------------------------
# Check if all necessary variables are set
# (Checks that are not possible to be performed within Makefile.static)
#------------------------------------------------------------------------------

###############################################################################
######### DO NOT remove these lines from the end of the Makefile!!! ###########
###############################################################################

#------------------------------------------------------------------------------
# Include the main makefile where all the targets are defined
#------------------------------------------------------------------------------
include $(MAKESUPPORT_DIR)/Global.Makefile.target.$(VERSION).mk

# End of Makefile
