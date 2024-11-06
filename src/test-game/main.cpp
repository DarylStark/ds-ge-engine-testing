#include <iostream>
#include <thread>

#include "target_fps_timer.h"

int main()
{
    ds::graphics::TargetFPSTimer timer(1000);

    while (true)
    {
        timer.start();

        // Process the frame
        std::this_thread::sleep_for(std::chrono::milliseconds(5));

        timer.stop();
    }

    return 0;
}