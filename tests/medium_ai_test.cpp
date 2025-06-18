#include <gtest/gtest.h>
#include <vector>
#include "../include/ai_logic.h"
#include "../include/game_logic.h"
#include <algorithm>

TEST(MediumAITest, BlocksOpponentWin) {
    std::vector<char> board = {'X', 'X', '3', '4', 'O', '6', '7', '8', '9'};
    std::vector<int> used = {1, 2, 5};
    int choice = 0;

    AILogic::mediumAI(board, used, choice, 'O', 'X');

    // AI لازم تسد خانة 3
    EXPECT_EQ(choice, 3);
}

TEST(MediumAITest, TakesWinningMove) {
    std::vector<char> board = {'O', 'O', '3', '4', 'X', '6', '7', '8', '9'};
    std::vector<int> used = {1, 2, 5};
    int choice = 0;

    AILogic::mediumAI(board, used, choice, 'O', 'X');

    // AI لازم تاخد خانة 3 وتكسب
    EXPECT_EQ(choice, 3);
}
