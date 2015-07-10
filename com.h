/*
 * com.h
 *
 *  Created on: Jul 10, 2015
 *      Author: quad
 */

#ifndef COM_H_
#define COM_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include <string>

class com{
public:
	com();
	void callBBB();
	void closeBBB();
	char* readBBB();
	void sendBBB(char *_message);
	void setAddress(char *_address);
	void setPort(int _port);

private:

	char buffer[256];
    int sockfd, portNo, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
};


#endif /* COM_H_ */
