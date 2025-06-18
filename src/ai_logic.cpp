#include "../include/ai_logic.h"
#include "../include/game_logic.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>
#include <chrono>
#include <memory> // For std::unique_ptr
#include <cstdlib> // For rand()
#include "../include/game_constants.h"

using namespace std;

// --- Tree Node Definition ---
/**
 * @struct Node
 * @brief Represents a single state (a node) in the game tree.
 *
 * Each node contains the board state, the move that led to this state,
 * and pointers to all possible subsequent states (children).
 */
struct Node {
    vector<char> board;
    int moveIndex; // The board index (0-8) of the move that led to this state.
    vector<unique_ptr<Node>> children; // Pointers to child nodes for subsequent moves.

    Node(vector<char> b, int m = -1) : board(b), moveIndex(m) {}
};

// --- Helper Functions for Tree-based AI ---

/**
 * @brief Recursively builds the game tree from a given node.
 * @param node The current node (game state) from which to build the tree.
 * @param player The symbol of the player whose turn it is.
 * @param opponent The symbol of the opponent.
 */
void buildTree(Node* node, char player, char opponent) {
    // Stop building if the current state is a win, loss, or draw
    if (GameLogic::checkWin(node->board) != -1) {
        return;
    }

    // Explore all possible moves from the current board state
    for (int i = 0; i < 9; ++i) {
        if (node->board[i] != 'X' && node->board[i] != 'O') {
            vector<char> newBoard = node->board;
            newBoard[i] = player;

            // Create a child node for this move and add it to the current node's children
            node->children.push_back(make_unique<Node>(newBoard, i));

            // Recursively build the subtree from the new child node, switching the player
            buildTree(node->children.back().get(), opponent, player);
        }
    }
}

/**
 * @brief Runs the minimax algorithm with alpha-beta pruning on the pre-built game tree.
 * @param node The current node in the tree to evaluate.
 * @param isMaximizing True if we are maximizing (AI's turn), false if minimizing (Player's turn).
 * @param alpha The best score for the maximizer.
 * @param beta The best score for the minimizer.
 * @return The evaluated score for the given node.
 */
int minimaxOnTree(Node* node, bool isMaximizing, int alpha, int beta) {
    int gameState = GameLogic::checkWin(node->board);
    if (gameState == 1) { // Win state
        // If it's the maximizer's turn, the minimizer must have made the winning move.
        return isMaximizing ? -10 : 10;
    }
    if (gameState == 0) { // Draw state
        return 0;
    }

    // If it is a non-terminal node with no possible moves
    if (node->children.empty()) {
        return 0;
    }

    if (isMaximizing) {
        int bestScore = -1000;
        for (const auto& child : node->children) {
            int score = minimaxOnTree(child.get(), false, alpha, beta);
            bestScore = max(bestScore, score);
            alpha = max(alpha, bestScore);
            if (beta <= alpha) {
                break; // Beta cut-off
            }
        }
        return bestScore;
    } else { // Minimizing player
        int bestScore = 1000;
        for (const auto& child : node->children) {
            int score = minimaxOnTree(child.get(), true, alpha, beta);
            bestScore = min(bestScore, score);
            beta = min(beta, bestScore);
            if (beta <= alpha) {
                break; // Alpha cut-off
            }
        }
        return bestScore;
    }
}


// --- AILogic Class Method Implementations ---

bool AILogic::isMoveValid(const vector<int>& used, int num) {
    // The user's choice is 1-9, board index is 0-8.
    // Check if the number (1-9) is in the 'used' list.
    return find(used.begin(), used.end(), num) == used.end();
}

void AILogic::easyAI(const vector<char>& board, vector<int>& used, int& choice) {
    cout << " " << dice << " Computer is choosing randomly...\n";
    this_thread::sleep_for(chrono::milliseconds(500));
    do {
        choice = rand() % 9 + 1;
    } while (!isMoveValid(used, choice));
}

// *** MODIFIED mediumAI - Made easier and less predictable ***
void AILogic::mediumAI(const vector<char>& board, vector<int>& used, int& choice,
                       char aiSymbol, char playerSymbol) {
    cout << " " << brain << " Computer is strategizing...\n";
    this_thread::sleep_for(chrono::milliseconds(500));

    // **Priority 1: Win if possible**
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            vector<char> temp = board;
            temp[i] = aiSymbol;
            if (GameLogic::checkWin(temp) == 1) {
                choice = i + 1;
                return;
            }
        }
    }

    // **Priority 2: 50% chance to play strategically, 50% chance for a random move**
    if (rand() % 2 == 0) { // Strategic move
        // Prefer center
        if (board[4] == '5') {
            choice = 5;
            return;
        }

        // Then corners
        vector<int> corners = {0, 2, 6, 8};
        vector<int> available_corners;
        for (int corner : corners) {
            if (board[corner] != 'X' && board[corner] != 'O') {
                available_corners.push_back(corner);
            }
        }
        if (!available_corners.empty()) {
            choice = available_corners[rand() % available_corners.size()] + 1;
            return;
        }
    }

    // **Fallback: Make a random valid move**
    // This part runs if the AI chose the "random" path, or if no strategic moves were available.
    do {
        choice = rand() % 9 + 1;
    } while (!isMoveValid(used, choice));
}


// Corrected hardAI signature to match the declaration in ai_logic.h
void AILogic::hardAI(const vector<char>& board, vector<int>& used, int& choice, char aiSymbol) {
    // The 'used' parameter is not needed for the minimax logic but is included
    // to match the function declaration and resolve the compiler error.

    cout << " " << genius << " Computer is building game tree and calculating optimal move...\n";
    this_thread::sleep_for(chrono::milliseconds(500));

    char playerSymbol = (aiSymbol == 'X') ? 'O' : 'X';

    // 1. Create the root of the tree with the current board state
    auto root = make_unique<Node>(board);

    // 2. Build the entire game tree from the root node
    buildTree(root.get(), aiSymbol, playerSymbol);

    int bestScore = -1000;
    int bestMove = -1;

    // 3. Evaluate the direct children of the root to find the best move
    for (const auto& moveNode : root->children) {
        // The AI makes a move (maximizing), so the next turn is the player's (minimizing)
        int score = minimaxOnTree(moveNode.get(), false, -1000, 1000);
        if (score > bestScore) {
            bestScore = score;
            bestMove = moveNode->moveIndex;
        }
    }

    // If no moves are possible (e.g., board is full), this will be -1.
    if (bestMove == -1) {
        // Fallback: find any available spot (should not be needed if called correctly)
        for(int i=0; i<9; ++i) {
            if(board[i] != 'X' && board[i] != 'O') {
                choice = i + 1;
                return;
            }
        }
    } else {
       choice = bestMove + 1;
    }
}
