#include "circular-queue.h"
#include <iostream>

const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue() {
    capacity_ = 16;
    size_ = 0;
    head_ = 0;
    tail_ = 0;
    items_ = new QueueItem[capacity_];
}

CircularQueue::CircularQueue(unsigned int capacity) {
    capacity_ = capacity;
    size_ = 0;
    head_ = 0;
    tail_ = 0;
    items_ = new QueueItem[capacity_];
}

CircularQueue::~CircularQueue() {
    delete[] items_;
}

unsigned int CircularQueue::size() const {
    return size_;
}

bool CircularQueue::empty() const {
    return size_ == 0;
}

bool CircularQueue::full() const {
    return size_ == capacity_;
}

CircularQueue::QueueItem CircularQueue::peek() const {
    if (empty()) {
        return EMPTY_QUEUE;
    }
    return items_[head_];
}

bool CircularQueue::enqueue(QueueItem value) {
    if (full()) {
        return false;
    }
    items_[tail_] = value;
    tail_ = (tail_ + 1) % capacity_;
    size_++;
    return true;
}

CircularQueue::QueueItem CircularQueue::dequeue() {
    if (empty()) {
        return EMPTY_QUEUE;
    }
    QueueItem item = items_[head_];
    head_ = (head_ + 1) % capacity_;
    size_--;
    return item;
}

void CircularQueue::print() const {
    if (empty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    std::cout << "Queue (front to rear): ";
    unsigned int current = head_;
    for (unsigned int count = 0; count < size_; count++) {
        std::cout << items_[current] << " ";
        current = (current + 1) % capacity_;
    }
}
