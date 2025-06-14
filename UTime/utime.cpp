#include "utime.h"
#include <cstdio>
#include <ctime>
#include <chrono>
#include <thread>


long long get_current_time_ms()
{
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}

void utime()
{
    // Instantiation
    long long inst_millis_ll = get_current_time_ms();  // Instantiation time, ms
    time_t readable_time_ull = time(nullptr);  // Get current time
    unsigned long long inst_time_ull = (unsigned long long) (time(nullptr)); // Instantiation time, s
    long long sample_time_ib_ll = 0ULL;  // Exact moment of selected Ib sample, ms
    unsigned long long now_ull = 0ULL;  // Time at sample, ms
    long long now_ll = 0LL;  // Time at sample, ms
    unsigned long now_ul = 0UL;  // Time at sample, ms

    printf("\n\n");
    printf("inst_millis_ll, ms  inst_time_ull, s  inst_time_ull, ms   sample_time_ib_ll, ms   now_ull, ms        now_ll, ms        now_ul, ms       asctime\n");

    for ( int i=0; i<3; i++)
    {
        readable_time_ull = time(nullptr);  // Get current time
        struct tm *gmt_readable = gmtime(&readable_time_ull);

        sample_time_ib_ll = get_current_time_ms();
        now_ull = (unsigned long long) sample_time_ib_ll - (unsigned long long) inst_millis_ll + inst_time_ull*1000;
        now_ll = sample_time_ib_ll - inst_millis_ll + (long long) (inst_time_ull*1000);
        now_ul = (unsigned long) sample_time_ib_ll - (unsigned long) inst_millis_ll + inst_time_ull*1000;

        printf("%lld       ", inst_millis_ll);
        printf("%llu        ", inst_time_ull);
        printf("%llu       ", inst_time_ull*1000);
        printf("%lld           ", sample_time_ib_ll);
        printf("%llu      ", now_ull);
        printf("%lld     ", now_ll);
        printf("%lu       ", now_ul);
        printf("%s", asctime(gmt_readable));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    printf("inst_millis_ll, ms  inst_time_ull, s  inst_time_ull, ms   sample_time_ib_ll, ms   now_ull, ms        now_ll, ms        now_ul, ms       asctime\n");
    printf("\n");
}
