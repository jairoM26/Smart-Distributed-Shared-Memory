/*
 * SocketException.h
 *
 *  Created on: Aug 29, 2015
 *      Author: jairo-mm
 */

#ifndef SOCKET_SOCKETEXCEPTION_H_
#define SOCKET_SOCKETEXCEPTION_H_

#include <string>
#include <string.h>

class SocketException {
public:
	SocketException(std::string s) : m_s( s ){}
	virtual ~SocketException(){}

	std::string description() { return m_s; }

private:
  std::string m_s;
};

#endif /* SOCKET_SOCKETEXCEPTION_H_ */
