#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include "Queue.h"

class CircularQueue:public Queue{
private:
    int _front;
    int _rear;
    int _size;
    int _capacity;
    int *_array;
public:
    CircularQueue(int);
    void push(int);
    int pop();
    bool is_empty();
    bool is_full();
    void display();
};
#endif