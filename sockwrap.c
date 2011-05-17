#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>


#include "sockwrap.h"
#include "msg.h"


int sw_listen(SockAddr* sa)
{
				int initsock;
				int accsock;
				struct sockaddr_in srvaddr, cliaddr;
				socklen_t clilen;
				char* buffer;
				int nread;
				msg_join_req m;

				initsock = socket(AF_INET, SOCK_STREAM, 0);
				if(initsock < 0) 	{
								printf("sw_listen create socket error\n");
				}

				//bind
				bzero((char*)&srvaddr, sizeof(srvaddr));
				srvaddr.sin_family = AF_INET;
				srvaddr.sin_addr.s_addr = INADDR_ANY;
				srvaddr.sin_port = sa->port;
				if(bind(initsock, (struct sockaddr*)&srvaddr, sizeof(srvaddr)) < 0) {
								printf("sw_listen bind error\n");
				}

				//listen
				listen(initsock, 5);
				printf("listening...\n");

				//accept
				buffer = (char*)malloc(1024);
				while(1)	{
								accsock = accept(initsock, (struct sockaddr*)&cliaddr, &clilen);
								if(accsock<0)	{
									printf("sw_listen accept error\n");
								}
								
								nread = read(accsock, buffer, 1024);
								if(nread < 0) {
									printf("sw_listen read error\n");
								}

								memcpy((void*)&m, (void*)buffer, sizeof(m));
								printf("===> srcId = %d, fwdId = %d\n", m.srcId, m.fwdId);
				}

}

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
