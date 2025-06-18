#include "../include/game_ui.h"
#include "../include/game_constants.h"
#include "../include/game_logic.h"
#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

void GameUI::showRules() {
    GameLogic::clearScreen();
    cout << ORANGE << BOLD << "\n\t" << star << " GAME RULES " << star << RESET << "\n\n";
    cout << " " << person << " Players take turns placing " << crossIcon << " or " << circleIcon << "\n";
    cout << " " << trophy << " First to get 3 in a row wins!\n";
    cout << " " << handshake << " Full board = Draw\n";
    cout << " " << fire << " Control center and corners!\n\n";

    char choice;
    cout << " " << link << " View tutorial? (Y/N): ";
    cin >> choice;
    if (tolower(choice) == 'y') {
#ifdef _WIN32
        system("start https://www.wikihow.com/Play-Tic-Tac-Toe");
#else
        system("xdg-open https://www.wikihow.com/Play-Tic-Tac-Toe");
#endif
    }
}

void GameUI::showMainMenu() {
    GameLogic::clearScreen();
    cout << CYAN << BOLD << "\n\t" << rainbow << " THE MAIN MENU " << rainbow << RESET << "\n\n";
    cout << " " << person    << " " << PINK    << "1. Human vs Human\n"      << RESET;
    cout << " " << robot     << " " << BLUE    << "2. Human vs Computer\n"   << RESET;
    cout << " " << trophy    << " " << YELLOW  << "3. Leaderboard\n"         << RESET;
    cout << " " << warning   << " " << RED     << "4. Exit Game\n"           << RESET;
    cout << " " << book      << " " << MAGENTA << "5. View My History\n"     << RESET;
    cout << " " << tree     << " " << BLUE << "6. Replay My Last Match\n" << RESET;
    cout << "\n " << check   << " Enter choice (1-6): ";
}
bool GameUI::selectSymbol(char &x, char &o, const string &u1) {
    char dec;
    cout << " " << u1 << ", choose " << crossIcon << " (X) or " << circleIcon << " (O): ";
    while (!(cin >> dec) || (toupper(dec) != 'X' && toupper(dec) != 'O')) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << " " << warning << " Invalid choice! Enter X or O: " << RESET;
    }

    x = toupper(dec);
    o = (x == 'X') ? 'O' : 'X';
    return true;
}

