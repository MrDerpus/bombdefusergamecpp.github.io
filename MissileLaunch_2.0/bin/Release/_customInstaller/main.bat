@ECHO OFF
TITLE .dpqb - Installer - BombDefuser v1
COLOR 0F
CLS
GOTO :MAIN

:MAIN

TYPE "installMessage.txt"
PING LOCALHOST -n 4 >NUL

:: Goto Documents and check if '.bqpdevelopment' is installed . . .
CD /d "C:\Users\%username%\Documents"
IF NOT EXIST ".bqpdevelopment" MKDIR ".bqpdevelopment"

CD /d ".bqpdevelopment"
IF NOT EXIST "BombDefuser" MKDIR BombDefuser

CD /d "BombDefuser"

CLS





EXIT /b