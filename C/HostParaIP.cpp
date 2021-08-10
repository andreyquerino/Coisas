// @AndreyQuerino
//
// Compilação linux g++/i686-w64-mingw32-g++ <filename>.cpp -o <filname>.exe -lws2_32 -s -ffunction-sections -fdata-sections -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc
// Compilação windows g++ -std=c++11 a.cpp -o a.exe -s -lws2_32 -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc
//
// Simples conversão de nome host para Ip

#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#define DEFAULT_BUFLEN 1024

int main(int argc , char *argv[]){
	WSADATA wsa;
	//char hostname[20];
	char *hostname = "www.github.com";
	char ip[100];
	struct hostent *he;
	struct in_addr **addr_list;
	int i;
	
	//printf("\nInsira o dominio: ");
	//scanf("%s",&hostname);
	printf("\nIniciando Winsock...");

	if (WSAStartup(MAKEWORD(2,2),& wsa) != 0){
		printf("\n Erro : %d",WSAGetLastError());
		return 1;
	}

	printf("\n\nPerfeito, inicializado :)");

	if ((he = gethostbyname(hostname)) == NULL) {
		printf("\n\nFalha ao obter o nome do host : %d" , WSAGetLastError());
		return 1;
	}

	addr_list = (struct in_addr **) he-> h_addr_list;

	for(i = 0; addr_list[i] != NULL; i++) {
		strcpy(ip , inet_ntoa(*addr_list[i]) );
	}

	printf("\n\nDominio: %s \nIP: %s\n\n" ,hostname ,ip);
	return 0;
}

//Saída
//Dominio: www.github.com
//IP: 20.201.28.151
