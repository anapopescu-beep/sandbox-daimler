#HELPER: ## app : builds the software Application
#HELPER: ## app-clean : cleans the software Application
VALID_TARGETS := app hsm hsm_upd fbl fbl_upd bm fblbm_upd
SUPPORT_TARGETS := generateobjectlists compileobjectlists linkobjectlists
TARGET_KEYWORD_app := Application
TARGET_TYPE_app := ALV_BUILD
TARGET_KEYWORD_hsm := HSM
TARGET_TYPE_hsm := ALV_BUILD
TARGET_KEYWORD_hsm_upd := HSM_UPDATER
TARGET_TYPE_hsm_upd := ALV_BUILD
TARGET_KEYWORD_fbl := FBL
TARGET_TYPE_fbl := ALV_BUILD
TARGET_KEYWORD_fbl_upd := FBL_UPDATER
TARGET_TYPE_fbl_upd := ALV_BUILD
TARGET_KEYWORD_bm := BM
TARGET_TYPE_bm := ALV_BUILD
TARGET_KEYWORD_fblbm_upd := FBLBM_UPDATER
TARGET_TYPE_fblbm_upd := ALV_BUILD

#HELPER: ### example for Application Variant Build
# VALID_TARGETS := app1 app2 app3   
# TARGET_KEYWORD_app1 := Application1
# TARGET_KEYWORD_app2 := Application2
# TARGET_KEYWORD_app3 := Application3
# NB_AREA_app1 := 2
# NB_AREA_app2 := 3
# NB_AREA_app3 := 4
# NB_AREA=$(NB_AREA_$(VALID_TARGET)) -> Must be added on each "make -s -e -j -f Makefile.main.mk ..." command in the Makefile file
