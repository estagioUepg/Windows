# O arquivo ccl.bat deve estar no Servidor onde executarPSEXEC.exe será executado, dentro do caminho especificado na linha 44 de executarPSEXEC.c
\"C:\\users\\<userName>\\ccl.bat\"

# O arquivo "filet.txt" especificado na linha 23 de executarPSEXEC.c é o arquivo onde os IPs foram extraídos com o código:
https://github.com/estagioUepg/Windows/blob/main/Configura%C3%A7%C3%B5es/Endere%C3%A7os%20IPv4/GetIPv4.c
Pode estar no mesmo caminho de executarPSEXEC.exe ou outro caminho pode ser especificado.

# PsExec deve estar declarado nas variaveis de ambiente do Windows

# executarPSEXEC.c deve ser compilado e executado pelo servidor.
