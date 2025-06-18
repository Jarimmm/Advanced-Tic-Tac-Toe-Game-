#include "UserManager_qt.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStringList>
#include <functional> // for std::hash

extern QString getProjectFilePath(const QString& fileName, bool createIfNotFound);

// ✅ Hash the password using std::hash
QString UserManagerQt::hashPassword(const QString& password) {
    std::hash<std::string> hasher;
    size_t hashed = hasher(password.toStdString());
    return QString::number(static_cast<qulonglong>(hashed));
}

// ✅ Register user with hashing and duplicate check
bool UserManagerQt::registerUser(const User& user) {
    QString userPath = getProjectFilePath("users.txt", true);
    if (userPath.isEmpty()) {
        qDebug() << "❌ Could not locate or create users.txt";
        return false;
    }

    QFile inFile(userPath);
    if (inFile.exists() && inFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&inFile);
        while (!in.atEnd()) {
            QString line = in.readLine();
            int colonIndex = line.indexOf(':');
            if (colonIndex != -1) {
                QString storedUser = line.left(colonIndex);
                if (storedUser == QString::fromStdString(user.username)) {
                    qDebug() << "❌ Username already exists!";
                    inFile.close();
                    return false;
                }
            }
        }
        inFile.close();
    }

    QFile outFile(userPath);
    if (!outFile.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "❌ Could not write to users.txt at:" << userPath;
        return false;
    }

    QTextStream out(&outFile);
    QString hashedPassword = hashPassword(QString::fromStdString(user.password));
    out << QString::fromStdString(user.username) << ":" << hashedPassword << "\n";
    outFile.close();

    qDebug() << "✅ Registration successful!";
    return true;
}

// ✅ Login user by comparing hashed password
bool UserManagerQt::loginUser(const std::string& username, const std::string& password) {
    QString userPath = getProjectFilePath("users.txt",false);
    if (userPath.isEmpty()) {
        qDebug() << "❌ Could not locate users.txt";
        return false;
    }

    QFile file(userPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "❌ Could not open users.txt";
        return false;
    }

    QTextStream in(&file);
    QString hashedInput = hashPassword(QString::fromStdString(password));

    while (!in.atEnd()) {
        QString line = in.readLine();
        int colonIndex = line.indexOf(':');
        if (colonIndex == -1) continue;

        QString storedUser = line.left(colonIndex);
        QString storedHash = line.mid(colonIndex + 1);

        if (storedUser == QString::fromStdString(username) && storedHash == hashedInput) {
            qDebug() << "✅ Login successful!";
            file.close();
            return true;
        }
    }

    qDebug() << "❌ Invalid credentials.";
    file.close();
    return false;
}
