Sintaxe:
psexec -i -h <HOST> -u <USER> -p <PASSWD> \path\app.exe <PARAMETROS>

EXEMPLO:
psexec -i -h \\192.168.0.13 -u WORKGROUP\pedro -p minhaSenha -c "C:\app.exe"

-> Onde -c: Copia o arquivo local(127.0.0.1)  "C:\OCSWindowsAgentSetupx64.exe" para o host remoto(192.168.0.13) e executa no host remoto.


NOTA:
Se executar, por exemplo: 
psexec \\192.168.0.26 -u user1 -p passwdUser1 <-c> "C:\users\user2\...\app.exe" 
O PsExec irá ignorar as permissões para user1 caso as políticas de grupo impeçam acesso remoto a user2 sem uso de senha, portanto, o ideal é
psexec \\192.168.0.26 -u user1 -p passwdUser1 <-c> "C:\users\user1\...\app.exe" 
