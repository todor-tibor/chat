#include <stdio.h>
#include <windef.h>
#include <winerror.h>
#include <winsock2.h>
#include <iostream>

using namespace std;

int main() {

	//winsock inicializalasa

	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 0), &wsaData);
	if (iResult != NO_ERROR) {
		cout << "Error at WSAStartup()" << endl;
		return 0;
	}
	//letrehozzuk a socketett
	SOCKET ListenSocket;
	ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ListenSocket == INVALID_SOCKET) {
		cout << "Error at socket()";
		WSACleanup();
		return 0;
	}
	sockaddr_in service;
	service.sin_family = AF_INET;
	//int Port = 1300;
	service.sin_addr.s_addr = inet_addr("127.0.0.1");
	service.sin_port = htons(27015);
	if (bind(ListenSocket, (SOCKADDR*) &service,
			sizeof(service)) == SOCKET_ERROR) {
		cout << "bind failed " << endl;
		closesocket(ListenSocket);
		WSACleanup();
		return 0;
	}

	//figyelem a bejovo kapcsolodasi kereseket
	//a letrehozott foglalt
	if (listen(ListenSocket, 1) == SOCKET_ERROR) {
		//printf("Error listening on socket.\n");
		cout << "Error listening on socket " << endl;
		closesocket(ListenSocket);
		WSACleanup();
		return 0;
	}

	//a kapcsolta kivetele
	SOCKET AcceptSocket;
	//printf("Waiting for client to connect...\n");
	cout << "Waiting for client to connect.." << endl;
	//kapcsolat elfogadasa
	AcceptSocket = accept(ListenSocket, NULL, NULL);
	if (AcceptSocket == INVALID_SOCKET) {

		//printf("accept failed: %d\n", WSAGetLastError());
		cout<<"accept failed: ";
		closesocket(ListenSocket);
		WSACleanup();
		return 0;
	} else {
		//printf("Client connected.\n");
		cout<<"Vlient connected: ";
	}

	//printf("Receiving datagrams...\n");
	int accept(int fd, struct sockaddr *addressp, int *addrlen);

	//amikor az alkalmazas befejezodik
	//printf("Finished sending. Closing socket.\n");
	cout<<"Finished sending.Closing socket. ";
	closesocket(ListenSocket);
	closesocket(AcceptSocket);

	//kilepunk
	//printf("Exiting.\n");
	cout<<"Exiting";
	WSACleanup();
	return 0;
}
