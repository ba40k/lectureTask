//
// Created by radamir on 26.03.25.
//

#include "User.h"
uint64_t User::currentId = 0;

User::User(const std::string &_name) {
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
