include gmsl
include Makefile.target.config.mk
include Makefile.utilities.mk

$(if $(filter all,$(strip $(MAKECMDGOALS))),\
$(eval TARGET := all),\
$(if $(filter help,$(strip $(MAKECMDGOALS))),\
$(eval TARGET := help),\
$(if $(filter all-eclipse,$(strip $(MAKECMDGOALS))),\
$(eval TARGET := all-eclipse),\
$(if $(filter all-release,$(strip $(MAKECMDGOALS))),\
$(eval TARGET := all),\
$(if $(filter %-clean,$(strip $(MAKECMDGOALS))),\
$(eval TARGET := $(subst -clean,,$(MAKECMDGOALS))),\
$(if $(filter %-eclipse,$(strip $(MAKECMDGOALS))),\
$(eval TARGET := $(subst -eclipse,,$(MAKECMDGOALS))),\
$(if $(filter %-sanity_checks,$(strip $(MAKECMDGOALS))),\
$(eval TARGET := $(subst -sanity_checks,,$(MAKECMDGOALS))),\
$(eval TARGET := $(strip $(MAKECMDGOALS))))))))))

define setLowerCase
$(subst A,a,$(subst B,b,$(subst C,c,$(subst D,d,$(subst E,e,$(subst F,f,$(subst G,g,$(subst H,h,$(subst I,i,$(subst J,j,$(subst K,k,$(subst L,l,$(subst M,m,$(subst N,n,$(subst O,o,$(subst P,p,$(subst Q,q,$(subst R,r,$(subst S,s,$(subst T,t,$(subst U,u,$(subst V,v,$(subst W,w,$(subst X,x,$(subst Y,y,$(subst Z,z,$1))))))))))))))))))))))))))
endef

ifeq ($(strip $(MAKECMDGOALS)),all-release)
BUILD_MODE := RELEASE
else
BUILD_MODE := DEBUG
endif

ifeq ($(strip $(TARGET)),all)
$(strip $(MAKECMDGOALS)): ## all : cleans and build all of the available software components
	$(foreach VALID_TARGET,$(VALID_TARGETS),\
	$(eval MAKEFILE_CFG := $(if $(call seq,$(TARGET_TYPE_$(VALID_TARGET)),ALV_BUILD),Makefile.main.mk,Makefile.basic.mk)) \
	echo "make -s -e -j -f $(MAKEFILE_CFG) $(VALID_TARGET)-clean TARGET=$(VALID_TARGET) TARGET_KEY=$(TARGET_KEYWORD_$(VALID_TARGET)) CURRENT_DIR= BUILD_MODE=$(BUILD_MODE) EMPTY_VAR="; \
	make -s -e -j -f $(MAKEFILE_CFG) $(VALID_TARGET)-clean TARGET=$(VALID_TARGET) TARGET_KEY=$(TARGET_KEYWORD_$(VALID_TARGET)) CURRENT_DIR=$(CURDIR) BUILD_MODE=$(BUILD_MODE) EMPTY_VAR=; \
	echo $(EMPTY_VAR); \
	echo "make -s -e -j -f $(MAKEFILE_CFG) $(VALID_TARGET) TARGET=$(VALID_TARGET) TARGET_KEY=$(TARGET_KEYWORD_$(VALID_TARGET)) CURRENT_DIR= BUILD_MODE=$(BUILD_MODE) JENKINS_BUILD=$(JENKINS_BUILD) EMPTY_VAR="; \
	make -s -e -j -f $(MAKEFILE_CFG) $(VALID_TARGET) TARGET=$(VALID_TARGET) TARGET_KEY=$(TARGET_KEYWORD_$(VALID_TARGET)) CURRENT_DIR=$(CURDIR) BUILD_MODE=$(BUILD_MODE) JENKINS_BUILD=$(JENKINS_BUILD) EMPTY_VAR=; \
	echo $(EMPTY_VAR); \
	)
else

ifeq ($(strip $(TARGET)),all-eclipse)
$(strip $(MAKECMDGOALS)): ## all-eclipse -: generates an eclipse project and workspace for all of the available software components	
	$(eval MAKEFILE_CFG := $(if $(call seq,$(TARGET_TYPE_$(firstword $(VALID_TARGETS))),ALV_BUILD),Makefile.main.mk,Makefile.basic.mk))
	echo "make -s -e -j -f $(MAKEFILE_CFG) $(firstword $(VALID_TARGETS))-eclipse TARGET=$(firstword $(VALID_TARGETS)) TARGET_KEY=$(TARGET_KEYWORD_$(firstword $(VALID_TARGETS))) CURRENT_DIR= RUN_ECLIPSE=FALSE GENERATE_ECLIPSE=TRUE CLEAN_ECLIPSE_WORKSPACE=TRUE CLEAN_ECLIPSE_PROJECT=TRUE EMPTY_VAR= "
	make -s -e -j -f $(MAKEFILE_CFG) $(firstword $(VALID_TARGETS))-eclipse TARGET=$(firstword $(VALID_TARGETS)) TARGET_KEY=$(TARGET_KEYWORD_$(firstword $(VALID_TARGETS))) CURRENT_DIR=$(CURDIR) RUN_ECLIPSE=FALSE GENERATE_ECLIPSE=TRUE CLEAN_ECLIPSE_WORKSPACE=TRUE CLEAN_ECLIPSE_PROJECT=TRUE EMPTY_VAR= 
	echo $(EMPTY_VAR)

ifeq ($(filter $(call subtract,$(words $(VALID_TARGETS)),1),0),)
	$(foreach VALID_TARGET,$(wordlist 2,$(words $(VALID_TARGETS)),$(VALID_TARGETS)),\
	$(eval MAKEFILE_CFG := $(if $(call seq,$(TARGET_TYPE_$(VALID_TARGET)),ALV_BUILD),Makefile.main.mk,Makefile.basic.mk)) \
	echo "make -s -e -j -f $(MAKEFILE_CFG) $(VALID_TARGET)-eclipse TARGET=$(VALID_TARGET) TARGET_KEY=$(TARGET_KEYWORD_$(VALID_TARGET)) CURRENT_DIR= RUN_ECLIPSE=FALSE GENERATE_ECLIPSE=TRUE CLEAN_ECLIPSE_WORKSPACE=FALSE CLEAN_ECLIPSE_PROJECT=FALSE EMPTY_VAR= "; \
	make -s -e -j -f $(MAKEFILE_CFG) $(VALID_TARGET)-eclipse TARGET=$(VALID_TARGET) TARGET_KEY=$(TARGET_KEYWORD_$(VALID_TARGET)) CURRENT_DIR=$(CURDIR) RUN_ECLIPSE=FALSE GENERATE_ECLIPSE=TRUE CLEAN_ECLIPSE_WORKSPACE=FALSE CLEAN_ECLIPSE_PROJECT=FALSE EMPTY_VAR=; \
	echo $(EMPTY_VAR); \
	)
endif

	# dummy call to run eclipse
	$(eval MAKEFILE_CFG := $(if $(call seq,$(TARGET_TYPE_$(lastword $(VALID_TARGETS))),ALV_BUILD),Makefile.main.mk,Makefile.basic.mk))
	make -s -e -j -f Makefile.main.mk $(lastword $(VALID_TARGETS))-eclipse TARGET=$(lastword $(VALID_TARGETS)) TARGET_KEY=$(TARGET_KEYWORD_$(lastword $(VALID_TARGETS))) CURRENT_DIR=$(CURDIR) RUN_ECLIPSE=TRUE GENERATE_ECLIPSE=FALSE CLEAN_ECLIPSE_WORKSPACE=FALSE CLEAN_ECLIPSE_PROJECT=FALSE EMPTY_VAR= 
	echo $(EMPTY_VAR)	
else

ifneq ($(strip $(TARGET)),help)
TARGET_KEY := $(foreach VALID_TARGET,$(VALID_TARGETS),$(if $(filter %$(call setLowerCase,$(TARGET)), $(VALID_TARGET)),$(TARGET_KEYWORD_$(VALID_TARGET))))
MAKEFILE_CFG := $(if $(call seq,$(TARGET_TYPE_$(TARGET)),ALV_BUILD),Makefile.main.mk,Makefile.basic.mk)
	
ifeq ($(strip $(TARGET_KEY)),)
$(error $(MAKECMDGOALS) is not a valid build target)
endif

$(strip $(MAKECMDGOALS)):
#if TARGET = FBL_UPDATER, prepare the FBL for the Updater before starting to build
ifeq ($(strip $(MAKECMDGOALS)),fbl_upd)
	pushd $(subst \,/,$(FBL_UPDATER_CONFIG_DIR)) > /dev/null
	cmd /C $(subst \,/,$(FBL_UPDATER_CONFIG_DIR))/FblUpd_Prepare.bat
	popd > /dev/null
endif
ifeq ($(strip $(MAKECMDGOALS)),fblbm_upd)
	pushd $(subst \,/,$(FBLBM_UPDATER_CONFIG_DIR)) > /dev/null
	cmd /C $(subst \,/,$(FBLBM_UPDATER_CONFIG_DIR))/FblUpd_Prepare.bat
	popd > /dev/null
endif
#BUILD the target
	make -s -e -j $(THREAD) -f $(MAKEFILE_CFG) $(strip $(MAKECMDGOALS)) TARGET=$(TARGET) TARGET_KEY=$(strip $(TARGET_KEY)) CURRENT_DIR=$(CURDIR) RUN_ECLIPSE=TRUE GENERATE_ECLIPSE=TRUE CLEAN_ECLIPSE_WORKSPACE=TRUE CLEAN_ECLIPSE_PROJECT=TRUE BUILD_MODE=$(BUILD_MODE) FILTER=$(FILTER) EMPTY_VAR=  
endif
endif
endif

MAKEFILE_LIST := ./Makefile $(call rwildcard,./,*.mk)

help: ## help : output this list
	@grep -E '[a-zA-Z\$\%\(\)_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | gawk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
	
.PHONY: $(strip $(MAKECMDGOALS)) help
.ONESHELL:
.SUFFIXES:
.SILENT:

# filename    : Makefile
# description : Entry point to build environment
# author      : Dan Dustinta
# copyright   : Copyright (c) 2018, Autoliv Electronic
# version     : 2.0.0
# email       : dan.dustinta@autoliv.com
# status      : Released
