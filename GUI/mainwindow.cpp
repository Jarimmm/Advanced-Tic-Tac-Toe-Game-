#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "UserManager_qt.h"
#include "User.h"
#include "game_logic.h"
#include "ai_logic.h"
#include "leaderboard_qt.h"
#include "StyleManager.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QTimer>
#include <QTableWidget>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMap>
#include <QVector>
#include <QPair>
#include <QTableWidgetItem>
#include <QApplication>
#include <QScreen>
#include <algorithm>

QChar MainWindow::getPlayer1Symbol() const { return player1Symbol; }
QChar MainWindow::getPlayer2Symbol() const { return player2Symbol; }
void MainWindow::setPlayer1Symbol(QChar s) { player1Symbol = s; }
void MainWindow::setPlayer2Symbol(QChar s) { player2Symbol = s; }

QString getProjectFilePath(const QString& fileName, bool createIfNotFound = false)
{
    QDir dir(QCoreApplication::applicationDirPath());
    QString projectRoot;
    int maxLevels = 5;

    for (int i = 0; i < maxLevels; ++i) {
        QStringList txtFiles = dir.entryList({"*.txt", "*.pro"}, QDir::Files);
        if (!txtFiles.isEmpty()) {
            projectRoot = dir.absolutePath();
            QString path = dir.filePath(fileName);
            if (QFile::exists(path)) {
                qDebug() << "Found" << fileName << "at:" << path;
                return path;
            }
            break;
        }
        dir.cdUp();
    }

    if (createIfNotFound && !projectRoot.isEmpty()) {
        QString newPath = QDir(projectRoot).filePath(fileName);
        qDebug() << "Creating" << fileName << "at:" << newPath;
        return newPath;
    }

    qDebug() << "Could not find or create" << fileName;
    return QString();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->leaderboardTable->setObjectName("leaderboardTable");


    // Set window title and make fullscreen
    setWindowTitle("Tic Tac Toe - Ultimate Game");
    showMaximized();

    // Apply modern styling to the main window and application
    StyleManager::applyMainWindowStyle(this);
    StyleManager::applyApplicationStyle(qApp);

    // Initialize board with placeholders '1' to '9'
    for (int i = 1; i <= 9; ++i)
        board.push_back('0' + i);

    currentPlayer = 1;

    boardButtons = {
        ui->cell00, ui->cell01, ui->cell02,
        ui->cell10, ui->cell11, ui->cell12,
        ui->cell20, ui->cell21, ui->cell22
    };

    for (int i = 0; i < 9; ++i) {
        connect(boardButtons[i], &QPushButton::clicked, this, [this, i]() {
            if (player2Name == "Computer") {
                handlePlayerMove(i + 1);
            } else {
                if (currentPlayer == 1) {
                    handlePlayerMove(i + 1);
                } else {
                    handlePlayer2Move(i + 1);
                }
            }
        });
    }

    connect(ui->pushButton_NewG, &QPushButton::clicked, this, &MainWindow::on_pushButton_NewG_clicked);
    updateBoardDisplay();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showStyledMessageBox(const QString &title, const QString &message, QMessageBox::Icon icon)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setText(message);
    msgBox.setIcon(icon);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);

    QRect screenGeometry = QApplication::primaryScreen()->geometry();
    int x = (screenGeometry.width() - msgBox.width()) / 2;
    int y = (screenGeometry.height() - msgBox.height()) / 2;
    msgBox.move(x, y);

    msgBox.exec();
}

QString MainWindow::showStyledInputDialog(const QString &title, const QString &label, const QString &defaultText)
{
    bool ok;
    QString result = QInputDialog::getText(this, title, label, QLineEdit::Normal, defaultText, &ok);
    return ok ? result.trimmed() : QString();
}

QString MainWindow::determineWinner(const std::vector<char>& board)
{
    // Same winning combinations as in GameLogic::checkWin
    const int winCombos[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}            // Diagonals
    };

    for (const auto& combo : winCombos) {
        if (board[combo[0]] == board[combo[1]] && board[combo[1]] == board[combo[2]]) {
            char winningSymbol = board[combo[0]];
            if (winningSymbol == player1Symbol.toLatin1()) {
                return player1Name;
            } else if (winningSymbol == player2Symbol.toLatin1()) {
                return player2Name;
            }
        }
    }
    return "DRAW"; // Fallback, should not reach here if called after checkWin == 1
}

void MainWindow::on_login_clicked()
{
    QString username_qt = ui->usernameEdit->text().trimmed();
    QString password_qt = ui->passwordEdit->text().trimmed();

    std::string username = username_qt.toStdString();
    std::string password = password_qt.toStdString();

    if (UserManagerQt::loginUser(username, password)) {
        showStyledMessageBox("Login Success", "Welcome back, " + username_qt + "!", QMessageBox::Information);
        ui->stackedWidget->setCurrentIndex(1);
    } else {
        showStyledMessageBox("Login Failed", "Invalid username or password.\nPlease try again.", QMessageBox::Warning);
    }
}

void MainWindow::on_RegisterButton_clicked()
{
    QString username = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text().trimmed();

    if (username.isEmpty() || password.isEmpty()) {
        showStyledMessageBox("Input Error", "Please enter both username and password.", QMessageBox::Warning);
        return;
    }

    bool success = UserManagerQt::registerUser(User(username.toStdString(), password.toStdString()));

    if (success) {
        showStyledMessageBox("Registration Success", "Welcome to Tic Tac Toe, " + username + "!\nYour account has been created successfully.", QMessageBox::Information);
        ui->stackedWidget->setCurrentIndex(1);
    } else {
        showStyledMessageBox("Registration Failed", "Username '" + username + "' already exists!\nPlease choose a different username.", QMessageBox::Critical);
    }
}

void MainWindow::on_pushButton_GRules_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_Back_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_PvP_clicked()
{
    player1Name = ui->usernameEdit->text().trimmed();

    QString player2Input = showStyledInputDialog("Player vs Player", "Enter Player 2 Name:", "");
    if (player2Input.isEmpty()) {
        showStyledMessageBox("Input Error", "Player 2 name is required for PvP mode.", QMessageBox::Warning);
        return;
    }
    player2Name = player2Input;

    QStringList symbolOptions;
    symbolOptions << "X" << "O";
    QString selectedSymbol = QInputDialog::getItem(this, "Choose Your Symbol",
                                                   player1Name + ", select your preferred symbol:", symbolOptions, 0, false);

    if (selectedSymbol.isEmpty()) {
        showStyledMessageBox("Input Error", "You must choose either X or O to continue.", QMessageBox::Warning);
        return;
    }

    player1Symbol = selectedSymbol[0].toUpper();
    player2Symbol = (player1Symbol == 'X') ? 'O' : 'X';

    setupGameBoard();

    QString historyPath = getProjectFilePath(player1Name + "_history.txt", true);
    if (!historyPath.isEmpty()) {
        QFile file(historyPath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
            QTextStream out(&file);
            out << "Match: " << player1Name << " vs " << player2Name << "\n";
            file.close();
        }
    }

    ui->stackedWidget->setCurrentIndex(3);
    updateBoardDisplay();
}

void MainWindow::on_pushButton_PvC_clicked()
{
    player1Name = ui->usernameEdit->text().trimmed();
    player2Name = "Computer";

    QMessageBox diffBox;
    diffBox.setWindowTitle("AI Difficulty Selection");
    diffBox.setText("Choose your challenge level:");
    QPushButton *easy = diffBox.addButton("Easy", QMessageBox::ActionRole);
    QPushButton *medium = diffBox.addButton("Medium", QMessageBox::ActionRole);
    QPushButton *hard = diffBox.addButton("Hard", QMessageBox::ActionRole);
    diffBox.exec();

    if (diffBox.clickedButton() == easy) aiLevel = 1;
    else if (diffBox.clickedButton() == medium) aiLevel = 2;
    else if (diffBox.clickedButton() == hard) aiLevel = 3;

    QMessageBox symbolBox;
    symbolBox.setWindowTitle("Symbol Selection");
    symbolBox.setText(player1Name + ", choose your battle symbol:");
    QPushButton *x = symbolBox.addButton("X", QMessageBox::ActionRole);
    QPushButton *o = symbolBox.addButton("O", QMessageBox::ActionRole);
    symbolBox.exec();

    if (symbolBox.clickedButton() == x) {
        player1Symbol = 'X';
        player2Symbol = 'O';
    } else if (symbolBox.clickedButton() == o) {
        player1Symbol = 'O';
        player2Symbol = 'X';
    }

    setupGameBoard();

    QString historyPath = getProjectFilePath(player1Name + "_history.txt", true);
    if (!historyPath.isEmpty()) {
        QFile file(historyPath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
            QTextStream out(&file);
            out << "Match: " << player1Name << " vs " << player2Name << "\n";
            file.close();
        }
    }

    ui->stackedWidget->setCurrentIndex(3);
    updateBoardDisplay();
}

void MainWindow::promptNextTurn()
{
    QString currentPlayerName = (currentPlayer == 1) ? player1Name : player2Name;
    QChar symbol = (currentPlayer == 1) ? player1Symbol : player2Symbol;
    QString text;
    if (player2Name == "Computer" && currentPlayer == 2) {
        text = "🖥 Computer's Turn (" + QString(symbol) + ")";
    } else {
        text = "🎮 " + currentPlayerName + "'s Turn (" + QString(symbol) + ")";
    }
    StyleManager::applyTurnLabelStyle(ui->label_turn, text, false);
}

void MainWindow::handlePlayerMove(int position)
{
    int index = position - 1;
    if (GameLogic::checkWin(board) != -1)
        return;
    if (board[index] == 'X' || board[index] == 'O') {
        showStyledMessageBox("Invalid Move", "This position is already occupied!\nPlease choose an empty spot.", QMessageBox::Warning);
        return;
    }

    board[index] = player1Symbol.toLatin1();
    updateBoardDisplay();

    QString historyPath = getProjectFilePath("history.txt", true);
    if (historyPath.isEmpty()) {
        showStyledMessageBox("Error", "Could not locate or create history.txt.", QMessageBox::Critical);
        return;
    }
    QFile file(historyPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        showStyledMessageBox("Error", "Could not write to history.txt at:\n" + historyPath, QMessageBox::Critical);
        return;
    }
    QTextStream out(&file);
    out << player1Name << " played " << position << "\n";
    file.close();

    QString userHistoryPath = getProjectFilePath(player1Name + "_history.txt", true);
    if (!userHistoryPath.isEmpty()) {
        QFile userFile(userHistoryPath);
        if (userFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
            QTextStream userOut(&userFile);
            userOut << player1Name << " played " << position << "\n";
            userFile.close();
        }
    }

    int result = GameLogic::checkWin(board);
    if (result != -1) {
        QString winner;
        if (result == 1) {
            winner = determineWinner(board);
        } else {
            winner = "DRAW";
        }

        QString gameOverMsg = (winner == "DRAW") ?
                                  "🤝 It's a Draw!\nBoth players played excellently!" :
                                  "🎉 " + winner + " Wins!\nCongratulations on your victory!";

        showStyledMessageBox("Game Over", gameOverMsg, QMessageBox::Information);
        LeaderboardQt::updateLeaderboard(player1Name.toStdString(), player2Name.toStdString(), winner.toStdString());

        QFile fileResult(historyPath);
        if (!fileResult.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
            showStyledMessageBox("Error", "Could not write to history.txt at:\n" + historyPath, QMessageBox::Critical);
            return;
        }
        QTextStream outResult(&fileResult);
        outResult << "Result: " << winner << "\n-----------------------------\n";
        fileResult.close();

        if (!userHistoryPath.isEmpty()) {
            QFile userFileResult(userHistoryPath);
            if (userFileResult.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
                QTextStream userOutResult(&userFileResult);
                userOutResult << "Result: " << winner << "\n-----------------------------\n";
                userFileResult.close();
            }
        }

        for (auto button : boardButtons)
            button->setEnabled(false);
        return;
    }

    if (player2Name == "Computer") {
        promptNextTurn();
        QTimer::singleShot(500, this, &MainWindow::handleComputerMove);
    } else {
        currentPlayer = 2;
        promptNextTurn();
    }
}

void MainWindow::handlePlayer2Move(int position)
{
    int index = position - 1;
    if (GameLogic::checkWin(board) != -1)
        return;
    if (board[index] == 'X' || board[index] == 'O') {
        showStyledMessageBox("Invalid Move", "This position is already occupied!\nPlease choose an empty spot.", QMessageBox::Warning);
        return;
    }

    board[index] = player2Symbol.toLatin1();
    updateBoardDisplay();

    QString historyPath = getProjectFilePath("history.txt", true);
    if (!historyPath.isEmpty()) {
        QFile file(historyPath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
            QTextStream out(&file);
            out << player2Name << " played " << position << "\n";
            file.close();
        }
    }

    QString userHistoryPath = getProjectFilePath(player1Name + "_history.txt", true);
    if (!userHistoryPath.isEmpty()) {
        QFile userFile(userHistoryPath);
        if (userFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
            QTextStream userOut(&userFile);
            userOut << player2Name << " played " << position << "\n";
            userFile.close();
        }
    }

    int result = GameLogic::checkWin(board);
    if (result != -1) {
        QString winner;
        if (result == 1) {
            winner = determineWinner(board);
        } else {
            winner = "DRAW";
        }

        QString gameOverMsg = (winner == "DRAW") ?
                                  "🤝 It's a Draw!\nBoth players played excellently!" :
                                  "🎉 " + winner + " Wins!\nCongratulations on your victory!";

        showStyledMessageBox("Game Over", gameOverMsg, QMessageBox::Information);
        LeaderboardQt::updateLeaderboard(player1Name.toStdString(), player2Name.toStdString(), winner.toStdString());

        QFile fileResult(historyPath);
        if (!fileResult.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
            showStyledMessageBox("Error", "Could not write to history.txt at:\n" + historyPath, QMessageBox::Critical);
            return;
        }
        QTextStream outResult(&fileResult);
        outResult << "Result: " << winner << "\n-----------------------------\n";
        fileResult.close();

        if (!userHistoryPath.isEmpty()) {
            QFile userFileResult(userHistoryPath);
            if (userFileResult.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
                QTextStream userOutResult(&userFileResult);
                userOutResult << "Result: " << winner << "\n-----------------------------\n";
                userFileResult.close();
            }
        }

        for (auto button : boardButtons)
            button->setEnabled(false);
        return;
    }

    currentPlayer = 1;
    promptNextTurn();
}

void MainWindow::handleComputerMove()
{
    // Indicate computer's turn
    currentPlayer = 2; // Set to computer
    promptNextTurn();

    // Add a slight delay to make the turn change visible
    QTimer::singleShot(300, this, [=]() {
        std::vector<int> usedMoves;
        for (int i = 0; i < 9; ++i)
            if (board[i] == 'X' || board[i] == 'O') usedMoves.push_back(i + 1);

        int choice = -1;
        switch (aiLevel) {
        case 1: AILogic::easyAI(board, usedMoves, choice); break;
        case 2: AILogic::mediumAI(board, usedMoves, choice, player2Symbol.toLatin1(), player1Symbol.toLatin1()); break;
        case 3: AILogic::hardAI(board, usedMoves, choice, player2Symbol.toLatin1()); break;
        }

        if (choice != -1)
            board[choice - 1] = player2Symbol.toLatin1();

        updateBoardDisplay();

        QString historyPath = getProjectFilePath("history.txt", true);
        if (historyPath.isEmpty()) {
            showStyledMessageBox("Error", "Could not locate or create history.txt.", QMessageBox::Critical);
            return;
        }
        QFile file(historyPath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
            showStyledMessageBox("Error", "Could not write to history.txt at:\n" + historyPath, QMessageBox::Critical);
            return;
        }
        QTextStream out(&file);
        out << "Computer played " << choice << "\n";
        file.close();

        QString userHistoryPath = getProjectFilePath(player1Name + "_history.txt", true);
        if (!userHistoryPath.isEmpty()) {
            QFile userFile(userHistoryPath);
            if (userFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
                QTextStream userOut(&userFile);
                userOut << "Computer played " << choice << "\n";
                userFile.close();
            }
        }

        int result = GameLogic::checkWin(board);
        if (result != -1) {
            QString winner;
            if (result == 1) {
                winner = determineWinner(board);
            } else {
                winner = "DRAW";
            }

            QString gameOverMsg = (winner == "DRAW") ?
                                      "🤝 It's a Draw!\nGreat match against the AI!" :
                                      "🎉 " + winner + " Wins!\n" + (winner == player1Name ? "Congratulations on beating the AI!" : "The AI got you this time! Try again?");

            showStyledMessageBox("Game Over", gameOverMsg, QMessageBox::Information);
            LeaderboardQt::updateLeaderboard(player1Name.toStdString(), player2Name.toStdString(), winner.toStdString());

            QFile fileResult(historyPath);
            if (!fileResult.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
                showStyledMessageBox("Error", "Could not write to history.txt at:\n" + historyPath, QMessageBox::Critical);
                return;
            }
            QTextStream outResult(&fileResult);
            outResult << "Result: " << winner << "\n-----------------------------\n";
            fileResult.close();

            if (!userHistoryPath.isEmpty()) {
                QFile userFileResult(userHistoryPath);
                if (userFileResult.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
                    QTextStream userOutResult(&userFileResult);
                    userOutResult << "Result: " << winner << "\n-----------------------------\n";
                    userFileResult.close();
                }
            }

            for (auto button : boardButtons)
                button->setEnabled(false);
            return;
        }

        // Switch back to player 1 and update the turn label
        currentPlayer = 1;
        promptNextTurn();
    });
}

void MainWindow::checkGameResult()
{
    int score = GameLogic::checkWin(board);
    QString winner;

    if (score == 1) {
        winner = determineWinner(board);
        QString winMsg = "🎉 " + winner + " Wins!\nCongratulations on your victory!";
        showStyledMessageBox("Game Over", winMsg, QMessageBox::Information);
    } else if (score == 0) {
        winner = "DRAW";
        showStyledMessageBox("Game Over", "🤝 It's a Draw!\nBoth players played excellently!", QMessageBox::Information);
    } else {
        return;
    }

    LeaderboardQt::updateLeaderboard(player1Name.toStdString(), player2Name.toStdString(), winner.toStdString());

    QString historyPath = getProjectFilePath("history.txt", true);
    if (historyPath.isEmpty()) {
        showStyledMessageBox("Error", "Could not locate or create history.txt.", QMessageBox::Critical);
        return;
    }
    QFile file(historyPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        showStyledMessageBox("Error", "Could not write to history.txt at:\n" + historyPath, QMessageBox::Critical);
        return;
    }
    QTextStream out(&file);
    out << "Result: " << winner << "\n-----------------------------\n";
    file.close();

    QString userHistoryPath = getProjectFilePath(player1Name + "_history.txt", true);
    if (!userHistoryPath.isEmpty()) {
        QFile userFile(userHistoryPath);
        if (userFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
            QTextStream userOut(&userFile);
            userOut << "Result: " << winner << "\n-----------------------------\n";
            userFile.close();
        }
    }

    for (auto button : boardButtons)
        button->setEnabled(false);
}

void MainWindow::setupGameBoard()
{
    board.clear();
    for (int i = 1; i <= 9; ++i)
        board.push_back('0' + i);

    currentPlayer = 1;
    promptNextTurn();
    updateBoardDisplay();

    for (auto button : boardButtons)
        button->setEnabled(true);
}

void MainWindow::updateBoardDisplay()
{
    for (int i = 0; i < 9; ++i) {
        QString text = (board[i] == 'X' || board[i] == 'O') ? QString(board[i]) : "";
        boardButtons[i]->setText(text);
        boardButtons[i]->setEnabled(board[i] != 'X' && board[i] != 'O');

        StyleManager::applyGameBoardButtonStyle(boardButtons[i], board[i]);
    }

    ui->label_5->setText("Player 1:");
    ui->lineEdit_2->setText(player1Name + " (" + player1Symbol + ")");

    ui->label_6->setText("Player 2:");
    ui->lineEdit_3->setText(player2Name + " (" + player2Symbol + ")");
}

void MainWindow::resetGame()
{
    setupGameBoard();
    for (auto button : boardButtons)
        button->setEnabled(true);
}

void MainWindow::on_pushButton_NewG_clicked()
{
    resetGame();

    QString historyPath = getProjectFilePath(player1Name + "_history.txt", true);
    if (!historyPath.isEmpty()) {
        QFile file(historyPath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
            QTextStream out(&file);
            out << "Match: " << player1Name << " vs " << player2Name << "\n";
            file.close();
        }
    }
}

void MainWindow::on_pushButton_BackToMenuFromGame_clicked()
{
    resetGame();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_Exit_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit Game",
                                  "Are you sure you want to quit?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        qApp->quit();
    } else {
        ui->stackedWidget->setCurrentIndex(1);
    }
}

void MainWindow::on_pushButton_ViewTutorial_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.wikihow.com/Play-Tic-Tac-Toe"));
}

void MainWindow::loadLeaderboardToTable()
{
    QString filePath = getProjectFilePath("score.txt");
    if (filePath.isEmpty()) {
        showStyledMessageBox("Leaderboard Error", "Could not locate score.txt in project folder.\nPlease ensure the file exists.", QMessageBox::Warning);
        return;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        showStyledMessageBox("File Access Error", "Could not open score.txt at:\n" + filePath + "\n\nPlease check file permissions.", QMessageBox::Critical);
        return;
    }

    QTextStream in(&file);
    QMap<QString, QVector<int>> stats;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList parts = line.split('\t', Qt::SkipEmptyParts);
        if (parts.size() != 3) continue;

        QString player1 = parts[0].trimmed();
        QString player2 = parts[1].trimmed();
        QString result = parts[2].trimmed();

        if (!stats.contains(player1)) stats[player1] = {0, 0, 0};
        if (!stats.contains(player2)) stats[player2] = {0, 0, 0};

        if (result == "DRAW") {
            stats[player1][2]++;
            stats[player2][2]++;
        } else {
            stats[result][0]++;
            QString loser = (result == player1) ? player2 : player1;
            stats[loser][1]++;
        }
    }

    file.close();

    QList<QPair<QString, QVector<int>>> sortedStats;
    for (auto it = stats.begin(); it != stats.end(); ++it)
        sortedStats.append(qMakePair(it.key(), it.value()));

    std::sort(sortedStats.begin(), sortedStats.end(), [](const auto &a, const auto &b) {
        if (a.second[0] != b.second[0]) return a.second[0] > b.second[0];
        return a.second[1] < b.second[1];
    });

    StyleManager::applyLeaderboardTableStyle(ui->leaderboardTable);

    ui->leaderboardTable->clearContents();
    ui->leaderboardTable->setRowCount(sortedStats.size());
    ui->leaderboardTable->setColumnCount(5);
    ui->leaderboardTable->setHorizontalHeaderLabels({"🏆 Rank", "👤 Player", "🎯 Wins", "💔 Losses", "🤝 Draws"});

    ui->leaderboardTable->setAlternatingRowColors(true);

    for (int i = 0; i < sortedStats.size(); ++i) {
        const auto &entry = sortedStats[i];

        QTableWidgetItem *rankItem = new QTableWidgetItem();
        if (i == 0) {
            rankItem->setText("🥇 1st");
            rankItem->setForeground(QBrush(QColor("#f39c12")));
        } else if (i == 1) {
            rankItem->setText("🥈 2nd");
            rankItem->setForeground(QBrush(QColor("#95a5a6")));
        } else if (i == 2) {
            rankItem->setText("🥉 3rd");
            rankItem->setForeground(QBrush(QColor("#cd7f32")));
        } else {
            rankItem->setText(QString::number(i + 1));
        }
        rankItem->setTextAlignment(Qt::AlignCenter);
        rankItem->setFont(QFont("Segoe UI", 12, QFont::Bold));

        QTableWidgetItem *playerItem = new QTableWidgetItem("🎮 " + entry.first);
        playerItem->setFont(QFont("Segoe UI", 11, QFont::Medium));
        playerItem->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);

        QTableWidgetItem *winsItem = new QTableWidgetItem(QString::number(entry.second[0]));
        winsItem->setTextAlignment(Qt::AlignCenter);
        winsItem->setForeground(QBrush(QColor("#27ae60")));
        winsItem->setFont(QFont("Segoe UI", 11, QFont::Bold));

        QTableWidgetItem *lossesItem = new QTableWidgetItem(QString::number(entry.second[1]));
        lossesItem->setTextAlignment(Qt::AlignCenter);
        winsItem->setForeground(QBrush(QColor("#e74c3c")));
        winsItem->setFont(QFont("Segoe UI", 11, QFont::Bold));

        QTableWidgetItem *drawsItem = new QTableWidgetItem(QString::number(entry.second[2]));
        drawsItem->setTextAlignment(Qt::AlignCenter);
        drawsItem->setForeground(QBrush(QColor("#f39c12")));
        drawsItem->setFont(QFont("Segoe UI", 11, QFont::Bold));

        ui->leaderboardTable->setItem(i, 0, rankItem);
        ui->leaderboardTable->setItem(i, 1, playerItem);
        ui->leaderboardTable->setItem(i, 2, winsItem);
        ui->leaderboardTable->setItem(i, 3, lossesItem);
        ui->leaderboardTable->setItem(i, 4, drawsItem);
    }

    ui->leaderboardTable->resizeColumnsToContents();
    ui->leaderboardTable->horizontalHeader()->setStretchLastSection(true);

    if (sortedStats.size() > 0) {
        showStyledMessageBox("📊 Leaderboard Loaded",
                             QString("Successfully loaded leaderboard with %1 players!\n\n"
                                     "🏆 Current Champion: %2\n"
                                     "🎯 Total Wins: %3")
                                 .arg(sortedStats.size())
                                 .arg(sortedStats.first().first)
                                 .arg(sortedStats.first().second[0]),
                             QMessageBox::Information);
    }
}

void MainWindow::on_LeaderBoardButton_clicked()
{
    loadLeaderboardToTable();
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_Back_fromLB_toMenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_ReplayMatch_clicked()
{
    QString currentUser = ui->usernameEdit->text().trimmed();
    if (currentUser.isEmpty()) {
        showStyledMessageBox("🔐 Authentication Required", "Please log in to access match replay functionality.\n\nThis feature requires user authentication.", QMessageBox::Warning);
        return;
    }

    QString historyFile = getProjectFilePath(currentUser + "_history.txt");
    if (historyFile.isEmpty()) {
        showStyledMessageBox("📝 No Match History", "No replayable matches found for user: " + currentUser + "\n\nPlay some games first to build your match history!", QMessageBox::Information);
        return;
    }

    QFile file(historyFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        showStyledMessageBox("📁 File Access Error", "Could not access your match history file at:\n" + historyFile + "\n\nPlease check file permissions.", QMessageBox::Critical);
        return;
    }

    QTextStream in(&file);
    QStringList allLines;
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (!line.isEmpty())
            allLines.append(line);
    }
    file.close();

    QStringList lastMatch;
    bool foundResult = false;
    QString matchLine;
    for (int i = allLines.size() - 1; i >= 0; --i) {
        const QString &line = allLines[i];
        lastMatch.prepend(line);
        if (line.startsWith("Match:")) {
            matchLine = line;
        }
        if (line.startsWith("Result:")) {
            foundResult = true;
        } else if (line.startsWith("Match:") && foundResult) {
            break;
        }
    }

    if (!foundResult || !lastMatch.first().startsWith("Match:")) {
        showStyledMessageBox("🎮 No Complete Matches", "No completed matches found to replay for user: " + currentUser + "\n\nFinish a game first to enable replay functionality!", QMessageBox::Information);
        return;
    }

    QString replayPlayer1, replayPlayer2;
    if (matchLine.startsWith("Match:")) {
        QStringList matchParts = matchLine.mid(6).trimmed().split(" vs ", Qt::SkipEmptyParts);
        if (matchParts.size() == 2) {
            replayPlayer1 = matchParts[0].trimmed();
            replayPlayer2 = matchParts[1].trimmed();
        }
    }

    if (player1Symbol.isNull() || player1Symbol == QChar()) {
        player1Symbol = 'X';
        player2Symbol = 'O';
    }
    if (replayPlayer1.isEmpty()) replayPlayer1 = currentUser;
    if (replayPlayer2.isEmpty()) replayPlayer2 = (replayPlayer1 == currentUser) ? "Opponent" : currentUser;

    showStyledMessageBox("🎬 Match Replay Starting",
                         QString("Replaying match: %1 vs %2\n\n"
                                 "🎮 Sit back and watch the action unfold!\n"
                                 "⏱️ Each move will be shown at 1-second intervals.")
                             .arg(replayPlayer1).arg(replayPlayer2),
                         QMessageBox::Information);

    QString savedPlayer1Name = player1Name;
    QString savedPlayer2Name = player2Name;
    player1Name = replayPlayer1;
    player2Name = replayPlayer2;

    board = {'1','2','3','4','5','6','7','8','9'};
    for (auto button : boardButtons)
        button->setEnabled(false);
    updateBoardDisplay();
    ui->stackedWidget->setCurrentIndex(3);

    StyleManager::applyTurnLabelStyle(ui->label_turn, "🎬 REPLAY MODE - Watch the Match Unfold", true);

    QTimer *replayTimer = new QTimer(this);
    int step = 0;

    connect(replayTimer, &QTimer::timeout, this, [=]() mutable {
        if (step >= lastMatch.size()) {
            replayTimer->stop();
            replayTimer->deleteLater();
            player1Name = savedPlayer1Name;
            player2Name = savedPlayer2Name;
            updateBoardDisplay();
            for (size_t i = 0; i < boardButtons.size(); ++i)
                boardButtons[i]->setEnabled(board[i] != 'X' && board[i] != 'O');

            promptNextTurn();

            showStyledMessageBox("🎬 Replay Complete", "Match replay finished!\n\nYou can now continue playing or return to the main menu.", QMessageBox::Information);
            return;
        }

        QString line = lastMatch[step++];
        if (line.contains("played")) {
            QStringList parts = line.split(" played ", Qt::SkipEmptyParts);
            if (parts.size() != 2) return;
            QString player = parts[0].trimmed();
            bool ok;
            int pos = parts[1].toInt(&ok);
            if (!ok || pos < 1 || pos > 9) return;

            char symbol = (player == replayPlayer1) ? player1Symbol.toLatin1() : player2Symbol.toLatin1();
            board[pos - 1] = symbol;
            updateBoardDisplay();

            StyleManager::applyTurnLabelStyle(ui->label_turn, QString("🎬 REPLAY: %1 played position %2").arg(player).arg(pos), true);
        } else if (line.startsWith("Result:")) {
            player1Name = savedPlayer1Name;
            player2Name = savedPlayer2Name;
            updateBoardDisplay();

            QString result = line.mid(8).trimmed();
            QString resultMsg;
            if (result == "DRAW") {
                resultMsg = "🤝 The match ended in a draw!\nBoth players played excellently!";
            } else {
                resultMsg = QString("🏆 %1 won the match!\nCongratulations on the victory!").arg(result);
            }
            showStyledMessageBox("🎯 Match Result", resultMsg, QMessageBox::Information);
        }
    });

    replayTimer->start(1000);
}

void MainWindow::on_pushButton_ViewHistory_clicked()
{
    QString currentUser = ui->usernameEdit->text().trimmed();
    if (currentUser.isEmpty()) {
        showStyledMessageBox("🔐 Login Required", "You must log in to view your match history.\n\nPlease authenticate first to access this feature.", QMessageBox::Warning);
        return;
    }

    QString historyPath = getProjectFilePath(currentUser + "_history.txt");
    if (historyPath.isEmpty() || !QFile::exists(historyPath)) {
        showStyledMessageBox("📝 No History Available",
                             QString("No match history found for user: %1\n\n"
                                     "🎮 Play some games to start building your history!\n"
                                     "📊 Your wins, losses, and game moves will be tracked here.")
                                 .arg(currentUser),
                             QMessageBox::Information);
        return;
    }

    QFile file(historyPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        showStyledMessageBox("📁 File Access Error", "Could not open your history file.\n\nPlease check file permissions and try again.", QMessageBox::Critical);
        return;
    }

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    StyleManager::applyHistoryTextEditStyle(ui->textEdit_HistoryView);

    QString formattedContent = content;
    formattedContent.replace("Match:", "\n🎮 MATCH:");
    formattedContent.replace("Result:", "🏆 RESULT:");
    formattedContent.replace("played", "⚡ played");
    formattedContent.replace("-----------------------------", "═══════════════════════════════════════");

    ui->textEdit_HistoryView->setPlainText(formattedContent);
    ui->stackedWidget->setCurrentIndex(5);

    int matchCount = content.count("Match:");
    showStyledMessageBox("📊 History Loaded",
                         QString("Your match history has been loaded!\n\n"
                                 "📈 Total matches recorded: %1\n"
                                 "📝 All moves and results are displayed below.")
                             .arg(matchCount),
                         QMessageBox::Information);
}

void MainWindow::on_pushButton_BackFromHistory_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::setAILevel(int level) {
    aiLevel = level;
}


void MainWindow::simulatePlayerMove(int position)
{
    // This method simulates a player move without triggering UI events
    // Position is 1-9, convert to 0-8 index
    int index = position - 1;

    if (index < 0 || index > 8) {
        qDebug() << "Invalid position:" << position;
        return;
    }

    // Check if position is already taken
    if (board[index] == 'X' || board[index] == 'O') {
        qDebug() << "Position already taken:" << position;
        return;
    }

    // Make the move for current player
    if (currentPlayer == 1) {
        board[index] = player1Symbol.toLatin1();
    } else {
        board[index] = player2Symbol.toLatin1();
    }

    // Update display
    updateBoardDisplay();
}
