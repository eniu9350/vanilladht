#include "node.h"
#include "msg.h"

void getBootstrapNodeIp(IpAddr& bootIp)
{
	ipaddr_set(bootIp, 192, 168, 8, 1);
}


void join(Node& n)
{
	//get bootstrap node address
	IpAddr bootIp;
	getBootstrapNodeIp(&bootIp);

	//send join msg to bootstrap node
	msgheader* h = (msgheader*)malloc(sizeof(msgheader));
	h->type = MT_JOINREQ;
	h->srcIp = n->ip;
	h->srcId = n->id;

	msg_join_req m;
	m.h = &h;
	send_join_req(&m, &bootIp);
}

void leave()
{
}

//send messages
void send_join_req(Node* n, msg_join_req* m, IpAddr* ip)
{
	
}

//on receiving messages
void on_receive_join_resp(Node* n, msg_join_resp* m)
{
	//get join response
	/* if destId not id */
	n->succId = m->succId;
	n->succIp = m->succIp;

	//update successor
}
