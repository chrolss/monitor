/*
 * com.cpp
 *
 *  Created on: Jul 10, 2015
 *      Author: quad
 */

#include "com.h"

com::com(){}

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

void com::setPort(int _port){
	this->portNo = _port;
}

void com::setAddress(char *_address){
	this->server = gethostbyname(_address);
}

void com::callBBB(){

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0){
        error("ERROR opening socket");
    }
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host or no host provided\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portNo);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");
}

void com::sendBBB(char *_message){
    printf("You are connected to the server.\n Write your message and press 'Enter' to send it.\n Type 'quit' to exit the conversation.\n ");

/*
 	char buffer[256];
	bzero(buffer,256);
	fgets(buffer,255,stdin);
*/

	n = write(sockfd,_message,strlen(_message));
	if (n < 0)
		error("ERROR writing to socket");

	 //break communication if client types "quit"
	 std::string str(_message);
	 std::string subst = str.substr(0,4);
	 if (subst == "quit"){
		 printf("The client has quit the conversation \n");
	 }
}

char* com::readBBB(){
	//reset buffer for incoming communication
	bzero(buffer,256);
	n = read(sockfd,buffer,255);
	if (n < 0)
		error("ERROR reading from socket");
	return buffer;
}


void com::closeBBB(){
    close(sockfd);
}
