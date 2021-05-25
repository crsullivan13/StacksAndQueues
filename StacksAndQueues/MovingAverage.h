#ifndef MOVINGAVERAGE_H
#define MOVINGAVERAGE_H
#pragma once


class MovingAverage
{
private:
    int* stream;
    int length;
    int total;
    int insert;
    int sum;

public:
    MovingAverage(int size);
    double next(int val);

};
#endif