/*
 * TcpClient.h
 *
 *  Created on: Nov 30, 2016
 *      Author: Baltak
 */

#include<iostream>    //cout
#include<stdio.h> //printf
#include<string.h>    //strlen
#include<string>  //string
#include <winsock2.h>
#include <stdio.h>

using namespace std;

#ifndef TCPCLIENT_H_
#define TCPCLIENT_H_

class TcpClient {
private:

public:
	boolean initializeWinsock();
	TcpClient();
	virtual ~TcpClient();
};

#endif /* TCPCLIENT_H_ */
