#ifndef PARAM_H
#define PARAM_H

#include <stdint.h>
#include <net/ethernet.h>
#include <netinet/in.h>

#define DEFAULT_MTU ETHERMTU
#define DEFAULT_IP_TTL 64
#define DEFAULT_PING_SIZE 64

#define DUMMY_WAIT_MS 100
#define RETRY_COUNT 3

typedef struct {
  char *device;
  uint8_t mac[6];
  struct in_addr ip;
  uint8_t vmac[6];
  struct in_addr vip;
  struct in_addr vmask;
  int ip_ttl;
  int mtu;
  struct in_addr gateway;
} parameter;

extern int set_default_param();
extern int read_param(char *fname);
extern int is_target_ip_addr(struct in_addr *addr);
extern int is_same_subnet(struct in_addr *addr);

extern parameter PARAM;

#endif