sqlite3 -header -csv /usr/local/DatabaseFiles/exampleDB "select id, datetime(time, 'unixepoch'), value from log;" > output.csv
