#include "stats.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float* numberset, int setlength) 
{
    int i=0,a=0;
    struct Stats s;
    
    for(i=0;i<setlength;i++)
    {
        a = a+*(numberset + i);
    }
    s.average = a/setlength;
    
}
