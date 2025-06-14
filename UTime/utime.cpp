#include "utime.h"
#include <cstdio>
#include <ctime>
#include <chrono>



long long get_current_time_ms()
{
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}

void utime()
{
    long long milliseconds_ll = get_current_time_ms();
    time_t currentTime_ll = time(nullptr); // Get current time

    unsigned long long start_ull =  (unsigned long long) milliseconds_ll;
    unsigned long now_ul = (unsigned long) (currentTime_ll);
    unsigned long long now_ull = (unsigned long long) (currentTime_ll);
    struct tm *gmt = gmtime(&currentTime_ll);
    
    unsigned long long time_now_ull = now_ull;
    unsigned long long inst_millis_ull = start_ull;          // millis offset to account for setup() time, ms
    unsigned long long inst_time_ull = time_now_ull;         // UTC Zulu at instantiation, s

    printf("%s\n", asctime(gmt));
    printf("currentTime_ll    %lld     s\n", currentTime_ll);
    printf("milliseconds_ll   %lld ms\n", milliseconds_ll);
    printf("start_ull         %llu ms\n", start_ull);
    printf("now_ul            %lu     s\n", now_ul);
    printf("now_ull           %llu     s\n", now_ull);
    printf("time_now_ull      %llu     s\n", time_now_ull);
    printf("inst_millis_ull   %llu ms\n", inst_millis_ull);
    printf("inst_time_ull     %llu     s\n\n\n", inst_time_ull);
}
