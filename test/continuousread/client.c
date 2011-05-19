#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

#define PORT 9350

int main(int argc, char *argv[])
{
				int sock;
				struct sockaddr_in srvaddr;
				struct hostent* s;
				char buf[256] = "test write again";



				sock = socket(AF_INET, SOCK_STREAM, 0);
				if(sock<0)	{
								perror("create socket error");
				}

				s = gethostbyname("192.168.70.140");
				bzero((void*)&srvaddr, sizeof(srvaddr));
				bcopy((char*)(s->h_addr), (char*)&srvaddr.sin_addr.s_addr, s->h_length);
				srvaddr.sin_family = AF_INET;
				srvaddr.sin_port = htons(PORT);
				if(connect(sock, (struct sockaddr*)&srvaddr, sizeof(srvaddr))<0)	{
								perror("socket connect error");
				}

				write(sock, buf, 256);

}
