#ifndef _VDHT_NODE_H_
#define _VDHT_NODE_H_
#include <stdio.h>

#include "ip.h"

typedef int Id;

typedef struct	{
	IpAddr ip;
	Id id;

	IpAddr succIp;
	Id succId;

}Node;
#endif
