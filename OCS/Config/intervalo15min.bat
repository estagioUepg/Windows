@echo off
echo ---------Criando Tarefa----------
echo :
echo Desabilitando servico padrao...
sc config "OCS Inventory Service" start= disabled
echo :
echo Parando Servico
sc stop "OCS Inventory Service"
echo :
echo ----Importando Tarefa-----
cd /d %~dp0
if exist "C:\Program Files (x86)\OCS Inventory Agent" (
  schtasks /create /xml "tarefa86.xml" /tn "OCSTask" /ru "userName" /rp "Senha"
) else if exist "C:\Program Files\OCS Inventory Agent" (
  schtasks /create /xml "tarefa.xml" /tn "OCSTask" /ru "userName" /rp "Senha"
) else (
  echo OCS nao instalado!!!
)
echo :
set /p DUMMY = "Pressione qualquer tecla para sair"
