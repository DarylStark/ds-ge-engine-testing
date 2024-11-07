#include <thread>

#include "frame_rate_limiter.h"

int main()
{
    while (true)
    {
        ds::graphics::FrameRateLimiter timer(60);

        std::this_thread::sleep_for(std::chrono::microseconds(50));
    }

    return 0;
}