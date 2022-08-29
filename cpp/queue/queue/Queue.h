#ifndef QUEUE_H
#define QUEUE_H

class Queue{
public:
    virtual void push(int) = 0;
    virtual int pop() = 0;
    virtual bool is_empty() = 0;
    virtual bool is_full() = 0;
    virtual void display() = 0;
};

#endif