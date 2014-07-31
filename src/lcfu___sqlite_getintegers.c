#ifndef LC_PROT_LCFU___SQLITE_GETINTEGERS__C
#define LC_PROT_LCFU___SQLITE_GETINTEGERS__C

#include <lcfu___sqlite_getintegers.h>
#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include "debug.h"
/*                            Functions                        */
void  lcfu___SQLITE_GETINTEGERS(LC_TD_Function_SQLITE_GETINTEGERS* LC_this, LC_TD_LINT LC_VD_HANDLE, LcCgChar LC_VD_SQL[501], struct _lcoplck_epdb_1_impl* pEPDB)
{
  /* Vendor C Code */
	int erg;
	sqlite3_stmt *stmt;
	int handle;
	int col;
	int cols;
	int w;

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
			 for(col=0 ; col<cols;col++)
			{
				int val = (int)sqlite3_column_int(stmt,col);
			/*	printf("%s = %d\t",sqlite3_column_name(stmt,col),val);*/
				LC_this->LC_VD_INTEGERS[col] = (int)val;
				/*DEBUG_PRINT(("%i\t",col));*/
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
