#include "progression.h"

FibonacciProgression::FibonacciProgression(long f, long s)
    : Progression(f), second(s), prev(second - first)
{
}

long FibonacciProgression::FirstValue()
{
    cur = first;
    prev = second - first;
    return cur;
}

long FibonacciProgression::NextValue()
{
    long temp = prev;
    prev = cur;
    cur += temp;
    return cur;
}