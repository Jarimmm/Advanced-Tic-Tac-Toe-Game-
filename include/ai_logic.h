
#ifndef AI_LOGIC_H
#define AI_LOGIC_H

#include <vector>
#include "game_constants.h"
struct Node; 
class AILogic {
public:
    static bool isMoveValid(const std::vector<int>& used, int num);
    static void easyAI(const std::vector<char>& board, std::vector<int>& used, int& choice);
    static void mediumAI(const std::vector<char>& board, std::vector<int>& used, int& choice,
                         char aiSymbol, char playerSymbol);
    static void hardAI(const std::vector<char>& board, std::vector<int>& used, int& choice, char aiSymbol);

    // 🆕 Correct declaration of the actual used function
static int minimax(std::vector<char> board, bool isMaximizing, char aiSymbol, char playerSymbol);
cpp
Copy
Edit
};

#endif
