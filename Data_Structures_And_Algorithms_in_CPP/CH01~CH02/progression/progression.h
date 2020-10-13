#ifndef PROGRESSION_H
#define PROGRESSION_H

#include <iostream>

using namespace std;

class Progression
{
public:
    Progression(long f = 0)
        : first(f), cur(f) {}
    virtual ~Progression() {}
    void PrintProgression(int n);

protected:
    virtual long FirstValue();
    virtual long NextValue();

protected:
    long first; // 첫 번째 값
    long cur;   // 현재 값
};

// 등차 수열
class ArithProgression : public Progression
{
public:
    ArithProgression(long i = 1);

protected:
    virtual long NextValue(); // 증가

protected:
    long inc; // 증가량
};

// 등비 수열
class GeomProgression : public Progression
{
public:
    GeomProgression(long b = 2);

protected:
    virtual long NextValue();

protected:
    long base; // 기저 값
};

// 피보나치 수열 클래스
class FibonacciProgression : public Progression
{
public:
    FibonacciProgression(long f = 0, long s = 1);

protected:
    virtual long FirstValue(); // 리셋
    virtual long NextValue();  // 증가

protected:
    long second; // 두 번째 값
    long prev;   // 이전 값
};

#endif