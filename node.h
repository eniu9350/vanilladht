#include <stdio.h>

#include "ip.h"

typedef int Id;

typedef struct	{
	Ip ip;
	Id id;

	IpAddr succIp;
	Id succId;

}Node;
