lc3-vendor-sqlite
=================

Vendor POUs for accessing SQLite from LC3

Description of the Vendor POUs:
----------------------------

**SQLite_Connect**
Diese Methode ist für die Verbindung der Datenbank zuständig. Als Parameter empfängt der Baustein lediglich den Dateipfad zur SQLite Datenbankdatei.
Ist die Verbindung erfolgreich wird ein handle, welcher ungleich 0 ist, zurückgesendet. Dieser handle ist ein lint.

**SQLite_Disconnect**
Dieser Baustein ist für die Trennung der Datenbank zuständig. Als Parameter empfängt der Baustein den handle des SQLite_Connect Bausteins.
Es gibt keinen Rückgabewert.

**SQLite_ExecuteStatement**
Mit diesem Baustein ist es möglich SQL Statements auszuführen. Dazu zählen insert, update und alter Befehle. Dazu braucht er einerseits den handle,
sowie das SQL Statement, welches in einem String[500] übergeben werden muss. Ist das SQL-Statement erfolgreich ausgeführt worden gibt die methode
über sqlresponse (int) eine 0 zurück. Liegt ein Fehler vor, wird eine Kennzahl mit sqlresponse übermittelt welche man nachschlagen muss.

**SQLite_GetTimestamp**
Dieser Baustein gibt den aktuellen Timestamp in unixepoch format als String[10] über die variable timestamp zurück.

**SQLite_GetIntegers**
Dieser Baustein gibt eine Reihe Integer Werte von der Datenbank zurück. Er braucht dazu den Handle der Datenbank, sowie ein gültiges select Statement. Mit dem Anfügen von "limit x, x+1", kann eine bestimmte Reihe herausgefiltert werden. Es können bis zu 10 spalten auf einmal ausgelesen werden. Die Daten werden dann in einem Int array gespeichert

**SQLite_GetString**
Dieser Baustein liefert einen String von maximal 50 Zeichen zurück. Zum Ausführen werden der Handle der Datenbank und ein SQL Statement benötigt. Zurück bekommt man über den retstr von String[50] den Wert, den das SQL-Statement liefert.

**SQLite_StatementReplacer**
Mit dem SQLite_StatementReplacer lässt sich ein Text mit Variablen vom Typ String und Int befüllen. Dazu gibt man ihm mit string1 den Haupttext an, indem die Variablen eingesetzt werden sollen. In der str variable steht dann der String wert der eingesetzt werden soll. Mit dem ints Array kann man bis zu zehn Ints übergeben, welche ebenfalls im Haupttext ersetzt werden können. zurück bekommt man dann den retstr (return string) von dem Typ String[500].

Database scheme
-----------------
CREATE TABLE log(id integer primary key, time integer, value integer);
