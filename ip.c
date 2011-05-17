#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


#include "ip.h"

int ipaddr_cmp(IpAddr* ip1, IpAddr* ip2)
{
		if( (ip1->a == ip2->a) && (ip1->b == ip2->b) && (ip1->c == ip2->c) && (ip1->d == ip2->d) ) {
				return 1;
		}
		else	{
				return 0;
		}
}

void ipaddr_set(SockAddr* sa, unsigned char a, unsigned char b, unsigned char c, unsigned char d, int port)
{
		sa->ip.a = a;
		sa->ip.b = b;
		sa->ip.c = c;
		sa->ip.d = d;
		sa->port = port;
}

void ipaddr_str(SockAddr* sa, char* s)
{
/*
	char t[4];
	itoa(sa->ip.a, t, 10);
	memcpy(s, t, strlen(t));
	s += strlen(t);
	*s++ = '.';

	bzero(t, 4);
	itoa(sa->ip.b, t, 10);
	memcpy(s, t, strlen(t));
	s += strlen(t);
	*s++ = '.';

	bzero(t, 4);
	itoa(sa->ip.c, t, 10);
	memcpy(s, t, strlen(t));
	s += strlen(t);
	*s++ = '.';

	bzero(t, 4);
	itoa(sa->ip.d, t, 10);
	memcpy(s, t, strlen(t));
	s += strlen(t);
	*s = '\0';
	*/

	sprintf(s, "%d.%d.%d.%d", sa->ip.a, sa->ip.b, sa->ip.c, sa->ip.d);
}
