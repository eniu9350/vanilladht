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
	msgheader* h;
	SockAddr srcAddr;
	Id srcId;
	SockAddr fwdAddr;
	Id fwdId;
}msg_join_req;

typedef struct {
	msgheader* h;
	SockAddr succAddr;
	Id succId;
}msg_join_resp;

typedef struct {
		msgheader* h;
		SockAddr srcAddr;
		Id srcId;
}msg_leave_req;

typedef struct {
		msgheader* h;
		SockAddr srcAddr;
		Id srcId;
}msg_leave_resp;

#endif
