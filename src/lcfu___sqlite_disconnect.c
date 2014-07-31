#ifndef LC_PROT_LCFU___SQLITE_DISCONNECT__C
#define LC_PROT_LCFU___SQLITE_DISCONNECT__C

#include <lcfu___sqlite_disconnect.h>
#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include "debug.h"
/*                            Functions                        */
void  lcfu___SQLITE_DISCONNECT(LC_TD_Function_SQLITE_DISCONNECT* LC_this, LC_TD_LINT LC_VD_HANDLE, struct _lcoplck_epdb_1_impl* pEPDB)
{
  /* Vendor C Code */
	/*printf("Disconnected! Handle: %d\n", (int)LC_VD_HANDLE);*/
	int erg;
	erg = sqlite3_close((sqlite3 *)((int)LC_VD_HANDLE)); /* Mittels Handle von der datenbank trennen*/

	LC_this->LC_VD_RESPONSE = (int)erg;

	if(erg == 0)
		LC_this->LC_VD_ENO = LC_EL_true;
	else
		LC_this->LC_VD_ENO = LC_EL_false;


}

#endif
