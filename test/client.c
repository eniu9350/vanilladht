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

	n.id = 5;
	n.addr = sa;

	printf("client before boot\n");
	boot(&n);
}

