#include "ip.h"


bool ipaddr_cmp(IpAddr* ip1, IpAddr* ip2)
{
		if( (ip1->a == ip2->a) && (ip1->b == ip2->b) && (ip1->c == ip2->c) && (ip1->d == ip2->d) ) {
				return true;
		}
		else	{
				return false;
		}
}

void ipaddr_set(IpAddr* ip, unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
		ip->a = a;
		ip->b = b;
		ip->c = c;
		ip->d = d;
}
