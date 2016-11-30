/*
 * TcpClient.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: Baltak
 */

#include "TcpClient.h"

TcpClient::TcpClient() {

}

TcpClient::~TcpClient() {
}

boolean TcpClient::initializeWinsock() {
	WSADATA wsaData;
	WORD version;
	int error;

	version = MAKEWORD(2, 0);

	error = WSAStartup(version, &wsaData);

	/* check for error */
	if (error != 0) {
		/* error occured */
		return false;
	}

	/* check for correct version */
	if ( LOBYTE( wsaData.wVersion ) != 2 ||
	HIBYTE( wsaData.wVersion ) != 0) {
		/* incorrect WinSock version */
		WSACleanup();
		return false;
	}

	SOCKET conn;
	conn = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (conn == INVALID_SOCKET) {
		// error
		return false;
	}

	return true;
}
