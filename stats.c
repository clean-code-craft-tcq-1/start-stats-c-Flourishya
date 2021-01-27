#include "stats.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float* numberset, int setlength) 
{
    int i=0,a=0;
    struct Stats s;
    
    for(i=0;i<4;i++)
    {
        a = a+*(numberset + i);
    }
    s.average = a/setlength;
    
    return s;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    emailAlertCallCount = 1;
    ledAlertCallCount = 1;
}
