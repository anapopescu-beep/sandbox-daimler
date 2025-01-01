include gmsl

comma:= ,
space:= $(EMPTY_VAR) $(EMPTY_VAR)

# description\: silence certain irrelevant warnings from srec_cat
# param\: $1 - command line
# return\: program output
define srec_cat
srec_cat_wrapper -s="$(SRECORD_INSTALLATION_DIR)/srec_cat.exe" -c="$1"
endef

# description\: make does not offer a recursive wildcard function, so here's one
# param\: $1 - path
#         $2 - item pattern 
# return\: list of items in folder
define rwildcard
$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))
endef

# description\: returns items not containing token
# param\: $1 - token list
#         $2 - item list 
# return\: list of items not containing token
define not-containing 
$(foreach v,$2,$(if $(strip $(foreach i,$1,$(findstring $i,$v))),,$v))
endef

define containing 
$(foreach v,$2,$(if $(strip $(foreach i,$1,$(findstring $i,$v))),$v,))
endef

# description\: searches for the source file path by taking the object file stem as a parameter
# param\: $@ - path to object file
#         $1 - c/asm to differentiate between assembler/c source lists
#         $2 - source group that will be searched 
# return\: path to correspondent source file

define getSourceFile
$(filter %/$(basename $(notdir $@)).$($1_SUFFIX),$(COMPONENT_$1_SOURCES_$2))
endef

# description\: transforms a relative path into a windows style absolute path
# param\: $1 - relative path
# return\: absolute windows style path

define getWinDir
$(strip $(if $(strip $1),\
$(if $(realpath $(strip $1)),\
$(if $(strip $(filter /cygdrive/%,$(realpath $(strip $1)))),\
$(subst \,/,$(call substr,$(patsubst /cygdrive/%,%,$(realpath $(strip $1))),1,1):$(call substr,$(patsubst /cygdrive/%,%,$(realpath $(strip $1))),2,256)),\
$(subst \,/,$(shell cygpath --absolute --windows $1))),\
$(subst \,/,$(shell cygpath --absolute --windows $1)))))
endef


# description\: searches the linker file for static addresses that may change over the development lifecycle of the Application
#               and are needed in Bootloader
# param\: $1 - path to linker file
#         $2 - section
# return\: address of section

define readApplicationLinkerFileAddr
$(strip $(shell cat $1 | sed -n 's| $2 | $2 |p' | sed -n 's|.*\($2\)[a-zA-Z -]*\(-b\)[ ]*\(0x[0-9a-fA-F]*\).*|\3|p' ))
endef

# description\: searches the linker file for section length that may change over the development lifecycle of the Application
#               and are needed in Bootloader
# param\: $1 - path to linker file
#         $2 - section
# return\: size of section

define readApplicationLinkerFileLen
$(strip $(shell cat $1 | sed -n 's| $2 | $2 |p' | sed 's|.*\($2\).*\(-m\)[ ]*\([0x]*[0-9a-fA-F]*\).*|\3|' ))
endef

# filename    : Makefile.utilities
# description : Makefile contains generic shell/Makefile functions that can be reused
# author      : Dan Dustinta
# copyright   : Copyright (c) 2018, Autoliv Electronic
# version     : 1.0.1
# email       : dan.dustinta@autoliv.com
# status      : Released
