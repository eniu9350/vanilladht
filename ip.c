#include "ip.h"

void ipaddr_set(IpAddr* ip, unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
	ip->a = a;
	ip->b = b;
	ip->c = c;
	ip->d = d;
}
