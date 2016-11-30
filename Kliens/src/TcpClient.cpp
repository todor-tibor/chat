/*
 * TcpClient.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: Baltak
 */

#include "TcpClient.h"

TcpClient::TcpClient(string hostAddres) {
	this->address = hostAddres;
}

TcpClient::~TcpClient() {
}
boolean TcpClient::clientConnect() {
	// Initialize Winsock
	WSADATA wsaData;
	struct addrinfo *result = NULL, hints;

	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		cout << "WSAStartup failed with error: %d\n" << iResult;
		return false;
	}

	ZeroMemory( &hints, sizeof(hints) );
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	// Resolve the server address and port
	iResult = getaddrinfo(this->address.c_str(), DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		cout << "getaddrinfo failed with error: %d\n" << iResult;
		WSACleanup();
		return false;
	}

	ConnectSocket = socket(result->ai_family, result->ai_socktype,
			result->ai_protocol);
	if (ConnectSocket == INVALID_SOCKET) {
		cout << "socket failed with error: %ld\n" << WSAGetLastError();
		WSACleanup();
		return 1;
	}

	// Connect to server.
	iResult = connect(ConnectSocket, result->ai_addr, (int) result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		closesocket(ConnectSocket);
		ConnectSocket = INVALID_SOCKET;
	}
	return true;
}

boolean TcpClient::clientSend() {
	char *sendbuf = "this is a test";
	// Send an initial buffer
	int iResult = send(ConnectSocket, sendbuf, (int) strlen(sendbuf), 0);
	if (iResult == SOCKET_ERROR) {
		cout << "send failed with error: %d\n" << WSAGetLastError();
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}
	return true;
}

boolean TcpClient::cleanUp() {
	// cleanup
	closesocket(ConnectSocket);
	WSACleanup();
	return true;
}
