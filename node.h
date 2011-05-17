#ifndef _VDHT_NODE_H_
#define _VDHT_NODE_H_
#include <stdio.h>

#include "ip.h"

typedef int Id;


/* dht peer on this machine*/
typedef struct	{
	SockAddr addr;
	Id id;

	SockAddr succAddr;
	Id succId;

	SockAddr bootAddr;
	//int bsSfd;	//bootstrap socket fd
	
}Node;
#endif
