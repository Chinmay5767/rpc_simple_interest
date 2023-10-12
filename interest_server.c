

#include "interest.h"

float *
rate_of_interest_1_svc(rate *argp, struct svc_req *rqstp)
{
	static float  result;
         printf("rate_of_interest(%f,%f,%f) is called ", argp->principal, argp->intrest, argp->time);
         result=argp->intrest*100;
         result=result/argp->principal;
         result=result/argp->time;

	return &result;
}
