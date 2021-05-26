#include "QueueStack.h"

void QueueStack::push(int val)
{
    int size = stack.size();
    int temp;

    stack.push(val);

    for(int i = 0; i < size; i++)
    {
        temp = stack.front();
        stack.pop();
        stack.push(temp);
    }
}

void QueueStack::pop()
{
    if (stack.size() > 0)
    {
        stack.pop();
    }
}

int QueueStack::peek()
{
    if(stack.size() > 0)
    {
        return stack.front();
    }
}

bool QueueStack::empty()
{
    return stack.size() == 0;
}