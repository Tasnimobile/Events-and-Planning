/**
 * @file Plan.hpp
 * @author Tahsinul Majumder
 * @brief This file is the interface for Plan class
 * @date 2024-06-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <iostream>

template <class T >
class Plan {
public:
    /**
     * @brief Default constructor of new Plan object
     * @post Plan object is created with an array of size 2 and capacity 2
     */
    Plan();

    /**
     * @brief Destroy the Plan object
     * @post Plan object is destroyed/deleted
     */
    ~Plan();

    /**
     * @brief Construct a new Plan object
     * 
     * @param other 
     * @post new Plan object is created by copying values from other
     */
    Plan(const Plan& other);

    /**
     * @brief 
     * 
     * @param other 
     * @return Plan& 
     * @post new Plan object is created using = operator and copying values
     * of other Plan object
     */
    Plan& operator=(const Plan& other);

    /**
     * @brief Construct a new Plan object
     * 
     * @param other 
     * @post Moves the values of other Plan object to the new object created.
     * Original object values are set to null and 0
     */
    Plan(Plan&& other) noexcept;

    /**
     * @brief 
     * 
     * @param other 
     * @return Plan& 
     * @post moves other Plan object to new Plan object created
     * Original object values are set to null and 0
     */
    Plan& operator=(Plan&& other) noexcept; 

    /** * * * *
     * @brief Add an event to the Plan
     * @param event The event to be added to the Plan
     * @post If the array is full, the capacity of the array will be doubled and the event will be added
    */
    void addEvent(const T& event);
    /** * * * *
    *
    *
    @brief Remove an event from the plan
    @param event The event to be removed
    @return true if the event is in the array and is successfully removed
    @return false if the event is not in the array and can’t be removed
    @post If the event exists in the Plan, it will be removed while retaining the order
    */
    bool removeEvent(const T& event);
    /**
    * @brief Get the pointer to the Plan array
    *
    * @return T* Pointer to the dynamically allocated array where Plan
    is stored */
    T* getEvents() const;
    /**
    * @brief Get the size of the Plan
    *
    * @return int Number of events in the plan
    5
    */
    int getSize() const;
    /**
    * @brief Get the capacity of the Plan array *
    * @return int The maximum number of items that can be stored in the
    currently allocated Plan array */
    int getCapacity() const;
    /**
    * @brief Get the index of the object *
    * @param event Object whose index is being queried
    * @return int Index of the object if it exists, -1 otherwise */
    int getIndexOf(const T& event);

private:
    int capacity_;
    int num_items_;
    T *array_;
};

#include "Plan.cpp"



