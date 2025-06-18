#include <gtest/gtest.h>
#include <vector>
#include <set>
#include "../include/ai_logic.h"
#include <algorithm>


TEST(AITest, EasyAIChoosesValidMove) {
    std::vector<char> board = {'1','2','3','4','5','6','7','8','9'};
    std::vector<int> used = {1, 2, 3};
    int choice = 0;

    AILogic::easyAI(board, used, choice);

    EXPECT_GE(choice, 1);
    EXPECT_LE(choice, 9);
    EXPECT_EQ(std::count(used.begin(), used.end(), choice), 0);
}
