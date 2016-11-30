/*
 * TcpClient.h
 *
 *  Created on: Nov 30, 2016
 *      Author: Baltak
 */
#define _WIN32_WINNT 0x501
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include  "TcpException.h"

#ifndef TCPCLIENT_H_
#define TCPCLIENT_H_

#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512

class TcpClient {
private:
	SOCKET ConnectSocket = INVALID_SOCKET;
	string address;
public:
	TcpClient(string hostAddress);
	virtual ~TcpClient();

	void clientConnect();
	void clientSend(string message);
	void cleanUp();
};

#endif /* TCPCLIENT_H_ */
