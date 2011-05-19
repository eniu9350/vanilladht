#ifndef _VDHT_MSG_H_
#define _VDHT_MSG_H_
#include "ip.h"
#include "node.h"


typedef struct {
				unsigned char type;	//join, leave, etc
}msgheader;

#define MT_JOINREQ 0;
#define MT_JOINRESP 1;
#define MT_LEAVEREQ 2;


typedef struct {
				msgheader h;
				SockAddr srcAddr;
				hashvalue srcId;
				SockAddr fwdAddr;
				hashvalue fwdId;
}msg_join_req;

typedef struct {
				msgheader h;
				SockAddr succAddr;
				hashvalue succId;
}msg_join_resp;

typedef struct {
				msgheader h;
				SockAddr srcAddr;
				hashvalue srcId;
}msg_leave_req;

typedef struct {
				msgheader h;
				SockAddr srcAddr;
				hashvalue srcId;
}msg_leave_resp;

typedef struct {
				msgheader h;
				hashvalue key;
				char body[100];
}msg_route;




#endif
