#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

uint64_t powmod_logs(uint64_t base, uint64_t exp, uint64_t mod, char *tag){
    
    printf("\n\n___%s___\n", tag);
    uint64_t new_base = base%mod;
    printf("base = base %% mod -> %" PRIu64 " %% %" PRIu64 " = %" PRIu64 "\n", base, mod, new_base);
    base = new_base;

    uint64_t result = 1;
    int loop_counter = 1;
    while(exp > 0){
        printf("\nloop #%d\n", loop_counter);
        printf("-----------------\n");
        printf("%s", (exp%2==0) ? "_even -> skip\n" : "_odd\n");
        if(exp % 2 == 1){
            uint64_t new_result = (result*base) % mod; 
            printf("result = (result*base) %% mod -> (%" PRIu64 "*%" PRIu64 ") %% %" PRIu64 " = %" PRIu64 "\n",result, base, mod, new_result);
            result = new_result;
        }
        uint64_t new_exp = exp / 2;
        printf("exp = exp / 2 -> %" PRIu64 "/ 2 = %" PRIu64 "\n", exp, new_exp);
        exp = new_exp;

        uint64_t update_base = (base*base) % mod;
        printf("base = (base*base) %% mod -> (%" PRIu64 "^2) %% %" PRIu64 " = %" PRIu64 "\n", base, mod, update_base);
        base = update_base;
        printf("-----------------\n");
        loop_counter++;
    }

    return result;
}
uint64_t powmod(uint64_t base, uint64_t exp, uint64_t mod){
    uint64_t result = 1;

    base = base % mod;
    while(exp > 0){
        if(exp%2==1)
            result = (base*result)%mod;
        exp = exp/2;
        base = (base*base)%mod;
    }
    return result;
}

uint64_t gcd_logs(uint64_t x, uint64_t y){
    while(y != 0){
        uint64_t temp = y;
        printf("temp = %" PRIu64 "\n", y);
        printf("%" PRIu64 " %% %" PRIu64 " = %" PRIu64 "\n", y, x, y = x % y);
        printf("x = %" PRIu64 "\n", x = temp);
    }

    return x;
}
uint64_t gcd(uint64_t x, uint64_t y){
    while(x != 0){
        uint64_t temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}
uint64_t linear_congruence_logs(uint64_t e, uint64_t phi){
    uint64_t d;
    printf("\n ___liner congruence of 'd'\n");
    printf("formula: (e*d) ≡ 1 (mod φ)\n");

    for (size_t i = 0; i < phi; i++){
        if((i*e)%phi == 1){
            printf("(%" PRIu64 "* %" PRIu64 ") %% %" PRIu64 " = %" PRIu64 "\t\t <--%s\n", e, i, phi, (e*i)%phi, ((e*i)%phi) == 1 ? "equel" : "not equal");
            printf("the Private_key = %" PRIu64 "\n\n", i);
            d = i;
            break;
        }
        printf("(%" PRIu64 "* %" PRIu64 ") %% %" PRIu64 " = %" PRIu64 "\t\t <--%s\n", e, i, phi, (e*i)%phi, ((e*i)%phi) == 1 ? "equel" : "not equal");
    }

    return d;
}
uint64_t linear_congruence(uint64_t e, uint64_t phi){
    uint64_t d;
    for(size_t i = 0; i < phi; i++){
        if((e*i)%phi == 1){
            d = i;
            break;
        }
    }
    return d;
}
