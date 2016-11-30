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

void TcpClient::clientConnect() {
	// Initialize Winsock
	WSADATA wsaData;
	struct addrinfo *result = NULL, hints;

	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		throw TcpException("WSAStartup failed with error");
	}

	ZeroMemory( &hints, sizeof(hints) );
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	// Resolve the server address and port
	iResult = getaddrinfo(this->address.c_str(), DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		WSACleanup();
		throw TcpException("getaddrinfo failed with error");
	}

	ConnectSocket = socket(result->ai_family, result->ai_socktype,
			result->ai_protocol);
	if (ConnectSocket == INVALID_SOCKET) {
		WSACleanup();
		throw TcpException("socket failed with error");
	}

	// Connect to server.
	iResult = connect(ConnectSocket, result->ai_addr, (int) result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		closesocket(ConnectSocket);
		ConnectSocket = INVALID_SOCKET;
		throw TcpException("connecting failed");
	}
}

void TcpClient::clientSend(string message) {
	int iResult = send(ConnectSocket, message.c_str(),
			(int) strlen(message.c_str()), 0);
	if (iResult == SOCKET_ERROR) {
		cout << "send failed with error: %d\n" << WSAGetLastError();
		closesocket(ConnectSocket);
		WSACleanup();
		throw TcpException("failed to send");
	}
}

void TcpClient::() {
	// cleanupcleanUp
	closesocket(ConnectSocket);
	WSACleanup();
}
