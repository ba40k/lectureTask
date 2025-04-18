//
// Created by radamir on 26.03.25.
//

#ifndef USER_H
#define USER_H

#include <QString>
class User {
    QString name;
    uint64_t id;
    static uint64_t currentId;
    public:
    bool operator==(const User &) const = default;
    User(const std::string &_name);
    User(const std::string &_name, const uint64_t &_id);
    uint64_t getId() const;
    QString getName() const;
    QString getUserInformation() const; // id name
};



#endif //USER_H
