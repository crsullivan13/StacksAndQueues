#include "CallCounter.h"

int CallCounter::ping(int t)
{
    mRecentCalls.push(t);

    while(mRecentCalls.front() < t - 3000)
    {
        mRecentCalls.pop();
    }

    return mRecentCalls.size();
}