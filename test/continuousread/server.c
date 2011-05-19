#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define PORT 9350

int main(int argc, char *argv[])
{
				int initsock, accsock;
				struct sockaddr_in srvaddr, cliaddr;
				socklen_t clilen = 0;	//error accepting if no init here
				char buffer[256];
				int n;
				int i;

				//create
				initsock = socket(AF_INET, SOCK_STREAM, 0);
				if(initsock<0)	{
								perror("socket create error");
				}

				//bind
				bzero((void*)&srvaddr, sizeof(srvaddr));
				srvaddr.sin_family = AF_INET;
				srvaddr.sin_addr.s_addr = INADDR_ANY;
				srvaddr.sin_port = htons(PORT);
				if(bind(initsock, (struct sockaddr*)&srvaddr, sizeof(srvaddr))<0)	{
								perror("socket bind error");
				}

				//listen
				printf("listen = %d\n", listen(initsock,5));

				//accept
				bzero((void*)&cliaddr, sizeof(cliaddr));
				accsock = accept(initsock, (struct sockaddr*)&cliaddr, &clilen);
				if(accsock<0)	{
								perror("accept error");
				}

				i=0;
				while(1)	{
								n = read(accsock, buffer, 255);
								if(n<0)	{
												perror("error reading");
								}
								if(n==0)	{
									break;
								}
								buffer[255]=0;
								printf("[%d]read from buf=> %s", n, buffer);
								bzero(buffer, 256);
				}

}

