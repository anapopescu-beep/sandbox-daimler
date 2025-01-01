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

COMP := $(subst \,/,$(COMPILER_DIR))/ctc/bin/cctc.exe
AS := $(subst \,/,$(COMPILER_DIR))/ctc/bin/cctc.exe
CPP = 
LINK := $(subst \,/,$(COMPILER_DIR))/ctc/bin/cctc.exe
LIB := 
CELF := $(subst \,/,$(COMPILER_DIR))/ctc/bin/elfsize.exe
CHEX := 
CPRD :=
PARSER :=
CODE_OPTIMIZER :=
CODE_GEN :=
LICENSE_SERVER :=
IMAGE_CREATOR := csapacmpz.exe

DEP := gcc

COMPILER_INC  = $(subst \,/,$(COMPILER_DIR))../include/
COMPILER_LIB  = 

# filename    : Makefile.compiler
# description : Compiler specific variable setup
# author      : Dan Dustinta
# copyright   : Copyright (c) 2018, Autoliv Electronic
# version     : 1.0.2
# email       : dan.dustinta@autoliv.com
# status      : Released
