@echo off
echo ---------Habilitando PSExec------------
echo :
echo Configurando rede como particular...
cd /d %~dp0
C:\Windows\System32\WindowsPowerShell\v1.0\powershell.exe -executionpolicy remotesigned -File "%~dp0\1-privateNetwork.ps1"
echo OK
echo :
echo Adicionando admin share...
reg add HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\system /v LocalAccountTokenFilterPolicy /t REG_DWORD /d 1 /f
echo :
echo Abrindo porta 445...
netsh advfirewall firewall add rule name="PSExec TCP" dir=in action=allow protocol=TCP localport=445
echo :
echo Abrindo porta 137...
netsh advfirewall firewall add rule name="PSExec UDP" dir=in action=allow protocol=UDP localport=137
echo :
echo Habilitando descoberta de rede...
netsh advfirewall firewall set rule group="descoberta de rede" new enable=Yes
echo :
echo Habilitando compartilhamento...
netsh advfirewall firewall set rule group="compartilhamento de arquivo e impressora" new enable=Yes
echo :
set /p DUMMY = "Pressione qualquer tecla para sair..."
