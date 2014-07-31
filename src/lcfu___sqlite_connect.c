#ifndef LC_PROT_LCFU___SQLITE_CONNECT__C
#define LC_PROT_LCFU___SQLITE_CONNECT__C

#include <lcfu___sqlite_connect.h>
#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>

#include "debug.h"
/*                            Functions                        */
void  lcfu___SQLITE_CONNECT(LC_TD_Function_SQLITE_CONNECT* LC_this, LcCgChar LC_VD_DBNAME[101], struct _lcoplck_epdb_1_impl* pEPDB)
{
  /* Vendor C Code */
	int erg;
	sqlite3 *handle;

	/*printf("Database located in: %s\n", (char*)LC_VD_DBNAME);*/

	erg = sqlite3_open((char *)LC_VD_DBNAME, &handle); /* in LC_VD_DBNAME ist der Pfad zur SQLite Datei */

	if(erg)  /*Wenn das Ergebnis nicht 0 ist, wird es in der Console ausgegeben und ein Handle von -1 zurückgegeben */
	{
		DEBUG_PRINT(("Database connection failed\n"));
		LC_this->LC_VD_HANDLE = -1;
		LC_this->LC_VD_ENO = LC_EL_false;
	}

	LC_this->LC_VD_HANDLE = (int)handle; /* Hier kommt der Handle dann zum Programm */
	LC_this->LC_VD_ENO = LC_EL_true;


}

#endif
