#ifndef QUEUESTACK_H
#define QUEUESTACK_H
#pragma once
#include <queue>

class QueueStack
{
private:
    std::queue<int> stack;

public:
    void push(int val);
    void pop();
    int peek();
    bool empty();

};
#endif