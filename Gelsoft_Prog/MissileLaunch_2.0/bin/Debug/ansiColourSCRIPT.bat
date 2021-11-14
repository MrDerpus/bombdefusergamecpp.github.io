@ECHO OFF
TITLE ansiCOLOUR picture display

GOTO :LOOP

:LOOP

CLS
TYPE "poppyflower.txt"

PING LOCALHOST -l 2 >NUL

GOTO :LOOP