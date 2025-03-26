//
// Created by radamir on 26.03.25.
//

#include "User.h"


User::User(std::string _name) {
    this->name =QString::fromStdString(_name);
    this->id = currentId;
    currentId++;
}
uint64_t User::getId() const {
    return id;
}
QString User::getName() const {
    return name;
}
