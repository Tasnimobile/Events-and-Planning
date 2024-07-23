/**
 * @file Event.cpp
 * @author Tahsinul Majumder
 * @brief This file is the implementation for Event class
 * @date 2024-06-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Event.hpp"

//using namespace std;


/**
 * @brief 
 * 
 * @return std::string 
 */
std::string Event::timeToString() const {
    // if timestamp is -1, it is not valid and is the result of default constructor
    if (timestamp_ == -1) 
        return "Not Set Yet";
    struct tm* dt = localtime(&timestamp_);
    std::string time = asctime(dt);
    time.pop_back();
    return time;
}

//default constructor
Event::Event() {
    name_ = "Not Set Yet";
    timestamp_ = -1;
}

//parameterized constructor
Event::Event(const std::string& name, const long& timestamp) {
    name_ = name;
    timestamp_ = timestamp;
}

//getName
std::string Event::getName() const {
    return this->name_;
}

//getTimestamp
long Event::getTimestamp() const {
    return this->timestamp_;
}

//getGuests
std::vector<std::string> Event::getGuests() const {
    return this->guests_;
}

//setName
void Event::setName(const std::string& name) {
    name_ = name;
}

//setTimeStamp
bool Event::setTimestamp(const long& timestamp) {
    //if timestamp is positive
    if (timestamp > 0) {
        timestamp_ = timestamp;
        return true;
    }
    else
        return false;
}

//setGuests
bool Event::setGuests(const std::vector<std::string>& guests) {

    //iterate through
    for (int i = 0; i < guests.size(); i++) {
        //if the new guests vector is empty
        if (guests[i].empty())
            return false;
    }

    guests_ = guests;
    return true;
}

//overload output operator
std::ostream& operator<<(std::ostream& os, const Event& event) {
    os << "Name: " << event.getName() << std::endl;
    os << "Time: " << event.timeToString() << std::endl;
    os << "Guests:" << std::endl;

    //iterates through guests_ vector
    for (int i = 0; i < event.guests_.size(); i++) {
        os << i << ": " << event.guests_[i];

        //prints an endline for all guests except the last
        if (i < event.guests_.size() - 1)
            os << std::endl;
    }

    return os;
}

//overload input operator
std::istream& operator>>(std::istream& is, Event& event) {
    std::string inp;
    std::cout << "Enter guest name: ";
    getline(is, inp);

    //if user's input is not empty
    if (!inp.empty()) 
        event.guests_.push_back(inp);

    return is;
}

//add guest using name
bool Event::addGuest(const std::string& name) {
    //return false if the name is empty
    if (name.empty())
        return false;

    guests_.push_back(name);

    return true;
}

//add multiple guests
bool Event::addGuest(const std::vector<std::string>& names) {
    //iterates through names vector
    for (int i = 0; i < names.size(); i++) {
        //if it is empty, return false
        if (names[i].empty())
            return false;
    }

    //iterates through again to add it to guests_
    for (int i = 0; i < names.size(); i++) 
        guests_.push_back(names[i]);
    return true;
}

//remove guests while maintaining order and finding guest by name
bool Event::removeGuest(const std::string& name) {

    //iterates through guests_ vector
    for (int i = 0; i < guests_.size(); i++) {
        if (guests_[i] == name) {
            //brings everything after that index to the previous slot
            //replacing name
            for (int j = i; j < guests_.size() - 1; j++) 
                guests_[j] = guests_[j + 1];
            
            //removes the last element as it is a duplicate now
            guests_.pop_back();
            return true;
        }
    }
    return false;
}

//remove guests while maintaining order and finding guest by index
bool Event::removeGuest(const size_t& id) {

    //if the id is valid
    if (id < guests_.size()) {
        //brings everything after that index to the previous slot
        //removing the item at id
        for (int j = id; j < guests_.size() - 1; j++) 
            guests_[j] = guests_[j + 1];

        //removes the last element as it is now a duplicate
        guests_.pop_back();
        return true;
    }

    return false;
}
