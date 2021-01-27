#include "stats.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float* numberset, int setlength) 
{
    int i=0;
    float a=0, b=0 , c=10;
    struct Stats s;
    
    for(i=0;i<setlength;i++)
    {
        a = a+*(numberset + i);
        b = ((*(numberset + i))>b) ? *(numberset + i):b;
        c = ((*(numberset + i))<c) ? *(numberset + i):c;
    }
    s.average = a/setlength;
    s.max = b;
    s.min = c;
    
    return s;
}

void emailAlerter(void)
{
    emailAlertCallCount = 1;
}

void ledAlerter(void)
{
    ledAlertCallCount = 1;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    if(computedStats.max > maxThreshold)
    {
        alerters[0]();
        alerters[1]();
    }      
}
