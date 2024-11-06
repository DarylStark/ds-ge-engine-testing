#include <thread>

#include "target_fps_timer.h"

int main()
{
    while (true)
    {
        ds::graphics::TargetFPSTimer timer(60);

        std::this_thread::sleep_for(std::chrono::microseconds(50));
    }

    return 0;
}