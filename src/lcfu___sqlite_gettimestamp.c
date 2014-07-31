#ifndef LC_PROT_LCFU___SQLITE_GETTIMESTAMP__C
#define LC_PROT_LCFU___SQLITE_GETTIMESTAMP__C

#include <lcfu___sqlite_gettimestamp.h>
#include <time.h>
/*       LC_this->LC_VD_TIMESTAMP = str1;                    Functions                        */
void  lcfu___SQLITE_GETTIMESTAMP(LC_TD_Function_SQLITE_GETTIMESTAMP* LC_this, struct _lcoplck_epdb_1_impl* pEPDB)
{
	char str1[100];
	long t = ((long)time(NULL)); /*Hier wird der Timestamp als long ausgegeben*/
	int i;
	str1[0] = '\0';
	sprintf(str1, "%ld", (long)t); /* Zu einem String convertieren */

	for(i=0; i<11; i++)
		    	LC_this->LC_VD_TIMESTAMP[i] = ((LcCgChar)str1[i]); /* übergeben */
}

#endif
