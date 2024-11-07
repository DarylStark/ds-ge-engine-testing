#pragma once

#include <chrono>

namespace ds::utilities
{
    class ScopedTimer
    {
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock>
            _frame_start_time;
        std::chrono::time_point<std::chrono::high_resolution_clock>
            _frame_end_time;

    public:
        ScopedTimer();
        ~ScopedTimer();
    };
}  // namespace ds::utilities
