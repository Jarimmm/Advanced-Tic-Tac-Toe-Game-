
#ifndef AI_LOGIC_H
#define AI_LOGIC_H

#include <vector>
#include "game_constants.h"
struct Node; 
class AILogic {
class AILogic {
public:
    static void easyAI(const std::vector<char>& board, std::vector<int>& used, int& choice);
    static void mediumAI(const std::vector<char>& board, std::vector<int>& used, int& choice, char aiSymbol, char playerSymbol);
    static void hardAI(const std::vector<char>& board, std::vector<int>& used, int& choice, char aiSymbol);
    static int minimax(std::vector<char> board, bool isMaximizing, char aiSymbol, char playerSymbol); // 👈 Add this
    static int minimaxOnTree(Node* node, bool isMaximizing, int alpha, int beta); // assumed already declared
};
