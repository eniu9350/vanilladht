#ifndef _VDHT_NODE_H_
#define _VDHT_NODE_H_
#include <stdio.h>

#include "ip.h"


#define NODELOCAL_DEFAULT_PORT_ROUTING_LAYER_PEER 9350
#define NODELOCAL_DEFAULT_PORT_ROUTING_LAYER_UPPER 10350

typedef int Id;


/* dht peer on this machine*/
typedef struct	{
	SockAddr addr;
	Id id;

	SockAddr succAddr;
	Id succId;

	SockAddr bootAddr;
	//int bsSfd;	//bootstrap socket fd
	
	int port_upper;
	
}localnode;
#endif
