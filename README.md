Tic-Tac-Toe Game
Project Overview
This is an advanced Tic-Tac-Toe game developed as part of the Data Structures and Embedded Systems Project for Spring 2025 at [University Name]. The project implements a console-based Tic-Tac-Toe game in C++ with user authentication, personalized game history, and AI opponents with three difficulty levels (Easy, Medium, Hard). It employs object-oriented programming, unit testing with Google Test, and a CI/CD pipeline using GitHub Actions. The game supports human vs. human and human vs. AI gameplay, saves game history to history.txt, and allows users to replay their last match.
Team Members

مريم سامي راغب عطا (ID: 9220822)
ماركو شنوده ثابت اسعد (ID: 9230707)
رنا يوسف عبدالله صالح (ID: 9230373)
اميرة سامح عبدالحليم سيد (ID: 9230246)
ريم حسين احمد بسيوني (ID: 9230384)

Objectives

Develop a console-based Tic-Tac-Toe game with a user-friendly interface.
Implement secure user authentication for registration and login.
Create a challenging AI opponent using strategic algorithms (e.g., minimax with alpha-beta pruning).
Enable game history saving and replay functionality.
Use Google Test for unit and integration testing to ensure code quality.
Integrate a CI/CD pipeline with GitHub Actions for automated building, testing, and deployment.

Features

User Authentication: Register and login with unique usernames and passwords.
Game Modes:
Human vs. Human: Play against another player.
Human vs. AI: Play against an AI with Easy, Medium, or Hard difficulty.


Game History: Save game moves and results to history.txt and replay the last match.
Leaderboard: Track and display player wins and draws.
Console UI: Colorful board display using ANSI color codes for an intuitive experience.
Input Validation: Graceful handling of invalid inputs.
Performance: Optimized for low CPU usage (0.1%) and reasonable memory usage (~377.5 MB).

Prerequisites

A modern C++ compiler (e.g., g++ with C++17 support).
CMake (version 3.10 or higher).
Google Test (libgtest-dev) for running tests.
Linux (recommended for deployment) or Windows (with UTF-8 console support).
Git for version control.

Setup Instructions
Clone the Repository
git clone https://github.com/[your-username]/tictactoe.git
cd tictactoe

Install Dependencies
On Ubuntu:
sudo apt-get update
sudo apt-get install -y g++ cmake libgtest-dev

On Windows:

Install a C++ compiler (e.g., MSVC via Visual Studio).
Install CMake: choco install cmake (using Chocolatey).
Install Google Test manually or via a package manager.

Build the Project
mkdir build
cd build
cmake ..
cmake --build .

This creates the TicTacToe executable and TicTacToeTests for running tests.
Run the Game
./TicTacToe

Run Tests
cd build
ctest --output-on-failure

Usage

Start the Game:

Run ./TicTacToe (Linux) or TicTacToe.exe (Windows).
Choose 1 to register or 2 to login.
Enter a username and password.


Main Menu:

1: Play Human vs. Human (enter second player’s name).
2: Play Human vs. AI (select difficulty: Easy, Medium, Hard).
3: View leaderboard.
4: Exit.
5: View your game history.
6: Replay the last match.


Gameplay:

Select your symbol (X or O).
Enter a position (1–9) to place your symbol.
The game validates moves and announces the winner or draw.
Game history is saved to history.txt.


Replay Last Match:

Choose option 6 to replay the last match from history.txt, showing each move with a 1-second delay.



CI/CD Pipeline
The project uses GitHub Actions for Continuous Integration (CI) and Continuous Deployment (CD):

CI:
Triggered on push to main or pull_request.
Builds the project using CMake.
Runs Google Test suite via ctest.
Uploads the TicTacToe executable and history.txt as artifacts.


CD:
Triggered on tagged pushes (e.g., git tag v1.0.0 && git push origin v1.0.0).
Creates a GitHub Release with the executable (TicTacToe-<tag>-linux) and history.txt (if available).
Artifacts are downloadable from the Releases page for the live presentation.



To create a release:
git tag v1.0.0
git push origin v1.0.0

File Structure
tictactoe/
├── include/           # Header files
│   ├── User.h
│   ├── UserManager.h
│   ├── game_logic.h
│   ├── game_ui.h
│   ├── ai_logic.h
│   ├── leaderboard.h
│   ├── game_constants.h
├── src/              # Source files
│   ├── main.cpp
│   ├── *.cpp        # Other implementation files
├── tests/            # Test files
│   ├── *.cpp
├── CMakeLists.txt    # CMake configuration
├── history.txt       # Game history file
├── .github/workflows/ci-cd.yml  # GitHub Actions workflow
├── README.md         # This file
├── docs/             # Documentation (SRS, SDS, etc.)

Performance Optimizations

Array Consideration: The game uses vector<char> for the board; consider switching to char[9] for lower overhead (as noted in Performance Measurement and Optimization).
AI Efficiency: Uses minimax with alpha-beta pruning for Hard difficulty, ensuring AI moves within 2 seconds.
File Handling: history.txt is opened efficiently, but further optimization could avoid repeated opens.
Memory Usage: ~377.5 MB, CPU utilization: 0.1%.
Input Validation: Reusable validation reduces code repetition.

Known Limitations

Console-Based UI: Currently uses ANSI colors instead of a Qt GUI, deviating from the project’s GUI requirement. A Qt implementation may be in progress.
File-Based Storage: Uses history.txt instead of SQLite for game history. SQLite integration is planned for user data and leaderboards.
Platform Support: Primarily tested on Linux; Windows requires UTF-8 console settings (chcp 65001).

Future Improvements

Implement a Qt-based GUI for cross-platform compatibility.
Integrate SQLite for user data and leaderboard storage.
Add Windows builds to the CI/CD pipeline.
Optimize memory usage further by using arrays and reducing vector overhead.

Contributing

Follow Google C++ Style Guidelines.
Write unit tests for new features using Google Test.
Submit pull requests with clear descriptions.
Ensure all tests pass in the CI pipeline.

Documentation

SRS: Details functional and non-functional requirements (docs/SRS.docx).
SDS: Includes flowcharts, sequence diagrams, and class diagrams (docs/SDS.docx).
Testing: Unit and integration test cases in tests/.
Performance: Optimization report in docs/Performance Measurement and Optimization.docx.

License
This project is for educational purposes and not distributed under a specific license.
Acknowledgments

Developed under the guidance of Dr. Omar Nasr.
Inspired by resources like wikiHow.
Built with assistance from online tools and references (properly cited in project documentation).


For issues or questions, contact the team via GitHub Issues or [team email].
