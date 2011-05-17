#ifndef _VDHT_IP_H_
#define _VDHT_IP_H_

typedef struct {
				unsigned char a;
				unsigned char b;
				unsigned char c;
				unsigned char d;
}IpAddr;

typedef struct {
				IpAddr ip;
				int port;
}SockAddr;

int ipaddr_cmp(IpAddr* ip1, IpAddr* ip2);
void ipaddr_set(SockAddr* addr, unsigned char a, unsigned char b, unsigned char c, unsigned char d, int port);
void ipaddr_str(SockAddr* sa, char* s);
#endif
