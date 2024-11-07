#include <thread>

#include "frame_rate_limiter.h"
#include "scoped_timer.h"

int main()
{
    while (true)
    {
        DS_GRAPHICS_SCOPED_TIMER;
        ds::graphics::FrameRateLimiter limiter(60);

        std::this_thread::sleep_for(std::chrono::milliseconds(15));
    }

    return 0;
}