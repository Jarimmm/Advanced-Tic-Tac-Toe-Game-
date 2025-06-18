/*
 * ai_logic.h
 *
 *  Created on: Apr 28, 2025
 *      Author: Mariam Samy
 */

#ifndef AI_LOGIC_H
#define AI_LOGIC_H

#include <vector>
#include "game_constants.h"

class AILogic {
public:
    static bool isMoveValid(const std::vector<int>& used, int num);
    static void easyAI(const std::vector<char>& board, std::vector<int>& used, int& choice);
    static void mediumAI(const std::vector<char>& board, std::vector<int>& used, int& choice,
                        char aiSymbol, char playerSymbol);
    static void hardAI(const std::vector<char>& board, std::vector<int>& used, int& choice, char aiSymbol);

private:
    static int minimax(std::vector<char> board, bool isMaximizing, char aiSymbol, char playerSymbol);
};

#endif
