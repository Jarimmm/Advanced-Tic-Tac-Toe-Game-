#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <cstdio> // for std::remove

TEST(GameHistoryTest, SaveMatchHistory) {
    std::string testFile = "test_history.txt";

    // Simulate writing to history
    std::ofstream history(testFile, std::ios::app);
    ASSERT_TRUE(history.is_open());

    history << "Match: rana vs ai\n";
    history << "rana played 5\n";
    history << "Result: rana\n";
    history.close();

    // Now read back the file to verify
    std::ifstream file(testFile);
    ASSERT_TRUE(file.good());

    std::string line;
    bool foundMatch = false;
    while (getline(file, line)) {
        if (line.find("Match: rana vs ai") != std::string::npos) {
            foundMatch = true;
            break;
        }
    }

    ASSERT_TRUE(foundMatch); // Test passes if we find the line
    file.close();

    // Clean up test file
    std::remove(testFile.c_str());
}
