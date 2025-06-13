#include "utime.h"
#include <cstdio>
#include <ctime>


void utime()
{
    // unsigned long long time_now = (unsigned long long) Time.now();  // UTC Zulu, s
    time_t currentTime = time(nullptr); // Get current time
    unsigned long now_ul = (unsigned long) (currentTime);
    unsigned long long now_ull = (unsigned long long) (currentTime);
    struct tm *gmt = gmtime(&currentTime);
    unsigned long long time_now = now_ull;
    unsigned long long inst_millis;          // millis offset to account for setup() time, ms
    unsigned long long inst_time = time_now;            // UTC Zulu at instantiation, s
    unsigned long long start = System.millis();
    printf("     %s\n", asctime(gmt));
    printf("currentTime %ld\n", currentTime);
    printf("now_ul      %lu\n", now_ul);
    printf("now_ull     %llu\n", now_ull);
    printf("time_now    %llu\n", time_now);
    printf("inst_millis %llu\n", inst_millis);
    printf("inst_time   %llu\n", inst_time);
}
