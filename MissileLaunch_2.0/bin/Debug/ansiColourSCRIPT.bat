@ECHO OFF
TITLE ansiCOLOUR picture display

GOTO :LOOP

:LOOP

CLS
TYPE "aus_day.txt"

PING LOCALHOST -l 2 >NUL

GOTO :LOOP