#ifndef LC_PROT_LCFU___SQLITE_GETSTRING__C
#define LC_PROT_LCFU___SQLITE_GETSTRING__C

#include <lcfu___sqlite_getstring.h>
#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include "debug.h"
/*                            Functions                        */
void  lcfu___SQLITE_GETSTRING(LC_TD_Function_SQLITE_GETSTRING* LC_this, LC_TD_LINT LC_VD_HANDLE, LcCgChar LC_VD_SQL[501], struct _lcoplck_epdb_1_impl* pEPDB)
{
	int erg;
	sqlite3_stmt *stmt;
	int handle;
	int col;
	int cols;
	int w;
	int i;
	char * text;
	char stext[50];

	stext[0] = '\0';

	col = 0;
	handle = (int)LC_VD_HANDLE;

	erg = sqlite3_prepare_v2((sqlite3 *)handle,(const char *)LC_VD_SQL,-1,&stmt,NULL);

	if(erg)
	{
		DEBUG_PRINT(("Error at preparing sql statement: %d \n", erg));
		return;
	}

	cols = sqlite3_column_count(stmt);

	if(cols > 10)
	{
		DEBUG_PRINT(("Too many colums selected! %d of 10\n", cols));
		return;
	}
	/*printf("Cols: %d\n", cols);*/

	w = 1;
	while(w)
	{
		erg = (int)sqlite3_step(stmt);
		if(erg == SQLITE_ROW)
		{
			if(col<cols)
			{
				text = (char*)sqlite3_column_text(stmt, 0);
				sprintf(stext, "%s", text);
				for(i=0; i<51; i++)
				LC_this->LC_VD_RETSTR[i] = (LcCgChar)stext[i];
			}
			 w=0;
			 LC_this->LC_VD_ENO = LC_EL_true;
			 sqlite3_finalize(stmt);
			 break;

			/* printf("\n");*/
		}
		else if(erg = SQLITE_DONE)
		{
			w=0;
			LC_this->LC_VD_ENO = LC_EL_true;
			break;

		}
		else
		{
			LC_this->LC_VD_ENO = LC_EL_false;
			DEBUG_PRINT(("Error at select statement: %d", erg));
		}
	}

}

#endif
