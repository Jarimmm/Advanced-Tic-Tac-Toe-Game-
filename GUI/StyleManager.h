#ifndef STYLEMANAGER_H
#define STYLEMANAGER_H

#include <QString>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTableWidget>
#include <QTextEdit>
#include <QLabel>


class StyleManager
{
public:
    // Main application styles
    static void applyMainWindowStyle(QWidget* mainWindow);
    static void applyApplicationStyle(QApplication* app);

    // Game board styles
    static void applyGameBoardButtonStyle(QPushButton* button, char symbol);
    static void applyTurnLabelStyle(QLabel* label, const QString& text, bool isReplay = false);

    // UI Component styles
    static void applyLeaderboardTableStyle(QTableWidget* table);
    static void applyHistoryTextEditStyle(QTextEdit* textEdit);

    // Message box and dialog styles
    static QString getMessageBoxStyleSheet();
    static QString getInputDialogStyleSheet();

    // Color schemes and constants
    static const QString PRIMARY_GRADIENT;
    static const QString SECONDARY_GRADIENT;
    static const QString BUTTON_GRADIENT;
    static const QString HOVER_GRADIENT;
    static const QString PRESSED_GRADIENT;
    static const QString SUCCESS_GRADIENT;
    static const QString WARNING_GRADIENT;
    static const QString ERROR_GRADIENT;

private:
    StyleManager() = default; // Static class - no instantiation

    // Helper methods for common style patterns
    static QString createGradientStyle(const QString& gradient, const QString& borderColor = "");
    static QString createButtonStyle(const QString& gradient, const QString& hoverGradient = "");
};

#endif // STYLEMANAGER_H
