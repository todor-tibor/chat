/*
 * TcpException.h
 *
 *  Created on: Nov 30, 2016
 *      Author: Baltak
 */

#ifndef TCPEXCEPTION_H_
#define TCPEXCEPTION_H_

#include <exception>
#include <iostream>
using namespace std;

class TcpException: public std::exception {
private:
	string message;
public:
	TcpException(string message);
	virtual ~TcpException() throw();

	virtual const char* what() const throw ();
};

#endif /* TCPEXCEPTION_H_ */
