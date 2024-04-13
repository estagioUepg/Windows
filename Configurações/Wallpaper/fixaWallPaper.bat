cd /d %~dp0
pause
mkdir C:\LogsVar3\user\log\bin
pause
copy img102.jpg C:\LogsVar3\user\log\bin
pause
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\System" /v Wallpaper /d "C:\LogsVar3\user\log\bin\img102.jpg" /t REG_SZ
pause
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\System" /v WallpaperStyle /d "4" /t REG_SZ
pause