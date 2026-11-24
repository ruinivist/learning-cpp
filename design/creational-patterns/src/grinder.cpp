// Calculates how many whole grams a blade grinder yields.
// The brew cycle reports the resulting dose.

#include "grinder.h"

int BladeGrinder::grind(int gramsRequested, GrindSize size) {
    double yield = 1.0;
    switch (size) {
        case GrindSize::Fine:
            yield = 0.9;
            break;
        case GrindSize::Medium:
            yield = 0.95;
            break;
        case GrindSize::Coarse:
            yield = 1.0;
            break;
    }
    last_size_ = size;
    return static_cast<int>(gramsRequested * yield);
}
