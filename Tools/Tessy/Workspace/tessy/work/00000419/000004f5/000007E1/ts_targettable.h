/* Target Table */
#ifndef __TARGETTABLE_H
#define __TARGETTABLE_H
typedef struct tag_tte {
   const char     *Name;
   unsigned short Index;
   IDB_TYPEID     TID;
   IDB_TYPEID     ID;
   unsigned char  Targetkind;
} TS_TARGET_TABLE_ENTRY;
#endif
