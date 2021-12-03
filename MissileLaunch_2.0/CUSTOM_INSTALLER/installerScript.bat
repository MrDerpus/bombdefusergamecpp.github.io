@ECHO OFF
TITLE Bomb Defuser v1.0.0 - Installer v1.0.0
COLOR 0F

REM Variable setup . . .
SET timestrt=%time%
SET install_loc=%userprofile%\Documents\bombDefuser\v1.0.0
SET prog_loc=%install_loc%\Project.exe
SET desktop_loc=%userprofile%\Desktop

explorer .

ECHO.
ECHO.
ECHO Bomb Defuser v1.0.0 - Installer v1.0.0
ECHO.
ECHO.



:MAIN
IF NOT EXIST %install_loc% MKDIR %install_loc%    REM Create copy folder if it doesn't exist . . .
echo 1

XCOPY "copy_folder" "%install_loc%" /e            REM Copy files over to install location . . .
echo 2
::CD /D "%install_loc%"

CD /D "%desktop_loc%"
echo 3
MKLINK "Bomb Defuser v1.0.0" "%prog_loc%"         REM Create shortcut to game on Desktop . . .
echo 4

ECHO INSTALLATION PROCESS COMPLETE!
ECHO TIME STARTED: %timestrt%     TIME FINNISHED: %time%

ECHO.

ECHO Press any key to close the installation program . . .
PAUSE >NUL



EXIT /B