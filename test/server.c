#include "../peer.h"

int main()
{

	Node n;
	SockAddr sa;
	sa.ip.a = 192;
	sa.ip.b = 168;
	sa.ip.c = 70;
	sa.ip.d = 140;
	sa.port = 7001;

	n.addr = sa;

	printf("server before boot\n");

	boot(&n);
}

