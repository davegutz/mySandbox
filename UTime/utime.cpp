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
    // Instantiation
    long long inst_millis_ll = get_current_time_ms();              // Instantiation time, ms
    time_t start_time_ll = time(nullptr);                    // Get current time
    unsigned long inst_time_ul = (unsigned long) (start_time_ll); // Instantiation time, s
    unsigned long long sample_time_ib = 0ULL;                     // Exact moment of selected Ib sample, ms

    unsigned long long start_ull =  (unsigned long long) inst_millis_ll;
    unsigned long now_ul = (unsigned long) (start_time_ll);
    unsigned long long now_ull = (unsigned long long) (start_time_ll);
    struct tm *gmt = gmtime(&start_time_ll);
    
    unsigned long long time_now_ull = now_ull;
    unsigned long long inst_millis_ull = start_ull;     // millis offset to account for setup() time, ms
    unsigned long long start_time_ull = time_now_ull;    // UTC Zulu at instantiation, s




    printf("%s\n", asctime(gmt));
    printf("start_time_ll    %lld     s\n", start_time_ll);
    printf("inst_millis_ll  %lld ms\n", inst_millis_ll);
    printf("start_ull       %llu ms\n", start_ull);
    printf("now_ul          %lu     s\n", now_ul);
    printf("now_ull         %llu     s\n", now_ull);
    printf("time_now_ull    %llu     s\n", time_now_ull);
    printf("inst_millis_ull %llu ms\n", inst_millis_ull);
    printf("start_time_ull   %llu     s\n\n\n", start_time_ull);
}
