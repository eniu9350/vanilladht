#include <stdio.h>

#include "ip.h"
#include "node.h"
#include "msg.h"

void getBootstrapNodeIp(IpAddr& bootIp);
void join(Node* n);
void leave(Node* n);


void send_join_req(Node* n, msg_join_req* m, IpAddr* ip);
void fwd_join_req(Node* n, msg_join_req* m, IpAddr* ip);
void send_join_resp(Node* n, msg_join_req* m, IpAddr* ip);
void send_leave_req(Node* n, msg_join_req* m, IpAddr* ip);
void fwd_leave_req(n, _m, &n->succIp);
void send_leave_resp(Node* n, msg_join_req* m, IpAddr* ip);



void on_receive_join_resp(Node* n, msg_join_resp* m);
void on_receive_join_req(Node* n, msg_join_req* m);
