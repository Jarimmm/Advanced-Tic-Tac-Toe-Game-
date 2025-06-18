#include <gtest/gtest.h>
#include <vector>
#include "../include/ai_logic.h"
#include "../include/game_logic.h"
#include <algorithm>

TEST(HardAITest, TakesWinningMove) {
    std::vector<char> board = {'O', 'O', '3', '4', 'X', '6', '7', '8', '9'};
    std::vector<int> used = {1, 2, 5};
    int choice = 0;

    AILogic::hardAI(board, used, choice, 'O');

    EXPECT_EQ(choice, 3);  // O can win by playing at position 3
}

TEST(HardAITest, BlocksPlayerWinningMove) {
    std::vector<char> board = {'X', 'X', '3', '4', 'O', '6', '7', '8', '9'};
    std::vector<int> used = {1, 2, 5};
    int choice = 0;

    AILogic::hardAI(board, used, choice, 'O');

    EXPECT_EQ(choice, 3);  // O must block X at position 3
}
