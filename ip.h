#ifndef _VDHT_IP_H_
#define _VDHT_IP_H_

typedef struct {
        unsigned char a;
        unsigned char b;
        unsigned char c;
        unsigned char d;
}IpAddr;

void ipaddr_set(IpAddr* ip, unsigned char a, unsigned char b, unsigned char c, unsigned char d);

#endif
