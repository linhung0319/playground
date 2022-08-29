#include <iostream>
#include "CircularQueue.h"
using namespace std;

CircularQueue::CircularQueue(int capacity=10){
    _size = 0;
    _capacity = capacity;
    _array = new int[_capacity] {0};
    _front = 0;
    _rear = -1;
}

bool CircularQueue::is_empty(){
    if (_size == 0){
        return true;
    }
    return false;
}

bool CircularQueue::is_full(){
    if (_size == _capacity){
        return true;
    }
    return false;
}

void CircularQueue::push(int v){
    if ( is_full() ){
        cout << "The queue is full." << endl;
        return;
    }
    _rear = (_rear + 1) % _capacity;
    _array[_rear] = v;
    _size += 1; 
}

int CircularQueue::pop(){
    if ( is_empty() ){
        cout << "The queue is empty." << endl;
        return -1;
    }
    int index = _front;
    _front = (_front + 1) % _capacity;
    _size -= 1;
    return _array[index];
}

void CircularQueue::display() {
    for (register int i = 0; i < _capacity; i++) {
        cout << _array[i] << " ";
    }
    cout << endl;
}