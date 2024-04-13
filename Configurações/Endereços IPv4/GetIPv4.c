#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0A00 /**0x0A00 = Windows 10 ou superior, carrega as bibliotecas abaixo conforme a versão do windows*/
#endif
#include <winsock2.h> /**Biblioteca dinamica que permite que as demais bibliotecas abaixo obtenham dados*/
#include <iphlpapi.h> /*IP Helper API, Com a função GetAdaptersAddresses() pemite ecnher um buffer com uma lista linkada de adaptadores  _IP_ADAPTER_ADDRESSES_LH(adapter)*/
//LINKAR  -liphlpapi -lws2_32
#include <ws2tcpip.h> /*Cada estrutura _IP_ADAPTER_ADDRESSES_LH(adapter) tem uma estrutura de lista linkada _IP_ADAPTER_UNICAST_ADDRESS_LH(FirstUnicastAddress). 
Para cada _IP_ADAPTER_UNICAST_ADDRESS_LH, tem-se uma estrutura SOCKET_ADDRESS(Address) que possui um sockaddr(lpSockaddr) que possui informações de família e 
valor do endereço unicast .
Esta biblioteca contém a função getnameinfo() que recebe um sockaddr(lpSockaddr) e salva o valor de IP num buffer(ap)*/

#include <stdio.h> /*printf*/
#include <stdlib.h> /**alocação de memoria*/

int main(int argc, char *argv[]) 
{
//BOILERPLATE -------------------------------------------    
   // if (argc < 3) 
   // {
    //    fprintf(stderr, "usage: \n");
   //     return 1;
   // }

    //Linkando Winsock
    WSADATA d;
    
    if (WSAStartup(MAKEWORD(2, 2), &d)) 
    {
        printf("Failed to initialize.\n");
        return -1;
    }

//ALOCAÇÃO DE MEMÓRIA E EXTRAÇÃO DE INTERFACES ---------------------------------------------
    //Tamanho de Buffer para armazenamento de lista linkada de adaptadores
    DWORD asize = 17000;
    //Estrutura de lista linkada de adapters
    PIP_ADAPTER_ADDRESSES adapters;

    //Alocação do buffer
    adapters = (PIP_ADAPTER_ADDRESSES)malloc(asize);
    if (!adapters) 
    {
        printf("Couldn't allocate %ld bytes for adapters.\n", asize);
        WSACleanup();
        return -1;
    }
    //Inserindo lista linkada de adaptadores no buffer alocado
    int r = GetAdaptersAddresses(AF_UNSPEC, GAA_FLAG_INCLUDE_PREFIX, 0,adapters, &asize);

//TRATAMENTO DE ERROS -------------------------------------------------------------
    if (r == ERROR_BUFFER_OVERFLOW) 
    {
        printf("GetAdaptersAddresses wants %ld bytes.\n", asize);
        free(adapters);
        printf("%p\n", adapters);
        printf("%d\n", !adapters);

    } else if (r == ERROR_SUCCESS) 
    {
    } else 
    {
        printf("Error from GetAdaptersAddresses: %d\n", r);
        free(adapters);
        WSACleanup();
        return -1;
    }

//LÓGICA/CÓIGO PRINCIPAL ------------------------------------------------------------
    //Abre arquivo e verifica
    FILE* fptr;
    fptr = fopen("IPs.txt", "a");
    if (fptr == NULL) {
        printf("Impossível abrir o arquivo "
               "Saindo...");
        getchar();    
        exit(0);
    }

    //Apontando para o 1º elemento da lista de adaptadores
    PIP_ADAPTER_ADDRESSES adapter = adapters;

    //Iterando pela lista de adaptadores
    while (adapter) 
    {
        //Apontando para o 1º elemento da lista de endereços Unicast
        PIP_ADAPTER_UNICAST_ADDRESS address = adapter->FirstUnicastAddress;

        //Iterando pela lista linkada de strcutures/endereços Unicast
        while (address) 
        {
            //se for ipv4
            if(address->Address.lpSockaddr->sa_family == AF_INET)
            {
                unsigned int ip[6];
                for(int j = 0; j < 6; j++) //extrai ip
                {
                    //sa_data é uma array de 14 unsigned char, ou seja, de 14 bytes
                    //Os dois primeiros bytes são a porta, os 4 seguintes são o IP
                    ip[j] = (unsigned int)(address->Address.lpSockaddr->sa_data[j] & 0xFF);
                } 
                //Gateway para mascara 255.255.255.0
                if(ip[2] == 192 && ip[3] == 168 && ip[4] == 56)
                {
                   char hostname[1024];
                    hostname[1023] = '\0';
                    gethostname(hostname, 1023);
                    char bufferC[110];
                    snprintf(bufferC, sizeof(bufferC), "NOME: %s  HOST: %d.%d.%d.%d\n", 
                    hostname, ip[2], ip[3], ip[4], ip[5]);
                    printf("Adicionando %s no arquivo\n", bufferC);
                    fputs(bufferC, fptr);
                    printf("\n"); 
                }
            }             
            address = address->Next;
        }

        adapter = adapter->Next;
    }

//FIM ------------------------------------------------------------------------------
    fclose(fptr);
    free(adapters);
    WSACleanup();
    getchar();    
    return 0;
}
