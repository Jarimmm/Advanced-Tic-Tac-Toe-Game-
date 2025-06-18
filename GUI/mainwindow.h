#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <vector>
#include<QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:
    QChar getPlayer1Symbol() const;
    QChar getPlayer2Symbol() const;
    void setupGameBoard();
    void handlePlayerMove(int position);
    void setPlayer1Symbol(QChar);
    void setPlayer2Symbol(QChar);
    // === TEST HELPERS ===
    void setPlayer1Name(const QString& name) { player1Name = name; }
    void setPlayer2Name(const QString& name) { player2Name = name; }
    void setAILevel(int level);
    void initTestGameBoard() { setupGameBoard(); }
    void handlePlayerMoveTest(int pos) { handlePlayerMove(pos); }
    std::vector<char> getBoardState() const { return board; }
    QString getPlayer1Name() const { return player1Name; }
    QString getPlayer2Name() const { return player2Name; }
    void simulatePlayerMove(int position);
    void loadLeaderboardToTable();



private slots:
    void on_login_clicked();
    void on_RegisterButton_clicked();
    void on_pushButton_GRules_clicked();
    void on_pushButton_Back_clicked();
    void on_pushButton_PvP_clicked();
    void on_pushButton_PvC_clicked();
    void on_pushButton_NewG_clicked();
    void handleComputerMove();
    void on_pushButton_Exit_clicked();
    void on_pushButton_BackToMenuFromGame_clicked();
    void on_pushButton_ViewTutorial_clicked();
    void on_LeaderBoardButton_clicked();
    void on_pushButton_ReplayMatch_clicked();
    void on_Back_fromLB_toMenu_clicked();
    void on_pushButton_ViewHistory_clicked();
    void on_pushButton_BackFromHistory_clicked();

private:
    Ui::MainWindow *ui;
    QString player1Name, player2Name;
    QChar player1Symbol, player2Symbol;
    int aiLevel;
    std::vector<char> board;
    int currentPlayer;
    std::vector<QPushButton*> boardButtons;
    void updateBoardDisplay();
    void handlePlayer2Move(int position);
    QString determineWinner(const std::vector<char>& board);
    void checkGameResult();
    void resetGame();
    void promptNextTurn();
    void setupCustomMessageBoxStyle();
    void showStyledMessageBox(const QString &title, const QString &message, QMessageBox::Icon icon);
    QString showStyledInputDialog(const QString &title, const QString &label, const QString &defaultText);

};
#endif
