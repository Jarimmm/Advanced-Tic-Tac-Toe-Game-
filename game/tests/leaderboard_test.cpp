#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <cstdio> // for std::remove
#include "../include/leaderboard.h"

TEST(LeaderboardTest, UpdateLeaderboardFile) {
    std::string testFile = "test_score.txt";

    // استبدال اسم الملف مؤقتًا
    std::ofstream score(testFile, std::ios::app);
    ASSERT_TRUE(score.is_open());
    score.close();

    // نفذ الدالة يدويًا
    Leaderboard::updateLeaderboard("rana", "marko", "rana");

    // اقرأ الملف وتأكد إن السطر مكتوب
    std::ifstream file("score.txt"); // بتكتب في score.txt
    ASSERT_TRUE(file.is_open());

    std::string line;
    bool found = false;
    while (getline(file, line)) {
        if (line.find("rana\tmarko\trana") != std::string::npos) {
            found = true;
            break;
        }
    }

    file.close();
    ASSERT_TRUE(found);

    // تنظيف الملف (اختياري)
    // std::remove("score.txt");
}
