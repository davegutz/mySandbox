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
    printf("     %s\n", asctime(gmt));
    printf("Current time %ld\n", currentTime);
    printf("Current time %lu\n", now_ul);
    printf("Current time %llu\n", now_ull);
}
