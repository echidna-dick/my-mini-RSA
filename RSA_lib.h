#ifndef RSA_LIB_H
#define RSA_LIB_H

#include <stdint.h>
#include <inttypes.h>

uint64_t powmod_logs(uint64_t base, uint64_t exp, uint64_t mod, char *tag);
uint64_t powmod(uint64_t base, uint64_t exp, uint64_t mod);
uint64_t gcd_logs(uint64_t x, uint64_t y);
uint64_t gcd(uint64_t x, uint64_t y);
uint64_t linear_congruence_logs(uint64_t e, uint64_t phi);
uint64_t linear_congruence(uint64_t e, uint64_t phi);

#endif
