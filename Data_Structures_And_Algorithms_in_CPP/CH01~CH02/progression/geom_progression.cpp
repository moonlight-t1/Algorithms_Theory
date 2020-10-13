#include "progression.h"

// constructor
GeomProgression::GeomProgression(long b)
    : Progression(1), base(b) {}

// increase by multiplying
long GeomProgression::NextValue()
{
    cur *= base;
    return cur;
}
