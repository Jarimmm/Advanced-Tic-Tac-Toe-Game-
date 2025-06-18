/*
 * leaderboard.h
 *
 *  Created on: Apr 28, 2025
 *      Author: Mariam Samy
 */

#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <string>
#include <map>
#include <vector>

class Leaderboard {
public:
    static void showLeaderboard();
    static void updateLeaderboard(const std::string &player1, const std::string &player2,
                                const std::string &result);
};

#endif
