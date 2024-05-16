
cd /d %~dp0
copy Ips.txt "C:\Program Files\Veyon"
set /P sala=Escreva o nome da sala: 
cd "C:\Program Files\Veyon"
veyon-cli networkobjects import Ips.txt location %sala% regex "^NOME:(%%name%%:.*)\s+HOST:(%%host%%:.*)$"
pause
