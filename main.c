#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#include "RSA_lib.h"

int main(){
    SetConsoleOutputCP(65001);

    uint64_t p   = 61;
    uint64_t q   = 53;
    uint64_t n   = p * q;           // = 3233 pub module
    uint64_t phi = (p-1) * (q-1);  // = 3120
    uint64_t e   = 17;

    gcd_logs(e, phi);

    uint64_t d = linear_congruence_logs(e, phi);
    char *msg = "hi";
    size_t len = strlen(msg);

    uint64_t *enc = malloc(len * sizeof(uint64_t));
    if(!enc) return 1;
    for(size_t i = 0; msg[i] != '\0'; i++){
        enc[i] = powmod_logs((uint64_t)msg[i], e, n, "encrypted");
    }

    printf("the msg is !encrypted!\n");
    printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    printf("the secret msg is: ");
    uint64_t *dec = malloc(len * sizeof(uint64_t));
    if(!dec) return 1;
    for(size_t i = 0; i < len; i++){
        dec[i] = powmod(enc[i], d, n);
        printf("%c",(char)dec[i]);
    }

    free(enc);
    free(dec);
    return 0;
}
