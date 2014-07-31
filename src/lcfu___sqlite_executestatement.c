#ifndef LC_PROT_LCFU___SQLITE_EXECUTESTATEMENT__C
#define LC_PROT_LCFU___SQLITE_EXECUTESTATEMENT__C

#include <lcfu___sqlite_executestatement.h>
#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>

#include "debug.h"
/*                            Functions                        */
void  lcfu___SQLITE_EXECUTESTATEMENT(LC_TD_Function_SQLITE_EXECUTESTATEMENT* LC_this, LcCgChar LC_VD_SQL[501], LC_TD_LINT LC_VD_HANDLE, struct _lcoplck_epdb_1_impl* pEPDB)
{
  /* Vendor C Code */
	int erg;
	erg =  (int)sqlite3_exec((sqlite3 *)((int)LC_VD_HANDLE),(char *)LC_VD_SQL,NULL,NULL,0); /* Hier wird der SQL Code ausgeführt */
	/*printf("Executing! %i\n", (int)erg);*/

	if(erg)
	{
		DEBUG_PRINT(("Executing failed! Error code: %i\n", (int)erg));
		LC_this->LC_VD_ENO = LC_EL_false;
	}
	else {

	LC_this->LC_VD_SQLRESPONSE = (int)erg;
	LC_this->LC_VD_ENO = LC_EL_true;



	}
}

#endif
