#include <stdlib.h>

#include "peer.h"
#include "sockwrap.h"

void getBootstrapNodeIp(SockAddr* bootIp)
{
				ipaddr_set(bootIp, 192, 168, 70, 140, 7001);
}

void boot(Node* n)
{
				//listen for connections
				sw_listen(&n->addr);

				//get bootstrap node address
				SockAddr bootAddr;
				getBootstrapNodeIp(&bootAddr);
				if(ipaddr_cmp(&bootAddr.ip, &n->addr.ip)==true && bootAddr.port == n->addr.port)	{
								;
				}
				else	{
								//connect and save socket fd
								//n->bsSfd = sw_conn(bootAddr);
								n->bootAddr = bootAddr;

								join(n);
				}
}


void join(Node* n)
{

				//send join msg to bootstrap node
				msgheader* h = (msgheader*)malloc(sizeof(msgheader));
				h->type = MT_JOINREQ;
				//h->srcIp = n->ip;
				//h->srcId = n->id;

				msg_join_req m;
				m.h = *h;
				m.fwdId = n->id;
				m.fwdAddr = n->addr;
				send_join_req(n, &m, &n->bootAddr);	//mmm:right? temp var?
}

void leave(Node* n)
{
				msg_leave_req m;
				m.srcId = n->id;
				m.srcAddr = n->addr;	
				send_leave_req(n, &m, &n->succAddr);
}

//send messages
void send_join_req(Node* n, msg_join_req* m, SockAddr* addr)
{
				int sockfd;
				sockfd = sw_conn(addr);
				sw_send(sockfd, (char*)m, sizeof(msg_join_req));

}

//send messages
void fwd_join_req(Node* n, msg_join_req* m, SockAddr* ip)
{
;

}

//send messages
void send_join_resp(Node* n, msg_join_req* m, SockAddr* ip)
{
;

}

//send messages
void send_leave_req(Node* n, msg_leave_req* m, SockAddr* ip)
{

}

//send messages
void fwd_leave_req(Node* n, msg_leave_req* m, SockAddr* ip)
{

}

//send messages
void send_leave_resp(Node* n, msg_join_req* m, SockAddr* ip)
{

}

//on receiving messages
void on_receive_join_resp(Node* n, msg_join_resp* m)
{
				//get join response
				/* if destId not id */
				n->succId = m->succId;
				n->succAddr = m->succAddr;

				//update successor
}

void on_receive_join_req(Node* n, msg_join_req* m)
{
				msgheader* _h;
				msg_join_resp* _m;
				if(m->fwdId == m->srcId)	{
								//sent from joining node
								m->fwdId = n->id;
								m->fwdAddr = n->addr;
								//mmm:toimpl
								//forward join

				}
				else	{
								//forwarded
								if(m->fwdId>m->srcId)	{
												m->fwdId = n->id;
												m->fwdAddr = n->addr;
												//mmm:toimpl--forward
								}
								else	{
												//fwdId < srcId
												if(n->id < m->srcId)	{
																m->fwdId = n->id;
																m->fwdAddr = n->addr;
												}
												else	if(n->id > m->srcId){
																_h = (msgheader*)malloc(sizeof(msgheader));
																_h->type = MT_JOINRESP;
																_m = (msg_join_resp*)malloc(sizeof(msg_join_resp));
																_m->succId = n->id;
																_m->succAddr = n->addr;
																send_join_resp(n, _m, &m->srcAddr);
																//mmm:toimpl send
												}
												else	{
																printf("dup hash values!\n");
												}
												//mmm:toimpl forward
								}
				}
}

void on_receive_leave_req(Node* n, msg_leave_req* m)
{
				msg_leave_resp* _m;
				msgheader* _h = (msgheader*)malloc(sizeof(msgheader));	
				_h->type = MT_LEAVEREQ;
				if( m->srcId == n->succId ) {
								//update succId
								//n->succId = 	//get succ's succ

								//send leave message
								_m = (msg_leave_resp*)malloc(sizeof(msg_leave_resp));
								_m->h = _h;
								_m->srcId = n->id;
								_m->srcAddr = n->addr;
								send_leave_resp(n, _m, &m->srcAddr);
				}
				else	{
								fwd_leave_req(n, m, &n->succAddr);
				}
}

void on_receive_leave_resp(Node* n, msg_leave_resp* m)
{
				//validate src(may it be its pred's pred?)
				//can't validate!!
				printf("node %d exit exit successfully\n", n->id);
}
