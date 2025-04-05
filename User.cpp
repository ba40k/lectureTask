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
User::User(const std::string &_name, const uint64_t &_id) {
    this->name =QString::fromStdString(_name);
    this->id = _id;
}

uint64_t User::getId() const {
    return id;
}
QString User::getName() const {
    return name;
}
QString User::getUserInformation() const {
    return QString::fromStdString(std::to_string(currentId)) + " " + name;
}


