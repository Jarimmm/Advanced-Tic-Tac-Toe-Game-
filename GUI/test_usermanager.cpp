#include <QtTest>
#include "UserManager_qt.h"
#include "User.h"

class TestUserManager : public QObject {
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();

    void testRegisterNewUser();
    void testRegisterExistingUser();
    void testLoginSuccess();
    void testLoginFailure();
};

void TestUserManager::initTestCase() {
    // Remove test user if exists
    QFile file("users.txt");
    if (file.exists()) {
        file.remove();  // Clean slate
    }
}

void TestUserManager::cleanupTestCase() {
    QFile::remove("users.txt");  // Clean up after tests
}

void TestUserManager::testRegisterNewUser() {
    User newUser("testuser", "testpass");
    QVERIFY2(UserManagerQt::registerUser(newUser), "Failed to register a new user.");
}

void TestUserManager::testRegisterExistingUser() {
    User duplicateUser("testuser", "testpass");
    QVERIFY2(!UserManagerQt::registerUser(duplicateUser), "Should not allow registering an existing user.");
}

void TestUserManager::testLoginSuccess() {
    QVERIFY2(UserManagerQt::loginUser("testuser", "testpass"), "Valid credentials should log in.");
}

void TestUserManager::testLoginFailure() {
    QVERIFY2(!UserManagerQt::loginUser("testuser", "wrongpass"), "Wrong password should fail login.");
    QVERIFY2(!UserManagerQt::loginUser("nonexistent", "any"), "Nonexistent user should fail login.");
}

QTEST_MAIN(TestUserManager)
#include "test_usermanager.moc"
