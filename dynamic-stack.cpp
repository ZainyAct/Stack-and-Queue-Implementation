#include "dynamic-stack.h"
#include <iostream>

const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack() {

    capacity_ = 16;
    init_capacity_ = 16;
    size_ = 0;
    items_ = new int [capacity_];

}

DynamicStack::DynamicStack(unsigned int capacity){
    capacity_ = init_capacity_ = capacity;
    size_ = 0;
    items_ = new int [capacity_];
}

DynamicStack::~DynamicStack() {
    delete [] items_;
    items_ = nullptr;
}

unsigned int DynamicStack::size() const {
    return size_;
}

bool DynamicStack::empty() const {
    return size_ == 0;
}

DynamicStack::StackItem DynamicStack::peek() const {
    if(empty())
        return EMPTY_STACK;
    else
        return items_[size_-1];
}

void DynamicStack::push(StackItem value) {
    if(size_ == capacity_) {
        int *newItems = new int[2 * capacity_];
        capacity_ = 2 * capacity_;
        for (int i = 0; i < size_; i++) {
            newItems[i] = items_[i];
        }
        int *temp = items_;
        items_ = newItems;
        delete[] temp;
        temp = nullptr;
    }
    items_[size_] = value;
    size_++;
}

DynamicStack::StackItem DynamicStack::pop() {
    if (empty())
        return EMPTY_STACK;

    StackItem top = items_[size_-1];
    size_--;

    if (size_ <= capacity_ / 4) {
        StackItem *newItems = new int [capacity_ / 2];
        for (int i = 0; i < size_; i++) {
            newItems[i] = items_[i];
        }

        delete[]items_;
        items_ = newItems;

    }
        return top;
}

void DynamicStack::print() const {
    for (int i = 0; i < size_; i++) {
        std::cout << items_[i] << ", ";
    }
}
