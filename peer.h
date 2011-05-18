#ifndef _VDHT_PEER_H_
#define _VDHT_PEER_H_

#include <stdio.h>

#include "ip.h"
#include "node.h"
#include "msg.h"

//-------------------- api --------
localnode* createlocalnode(int ipa, int ipb, int ipc, int ipd, int bipa, int bipb, int bipc, int bipd);

void boot(localnode* n);
void join(localnode* n);
void leave(localnode* n);


void send_join_req(localnode* n, msg_join_req* m, SockAddr* ip);
void fwd_join_req(localnode* n, msg_join_req* m, SockAddr* ip);
void send_join_resp(localnode* n, msg_join_resp* m, SockAddr* ip);
void send_leave_req(localnode* n, msg_leave_req* m, SockAddr* ip);
void fwd_leave_req(localnode* n, msg_leave_req* m, SockAddr* ip);
void send_leave_resp(localnode* n, msg_leave_resp* m, SockAddr* ip);



void on_receive_join_resp(localnode* n, msg_join_resp* m);
void on_receive_join_req(localnode* n, msg_join_req* m);
#endif
