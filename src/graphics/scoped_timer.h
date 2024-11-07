#pragma once

#include <chrono>

namespace ds::graphics
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
}  // namespace ds::graphics

// A MACRO that can be used to create a ScopedTimer object and print the
// duration and FPS of the scope. Only available in DEBUG mode.
#ifndef NDEBUG
#define DS_GRAPHICS_SCOPED_TIMER ds::graphics::ScopedTimer scoped_timer
#else
#define DS_GRAPHICS_SCOPED_TIMER
#endif