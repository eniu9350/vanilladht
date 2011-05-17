#include "../peer.h"

int main()
{

	printf("client\n");
	Node n;
	SockAddr sa;
	sa.ip.a = 192;
	sa.ip.b = 168;
	sa.ip.c = 70;
	sa.ip.d = 140;
	sa.port = 7002;

	n.addr = sa;

	boot(&n);
}

