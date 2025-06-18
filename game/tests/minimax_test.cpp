#include <gtest/gtest.h>
#include <vector>
#include "../include/ai_logic.h"
#include "../include/game_logic.h"
#include <algorithm>

TEST(MinimaxTest, DetectsWinForAI) {
    std::vector<char> board = {'O', 'O', '3', '4', 'X', '6', '7', '8', '9'};
    int score = AILogic::minimax(board, true, 'O', 'X');
    EXPECT_GT(score, 0); // AI (O) should detect winning move
}

TEST(MinimaxTest, DetectsLossForAI) {
    std::vector<char> board = {'X', 'X', '3', '4', 'O', '6', '7', '8', '9'};
    int score = AILogic::minimax(board, false, 'O', 'X');
    EXPECT_LT(score, 0); // AI (O) should detect player can win
}
