#include "progression.h"

// constructor
ArithProgression::ArithProgression(long i)
    : Progression(), inc(i)
{
}

// increase by adding
long ArithProgression::NextValue()
{
    cur += inc;
    return cur;
}
