/*
 * game_ui.h
 *
 *  Created on: Apr 28, 2025
 *      Author: Mariam Samy
 */

#ifndef GAME_UI_H
#define GAME_UI_H

#include <string>

class GameUI {
public:
    static void showRules();
    static void showMainMenu();
    static bool selectSymbol(char &x, char &o, const std::string &u1);
};

#endif
