Sintaxe:
psexec -i -h <HOST> -u <USER> -p <PASSWD> \path\app.exe <PARAMETROS>

EXEMPLO:
psexec -i -h \\192.168.0.13 -u WORKGROUP\pedro -p minhaSenha -c "C:\app.exe"

-> Onde -c: Copia o arquivo local(127.0.0.1)  "C:\OCSWindowsAgentSetupx64.exe" para o host remoto(192.168.0.13) e executa no host remoto.
