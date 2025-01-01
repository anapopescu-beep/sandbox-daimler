ASM_SUFFIX := asm
C_SUFFIX := c
H_SUFFIX := h
DEP_SUFFIX := d
LST_SUFFIX := lst
ERR_SUFFIX := err
WARN_SUFFIX := warn
DEP_WARN_SUFFIX := dwarn
OBJ_SUFFIX := o
MAP_SUFFIX := map
LNK_SUFFIX := lsl
BINARY_SUFFIX := elf
SYM_SUFFIX := sym
SYMBOL_SUFFIX :=
SREC_SUFFIX := s19
HEX_SUFFIX := hex
VBF_SUFFIX := vbf

COMP := $(subst \,/,$(COMPILER_DIR))/carm/bin/ccarm.exe
AS := $(subst \,/,$(COMPILER_DIR))/carm/bin/ccarm.exe
CPP = $(subst \,/,$(CYGWIN_DIR))/bin/clang.exe
LINK := $(subst \,/,$(COMPILER_DIR))/carm/bin/ccarm.exe
LIB := 
CELF := $(subst \,/,$(COMPILER_DIR))/carm/bin/elfsize.exe
CHEX :=
CPRD :=
PARSER :=
CODE_OPTIMIZER :=
CODE_GEN :=
LICENSE_SERVER :=
IMAGE_CREATOR := csapacmpz.exe

DEP := gcc

COMPILER_INC  = $(subst \,/,$(COMPILER_DIR))/carm/include \
				$(subst \,/,$(COMPILER_DIR))/carm/include.cpp \
				$(subst \,/,$(COMPILER_DIR))/carm/cmsis/Device/ARM/ARMCM3/Include \
                $(subst \,/,$(COMPILER_DIR))/carm/cmsis/Include	\
				$(subst \,/,$(COMPILER_DIR))/ctc/include/sfr
COMPILER_LIB  = $(subst \,/,$(COMPILER_DIR))/carm/lib

# filename    : Makefile.compiler
# description : Compiler specific variable setup
# author      : Dan Dustinta
# copyright   : Copyright (c) 2018, Autoliv Electronic
# version     : 1.0.2
# email       : dan.dustinta@autoliv.com
# status      : Released
