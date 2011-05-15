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

void ipaddr_set(SockAddr* addr, unsigned char a, unsigned char b, unsigned char c, unsigned char d);

#endif
