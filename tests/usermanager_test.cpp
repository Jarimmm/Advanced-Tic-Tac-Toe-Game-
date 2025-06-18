#include <gtest/gtest.h>
#include "UserManager.h"


TEST(UserManagerTest, RegisterSuccess) {
    EXPECT_TRUE(UserManager::registerUser("test_user", "test123"));
}

TEST(UserManagerTest, RegisterDuplicate) {
    UserManager::registerUser("duplicate", "pass1");
    EXPECT_FALSE(UserManager::registerUser("duplicate", "pass2"));
}

TEST(UserManagerTest, LoginSuccess) {
    UserManager::registerUser("login_user", "pass123");
    EXPECT_TRUE(UserManager::loginUser("login_user", "pass123"));
}

TEST(UserManagerTest, LoginFail) {
    EXPECT_FALSE(UserManager::loginUser("wrong_user", "nopass"));
}
