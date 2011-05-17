#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#include "sockwrap.h"

int sw_conn(SockAddr* sa)
{
	int sockfd;
	struct sockaddr_in srvaddr;

	char str_sa[20];
	struct hostent* s;
	int e;
	ipaddr_str(sa, str_sa);	
	s = gethostbyname(str_sa);


	sockfd = socket(AF_INET, SOCK_STREAM, 0);


	bzero((void*)&srvaddr, sizeof(srvaddr));
	bcopy((char*)(s->h_addr), (char*)&srvaddr.sin_addr.s_addr, s->h_length);	//why s->h_length rather than sizoef?
	srvaddr.sin_family = AF_INET;
	srvaddr.sin_port = htons(sa->port);

	e = connect(sockfd, (struct sockaddr*)&srvaddr, sizeof(srvaddr));
	
	if(e<0)	{
		printf("sockwrap error\n");
		//generate error!!!
	}
	return sockfd;	//must be valid!
}

void sw_send(int sockfd, char* buf, int len)
{
	write(sockfd, buf, len);
}
