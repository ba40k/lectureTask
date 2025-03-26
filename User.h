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
    User(std::string _name);
    uint64_t getId() const;
    QString getName() const;
};



#endif //USER_H
