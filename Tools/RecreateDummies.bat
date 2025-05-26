@echo off
setlocal enabledelayedexpansion

:: Check if arguments were provided
if "%~1"=="" (
    echo Usage: Backup-Folder.bat FolderNames...
    echo Each argument will be used to build: ..\Content\LOC\[Name]
    PAUSE
    exit /b 1
)

:: Set base source and destination folders
set "BaseSource=..\Content\LOC"
set "BaseBackup=..\Saved\Backup"

:: Create the backup base folder if it doesn't exist
if not exist "%BaseBackup%" (
    mkdir "%BaseBackup%"
)

rmdir /s /q "..\Saved\Backup\"

:: Loop through each argument
:loop
if "%~1"=="" goto done

    set "FolderName=%~1"
    set "SourcePath=%BaseSource%\%FolderName%"
    set "DestinationPath=%BaseBackup%\%FolderName%"

    echo Backing up "!SourcePath!" to "!DestinationPath!"

    :: Call the PowerShell script
    powershell -ExecutionPolicy Bypass -File "BackupFiles.ps1" -Source "!SourcePath!" -Destination "!DestinationPath!"

    shift
    goto loop

:done

rmdir /s /q %SourcePath%

pushd "%~dp0\.."
for %%F in ("Loc.uproject") do set "PROJECT_PATH=%%~fF"
popd

echo %PROJECT_PATH%

UnrealEditor.exe %PROJECT_PATH% -run=LocRecreateDummyAssets -stdout -log -FullStdOutLogOutput 

:: Call the PowerShell script
powershell -ExecutionPolicy Bypass -File "RestoreMissingFiles.ps1" -Source "../Saved/Backup/" -Destination "../Content/LOC/"

endlocal