
cd /d %~dp0
copy filet.txt "C:\Program Files\Veyon"
set /P sala=Escreva o nome da sala: 
cd "C:\Program Files\Veyon"
veyon-cli networkobjects import filet.txt location %sala% regex "^NOME:(%%name%%:.*)\s+HOST:(%%host%%:.*)$"
pause