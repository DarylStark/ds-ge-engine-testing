#include "target_fps_timer.h"

#include <iostream>
#include <thread>
namespace ds::graphics
{
    TargetFPSTimer::TargetFPSTimer(const uint32_t target_fps)
        : _target_fps(target_fps)
    {
        _target_frame_duration =
            std::chrono::microseconds(1000000 / _target_fps);
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

        print_frame_time();
    }

    void TargetFPSTimer::delay()
    {
        if (_target_fps == 0) return;

        // Calculate the delay time
        _delay_time = _target_frame_duration - _frame_processing_time;
        auto local_delay_time = _delay_time;

        if (_delay_time.count() > 0)
        {
            if (local_delay_time.count() >
                1000)  // Sleep only if delay time is significant
            {
                std::this_thread::sleep_for(local_delay_time -
                                            std::chrono::microseconds(1000));
                local_delay_time = std::chrono::microseconds(
                    1000);  // Set remaining delay time for busy-wait
            }

            // Busy-wait for the remaining time to achieve higher precision
            auto busy_wait_start = high_resolution_clock::now();
            while (std::chrono::duration_cast<std::chrono::microseconds>(
                       high_resolution_clock::now() - busy_wait_start) <
                   local_delay_time)
            {
                // Busy-wait loop
            }
        }
    }

    void TargetFPSTimer::print_frame_time() const
    {
        const auto total_frame_time =
            std::chrono::duration_cast<std::chrono::microseconds>(
                _frame_processing_time + _delay_time);
        const auto theoretical_fps = 1000000 / total_frame_time.count();

        std::cout << "Processing time: "
                  << std::chrono::duration_cast<std::chrono::microseconds>(
                         _frame_processing_time)
                         .count()
                  << "us."
                  << " Delay time: "
                  << std::chrono::duration_cast<std::chrono::microseconds>(
                         _delay_time)
                         .count()
                  << "ms."
                  << " Total: " << total_frame_time.count() << " ms."
                  << " Theoretical FPS: " << theoretical_fps << std::endl;
    }
}  // namespace ds::graphics