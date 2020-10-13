#include "progression.h"

void Progression::PrintProgression(int n)
{
    cout << FirstValue();
    for (int i = 0; i <= n; i++)
        cout << ' ' << NextValue();
    cout << endl;
}

// reset
long Progression::FirstValue()
{
    cur = first;
    return cur;
}

// increase
long Progression::NextValue()
{
    return ++cur;
}