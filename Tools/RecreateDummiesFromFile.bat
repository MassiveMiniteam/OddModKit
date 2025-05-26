@echo off

echo Sleeping for 5 seconds...
timeout /t 5 >nul

:: Set base source and destination folders
set "BaseSource=..\Content\LOC"
set "BaseBackup=..\Saved\Backup"

:: Create the backup base folder if it doesn't exist
if not exist "%BaseBackup%" (
    mkdir "%BaseBackup%"
)

rmdir /s /q "..\Saved\Backup\"

:: Call the PowerShell script
powershell -ExecutionPolicy Bypass -File "BackupFilesFromFile.ps1" -InputFilePath "%~1"

pushd "%~dp0\.."
for %%F in ("Loc.uproject") do set "PROJECT_PATH=%%~fF"
popd

echo %PROJECT_PATH%

UnrealEditor.exe %PROJECT_PATH% -run=LocRecreateDummyAssets -stdout -log -FullStdOutLogOutput 

:: Call the PowerShell script
powershell -ExecutionPolicy Bypass -File "RestoreMissingFiles.ps1" -Source "../Saved/Backup/" -Destination "../Content/LOC/"

endlocal