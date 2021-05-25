#include "MovingAverage.h"

MovingAverage::MovingAverage(int size)
{
    stream = new int[size];
    length = size;
    total = 0;
    insert = 0;
    sum = 0;
}

double MovingAverage::next(int val)
{
    if(total == 3)
    {
        sum -= stream[insert];
    }
    sum += val;
    stream[insert] = val;
    insert++;
    insert %= length;

    if (total < length)
    {
        total++;
    }

    return double(sum) / double(total);
}