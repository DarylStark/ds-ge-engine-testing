#include "target_fps_timer.h"

#include <thread>

namespace ds::graphics
{
    TargetFPSTimer::TargetFPSTimer(const uint32_t target_fps)
        : _target_fps(target_fps)
    {
    }

    void TargetFPSTimer::start()
    {
        _frame_start_time = std::chrono::high_resolution_clock::now();
    }

    void TargetFPSTimer::stop()
    {
        _frame_end_time = std::chrono::high_resolution_clock::now();
        _frame_processing_time =
            std::chrono::duration_cast<std::chrono::microseconds>(
                _frame_end_time - _frame_start_time);
        delay();
    }

    void TargetFPSTimer::delay() const
    {
        if (_target_fps == 0) return;

        const auto delaytime =
            (1000000 / _target_fps) - _frame_processing_time.count();

        if (delaytime > 0)
        {
            std::this_thread::sleep_for(std::chrono::microseconds(delaytime));
        }
    }
}  // namespace ds::graphics