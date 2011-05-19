#include <stdlib.h>

#include "peer.h"
#include "sockwrap.h"

/* ------------------------- api ------------------------- */
localnode* createlocalnode(int ipa, int ipb, int ipc, int ipd, int bipa, int bipb, int bipc, int bipd)
{
				localnode* ln = (localnode*)malloc(sizeof(localnode));

				SockAddr saself;
				saself.ip.a = ipa;
				saself.ip.b = ipb;
				saself.ip.c = ipc;
				saself.ip.d = ipd;
				//saself.port = port;

				//set bootstrap ip
				SockAddr saboot;
				saboot.ip.a = bipa;
				saboot.ip.b = bipb;
				saboot.ip.c = bipc;
				saboot.ip.d = bipd;
				//saboot.port = bport;

				ln->addr = saself;
				ln->bootAddr = saboot;

				return ln;
}


void boot(localnode* n)
{
				printf("1\n");
				//SockAddr bootAddr;	//addr of bootstrap node
				SockAddr thisaddr_upper;	//addr of this node for upper layer access

				//listen for connections
				n->addr.port = NODELOCAL_DEFAULT_PORT_ROUTING_LAYER_PEER;
				n->bootAddr.port = NODELOCAL_DEFAULT_PORT_ROUTING_LAYER_PEER;
				n->port_upper = NODELOCAL_DEFAULT_PORT_ROUTING_LAYER_UPPER;

				//get bootstrap node address
				//getBootstraplocalnodeIp(&bootAddr);
				if(ipaddr_cmp(&(n->bootAddr.ip), &n->addr.ip)==1 && n->bootAddr.port == n->addr.port)	{
								printf("cmp true, boot = this\n");
								//listen on peer port
								sw_listen(&n->addr);

								thisaddr_upper = n->addr;
								thisaddr_upper.port = n->port_upper;
								//listen on upper port
								sw_listen(&thisaddr_upper);
				}
				else	{
								//connect and save socket fd
								//n->bsSfd = sw_conn(bootAddr);
								//sw_listen(&n->addr);	//mmm:uncomment it! 
								//n->bootAddr = bootAddr;

								printf("before join\n");
								join(n);
				}

}


void join(localnode* n)
{

				//send join msg to bootstrap node
				msgheader* h = (msgheader*)malloc(sizeof(msgheader));
				h->type = MT_JOINREQ;
				//h->srcIp = n->ip;
				//h->srcId = n->id;

				msg_join_req m;
				m.h = *h;
				m.srcId = n->id;
				m.srcAddr = n->addr;
				m.fwdId = n->id;
				m.fwdAddr = n->addr;
				send_join_req(n, &m, &n->bootAddr);	//mmm:right? temp var?
}

void leave(localnode* n)
{
				msg_leave_req m;
				m.srcId = n->id;
				m.srcAddr = n->addr;	
				send_leave_req(n, &m, &n->succAddr);
}

/* ------------------------- message sending utilities ------------------------- */
void send_join_req(localnode* n, msg_join_req* m, SockAddr* addr)
{
				int sockfd;
				sockfd = sw_conn(addr);
				sw_send(sockfd, (char*)m, sizeof(msg_join_req));

}

void fwd_join_req(localnode* n, msg_join_req* m, SockAddr* ip)
{
				;

}

void send_join_resp(localnode* n, msg_join_resp* m, SockAddr* ip)
{
				;

}

//send messages
void send_leave_req(localnode* n, msg_leave_req* m, SockAddr* ip)
{

}

//send messages
void fwd_leave_req(localnode* n, msg_leave_req* m, SockAddr* ip)
{

}

//send messages
void send_leave_resp(localnode* n, msg_leave_resp* m, SockAddr* ip)
{

}

/* ------------------------- message handling ------------------------- */
void on_receive_join_resp(localnode* n, msg_join_resp* m)
{
				//get join response
				/* if destId not id */
				n->succId = m->succId;
				n->succAddr = m->succAddr;

				//update successor
}

void on_receive_join_req(localnode* n, msg_join_req* m)
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

void on_receive_leave_req(localnode* n, msg_leave_req* m)
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

void on_receive_leave_resp(localnode* n, msg_leave_resp* m)
{
				//validate src(may it be its pred's pred?)
				//can't validate!!
				printf("node %d exit exit successfully\n", n->id);
}
