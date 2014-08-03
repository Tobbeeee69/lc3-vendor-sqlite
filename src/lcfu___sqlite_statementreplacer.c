#ifndef LC_PROT_LCFU___SQLITE_SPRRINTF__C
#define LC_PROT_LCFU___SQLITE_SPRRINTF__C

#include <lcfu___sqlite_sprintf.h>
#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include "debug.h"

/*                            Functions                        */
void  lcfu___SQLITE_SPRINTF(LC_TD_Function_SQLITE_SPRRINTF* LC_this, LcCgChar LC_VD_STRING1[401], LcCgChar LC_VD_STR[51], LC_TD_INT LC_VD_INTS[10], struct _lcoplck_epdb_1_impl* pEPDB)
{
  /* Vendor C Code */
	LcCgChar str[500]; /*  */
	int i;
	int x;
	int w;
	int b;
	int f;
	char ch[1];
	LcCgChar helpstr[30]; /*  */
	int amount = 0;
	ch[0] = '\0';

	/*
	 * Diese Schleife überprüft jeden char im übergebenen Text (LC_VD_STRING1)
	 * Ist der char != '}' wird der char an str angehängt.
	 * Ist der char == '}' wird untersucht ob es sich um einen Text oder Zahl handelt.
	 * 		Falls der nachfolgende char ein 's' ist, wird '}s' durch LC_VD_STR ersetzt.
	 * 		Falls der nachfolgende char eine Zahl von 0-2 ist, wird }0, }1, }2 durch die
	 * 		im Array gespeicherte Zahl, mit index(0,1,2), ersetzt.
	 */
	for(i=x=0; i<strlen((char *)LC_VD_STRING1) || x < sizeof(str); i++)
	{
		if(LC_VD_STRING1[i] == '}')
		{
			b=1;
			if(LC_VD_STRING1[i+1] == 's')
			{
				for(w=0; w<strlen((char *)LC_VD_STR) && x < sizeof(str); w++)
				{
					str[x] = LC_VD_STR[w]; x++;
				}
				i++;
			}
			else {
				for(f=0; f<=9;) /* Herausfinden welcher Integer eingesetzt werden soll */
				{
					if(LC_VD_STRING1[i+1] == ((char)(f+48))) {
						sprintf((char *)helpstr, "%i", (int)LC_VD_INTS[f]); b = 0; break;
					}
					f = f+1;
				}
				if(b == 0)
				{
					for(w=0; w<strlen((char *)helpstr) && x < sizeof(str); w++)
					{
						str[x] = helpstr[w]; x++;
					}
					i++;
				}
			}
		}
		else
		{
			str[x] = LC_VD_STRING1[i]; x++;
		}
		amount = x;
	}
	for(i=0; i<500; i++) /* Hier wird der Rückgabewert LV_CD_RETSTR aufgebaut. */
	{
		if(i >= amount) {
			LC_this->LC_VD_RETSTR[i] = '\0'; /* Am Ende schließt man mit '\0' ab. */
		}
		LC_this->LC_VD_RETSTR[i] = (str[i]);
	}
}

#endif
