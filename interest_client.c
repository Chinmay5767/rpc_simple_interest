#include <stdio.h>
#include "interest.h"

void rate_prog_1(char *host) {
    CLIENT *clnt;
    float *result_1;
    rate rate_of_interest_1_arg;
    float x, y, z;

    // Input from the user
    printf("Enter principal amount: ");
    scanf("%f", &x);

    printf("Enter simple interest: ");
    scanf("%f", &y);

    printf("Enter time period: ");
    scanf("%f", &z);

    rate_of_interest_1_arg.principal = x;
    rate_of_interest_1_arg.intrest = y;
    rate_of_interest_1_arg.time = z;

#ifndef DEBUG
    clnt = clnt_create(host, RATE_PROG, RATE_VERS, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror(host);
        exit(1);
    }
#endif

    result_1 = rate_of_interest_1(&rate_of_interest_1_arg, clnt);
    if (result_1 == (float *)NULL) {
        clnt_perror(clnt, "call failed");
    } else {
        printf("Result is %f\n", *result_1);
    }

#ifndef DEBUG
    clnt_destroy(clnt);
#endif
}

int main(int argc, char *argv[]) {
    char *host;

    if (argc < 2) {
        printf("Usage: %s server_host\n", argv[0]);
        exit(1);
    }
    host = argv[1];
    rate_prog_1(host);
    exit(0);
}

