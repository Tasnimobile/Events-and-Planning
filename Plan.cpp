/**
 * @file Plan.cpp
 * @author Tahsinul Majumder
 * @brief This file is the implementation for Plan class
 * @date 2024-06-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Plan.hpp"

//default constructor
template <class T>
Plan<T>::Plan() {
    array_ = new T[2];
    capacity_ = 2;
    num_items_ = 0;
}

//destructor
template <class T>
Plan<T>::~Plan() {
    delete[] array_;
}

//copy constructor
template <class T>
Plan<T>::Plan(const Plan& other) {
    capacity_ = other.capacity_;
    num_items_ = other.num_items_;
    array_ = new T[capacity_];
    
    //goes through original array one by one to copy
    for (int i = 0; i < num_items_; ++i) 
        array_[i] = other.array_[i];
}

//copy assignment
template <class T>
Plan<T>& Plan<T>::operator=(const Plan& other) {

    //as long as they aren't the same object
    if (this != &other) {
        delete[] array_;
        num_items_ = other.num_items_;
        capacity_ = other.capacity_;
        array_ = new T[capacity_];

        //copies one by one
        for (int i = 0; i < num_items_; i++) 
            array_[i] = other.array_[i];
    }
    
    
    return *this;
}

//move constructor
template <class T>
Plan<T>::Plan(Plan&& other) noexcept {
    array_ = other.array_;
    num_items_ = other.num_items_;
    capacity_ = other.capacity_;

    //erase original
    other.array_ = nullptr;
    other.num_items_ = 0;
    other.capacity_ = 0;
}

//move assignment operator
template <class T>
Plan<T>& Plan<T>::operator=(Plan&& other) noexcept {
    if (this != &other) {
        delete[] array_;
        array_ = other.array_;
        capacity_ = other.capacity_;
        num_items_ = other.num_items_;

        //erase original
        other.array_ = nullptr;
        other.capacity_ = 0;
        other.num_items_ = 0;
    }
    return *this;
}

//addEvent
template <class T>
void Plan<T>::addEvent(const T& event) {
    
    //if it's at max capacity already then double and copy
    if (num_items_ == capacity_) {
        capacity_ *= 2;

        //temp array
        T* array = new T[capacity_];

        //temp array holds the values of original
        for (int i = 0; i < num_items_; i++) 
            array[i] = array_[i];

        //reassign original array to new array which has double the space
        delete[] array_;
        array_ = array;
    }

    //adds event
    array_[num_items_] = event;
    num_items_++;
}

//removeEvent
template <class T>
bool Plan<T>::removeEvent(const T& event) {
    int idx = getIndexOf(event);

    if (idx == -1)
        return false;

    //everything after index of event is brought down one slot
    for (int i = idx; i < num_items_ - 1; i++)
        array_[i] = array_[i + 1];

    //reduce num_items_ so you can't access duplicate at the end
    num_items_--;
    return true;
}

//getEvent
template <class T>
T* Plan<T>::getEvents() const {
    return array_;
}

//getSize
template <class T>
int Plan<T>::getSize() const {
    return num_items_;
}

//getCapacity
template <class T>
int Plan<T>::getCapacity() const {
    return capacity_;
}

//getIndexOf
template <class T>
int Plan<T>::getIndexOf(const T& event) {
    for (int i = 0; i < num_items_; i++) {
        if (array_[i] == event)
            return i;
    }

    return -1;
}