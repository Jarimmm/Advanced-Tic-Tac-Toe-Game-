#include <QtTest>
#include "mainwindow.h"

class TestGameVsAI : public QObject {
    Q_OBJECT
private slots:
    void testEasyAI();
    void testMediumAI();
    void testHardAI();
private:
    void runAITest(int aiLevel);
};

void TestGameVsAI::runAITest(int aiLevel)
{
    MainWindow window;
    window.show();

    // Set up game manually for test
    window.setPlayer1Symbol('X');
    window.setPlayer2Symbol('O');

    // Set player names and AI level - USE SETTERS, NOT GETTERS
    window.setPlayer1Name("Tester");
    window.setPlayer2Name("Computer");
    window.setAILevel(aiLevel);

    // Initialize the test game board
    window.initTestGameBoard();

    // Count initial symbols (should be 0)
    int initialCount = 0;
    std::vector<char> boardState = window.getBoardState();
    for (char cell : boardState) {
        if (cell == 'X' || cell == 'O') {
            initialCount++;
        }
    }

    qDebug() << "Initial count:" << initialCount;
    qDebug() << "AI Level:" << aiLevel;
    qDebug() << "Player 1:" << window.getPlayer1Name();
    qDebug() << "Player 2:" << window.getPlayer2Name();

    // Make a player move (position 1, which is index 0)
    window.handlePlayerMoveTest(1);

    // Wait for AI to respond (longer wait for processing)
    QTest::qWait(2000);

    // Count symbols after the move and AI response
    boardState = window.getBoardState();
    int afterCount = 0;
    for (char cell : boardState) {
        if (cell == 'X' || cell == 'O') {
            afterCount++;
        }
    }

    qDebug() << "After count:" << afterCount;
    qDebug() << "Expected: at least" << (initialCount + 2);

    // Debug: Print the board state
    qDebug() << "Board state:";
    for (int i = 0; i < 9; i++) {
        qDebug() << "Position" << i << ":" << boardState[i];
    }

    // Should have at least 2 symbols (player move + AI move)
    QVERIFY2(afterCount >= initialCount + 2,
             QString("Expected at least %1 symbols, got %2")
                 .arg(initialCount + 2)
                 .arg(afterCount)
                 .toLocal8Bit().constData());

    // Verify the first move was made by the player
    QVERIFY2(boardState[0] == 'X' || boardState[0] == 'O',
             "First position should be filled after player move");
}

void TestGameVsAI::testEasyAI() {
    qDebug() << "Testing Easy AI";
    runAITest(1);  // Easy
}

void TestGameVsAI::testMediumAI() {
    qDebug() << "Testing Medium AI";
    runAITest(2);  // Medium
}

void TestGameVsAI::testHardAI() {
    qDebug() << "Testing Hard AI";
    runAITest(3);  // Hard
}

QTEST_MAIN(TestGameVsAI)
#include "test_ailogic.moc"
