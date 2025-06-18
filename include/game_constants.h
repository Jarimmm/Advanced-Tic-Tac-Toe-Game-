/*
 * constants.h
 *
 *  Created on: Apr 28, 2025
 *      Author: Mariam Samy
 *   Edited on: Jun 15, 2025
 *      Editor: Rana Youssef
 */

#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

#include <string>

// Color & Emoji Constants
const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";

// Player Symbols
const std::string crossIcon = u8"❌ ";
const std::string circleIcon = u8"⭕ ";

// Game Icons
const std::string trophy = u8"🏆";
const std::string fire = u8"🔥";
const std::string star = u8"⭐";
const std::string sparkle = u8"✨";
const std::string warning = u8"⚠ ";
const std::string check = u8"✅ ";
const std::string robot = u8"🤖";
const std::string person = u8"👤";
const std::string dice = u8"🎲";
const std::string brain = u8"🧠";
const std::string genius = u8"🎯";
const std::string handshake = u8"🤝";
const std::string linkIcon = u8"🔗";
const std::string clockIcon = u8"⏱ ";
const std::string confetti = u8"🎊";
const std::string rainbow = u8"🌈";
const std::string book = u8"📖";
const std::string tree = u8"🌳";

// Color Codes
const std::string RED = "\033[38;5;196m";
const std::string BLUE = "\033[38;5;39m";
const std::string GREEN = "\033[38;5;46m";
const std::string YELLOW = "\033[38;5;226m";
const std::string PURPLE = "\033[38;5;129m";
const std::string CYAN = "\033[38;5;51m";
const std::string PINK = "\033[38;5;201m";
const std::string ORANGE = "\033[38;5;208m";
const std::string GOLD = "\033[38;5;220m";
const std::string MAGENTA = "\033[38;5;135m";



// Board Design Elements
const std::string horizontalLine = u8"───────────────";
const std::string verticalLine = u8"│";
const std::string cornerTL = u8"╔";
const std::string cornerTR = u8"╗";
const std::string cornerBL = u8"╚";
const std::string cornerBR = u8"╝";
const std::string cross = u8"╬";
const std::string tee = u8"╠";

#endif
