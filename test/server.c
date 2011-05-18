#include "../peer.h"

int main(int argc, char* argv[])
{

	localnode* ln;
	
	ln = createlocalnode(192, 168, 70, 140, 192, 168, 70, 140);

	boot(ln);
}

