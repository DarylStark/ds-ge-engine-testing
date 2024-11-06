#pragma once

#include <chrono>

namespace ds::graphics
{
    class TargetFPSTimer
    {
    private:
        uint32_t _target_fps;
        std::chrono::time_point<std::chrono::high_resolution_clock>
            _frame_start_time;
        std::chrono::time_point<std::chrono::high_resolution_clock>
            _frame_end_time;
        std::chrono::microseconds _target_frame_duration;
        std::chrono::microseconds _frame_processing_time;
        std::chrono::microseconds _delay_time;

    public:
        TargetFPSTimer(const uint32_t target_fps);
        void start();
        void stop();
        void delay();
        void print_frame_time() const;
    };
}  // namespace ds::graphics