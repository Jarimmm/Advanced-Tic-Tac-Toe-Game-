#include "../include/leaderboard.h"
#include "../include/game_constants.h"
#include "../include/game_logic.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void Leaderboard::showLeaderboard() {
    GameLogic::clearScreen();
    cout << GOLD << BOLD << "\n\t" << trophy << " LEADERBOARD " << trophy << RESET << "\n\n";
    cout << " " << string(60, '=') << "\n";
    cout << " " << setw(6) << left << "RANK"
         << setw(20) << left << "PLAYER"
         << setw(10) << "WINS"
         << setw(10) << "LOSSES"
         << setw(10) << "DRAWS" << "\n";
    cout << " " << string(60, '=') << "\n";

    ifstream scoreFile("score.txt");
    if (!scoreFile) {
        cout << " No game records found.\n";
        return;
    }

    map<string, vector<int>> stats;
    string line;

    while (getline(scoreFile, line)) {
        if (line.empty()) continue;

        size_t pos1 = line.find('\t');
        size_t pos2 = line.find('\t', pos1 + 1);
        if (pos1 == string::npos || pos2 == string::npos) continue;

        string player1 = line.substr(0, pos1);
        string player2 = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string result = line.substr(pos2 + 1);

        if (stats.find(player1) == stats.end()) stats[player1] = {0, 0, 0};
        if (stats.find(player2) == stats.end()) stats[player2] = {0, 0, 0};

        if (result == "DRAW") {
            stats[player1][2]++;
            stats[player2][2]++;
        } else {
            stats[result][0]++;
            string loser = (result == player1) ? player2 : player1;
            stats[loser][1]++;
        }
    }

    vector<pair<string, vector<int>>> sortedStats(stats.begin(), stats.end());

    sort(sortedStats.begin(), sortedStats.end(), [](const auto& a, const auto& b) {
        if (a.second[0] != b.second[0])
            return a.second[0] > b.second[0];
        return a.second[1] < b.second[1];
    });

    int rank = 1;
for (const auto& entry : sortedStats) {
    string rankLabel;
    if (rank < 10)
        rankLabel = " " + to_string(rank) + ".";
    else
        rankLabel = to_string(rank) + ".";

    int wins = entry.second[0];
    int losses = entry.second[1];
    int draws = entry.second[2];

    cout << " " << setw(6) << left << rankLabel
         << setw(20) << left << entry.first << "  ";

    cout << GREEN   << setw(10) << right << wins << RESET;
    cout << RED     << setw(10) << right << losses << RESET;
    cout << YELLOW  << setw(10) << right << draws << RESET;

    cout << "\n";
    rank++;
}


    scoreFile.close();
    cout << " " << string(60, '=') << endl;
    cout << "\n " << star << " Press Enter to continue...";
    cin.ignore();
    cin.get();
}

void Leaderboard::updateLeaderboard(const string &player1, const string &player2,
                                  const string &result) {
    ofstream scoreFile("score.txt", ios::app);
    scoreFile << player1 << "\t" << player2 << "\t" << result << "\n";
    scoreFile.close();
}
