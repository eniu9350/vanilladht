
typedef struct {
	unsigned char type;	//join, leave, etc
}msgheader;

#define MT_JOINREQ 0;
#define MT_JOINRESP 1;


typedef struct {
	msgheader* h;
	IpAddr srcIp;
	Id srcId;
	IpAddr fwdIp;
	Id fwdId;
}msg_join_req;

typedef struct {
	msgheader* h;
	IpAddr succIp;
	Id succId;
}msg_join_resp;
