#ifndef CALLCOUNTER_H
#define CALLCOUNTER_H
#pragma once

#include <queue>

class CallCounter
{
private:
    std::queue<int> mRecentCalls;

public:
    int ping(int t);


};
#endif
