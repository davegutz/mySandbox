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
    unsigned long inst_time_ul = (unsigned long) (time(nullptr)); // Instantiation time, s
    unsigned long long sample_time_ib_ll = 0ULL;  // Exact moment of selected Ib sample, ms
    unsigned long long now_ull = 0ULL;  // Time at sample, ms
    
    printf("\n\ninst_millis_ll, ms   sample_time_ib_ll, ms   now_ull, ms        asctime\n");

    for ( int i=0; i<3; i++)
    {
        readable_time_ull = time(nullptr);  // Get current time
        struct tm *gmt_readable = gmtime(&readable_time_ull);

        sample_time_ib_ll = get_current_time_ms();
        now_ull = sample_time_ib_ll - inst_millis_ll + inst_time_ul*1000;

        printf("%lld        ", inst_millis_ll);
        printf("%lld           ", sample_time_ib_ll);
        printf("%llu         ", now_ull);
        printf("%s", asctime(gmt_readable));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    printf("inst_millis_ll, ms   sample_time_ib_ll, ms   now_ull, ms        asctime\n\n");
}
