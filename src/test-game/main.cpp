#include <thread>

#include "frame_rate_limiter.h"
#include "scoped_timer.h"

int main()
{
    while (true)
    {
        ds::utilities::ScopedTimer timer;
        ds::utilities::FrameRateLimiter limiter(121);
    }

    return 0;
}