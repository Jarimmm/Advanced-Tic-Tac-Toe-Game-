#ifndef LEADERBOARD_QT_H
#define LEADERBOARD_QT_H

#include <string>

class LeaderboardQt {
public:
    static void updateLeaderboard(const std::string& player1, const std::string& player2, const std::string& result);
};

#endif // LEADERBOARD_QT_H
