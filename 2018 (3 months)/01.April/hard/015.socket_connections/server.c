/*
	SERVER

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFERSIZE 256

/* I don't have right now too much knowledge about this kind of 
 * unix standars and my code was really ugly so finally 
 * I decided to implement this leson to learn a lil more;
 * http://www.linuxhowtos.org/C_C++/socket.htm
 */


/*
 * 1. create a socket()
 * 2. Blind the socket to an address. bind()
 * 3. listen for connections.	listen()
 * 4. accept a connection.		accept()
 * 5. Send/receive
 */

void error(const char *msg);

void main( int argc, char *argv[]){

	int sockfd, newsockfd; //file descriptors. Store values returned by socket system call.
	int portno; //Stores the port number
	int n; //return of read() write() nª char to be written
	char buffer[BUFFERSIZE]; 

	socklen_t clilen;

	struct sockaddr_in serv_addr, cli_addr;
	/* struct sockaddr_in
	 * {
	 * 	short   sin_family; // must be AF_INET 
	 * 	u_short sin_port;
	 * 	struct  in_addr sin_addr;
	 * 	char    sin_zero[8]; // Not used, must be zero 
	 * };
	 */

	if (argc < 2) {
		fprintf(stderr,"ERROR, no port provided\n");
		exit(1);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) 
		error("ERROR opening socket");
	/* Socket() creates a new socket
	 * 1st. address domain	1. unix domain for 2 processes | 2. internet for 2 hosts on the internet
	 * 2nd. type of socket	1. stream | 2. datagram
	 * 3rd. protocol
	*/

	bzero((char *) &serv_addr, sizeof(serv_addr)); //sets all buffer values to 0
	portno = atoi(argv[1]); //port number

	serv_addr.sin_family = AF_INET; // address family
	serv_addr.sin_addr.s_addr = INADDR_ANY; //HOST IP ADDRESS
	serv_addr.sin_port = htons(portno); //port number (necessary to convert this to network byte order)

	if (bind(sockfd, (struct sockaddr *) &serv_addr,
			sizeof(serv_addr)) < 0) //bind a socket to an address
			error("ERROR on binding");


	listen(sockfd,5); //allows the process to listen on the socket 
	

	clilen = sizeof(cli_addr);
	newsockfd = accept(sockfd, //process blocks until client connects
			(struct sockaddr *) &cli_addr, 
			&clilen); //it return the file descriptor

	if (newsockfd < 0) 
		error("ERROR on accept");

	bzero(buffer,BUFFERSIZE); //buffer inicialization
	n = read(newsockfd,buffer,BUFFERSIZE);
	if (n < 0) error("ERROR reading from socket");
	printf("Here is the message: %s\n",buffer);

	n = write(newsockfd,"I got your message",18);
	if (n < 0) error("ERROR writing to socket");
	close(newsockfd);
	close(sockfd);

	return 0; 
}

void error(const char *msg){
	perror(msg);
	exit(1);
}




