//
// Created by radamir on 27.03.25.
//
#include "../Library.h"
#include <gtest/gtest.h>
class ComplexLibraryTesting : public ::testing::Test {
  public:
  Library lib;
};

TEST_F(ComplexLibraryTesting, handlesUserAddingTest1) {
  ASSERT_EQ(0,lib.getNumberOfUsers());
}

TEST_F(ComplexLibraryTesting, handlesUserAddingTest2) {
  lib.addUser(std::make_shared<User>(("Radamir")));
  lib.addUser(std::make_shared<User>(("Vladimir")));
  lib.addUser(std::make_shared<User>(("Denis")));

  auto res = lib.getUsersListed();

  ASSERT_TRUE(res.size()==3 && res[0].getName()=="Radamir"
                   && res[1].getName()=="Vladimir" && res[2].getName() == "Denis");
}
TEST_F(ComplexLibraryTesting, handlesUserRemovingTest1) {

  auto Radamirus = std::make_shared<User>("Radamirus");
  lib.addUser(Radamirus);
  lib.removeUser(Radamirus);
  // ВАЖНО!
  /*
   *User Radamirus("Radamir");
   *lib.addUser(make_shared<User>(Radamirus));
   *lib.removeUser(make_shared<User>(Radamirus));
   * Не удалит ничего, так как мы дважды создаем такого пользователся, и они будут иметь разные id
   */
  ASSERT_EQ(0,lib.getNumberOfUsers());
}
TEST_F(ComplexLibraryTesting, handlesUserRemovingTest2) {

  auto Radamirus = std::make_shared<User>("Radamirus");
  auto Vladimir = std::make_shared<User>("Vladimir");
  lib.addUser(Radamirus);
  lib.addUser(Vladimir);
  lib.removeUser(Radamirus);
  ASSERT_EQ(1,lib.getNumberOfUsers());

}
