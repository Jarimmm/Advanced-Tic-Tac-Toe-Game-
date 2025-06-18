#include "../include/User.h"
#include "../include/UserManager.h"
#include "../include/game_logic.h"
#include "../include/game_ui.h"
#include "../include/ai_logic.h"
#include "../include/leaderboard.h"
#include "../include/game_constants.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <limits>
#include <sstream>

using namespace std;
//test

void replayLastMatch() {            //new*
    ifstream file("history.txt");
    if (!file) {
        cout << RED << "No match history found.\n" << RESET;
        return;
    }

    vector<string> lines;
    string line;

    while (getline(file, line)) {
        if (!line.empty())
            lines.push_back(line);
    }

    file.close();

    int start = -1;
    for (int i = lines.size() - 1; i >= 0; --i) {
        if (lines[i].find("Match:") != string::npos) {
            start = i;
            break;
        }
    }

    if (start == -1) {
        cout << RED << "No complete match found.\n" << RESET;
        return;
    }

    vector<char> board = {'1','2','3','4','5','6','7','8','9'};
    char currentSymbol = 'X';

    string u1 = "Player1", u2 = "Player2";
    if (lines[start].find("Match:") != string::npos) {
        size_t vs = lines[start].find(" vs ");
        if (vs != string::npos) {
            u1 = lines[start].substr(7, vs - 7);
            u2 = lines[start].substr(vs + 4);
        }
    }

    for (int i = start + 1; i < lines.size(); ++i) {
        if (lines[i].find("Result:") != string::npos) {
            GameLogic::displayColorfulBoard('X', 'O', u1, u2, board);
            cout << GREEN << lines[i] << "\n" << RESET;
            break;
        }

        stringstream ss(lines[i]);
        string player, played, moveStr;
        ss >> player >> played >> moveStr;

        int move = stoi(moveStr);
        board[move - 1] = currentSymbol;

        GameLogic::displayColorfulBoard('X', 'O', u1, u2, board);
        cout << CYAN << player << " played " << move << "\n" << RESET;

        currentSymbol = (currentSymbol == 'X') ? 'O' : 'X';
        GameLogic::wait(1000);
    }
}

int main() {
#ifdef _WIN32
    system("chcp 65001");
    system("color 0D");
#endif

    srand(time(NULL));

    string username, password;
    int authChoice;

    cout << "1. Register\n2. Login\nChoose option: ";
    cin >> authChoice;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    bool loggedIn = false;

    if (authChoice == 1) {
        if (UserManager::registerUser(username, password)) {
            loggedIn = true;
        }
    } else if (authChoice == 2) {
        if (UserManager::loginUser(username, password)) {
            loggedIn = true;
        } else {
            cout << "Invalid credentials.\n";
        }
    } else {
        cout << "Invalid option.\n";
        return 0;
    }

    if (!loggedIn) return 0;

    char x, o;
    int choice;
    string u1 = username, u2;
    int menuChoice;
    vector<char> board(9);
    char playAgain;
    int aiLevel = 0;

    while (true) {
        GameUI::showRules();
        GameUI::showMainMenu();

        while (!(cin >> menuChoice) || menuChoice < 1 || menuChoice > 6) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << " " << warning << " Invalid input! Enter 1-6: " << RESET;
        }

        if (menuChoice == 4) {
            cout << "\n " << sparkle << " Thanks for playing! " << sparkle << "\n";
            break;
        }
        if (menuChoice == 3) {
            Leaderboard::showLeaderboard();
            continue;
        }
        if (menuChoice == 5) {
            ifstream history("history.txt");
            if (!history) {
                cout << RED << " No match history found.\n" << RESET;
            } else {
                cout << CYAN << "\n--- My Game History ---\n" << RESET;
                string line;
                while (getline(history, line)) {
                    if (line.find(u1) != string::npos || line.find("Match:") != string::npos || line.find("Result:") != string::npos)
                        cout << line << endl;
                }
            }
            continue;
        }
        if (menuChoice == 6) {
            replayLastMatch();
            continue;
        }

        GameLogic::clearScreen();

        if (menuChoice == 1) {
            cout << " " << person << " Enter name of player 2: ";
            cin >> u2;
        } else {
            u2 = "Computer";
            cout << "\n " << robot << " Select AI difficulty:\n";
            cout << " " << dice << " 1. Easy\n";
            cout << " " << brain << " 2. Medium\n";
            cout << " " << genius << " 3. Hard\n";
            cout << " " << check << " Enter choice (1-3): ";
            while (!(cin >> aiLevel) || aiLevel < 1 || aiLevel > 3) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << RED << " " << warning << " Invalid input! Enter 1-3: " << RESET;
            }
        }

        GameUI::selectSymbol(x, o, u1);

        do {
            board = {'1','2','3','4','5','6','7','8','9'};
            vector<int> usedMoves;
            int currentPlayer = 1;
            int score = -1;

            string historyFile = "history.txt";
            ofstream history(historyFile, ios::app);
            history << "\nMatch: " << u1 << " vs " << u2 << "\n";

            while (score == -1) {
                GameLogic::displayColorfulBoard(x, o, u1, u2, board);

                if (currentPlayer == 1 || menuChoice == 1) {
                    cout << " " << (currentPlayer == 1 ? u1 : u2) << ", enter position (1-9): ";
                    while (!(cin >> choice) || choice < 1 || choice > 9 ||
                        !AILogic::isMoveValid(usedMoves, choice) || board[choice-1] == 'X' || board[choice-1] == 'O') {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << RED << " " << warning << " Invalid move! Try again: " << RESET;
                    }
                } else {
                    switch (aiLevel) {
                        case 1: AILogic::easyAI(board, usedMoves, choice); break;
                        case 2: AILogic::mediumAI(board, usedMoves, choice, o, x); break;
                        case 3: AILogic::hardAI(board, usedMoves, choice, o); break;
                    }
                    cout << " " << robot << " Computer chooses position " << choice << "\n";
                    GameLogic::wait(500);
                }

                usedMoves.push_back(choice);
                board[choice-1] = (currentPlayer == 1) ? x : o;
                history << (currentPlayer == 1 ? u1 : u2) << " played " << choice << "\n";
                score = GameLogic::checkWin(board);
                currentPlayer = (currentPlayer % 2) + 1;
            }

            GameLogic::displayColorfulBoard(x, o, u1, u2, board);

            string winner;
            if (score == 1) {
                winner = (currentPlayer == 1) ? u2 : u1;
                cout << GREEN << "\n " << trophy << " " << winner << " wins! " << trophy << "\n" << RESET;
            } else {
                winner = "DRAW";
                cout << YELLOW << "\n " << handshake << " It's a draw! " << handshake << "\n" << RESET;
            }

            Leaderboard::updateLeaderboard(u1, u2, winner);
            history << "Result: " << winner << "\n";
            history << "-----------------------------\n";
            history.close();

            cout << "\n " << star << " Play again with same players? (y/n): ";
            cin >> playAgain;
        } while (tolower(playAgain) == 'y');
    }

    return 0;
}
