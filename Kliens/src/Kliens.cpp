//============================================================================
// Name        : Kliens.cpp
// Author      : server
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "TcpClient.h"
using namespace std;

int main() {
	TcpClient* client = new TcpClient("127.0.0.1");
	client->clientConnect();
	client->clientSend();
	client->cleanUp();
	return 0;
}
