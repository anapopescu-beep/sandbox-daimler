$(eval VARIANT_TARGET_KEY := $(if $(findstring Application,$(TARGET_KEY)),Application,$(TARGET_KEY)))
include $(VARIANT_TARGET_KEY)/Makefile.compiler.mk
include $(VARIANT_TARGET_KEY)/Makefile.config.mk
ifneq ($(MAKECMDGOALS),$(TARGET)-clean)
ifneq ($(TARGET),help)
include Makefile.utilities.mk
ifeq ($(MAKECMDGOALS),$(TARGET)-eclipse)
include Makefile.eclipse.mk
endif
ifeq ($(MAKECMDGOALS),$(TARGET)-neeva_ws)
include Makefile.eclipse.mk
endif
include Makefile.report.mk

#SHELL += -x

$(foreach COMPONENT,$(COMPONENTS_LIST),$(eval SRC_COMPONENT_PATH_LIST_$(COMPONENT) := $(foreach MODULE,$($(COMPONENT)_COMPONENTS_LIST),$(call $(COMPONENT)_SOURCES_DIR,$(MODULE)))))

ifeq ($(PARSE_HEADER_FILES),TRUE)
$(foreach COMPONENT,$(COMPONENTS_LIST),$(eval INC_COMPONENT_PATH_LIST_$(COMPONENT) := $(foreach MODULE,$($(COMPONENT)_COMPONENTS_LIST),$(call $(COMPONENT)_INCLUDES_DIR,$(MODULE)))))
endif

$(foreach COMPONENT,$(COMPONENTS_LIST),$(eval IGNORE_SOURCES_LIST_$(COMPONENT) := $(foreach IGNORE_SOURCE,$($(COMPONENT)_IGNORE_SOURCES_LIST),$(IGNORE_SOURCE))))

$(foreach COMPONENT,$(COMPONENTS_LIST),$(eval COMPONENT_C_SOURCES_$(COMPONENT) := $(foreach COMPONENT_PATH,$(SRC_COMPONENT_PATH_LIST_$(COMPONENT)),$(call not-containing,$(IGNORE_SOURCES_LIST_$(COMPONENT)),$(call rwildcard,$(COMPONENT_PATH)/,*.$(C_SUFFIX))))))

$(foreach COMPONENT,$(COMPONENTS_LIST),$(eval COMPONENT_ASM_SOURCES_$(COMPONENT) := $(foreach COMPONENT_PATH,$(SRC_COMPONENT_PATH_LIST_$(COMPONENT)),$(call not-containing,$(IGNORE_SOURCES_LIST_$(COMPONENT)),$(call rwildcard,$(COMPONENT_PATH)/,*.$(ASM_SUFFIX))))))

ifeq ($(PARSE_HEADER_FILES),TRUE)
$(info Parsing header files)
$(foreach COMPONENT,$(COMPONENTS_LIST),$(eval COMPONENT_H_SOURCES_$(COMPONENT) := $(foreach COMPONENT_PATH,$(INC_COMPONENT_PATH_LIST_$(COMPONENT)),$(call not-containing,$(IGNORE_SOURCES_LIST_$(COMPONENT)),$(call rwildcard,$(COMPONENT_PATH)/,*.$(H_SUFFIX))))))
endif

$(eval DEP_FILES := $(addprefix $(DEP_DIR)/,$(addsuffix .$(DEP_SUFFIX),$(basename $(notdir $(foreach COMPONENT,$(COMPONENTS_LIST),$(COMPONENT_C_SOURCES_$(COMPONENT))))))))

$(foreach COMPONENT,$(COMPONENTS_LIST),$(eval OBJ_C_SOURCES_$(COMPONENT) := $(addprefix $(OBJ_DIR)/,$(addsuffix .$(OBJ_SUFFIX),$(basename $(notdir $(COMPONENT_C_SOURCES_$(COMPONENT))))))))
$(foreach COMPONENT,$(COMPONENTS_LIST),$(eval OBJ_ASM_SOURCES_$(COMPONENT) := $(addprefix $(OBJ_DIR)/,$(addsuffix .$(OBJ_SUFFIX),$(basename $(notdir $(COMPONENT_ASM_SOURCES_$(COMPONENT))))))))

$(eval ALL_COMPONENT_C_SOURCES := $(foreach COMPONENT,$(COMPONENTS_LIST),$(COMPONENT_C_SOURCES_$(COMPONENT))))

$(eval ALL_OBJ_C_SOURCES := $(foreach COMPONENT,$(COMPONENTS_LIST),$(OBJ_C_SOURCES_$(COMPONENT))))
$(eval ALL_OBJ_ASM_SOURCES := $(foreach COMPONENT,$(COMPONENTS_LIST),$(OBJ_ASM_SOURCES_$(COMPONENT))))
$(eval ALL_OBJ_SOURCES := $(ALL_OBJ_C_SOURCES) $(ALL_OBJ_ASM_SOURCES))

include $(VARIANT_TARGET_KEY)/Makefile.compiler.options.mk

$(eval BINARY_FILE := $(OUT_DIR)/$(TARGET).$(BINARY_SUFFIX))
ifeq ($(ELF_FILE_GENERATION),TRUE)
$(eval ELF_FILE := $(OUT_DIR)/$(TARGET).$(SYMBOL_SUFFIX))
endif
$(eval SREC_FILE := $(OUT_DIR)/$(TARGET).$(SREC_SUFFIX))
$(eval LINKER_FILE := $(VARIANT_TARGET_KEY)/$(LINKER_FILE_STEM).$(LNK_SUFFIX))
ifneq ($(MAKECMDGOALS),$(TARGET)-eclipse)
-include $(shell find $(DEP_DIR) -name '*.$(DEP_SUFFIX)')
endif
endif
endif

NECESSARY_OUTPUT_PATHS := $(OUTPUT_DIR) \
                          $(DEP_DIR) \
                          $(ERR_DIR) \
                          $(LST_DIR) \
                          $(OBJ_DIR) \
                          $(OUT_DIR)

$(RELEASE_DIR)/$(notdir $(SREC_FILE)): $(SREC_FILE) $(BINARY_FILE) $(UNIFIED_CALIBRATION_FILE) $(FULL_MEMORY_FILE) $(if $(call seq,$(ELF_FILE_GENERATION),TRUE),$(ELF_FILE)) | $(RELEASE_DIR)
	if [ -d "$(RELEASE_DIR)" ]
	then
		echo "Cleaning directory: $(RELEASE_DIR)"
		rm -rf $(RELEASE_DIR) > /dev/null 2>&1 || true 
		mkdir -p $(RELEASE_DIR) > /dev/null 2>&1 || true 
	fi
	if [ ! -d $(RELEASE_DIR) ]
	then
		echo "Creating directory: $(RELEASE_DIR)"
		mkdir -p $(RELEASE_DIR) > /dev/null 2>&1 || true 
	fi
	echo Copying output to release folder
	cp -f $(OUT_DIR)/* $(RELEASE_DIR)
	
ifeq ($(TARGET_KEY),Bootloader)
	if [ ! -d $(BASE_RELEASE_DIR)/Secondary_Bootloader ]
	then
		echo "Creating directory: $(BASE_RELEASE_DIR)/Secondary_Bootloader"
		mkdir -p $(BASE_RELEASE_DIR)/Secondary_Bootloader > /dev/null 2>&1 || true 
	fi
	
	echo "Copying FlashDrv(Secondary Bootloader) to delivery"
	cp -f $(VECTOR_SOURCES_DIR)/Flash/_binaries/* $(BASE_RELEASE_DIR)/Secondary_Bootloader
	cp -f $(GENY_CONFIG_DIR)/Bootloader/DemoKeys/c_key.txt $(BASE_RELEASE_DIR)/Secondary_Bootloader
endif

ifneq (,$(findstring Application,$(TARGET_KEY)))
ifeq ($(AEC_CALIBRATION_SUPPORT),TRUE)
	cp -f $(AEC_CALIBRATION_FILE) $(RELEASE_DIR)

	cp -f $(CALIBRATION_FLASH_FILE) $(RELEASE_DIR)
	cp -f $(DEFAULT_FILE) $(RELEASE_DIR)
endif

ifeq ($(DYNAMIC_E2P_SUPPORT),TRUE)
	cp -f $(DYNAMIC_E2P_FILE) $(RELEASE_DIR)

	cp -f $(E2P_STUDY_FILE) $(RELEASE_DIR)
	cp -f $(E2P_SYMBOL_FILE) $(RELEASE_DIR)
endif

ifeq ($(BOLO_FLASH_VALIDATION),TRUE)	
	$(call srec_cat,$(DEFAULT_FILE) -crop $(DEFAULT_NVP_RANGE) -fill 0xFF $(DEFAULT_NVP_RANGE) -o $(RELEASE_DIR)/$(notdir $(basename $(DEFAULT_FILE)))_customer.$(SREC_SUFFIX))
	$(call srec_cat,$(UNIFIED_CALIBRATION_FILE) -crop $(CALIBRATION_RANGE) -fill 0xFF $(CALIBRATION_RANGE) -o $(RELEASE_DIR)/$(notdir $(basename $(UNIFIED_CALIBRATION_FILE)))_customer.$(SREC_SUFFIX))
	$(call srec_cat,$(subst .s19,_crc.s19,$(SREC_FILE)) -crop $(APPL_CROP_RANGE) -o $(RELEASE_DIR)/$(notdir $(basename $(subst .s19,_crc.s19,$(SREC_FILE))))_customer.$(SREC_SUFFIX))

	$(call srec_cat,$(RELEASE_DIR)/$(notdir $(basename $(subst .s19,_crc.s19,$(SREC_FILE))))_customer.$(SREC_SUFFIX) -exclude $(FLASH_VALIDATION_START_ADDR_APPL) $(FLASH_VALIDATION_END_ADDR_APPL) -generate $(FLASH_VALIDATION_START_ADDR_APPL) $(FLASH_VALIDATION_END_ADDR_APPL) -repeat-data $(FLASH_VALIDATION_FLAG_APPL) -o $(RELEASE_DIR)/$(notdir $(basename $(subst .s19,_crc.s19,$(SREC_FILE))))_debug.$(SREC_SUFFIX))
	$(call srec_cat,$(RELEASE_DIR)/$(notdir $(basename $(UNIFIED_CALIBRATION_FILE)))_customer.$(SREC_SUFFIX) -exclude $(FLASH_VALIDATION_START_ADDR_CALIB) $(FLASH_VALIDATION_END_ADDR_CALIB) -generate $(FLASH_VALIDATION_START_ADDR_CALIB) $(FLASH_VALIDATION_END_ADDR_CALIB) -repeat-data $(FLASH_VALIDATION_FLAG_CALIB) -o $(RELEASE_DIR)/$(notdir $(basename $(UNIFIED_CALIBRATION_FILE)))_debug.$(SREC_SUFFIX))
endif	

ifeq ($(BUILD_MODE),RELEASE)
	if [ ! -d $(BASE_RELEASE_DIR)/Production ]
	then
		echo "Creating directory: $(BASE_RELEASE_DIR)/Production"
		mkdir -p $(BASE_RELEASE_DIR)/Production > /dev/null 2>&1 || true 
	fi
	
	if [ ! -d $(BASE_RELEASE_DIR)/CanFlash ]
	then
		echo "Creating directory: $(BASE_RELEASE_DIR)/CanFlash"
		mkdir -p $(BASE_RELEASE_DIR)/CanFlash > /dev/null 2>&1 || true 
	fi
	
	if [ ! -d $(BASE_RELEASE_DIR)/DIA ]
	then
		echo "Creating directory: $(BASE_RELEASE_DIR)/DIA"
		mkdir -p $(BASE_RELEASE_DIR)/DIA > /dev/null 2>&1 || true 
	fi
ifeq ($(AEC_CALIBRATION_SUPPORT),TRUE)
	if [ ! -d $(BASE_RELEASE_DIR)/ERH ]
	then
		echo "Creating directory: $(BASE_RELEASE_DIR)/ERH"
		mkdir -p $(BASE_RELEASE_DIR)/ERH > /dev/null 2>&1 || true 
	fi
endif
	if [ ! -d $(BASE_RELEASE_DIR)/NVP ]
	then
		echo "Creating directory: $(BASE_RELEASE_DIR)/NVP"
		mkdir -p $(BASE_RELEASE_DIR)/NVP > /dev/null 2>&1 || true 
	fi
	if [ ! -d $(BASE_RELEASE_DIR)/SAP ]
	then
		echo "Creating directory: $(BASE_RELEASE_DIR)/SAP"
		mkdir -p $(BASE_RELEASE_DIR)/SAP > /dev/null 2>&1 || true 
	fi

ifeq ($(REPORT_GENERATION),TRUE)
	if [ ! -d $(BASE_RELEASE_DIR)/Release_log ]
	then
		echo "Creating directory: $(BASE_RELEASE_DIR)/Release_log"
		mkdir -p $(BASE_RELEASE_DIR)/Release_log > /dev/null 2>&1 || true 
	fi
endif

	cp -f $(FULL_MEMORY_FILE) $(BASE_RELEASE_DIR)/Production/$(APPL_VERSION_REV2)
	$(eval CURRENT_DATE:=$(shell date +"%Y_%m_%d"))		
	$(subst \,/,$(HEXVIEW_INSTALLATION_DIR))/hexview.exe $(BASE_RELEASE_DIR)/Production/$(APPL_VERSION_REV2) /XI:32 -o $(BASE_RELEASE_DIR)/Production/UnifiedSW_$(lastword $(subst .,$(space),$(APPL_VERSION_REV2)))_$(CURRENT_DATE).hex /G /s
	
	cp -f $(RELEASE_DIR)/$(notdir $(basename $(DEFAULT_FILE)))_customer.$(SREC_SUFFIX) $(BASE_RELEASE_DIR)/CanFlash
	cp -f $(RELEASE_DIR)/$(notdir $(basename $(UNIFIED_CALIBRATION_FILE)))_customer.$(SREC_SUFFIX) $(BASE_RELEASE_DIR)/CanFlash
	cp -f $(RELEASE_DIR)/$(notdir $(basename $(subst .s19,_crc.s19,$(SREC_FILE))))_customer.$(SREC_SUFFIX) $(BASE_RELEASE_DIR)/CanFlash
	$(call srec_cat, $(RELEASE_DIR)/$(notdir $(basename $(DEFAULT_FILE)))_customer.$(SREC_SUFFIX) $(RELEASE_DIR)/$(notdir $(basename $(subst .s19,_crc.s19,$(SREC_FILE))))_customer.$(SREC_SUFFIX) -o $(BASE_RELEASE_DIR)/CanFlash/$(notdir $(basename $(subst .s19,_crc.s19,$(SREC_FILE))))_customer_merged.$(SREC_SUFFIX) )

ifeq ($(BOOTLOADER_SUPPORT),TRUE)
	cp -f $(BOOTLOADER_FILE) $(BASE_RELEASE_DIR)/CanFlash
endif

	cp -f $(SOURCES_DIR)/DIA/Implementation/src/DIA_ReadDataByIdentifier.c $(BASE_RELEASE_DIR)/DIA
	
ifeq ($(AEC_CALIBRATION_SUPPORT),TRUE)
	tar -xvf $(SOURCES_DIR)/ERH/Config/Workspace_AEC_Configurator.tar -C $(CURRENT_DIR)/$(SOURCES_DIR)/ERH/Config > /dev/null 2>&1 || true
	cp -f $(SOURCES_DIR)/ERH/Config/Workspace_AECConfigurator/AEC_Configurator/ERH_cfg_private.h $(BASE_RELEASE_DIR)/ERH
	cp -f $(SOURCES_DIR)/ERH/Config/Workspace_AECConfigurator/AEC_Configurator/ERH_cfg_public.h $(BASE_RELEASE_DIR)/ERH
	cp -f $(SOURCES_DIR)/ERH/Config/Workspace_AECConfigurator/AEC_Configurator/ErhDataDictionnary.arxml $(BASE_RELEASE_DIR)/ERH
endif

	cp -f $(SOURCES_DIR)/NVP/Config/SBE_4G_NVP_layout.xls $(BASE_RELEASE_DIR)/NVP
ifeq ($(FAB_FILE_SUPPORT),TRUE)
	cp -f $(SOURCES_DIR)/NVP/Config/SBE_4G_NVP_layout.xls $(BASE_RELEASE_DIR)/Production/$(APPL_FAB_VERSION).xls
	cp -f $(FAB_FILE) $(BASE_RELEASE_DIR)/Production/$(APPL_FAB_VERSION)
endif
	cp -f $(SOURCES_DIR)/NVP/Implementation/inc/Nvp_Generated.h $(BASE_RELEASE_DIR)/NVP
	cp -f $(SOURCES_DIR)/NVP/Implementation/src/Nvp_Generated.c $(BASE_RELEASE_DIR)/NVP

ifeq ($(AEC_CALIBRATION_SUPPORT),TRUE)
	rm -rf $(SOURCES_DIR)/ERH/Config/Workspace_AECConfigurator/ > /dev/null 2>&1 || true 
endif

	echo Creating SAP image with $(IMAGE_CREATOR)
	$(call getWinDir,$(CYCLONE_INSTALLATION_DIR))/ImageCreationSupportFiles/$(IMAGE_CREATOR) ! $(call getWinDir,$(CYCLONE_UNIV_CONFIG_DIR)/$(PROJECT_STEM)_CycloneConfig.cfg) hideapp /imagefile $(call getWinDir,$(BASE_RELEASE_DIR)/SAP/UNI_$(SAP_NAME).SAP) imagecontent UNI_$(SAP_NAME).SAP INTERFACE=CYCLONE RESET_DELAY 0 "/param1=$(call getWinDir,$(FULL_MEMORY_FILE))" "/param0=$(call getWinDir,$(CYCLONE_UNIV_FLASH_ALGORITHM))"  
ifeq ($(CYCLONE_UNIV_NVP_SAP_GENERATION),TRUE)
	$(call getWinDir,$(CYCLONE_INSTALLATION_DIR))/ImageCreationSupportFiles/$(IMAGE_CREATOR) ! $(call getWinDir,$(CYCLONE_UNIV_CONFIG_DIR)/$(PROJECT_STEM)_CycloneConfig_NVP.cfg) hideapp /imagefile $(call getWinDir,$(BASE_RELEASE_DIR)/SAP/UNI_NVP_$(SAP_NAME).SAP) imagecontent UNI_NVP_$(SAP_NAME).SAP INTERFACE=CYCLONE RESET_DELAY 0 "/param1=$(call getWinDir,$(FULL_MEMORY_FILE_NO_EEP))" "/param0=$(call getWinDir,$(CYCLONE_UNIV_FLASH_ALGORITHM))" "/param2=$(call getWinDir,$(E2P_STUDY_FILE))"
ifeq ($(FAB_FILE_SUPPORT),TRUE)
	$(call getWinDir,$(CYCLONE_INSTALLATION_DIR))/ImageCreationSupportFiles/$(IMAGE_CREATOR) ! $(call getWinDir,$(CYCLONE_UNIV_CONFIG_DIR)/$(PROJECT_STEM)_CycloneConfig_NVP.cfg) hideapp /imagefile $(call getWinDir,$(BASE_RELEASE_DIR)/SAP/UNI_FAB_NVP_$(SAP_NAME).SAP) imagecontent UNI_FAB_NVP_$(SAP_NAME).SAP INTERFACE=CYCLONE RESET_DELAY 0 "/param1=$(call getWinDir,$(FULL_MEMORY_FILE))" "/param0=$(call getWinDir,$(CYCLONE_UNIV_FLASH_ALGORITHM))" "/param2=$(call getWinDir,$(FAB_FILE))"
endif
ifeq ($(NVM_CHECKSUM_SAP_FILE_GEN),TRUE)
	cp -f $(RELEASE_DIR)/$(notdir $(E2P_STUDY_FILE)) $(RELEASE_DIR)/$(basename $(notdir $(E2P_STUDY_FILE)))_Corrupted.s19
	$(call srec_cat,$(RELEASE_DIR)/$(basename $(notdir $(E2P_STUDY_FILE)))_Corrupted.s19 -exclude $(NVM_CHECKSUM_SAP_FILE_START_ADDR) $(NVM_CHECKSUM_SAP_FILE_END_ADDR) -Random_Fill $(NVM_CHECKSUM_SAP_FILE_START_ADDR) $(NVM_CHECKSUM_SAP_FILE_END_ADDR) -o $(RELEASE_DIR)/$(basename $(notdir $(E2P_STUDY_FILE)))_Corrupted.s19)
	$(call getWinDir,$(CYCLONE_INSTALLATION_DIR))/ImageCreationSupportFiles/$(IMAGE_CREATOR) ! $(call getWinDir,$(CYCLONE_UNIV_CONFIG_DIR)/$(PROJECT_STEM)_CycloneConfig_NVP.cfg) hideapp /imagefile $(call getWinDir,$(BASE_RELEASE_DIR)/SAP/UNI_NVP_CORRUPTED_$(SAP_NAME).SAP) imagecontent UNI_NVP_CORRUPTED_$(SAP_NAME).SAP INTERFACE=CYCLONE RESET_DELAY 0 "/param1=$(call getWinDir,$(FULL_MEMORY_FILE_NO_EEP))" "/param0=$(call getWinDir,$(CYCLONE_UNIV_FLASH_ALGORITHM))" "/param2=$(call getWinDir,$(RELEASE_DIR)/$(basename $(notdir $(E2P_STUDY_FILE)))_Corrupted.s19)"
	rm -f $(RELEASE_DIR)/$(basename $(notdir $(E2P_STUDY_FILE)))_Corrupted.s19 > /dev/null 2>&1 || true 
endif
endif

ifeq ($(REPORT_GENERATION),TRUE)
	echo "Copying build logs to delivery"
	cp -f $(CURRENT_DIR)/Report/* $(BASE_RELEASE_DIR)/Release_log
endif

ifeq ($(COPY_TO_DELIVERIES_DIR),TRUE)
	echo Mirroring Deliveries folder to Release folder
	rm -rf $(DELIVERIES_DIR)/*  
	
	if [ ! -d $(DELIVERIES_DIR) ]
	then
		echo "Creating the Deliveries directory"
		mkdir -p $(DELIVERIES_DIR) > /dev/null 2>&1 || true 
	fi

	cp -rf $(BASE_RELEASE_DIR)/* $(DELIVERIES_DIR)
endif

	$(POST_PROSESSING_DIR)/post_processing.bat "$(RELEASE_DIR)/$(notdir $(basename $(UNIFIED_CALIBRATION_FILE)))_customer.$(SREC_SUFFIX)" "$(BASE_RELEASE_DIR)/CanFlash/$(notdir $(basename $(subst .s19,_crc.s19,$(SREC_FILE))))_customer_merged.$(SREC_SUFFIX)" "$(BASE_RELEASE_DIR)/CanFlash"

endif
endif

ifneq (,$(findstring Application,$(TARGET_KEY)))
$(UNIFIED_CALIBRATION_FILE): $(SREC_FILE) $(BINARY_FILE) $(if $(call seq,$(ELF_FILE_GENERATION),TRUE),$(ELF_FILE))
	$(call srec_cat,$(AEC_CALIBRATION_FILE) $(CALIBRATION_FLASH_FILE) -o $@)

$(FULL_MEMORY_FILE): $(SREC_FILE) $(BINARY_FILE) $(if $(call seq,$(ELF_FILE_GENERATION),TRUE),$(ELF_FILE))
	$(call srec_cat,$(subst .s19,_crc.s19,$(SREC_FILE)) $(DEFAULT_FILE)	$(if $(call seq,$(AEC_CALIBRATION_SUPPORT),TRUE),$(AEC_CALIBRATION_FILE)) $(CALIBRATION_FLASH_FILE) $(if $(call seq,$(BOOTMANAGER_SUPPORT),TRUE),$(BOOTMANAGER_FILE)) $(if $(call seq,$(BOOTLOADER_SUPPORT),TRUE),$(BOOTLOADER_FILE)) $(if $(call seq,$(E2P_STUDY_SUPPORT),TRUE),$(E2P_STUDY_FILE)) -o $@)
ifeq ($(BOOTLOADER_SUPPORT),TRUE)
ifeq ($(BOLO_EEP_VALIDATION),TRUE)
	cp $@ $(FULL_MEMORY_FILE_NO_EEP)
	$(call srec_cat,-generate $(EEP_VALIDATION_START_ADDR) $(EEP_VALIDATION_END_ADDR) -repeat-data $(EEP_VALIDATION_FLAG) $@ -o $@)
endif
ifeq ($(BOLO_FLASH_VALIDATION),TRUE)
	$(call srec_cat,$@ -exclude $(FLASH_VALIDATION_START_ADDR_APPL) $(FLASH_VALIDATION_END_ADDR_APPL) -generate $(FLASH_VALIDATION_START_ADDR_APPL) $(FLASH_VALIDATION_END_ADDR_APPL) -repeat-data $(FLASH_VALIDATION_FLAG_APPL) -o $@)
	$(call srec_cat,$@ -exclude $(FLASH_VALIDATION_START_ADDR_CALIB) $(FLASH_VALIDATION_END_ADDR_CALIB) -generate $(FLASH_VALIDATION_START_ADDR_CALIB) $(FLASH_VALIDATION_END_ADDR_CALIB) -repeat-data $(FLASH_VALIDATION_FLAG_CALIB) -o $@)

	$(call srec_cat,$@ -fill 0xFF $(FULL_FLASH_FILL_RANGE) -o $@)
endif	
endif
endif

ifeq ($(ELF_FILE_GENERATION),TRUE)
$(ELF_FILE): $(BINARY_FILE)
	echo "Generating: [$(notdir $(basename $@)).$(SYMBOL_SUFFIX)]"
	$(CELF) -o $@ $(BINARY_FILE)
	$(CPRD) -s -o $(subst .$(BINARY_SUFFIX),.$(SYM_SUFFIX),$(BINARY_FILE)) $(BINARY_FILE)
endif

$(SREC_FILE): $(BINARY_FILE)
ifeq ($(SHOW_SIZE),TRUE)
	"$(CELF)" -v $(BINARY_FILE)
endif

ifeq ($(APPEND_PP_SUPPORT),TRUE)
	echo "Appending Presence Pattern to: [$(notdir $(basename $@)).$(HEX_SUFFIX)]"

	$(subst \,/,$(HEXVIEW_INSTALLATION_DIR))/hexview.exe $(basename $@).$(HEX_SUFFIX) $(APPEND_PP_ARGUMENTS) -o $(basename $@).$(HEX_SUFFIX)
endif

ifeq ($(DEFAULT_VALUES_MERGE),TRUE)
	echo "Merging default values into: [$(notdir $(basename $@)).$(HEX_SUFFIX)]"

	$(subst \,/,$(HEXVIEW_INSTALLATION_DIR))/hexview.exe $(basename $@).$(HEX_SUFFIX) $(DEFAULT_VALUES_ARGUMENTS) -o $(basename $@).$(HEX_SUFFIX)
endif

ifeq ($(POST_PROC_FBL_UPDATER),TRUE)
	echo "Post processing [$(notdir $(basename $@)).$(HEX_SUFFIX)]"
	
	$(subst \,/,$(HEXVIEW_INSTALLATION_DIR))/hexview.exe $(basename $@).$(HEX_SUFFIX) $(POST_PROC_ARGUMENTS) -o $(basename $@).$(HEX_SUFFIX)
endif
	
ifeq ($(POST_PROC_FBLBM_UPDATER),TRUE)
	echo "Post processing [$(notdir $(basename $@)).$(HEX_SUFFIX)]"
	
	$(subst \,/,$(HEXVIEW_INSTALLATION_DIR))/hexview.exe $(basename $@).$(HEX_SUFFIX) $(POST_PROC_ARGUMENTS) -o $(basename $@).$(HEX_SUFFIX)
endif

ifeq ($(VHSM_VALSTRUCT_SUPPORT),TRUE)
	echo "Appending vHSM Validation Structure to: [$(notdir $(basename $@)).$(HEX_SUFFIX)]"

# Generate ini-file for HexView
	echo "Generate Idx file $(VHSM_VALSTRUCT_INI_NAME).ini for HexView"
	echo "[HSMBOOT]"                               					 > $(VHSM_VALSTRUCT_INI_NAME).ini
	echo "GROUP_ID=$(VHSM_VALSTRUCT_GROUP_ID)"         				>> $(VHSM_VALSTRUCT_INI_NAME).ini
	echo "MODE=$(VHSM_VALSTRUCT_MODE)"      						>> $(VHSM_VALSTRUCT_INI_NAME).ini
	echo "HASH_METHOD=$(VHSM_VALSTRUCT_HASH_METHOD)"                >> $(VHSM_VALSTRUCT_INI_NAME).ini
	echo "SIGNATURE_METHOD=$(VHSM_VALSTRUCT_SIGNATURE_METHOD)"      >> $(VHSM_VALSTRUCT_INI_NAME).ini
	echo "SIGNATURE_PARAM=$(VHSM_VALSTRUCT_KEY_PATH)"              	>> $(VHSM_VALSTRUCT_INI_NAME).ini

	$(subst \,/,$(HEXVIEW_INSTALLATION_DIR))/hexview.exe $(basename $@).$(HEX_SUFFIX) $(VHSM_VALSTRUCT_ARGUMENTS) /o $(basename $@).$(HEX_SUFFIX)

# Show if any error has appeared, and the version of HexView
	cat vshsm_error.txt

# Remove the temporary files needed for this step
	rm -rf vshsm_error.txt
	rm -rf $(VHSM_VALSTRUCT_INI_NAME).ini
	
# Post processing for FBL_UPDATER after appending the vHsm structure
ifeq ($(TARGET),fbl_upd)
ifeq ($(POST_PROC_FBL_UPDATER),TRUE)
	pushd $(subst \,/,$(FBL_UPDATER_CONFIG_DIR)) > /dev/null
	cmd /C $(subst \,/,$(FBL_UPDATER_CONFIG_DIR))/_postprocappl.bat
	popd > /dev/null
endif
endif

# Post processing for FBLBM_UPDATER after appending the vHsm structure
ifeq ($(TARGET),fblbm_upd)
ifeq ($(POST_PROC_FBLBM_UPDATER),TRUE)
	pushd $(subst \,/,$(FBLBM_UPDATER_CONFIG_DIR)) > /dev/null
	cmd /C $(subst \,/,$(FBLBM_UPDATER_CONFIG_DIR))/_postprocappl.bat
	popd > /dev/null
endif
endif

endif

# Preparing the HSM firmware for HSM_UPDATER
ifeq ($(TARGET),hsm)
ifeq ($(HSM_FIRMWARE_PREPARE_FOR_HSMUPDATER),TRUE)
	echo "Preparing the firmware: [$(notdir $(basename $@)).$(HEX_SUFFIX)] for HSM_UPDATER"
	pushd $(subst \,/,$(HSM_UPDATER_CONFIG_DIR)/Appl) > /dev/null
	cmd /C $(subst \,/,$(HSM_UPDATER_CONFIG_DIR)/Appl)/PrepareFirmware.bat
	popd > /dev/null
endif
endif

ifneq (,$(findstring Application,$(TARGET_KEY)))
ifeq ($(S19_CRC_CALCULATION),TRUE)
ifeq ($(HEXVIEW_CRC_SUPPORTED),TRUE)
	$(subst \,/,$(HEXVIEW_INSTALLATION_DIR))/hexview.exe $@ "/FR:$(strip $(APPL_FILL_RANGE_INTV)):$(strip $(APPL_FILL_RANGE_BSW))" /FP:0xFF "/CS0:@$(APPL_CRC_ADDR);$(APPL_CRC_RANGES)" /XS:32 -o $(subst .s19,_crc.s19,$@) /G /s
	$(subst \,/,$(HEXVIEW_INSTALLATION_DIR))/hexview.exe $(subst .s19,_crc.s19,$@) /CR:$(APPL_EXCLUSION_RANGE) /XS:32 -o $(subst .s19,_crc.s19,$@) /G /s
else
ifeq ($(ALV_CRC_SUPPORTED),TRUE)
	cksum -f="$(call getWinDir,$@)" -c="$(APPL_CRC_RANGES)" -a="$(APPL_CRC_ADDR)"
endif
endif
endif
endif

$(BINARY_FILE): $(ALL_OBJ_SOURCES) $(LINKER_FILE) | $(NECESSARY_OUTPUT_PATHS)
	echo "Linking: [$(notdir $(basename $@)).$(BINARY_SUFFIX)]"
ifeq ($(GENERATE_LINKER_CMD),TRUE)
	find $(OBJ_DIR)/*.o | sort > "$(LINK_CMD_XCL)"
	echo $(LINK_CMD_OPT) >> "$(LINK_CMD_XCL)"
endif
ifeq ($(PARSE_LINKER_FILE),TRUE)	
	cp -f $(LINKER_FILE) $(basename $(LINKER_FILE))_bkup.lnk
	chmod 777 $(basename $(LINKER_FILE))_bkup.lnk
	chmod 777 $(LINKER_FILE)

	cat $(LINKER_FILE) | sed 's|+startup-objects|$(ALL_OBJ_ASM_SOURCES)|g' |\
	                     sed 's|+source-objects|$(sort $(ALL_OBJ_C_SOURCES))|g' |\
	                     sed 's|+library-objects|$(LINK_LIB_OBJ)|g' > $(LINKER_FILE)
endif

	if ! "$(LINK)" $(LINK_OPT) >> $(ERR_DIR)/$(basename $(notdir $@))_linker.$(WARN_SUFFIX) 2>&1; then
		mv -f $(ERR_DIR)/$(basename $(notdir $@))_linker.$(WARN_SUFFIX) $(ERR_DIR)/$(basename $(notdir $@))_linker.$(ERR_SUFFIX);
		cat $(ERR_DIR)/$(basename $(notdir $@))_linker.$(ERR_SUFFIX);
ifeq ($(PARSE_LINKER_FILE),TRUE)	
		mv -f $(LINKER_FILE) $(ERR_DIR)/$(notdir $(LINKER_FILE));
		mv -f $(basename $(LINKER_FILE))_bkup.lnk $(LINKER_FILE);
endif
		exit 1;
ifeq ($(PARSE_LINKER_FILE),TRUE)	
	else
		mv -f $(LINKER_FILE) $(ERR_DIR)/$(notdir $(LINKER_FILE));
		mv -f $(basename $(LINKER_FILE))_bkup.lnk $(LINKER_FILE);
endif
	fi
		
$(ALL_OBJ_ASM_SOURCES):  | $(NECESSARY_OUTPUT_PATHS)
	$(eval COMP_GROUP:=$(strip $(foreach COMPONENT,$(COMPONENTS_LIST),$(if $(call getSourceFile,ASM,$(COMPONENT)),$(COMPONENT)))))
	$(eval SOURCE_FILE:=$(strip $(call getSourceFile,ASM,$(COMP_GROUP))))
ifeq ($(PREPROCESS_AS_SUPPORT),TRUE)
	echo "Preprocessing: [$(notdir $(basename $@)).$(ASM_SUFFIX)]"
	echo "Preprocessor command line: '$(CPP)' $(CPP_OPT_$(COMP_GROUP)) "$(call getWinDir,$(SOURCE_FILE))" -P -o $(call getWinDir,$(strip $(dir $@)))/$(strip $(notdir $(SOURCE_FILE))) >> $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1	" > $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1
	echo "$(EMPTY_VAR)" >> $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1
	'$(CPP)' $(CPP_OPT_$(COMP_GROUP)) "$(call getWinDir,$(SOURCE_FILE))" -P -o $(call getWinDir,$(strip $(dir $@)))/$(strip $(notdir $(SOURCE_FILE))) >> $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1
	$(eval SOURCE_FILE:=$(dir $@)/$(notdir $(SOURCE_FILE)))
endif
	echo "Assembling: [$(notdir $(basename $@)).$(ASM_SUFFIX)]"
	echo "Assembler command line: '$(AS)' $(ASM_OPT_$(COMP_GROUP)) $(call getWinDir,$(dir $@)/$(notdir $(SOURCE_FILE))) >> $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1" >> $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1
	echo "$(EMPTY_VAR)" >> $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1
	'$(AS)' $(ASM_OPT_$(COMP_GROUP)) $(call getWinDir,$(SOURCE_FILE)) >> $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1

$(ALL_OBJ_C_SOURCES):  | $(NECESSARY_OUTPUT_PATHS)
	$(eval COMP_GROUP:=$(strip $(foreach COMPONENT,$(COMPONENTS_LIST),$(if $(call getSourceFile,C,$(COMPONENT)),$(COMPONENT)))))
	$(eval SOURCE_FILE:=$(strip $(call getSourceFile,C,$(COMP_GROUP))))
	echo "Compiling: [$(basename $(notdir $@)).$(C_SUFFIX)]"
	echo "Compiler command line: '$(COMP)' $(COMP_OPT_$(COMP_GROUP)) $(call getWinDir,$(SOURCE_FILE)) >> $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1" > $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1
	echo "$(EMPTY_VAR)" >> $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1
	if ! '$(COMP)' $(COMP_OPT_$(COMP_GROUP)) $(call getWinDir,$(SOURCE_FILE))  >> $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1 ; then
		cat "$(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX)"
		mv -f $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) $(ERR_DIR)/$(basename $(notdir $@)).$(ERR_SUFFIX);
		exit 1;
	fi
ifeq ($(PRINT_WARNINGS),TRUE)
	cat $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) | grep . | sed -n '/$(notdir $(basename $(AS)))\|$(notdir $(basename $(COMP)))\|$(notdir $(basename $(PARSER)))\|$(notdir $(basename $(DEP)))\|$(notdir $(basename $(CODE_OPTIMIZER)))\|$(notdir $(basename $(CODE_GEN)))/!p';	
endif

$(DEP_FILES): $(GEN_FILES) $(AEC_CALIBRATION_FILE) $(CALIBRATION_FLASH_FILE) | $(ALL_COMPONENT_C_SOURCES) $(NECESSARY_OUTPUT_PATHS)
	$(eval COMP_GROUP:=$(strip $(foreach COMPONENT,$(COMPONENTS_LIST),$(if $(call getSourceFile,C,$(COMPONENT)),$(COMPONENT)))))
	$(eval SOURCE_FILE:=$(strip $(call getSourceFile,C,$(COMP_GROUP))))
	echo "Creating dependency for: [$(notdir $@)]"
	echo "Dependency command line: '$(DEP)' $(DEP_PRE_OPT) $(SOURCE_FILE) $(DEP_POST_OPT) $(DEP_OUT_OPT)" > $(ERR_DIR)/$(basename $(notdir $@)).$(DEP_WARN_SUFFIX) 2>&1
	echo "$(EMPTY_VAR)" >> $(ERR_DIR)/$(basename $(notdir $@)).$(DEP_WARN_SUFFIX) 2>&1
	if ! '$(DEP)' $(DEP_PRE_OPT) $(SOURCE_FILE) $(DEP_POST_OPT) $(DEP_OUT_OPT); then
		cat $@ | sed -n '/error\[\|Error\[\|Warning\[/p';
		exit 1;
	fi
	
ifneq (,$(findstring Application,$(TARGET_KEY)))
ifeq ($(AEC_CALIBRATION_SUPPORT),TRUE)
$(AEC_CALIBRATION_FILE): | $(NECESSARY_OUTPUT_PATHS)
	echo Generating AEC Calibration
	if [ ! -d $(dir $@) ]
	then
		echo "Creating directory: $(dir $@)"
		mkdir -p $(dir $@) > /dev/null 2>&1 || true 
	fi
	cd $(SOURCES_DIR)/ERH/Config
	java -jar AEC_Configurator.jar 1
	cd $(CURRENT_DIR)
endif

$(CALIBRATION_FLASH_FILE) $(DEFAULT_FILE) $(DYNAMIC_E2P_FILE) $(E2P_STUDY_FILE): | $(NECESSARY_OUTPUT_PATHS)
	echo Generating NVP binary files
	if [ ! -d $(dir $(CALIBRATION_FLASH_FILE)) ]
	then
		echo "Creating directory: $(dir $(CALIBRATION_FLASH_FILE))"
		mkdir -p $(dir $(CALIBRATION_FLASH_FILE)) > /dev/null 2>&1 || true 
	fi

	generate_nvp_files "-f=$(call getWinDir,$(SOURCES_DIR)/NVP/Config/SBE_4G_NVP_layout.xls)"
endif

$(NECESSARY_OUTPUT_PATHS) $(RELEASE_DIR):
	if [ ! -d $@ ]
	then
		echo "Creating directory: $@"
		mkdir -p $@ > /dev/null 2>&1 || true 
	fi

ifneq ($(TARGET),help)
ifneq ($(MAKECMDGOALS),$(TARGET)-clean)
ifneq ($(MAKECMDGOALS),$(TARGET)-eclipse)
$(TARGET): updateSwVersion $(GEN_FILES) $(DEP_FILES) $(ALL_OBJ_SOURCES) $(BINARY_FILE) $(SREC_FILE) \
           $(RELEASE_DIR)/$(notdir $(SREC_FILE)) pdfReport \
           $(FULL_MEMORY_FILE) $(AEC_CALIBRATION_FILE) $(CALIBRATION_FLASH_FILE) $(UNIFIED_CALIBRATION_FILE) $(if $(call seq,$(ELF_FILE_GENERATION),TRUE),$(ELF_FILE)) | $(NECESSARY_OUTPUT_PATHS)
endif
endif
endif

%-clean:
	if [ -d $(OUTPUT_DIR)/$(TARGET) ]
	then
		echo "Removing directory: $(OUTPUT_DIR)/$(TARGET)"
		rm -rf $(OUTPUT_DIR)/$(TARGET)
	fi

updateSwVersion:
ifeq ($(BUILD_MODE),RELEASE)
ifneq (,$(findstring Application,$(TARGET_KEY)))
	change_sw_version "-f=$(call getWinDir,$(SOURCES_DIR)/DIA/Implementation/src/DIA_ReadDataByIdentifier.c)" "-s=$(APPL_VERSION_REV2)"
endif
endif
	
.PHONY: $(TARGET) updateSwVersion
.ONESHELL:
.SUFFIXES:
.SILENT:

# filename    : Makefile.main
# description : Makefile that defines the target linkage and source file packages
# author      : Dan Dustinta
# copyright   : Copyright (c) 2018, Autoliv Electronic
# version     : 1.0.3
# email       : dan.dustinta@autoliv.com
# status      : Released
