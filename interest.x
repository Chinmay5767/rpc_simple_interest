struct rate{
  float principal;
  float intrest;
  float time;
 };
 
 program RATE_PROG{
   version RATE_VERS{
    float rate_of_interest(rate)=1;
   }=1;
  }=0x2342362;
 
