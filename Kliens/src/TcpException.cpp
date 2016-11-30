/*
 * TcpException.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: Baltak
 */

#include "TcpException.h"

TcpException::TcpException(string message) {
	this->message = message;
}

TcpException::~TcpException() throw(){
}

const char* TcpException::what() const throw () {
	return this->message.c_str();
}
