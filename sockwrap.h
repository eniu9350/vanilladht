
#include "ip.h"


int sw_listen(SockAddr* sa);
int sw_conn(SockAddr* sa);
void sw_send(int sockfd, char* buf, int len);
