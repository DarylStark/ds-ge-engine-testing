#include "target_fps_timer.h"

int main()
{
    ds::graphics::TargetFPSTimer timer(1000);

    while (true)
    {
        timer.start();

        timer.stop();
    }

    return 0;
}