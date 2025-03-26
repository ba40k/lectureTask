//
// Created by radamir on 26.03.25.
//

#include <gtest/gtest.h>

#include "../Library.h"
#include "../User.h"


class LibraryTesting : public testing::Test {
    public:
    Library lib;
};

TEST(UserTests, handlesIdCorrectnessTest1) {
    User user("Radamir"); // 0
    ASSERT_EQ(0,user.getId());
}
TEST(UserTests, handlesIdCorrectnessTest2) {
    User user("Radamir"); //1
    User user2("Konstantin"); //2

    ASSERT_FALSE(user.getId() == user2.getId());
}
TEST(UserTests, handlesIdCorrectnessTest3) {
    User user("Radamir"); //3
    User user2("Konstantin"); //4
    std::vector<uint64_t> ids = {user.getId(),user2.getId()};
    std::vector<uint64_t> expected = {3,4};
    ASSERT_EQ(expected,ids);
}
TEST(UserTests, handlesIdCorrectnessTest4) {
    int numberOfUsers = 10;
    std::vector<uint64_t> ids;
    for (int i = 0; i < numberOfUsers; i++) {
        User user("dummy");
        ids.push_back(user.getId());
    }
    ids.erase(std::unique(ids.begin(), ids.end()), ids.end());
    ASSERT_EQ(numberOfUsers,ids.size());
}