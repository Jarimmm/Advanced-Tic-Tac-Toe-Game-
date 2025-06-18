#include "StyleManager.h"
#include <QPushButton>
#include <QLabel>

// Color scheme constants
const QString StyleManager::PRIMARY_GRADIENT = "qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1e3c72, stop:1 #2a5298)";
const QString StyleManager::SECONDARY_GRADIENT = "qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #667eea, stop:1 #764ba2)";
const QString StyleManager::BUTTON_GRADIENT = "qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #ff6b6b, stop:1 #ee5a24)";
const QString StyleManager::HOVER_GRADIENT = "qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #ff5252, stop:1 #d63031)";
const QString StyleManager::PRESSED_GRADIENT = "qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #d63031, stop:1 #b71c1c)";
const QString StyleManager::SUCCESS_GRADIENT = "qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #00b894, stop:1 #00a085)";
const QString StyleManager::WARNING_GRADIENT = "qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #fdcb6e, stop:1 #e17055)";
const QString StyleManager::ERROR_GRADIENT = "qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #fd79a8, stop:1 #e84393)";

void StyleManager::applyMainWindowStyle(QWidget* mainWindow)
{
    mainWindow->setStyleSheet(
        "QMainWindow {"
        "    background: " + PRIMARY_GRADIENT + ";"
                             "}"
                             "QWidget {"
                             "    font-family: 'Segoe UI', Arial, sans-serif;"
                             "}"
        );
}

void StyleManager::applyApplicationStyle(QApplication* app)
{
    app->setStyleSheet(app->styleSheet() + getMessageBoxStyleSheet() + getInputDialogStyleSheet());
}

void StyleManager::applyGameBoardButtonStyle(QPushButton* button, char symbol)
{
    if (symbol == 'X') {
        button->setStyleSheet(
            "color: red; "
            "font-weight: bold; "
            "font-size: 44px; "
            "background-color: lightorange; "
            "border: 2px solid #e74c3c; "
            "border-radius: 8px; "
            "padding: 8px;"
            );
    } else if (symbol == 'O') {
        button->setStyleSheet(
            "color: blue; "
            "font-weight: bold; "
            "font-size: 44px; "
            "background-color: lightorange; "
            "border: 2px solid #3498db; "
            "border-radius: 8px; "
            "padding: 8px;"
            );
    } else {
        button->setStyleSheet(
            "color: black; "
            "font-size: 24px; "
            "background-color: white; "
            "border: 2px solid #95a5a6; "
            "border-radius: 8px; "
            "padding: 8px;"
            "QPushButton:hover {"
            "    background-color: #ecf0f1; "
            "    border-color: #3498db;"
            "}"
            );
    }
}

void StyleManager::applyTurnLabelStyle(QLabel* label, const QString& text, bool isReplay)
{
    label->setText(text);

    if (isReplay) {
        label->setStyleSheet(
            "font-size: 28px; "
            "font-weight: bold; "
            "color: #e74c3c; "
            "background: qlineargradient(x1:0, y1:0, x2:1, y2:0, "
            "stop:0 rgba(231, 76, 60, 0.3), stop:1 rgba(192, 57, 43, 0.3)); "
            "border: 2px solid #e74c3c; "
            "border-radius: 15px; "
            "padding: 10px; "
            "margin: 5px;"
            );
    } else {
        label->setStyleSheet(
            "font-size: 32px; "
            "font-weight: bold; "
            "color: #ffd700; "
            "background: qlineargradient(x1:0, y1:0, x2:1, y2:0, "
            "stop:0 rgba(255, 215, 0, 0.3), stop:1 rgba(255, 140, 0, 0.3)); "
            "border: 2px solid #ffd700; "
            "border-radius: 15px; "
            "padding: 10px; "
            "margin: 5px;"
            );
    }
}

void StyleManager::applyLeaderboardTableStyle(QTableWidget* table)
{
    table->setStyleSheet(
        "QTableWidget {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, "
        "    stop:0 rgba(255, 255, 255, 0.95), stop:1 rgba(240, 248, 255, 0.9));"
        "    border: 3px solid #3498db;"
        "    border-radius: 15px;"
        "    gridline-color: #bdc3c7;"
        "    font-family: 'Segoe UI', Arial, sans-serif;"
        "    font-size: 14px;"
        "    selection-background-color: #3498db;"
        "    selection-color: white;"
        "    alternate-background-color: rgba(52, 152, 219, 0.1);"
        "}"
        "QTableWidget::item {"
        "    padding: 12px 8px;"
        "    border-bottom: 1px solid #ecf0f1;"
        "    color: #2c3e50;"
        "    font-weight: 500;"
        "}"
        "QTableWidget::item:selected {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
        "    stop:0 #3498db, stop:1 #2980b9);"
        "    color: white;"
        "    font-weight: bold;"
        "}"
        "QTableWidget::item:hover {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
        "    stop:0 rgba(52, 152, 219, 0.3), stop:1 rgba(41, 128, 185, 0.2));"
        "}"
        "QHeaderView::section {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
        "    stop:0 #34495e, stop:1 #2c3e50);"
        "    color: white;"
        "    font-weight: bold;"
        "    font-size: 16px;"
        "    padding: 15px 10px;"
        "    border: none;"
        "    border-right: 1px solid #7f8c8d;"
        "}"
        "QHeaderView::section:first {"
        "    border-top-left-radius: 12px;"
        "}"
        "QHeaderView::section:last {"
        "    border-top-right-radius: 12px;"
        "    border-right: none;"
        "}"
        "QScrollBar:vertical {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, "
        "    stop:0 #ecf0f1, stop:1 #bdc3c7);"
        "    width: 16px;"
        "    border-radius: 8px;"
        "    margin: 0px;"
        "}"
        "QScrollBar::handle:vertical {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, "
        "    stop:0 #3498db, stop:1 #2980b9);"
        "    border-radius: 8px;"
        "    min-height: 20px;"
        "}"
        "QScrollBar::handle:vertical:hover {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, "
        "    stop:0 #2980b9, stop:1 #1f4e79);"
        "}"
        );
}

void StyleManager::applyHistoryTextEditStyle(QTextEdit* textEdit)
{
    textEdit->setStyleSheet(
        "QTextEdit {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, "
        "    stop:0 #f8f9fa, stop:1 #e9ecef);"
        "    border: 3px solid #6c757d;"
        "    border-radius: 15px;"
        "    padding: 15px;"
        "    font-family: 'Consolas', 'Monaco', monospace;"
        "    font-size: 13px;"
        "    line-height: 1.6;"
        "    color: #212529;"
        "    selection-background-color: #007bff;"
        "    selection-color: white;"
        "}"
        "QScrollBar:vertical {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, "
        "    stop:0 #e9ecef, stop:1 #dee2e6);"
        "    width: 16px;"
        "    border-radius: 8px;"
        "    margin: 0px;"
        "}"
        "QScrollBar::handle:vertical {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, "
        "    stop:0 #6c757d, stop:1 #495057);"
        "    border-radius: 8px;"
        "    min-height: 20px;"
        "}"
        "QScrollBar::handle:vertical:hover {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, "
        "    stop:0 #495057, stop:1 #343a40);"
        "}"
        );
}

QString StyleManager::getMessageBoxStyleSheet()
{
    return "QMessageBox {"
           "    background: " + SECONDARY_GRADIENT + ";"
                                  "    color: white;"
                                  "    font-size: 14px;"
                                  "    font-weight: bold;"
                                  "    border-radius: 15px;"
                                  "    min-width: 400px;"
                                  "    min-height: 200px;"
                                  "}"
                                  "QMessageBox QLabel {"
                                  "    color: white;"
                                  "    font-size: 16px;"
                                  "    padding: 10px;"
                                  "}"
                                  "QMessageBox QPushButton {"
                                  "    background: " + BUTTON_GRADIENT + ";"
                               "    color: white;"
                               "    font-size: 14px;"
                               "    font-weight: bold;"
                               "    border: none;"
                               "    border-radius: 8px;"
                               "    padding: 10px 20px;"
                               "    margin: 5px;"
                               "    min-width: 80px;"
                               "}"
                               "QMessageBox QPushButton:hover {"
                               "    background: " + HOVER_GRADIENT + ";"
                              "    transform: scale(1.05);"
                              "}"
                              "QMessageBox QPushButton:pressed {"
                              "    background: " + PRESSED_GRADIENT + ";"
                                "}";
}

QString StyleManager::getInputDialogStyleSheet()
{
    return "QInputDialog {"
           "    background: " + SECONDARY_GRADIENT + ";"
                                  "    color: white;"
                                  "    font-size: 14px;"
                                  "    border-radius: 15px;"
                                  "    min-width: 350px;"
                                  "}"
                                  "QInputDialog QLabel {"
                                  "    color: white;"
                                  "    font-size: 16px;"
                                  "    font-weight: bold;"
                                  "    padding: 10px;"
                                  "}"
                                  "QInputDialog QLineEdit {"
                                  "    background: rgba(255, 255, 255, 0.9);"
                                  "    color: #2c3e50;"
                                  "    font-size: 14px;"
                                  "    border: 2px solid #3498db;"
                                  "    border-radius: 8px;"
                                  "    padding: 8px;"
                                  "    margin: 5px;"
                                  "}"
                                  "QInputDialog QComboBox {"
                                  "    background: rgba(255, 255, 255, 0.9);"
                                  "    color: #2c3e50;"
                                  "    font-size: 14px;"
                                  "    border: 2px solid #3498db;"
                                  "    border-radius: 8px;"
                                  "    padding: 8px;"
                                  "    margin: 5px;"
                                  "}"
                                  "QInputDialog QPushButton {"
                                  "    background: " + SUCCESS_GRADIENT + ";"
                                "    color: white;"
                                "    font-size: 14px;"
                                "    font-weight: bold;"
                                "    border: none;"
                                "    border-radius: 8px;"
                                "    padding: 10px 20px;"
                                "    margin: 5px;"
                                "    min-width: 80px;"
                                "}"
                                "QInputDialog QPushButton:hover {"
                                "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
                                "    stop:0 #00a085, stop:1 #019367);"
                                "}";
}

QString StyleManager::createGradientStyle(const QString& gradient, const QString& borderColor)
{
    QString style = "background: " + gradient + ";";
    if (!borderColor.isEmpty()) {
        style += " border: 2px solid " + borderColor + ";";
    }
    return style;
}

QString StyleManager::createButtonStyle(const QString& gradient, const QString& hoverGradient)
{
    QString style = "QPushButton { background: " + gradient + "; }";
    if (!hoverGradient.isEmpty()) {
        style += " QPushButton:hover { background: " + hoverGradient + "; }";
    }
    return style;
}
