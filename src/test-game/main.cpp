#include <iostream>
#include <thread>

#include "target_fps_timer.h"

int main()
{
    ds::graphics::TargetFPSTimer timer(100);

    auto start = std::chrono::high_resolution_clock::now();
    uint32_t framecounter = 0;

    while (true)
    {
        timer.start();
        framecounter++;

        // Processing the frame
        // std::this_thread::sleep_for(std::chrono::milliseconds(5));

        const auto end = std::chrono::high_resolution_clock::now();
        const auto duration =
            std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        if (duration.count() >= 1000)
        {
            std::cout << "Second passed: " << framecounter << " frames in "
                      << duration.count() << "ms\n";
            start = std::chrono::high_resolution_clock::now();
            framecounter = 0;
        }

        timer.stop();
    }

    return 0;
}