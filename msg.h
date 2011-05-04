typedef struct {
	unsigned char type;	//join, leave, etc
	IpAddr srcIp;
	Id srcId;
}msgheader;

#define MT_JOINREQ 0;


typedef struct {
	msgheader* h;
}msg_join_req;

typedef struct {
	msgheader* h;
	IpAddr succIp;
	Id succId;
}msg_join_resp;
