#include "../peer.h"

int main()
{ 
	localnode* ln;
	
	ln = createlocalnode(192, 168, 70, 141, 192, 168, 70, 140);

	boot(ln);

}

