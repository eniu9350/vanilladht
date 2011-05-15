#ifndef _VDHT_NODE_H_
#define _VDHT_NODE_H_
#include <stdio.h>

#include "ip.h"

typedef int Id;

typedef struct	{
	SockAddr addr;
	Id id;

	SockAddr succAddr;
	Id succId;

}Node;
#endif
