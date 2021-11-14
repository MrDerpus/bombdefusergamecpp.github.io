@ECHO OFF
TITLE FIND FILES
COLOR 0F

set fileone=serialKey.ini
set filetwo=timefile.timefile

GOTO :LOOP



:LOOP
CLS


IF EXIST "%fileone%" IF EXIST "%filetwo%" ECHO %fileone%, %filetwo% FOUND && PAUSE >NUL



GOTO :LOOP