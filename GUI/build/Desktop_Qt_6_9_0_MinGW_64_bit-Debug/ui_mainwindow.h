/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *login;
    QLabel *label_2;
    QPushButton *RegisterButton;
    QLabel *label;
    QLineEdit *passwordEdit;
    QLineEdit *usernameEdit;
    QLabel *label_3;
    QWidget *page_3;
    QLabel *label_4;
    QPushButton *pushButton_PvC;
    QPushButton *pushButton_PvP;
    QPushButton *LeaderBoardButton;
    QPushButton *pushButton_Exit;
    QPushButton *pushButton_GRules;
    QPushButton *pushButton_ViewHistory;
    QPushButton *pushButton_ReplayMatch;
    QWidget *page_4;
    QPushButton *pushButton_ViewTutorial;
    QPushButton *pushButton_Back;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *page_2;
    QGroupBox *groupBox;
    QPushButton *cell00;
    QPushButton *cell01;
    QPushButton *cell02;
    QPushButton *cell10;
    QPushButton *cell11;
    QPushButton *cell12;
    QPushButton *cell20;
    QPushButton *cell21;
    QPushButton *cell22;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_BackToMenuFromGame;
    QPushButton *pushButton_NewG;
    QLabel *label_turn;
    QWidget *page_5;
    QTableWidget *leaderboardTable;
    QLabel *label_9;
    QPushButton *Back_fromLB_toMenu;
    QWidget *page_6;
    QTextEdit *textEdit_HistoryView;
    QPushButton *pushButton_BackFromHistory;
    QLabel *label_10;
    QLabel *label_11;
    QStatusBar *statusbar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1186, 765);
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(22);
        font.setBold(true);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1091, 691));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(174, 129, 189);"));
        stackedWidget->setFrameShape(QFrame::Shape::NoFrame);
        page = new QWidget();
        page->setObjectName("page");
        login = new QPushButton(page);
        login->setObjectName("login");
        login->setGeometry(QRect(290, 460, 191, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(true);
        login->setFont(font1);
        login->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Times New Roman\";\n"
"background-color: rgb(241, 225, 255);"));
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 220, 251, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setItalic(false);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";\n"
"font: 700 16pt \"Times New Roman\";"));
        RegisterButton = new QPushButton(page);
        RegisterButton->setObjectName("RegisterButton");
        RegisterButton->setGeometry(QRect(600, 460, 211, 51));
        RegisterButton->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Times New Roman\";\n"
"background-color: rgb(241, 225, 255);"));
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 30, 651, 91));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Stencil")});
        font3.setPointSize(22);
        font3.setBold(false);
        font3.setItalic(false);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("font: 22pt \"Stencil\";"));
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        passwordEdit = new QLineEdit(page);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(470, 290, 361, 51));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Segoe UI")});
        font4.setPointSize(20);
        font4.setBold(false);
        font4.setItalic(false);
        passwordEdit->setFont(font4);
        passwordEdit->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";\n"
"background-color: rgb(241, 225, 255);"));
        usernameEdit = new QLineEdit(page);
        usernameEdit->setObjectName("usernameEdit");
        usernameEdit->setGeometry(QRect(470, 210, 361, 51));
        usernameEdit->setFont(font4);
        usernameEdit->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";\n"
"background-color: rgb(241, 225, 255);"));
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(160, 280, 241, 41));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";\n"
"font: 700 16pt \"Times New Roman\";"));
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        label_4 = new QLabel(page_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(260, 40, 491, 81));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Stencil")});
        font5.setPointSize(24);
        font5.setBold(false);
        font5.setItalic(false);
        label_4->setFont(font5);
        label_4->setStyleSheet(QString::fromUtf8("font: 24pt \"Stencil\";"));
        label_4->setScaledContents(false);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_PvC = new QPushButton(page_3);
        pushButton_PvC->setObjectName("pushButton_PvC");
        pushButton_PvC->setGeometry(QRect(290, 160, 431, 51));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Monotype Corsiva")});
        font6.setPointSize(22);
        font6.setBold(true);
        font6.setItalic(true);
        pushButton_PvC->setFont(font6);
        pushButton_PvC->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 225, 255);"));
        pushButton_PvP = new QPushButton(page_3);
        pushButton_PvP->setObjectName("pushButton_PvP");
        pushButton_PvP->setGeometry(QRect(290, 220, 431, 51));
        pushButton_PvP->setFont(font6);
        pushButton_PvP->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 225, 255);"));
        LeaderBoardButton = new QPushButton(page_3);
        LeaderBoardButton->setObjectName("LeaderBoardButton");
        LeaderBoardButton->setGeometry(QRect(290, 280, 431, 51));
        LeaderBoardButton->setFont(font6);
        LeaderBoardButton->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 225, 255);"));
        pushButton_Exit = new QPushButton(page_3);
        pushButton_Exit->setObjectName("pushButton_Exit");
        pushButton_Exit->setGeometry(QRect(290, 460, 431, 51));
        pushButton_Exit->setFont(font6);
        pushButton_Exit->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 225, 255);"));
        pushButton_GRules = new QPushButton(page_3);
        pushButton_GRules->setObjectName("pushButton_GRules");
        pushButton_GRules->setGeometry(QRect(810, 540, 201, 61));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Monotype Corsiva")});
        font7.setPointSize(20);
        font7.setBold(true);
        font7.setItalic(true);
        pushButton_GRules->setFont(font7);
        pushButton_GRules->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        pushButton_GRules->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 196, 94);"));
        pushButton_ViewHistory = new QPushButton(page_3);
        pushButton_ViewHistory->setObjectName("pushButton_ViewHistory");
        pushButton_ViewHistory->setGeometry(QRect(290, 340, 431, 51));
        pushButton_ViewHistory->setFont(font6);
        pushButton_ViewHistory->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 225, 255);"));
        pushButton_ReplayMatch = new QPushButton(page_3);
        pushButton_ReplayMatch->setObjectName("pushButton_ReplayMatch");
        pushButton_ReplayMatch->setGeometry(QRect(290, 400, 431, 51));
        pushButton_ReplayMatch->setFont(font6);
        pushButton_ReplayMatch->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 225, 255);"));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        pushButton_ViewTutorial = new QPushButton(page_4);
        pushButton_ViewTutorial->setObjectName("pushButton_ViewTutorial");
        pushButton_ViewTutorial->setGeometry(QRect(730, 520, 271, 51));
        pushButton_ViewTutorial->setFont(font7);
        pushButton_ViewTutorial->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 196, 94);"));
        pushButton_Back = new QPushButton(page_4);
        pushButton_Back->setObjectName("pushButton_Back");
        pushButton_Back->setGeometry(QRect(190, 520, 191, 51));
        pushButton_Back->setFont(font7);
        pushButton_Back->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 196, 94);"));
        label_7 = new QLabel(page_4);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(350, 40, 321, 61));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Stencil")});
        font8.setPointSize(22);
        font8.setBold(false);
        label_7->setFont(font8);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_8 = new QLabel(page_4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(160, 110, 851, 321));
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Century")});
        font9.setPointSize(20);
        font9.setBold(true);
        label_8->setFont(font9);
        stackedWidget->addWidget(page_4);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        groupBox = new QGroupBox(page_2);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(40, 10, 591, 421));
        QFont font10;
        font10.setFamilies({QString::fromUtf8("Rockwell")});
        font10.setPointSize(22);
        groupBox->setFont(font10);
        cell00 = new QPushButton(groupBox);
        cell00->setObjectName("cell00");
        cell00->setGeometry(QRect(70, 50, 111, 91));
        cell00->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 196, 94);"));
        cell01 = new QPushButton(groupBox);
        cell01->setObjectName("cell01");
        cell01->setGeometry(QRect(240, 50, 111, 91));
        cell01->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 196, 94);"));
        cell02 = new QPushButton(groupBox);
        cell02->setObjectName("cell02");
        cell02->setGeometry(QRect(420, 50, 111, 91));
        cell02->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 196, 94);"));
        cell10 = new QPushButton(groupBox);
        cell10->setObjectName("cell10");
        cell10->setGeometry(QRect(70, 170, 111, 91));
        cell10->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 196, 94);"));
        cell11 = new QPushButton(groupBox);
        cell11->setObjectName("cell11");
        cell11->setGeometry(QRect(240, 170, 111, 91));
        cell11->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 196, 94);"));
        cell12 = new QPushButton(groupBox);
        cell12->setObjectName("cell12");
        cell12->setGeometry(QRect(420, 170, 111, 91));
        cell12->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 196, 94);"));
        cell20 = new QPushButton(groupBox);
        cell20->setObjectName("cell20");
        cell20->setGeometry(QRect(70, 290, 111, 91));
        cell20->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 196, 94);"));
        cell21 = new QPushButton(groupBox);
        cell21->setObjectName("cell21");
        cell21->setGeometry(QRect(240, 290, 111, 91));
        cell21->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 196, 94);"));
        cell22 = new QPushButton(groupBox);
        cell22->setObjectName("cell22");
        cell22->setGeometry(QRect(420, 290, 111, 91));
        cell22->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 196, 94);"));
        lineEdit_2 = new QLineEdit(page_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(250, 460, 231, 41));
        QFont font11;
        font11.setFamilies({QString::fromUtf8("Monotype Corsiva")});
        font11.setPointSize(20);
        font11.setBold(false);
        font11.setItalic(true);
        lineEdit_2->setFont(font11);
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 225, 255);"));
        lineEdit_3 = new QLineEdit(page_2);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(700, 460, 211, 41));
        lineEdit_3->setFont(font11);
        lineEdit_3->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 225, 255);"));
        label_5 = new QLabel(page_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(130, 470, 111, 41));
        label_5->setFont(font11);
        label_6 = new QLabel(page_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(580, 470, 111, 41));
        label_6->setFont(font11);
        pushButton_BackToMenuFromGame = new QPushButton(page_2);
        pushButton_BackToMenuFromGame->setObjectName("pushButton_BackToMenuFromGame");
        pushButton_BackToMenuFromGame->setGeometry(QRect(80, 550, 201, 51));
        pushButton_BackToMenuFromGame->setFont(font7);
        pushButton_BackToMenuFromGame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 196, 94);"));
        pushButton_NewG = new QPushButton(page_2);
        pushButton_NewG->setObjectName("pushButton_NewG");
        pushButton_NewG->setGeometry(QRect(780, 530, 221, 61));
        pushButton_NewG->setFont(font7);
        pushButton_NewG->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 196, 94);"));
        label_turn = new QLabel(page_2);
        label_turn->setObjectName("label_turn");
        label_turn->setGeometry(QRect(680, 310, 381, 81));
        QFont font12;
        font12.setFamilies({QString::fromUtf8("Monotype Corsiva")});
        font12.setPointSize(20);
        font12.setItalic(true);
        label_turn->setFont(font12);
        label_turn->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 225, 255);"));
        stackedWidget->addWidget(page_2);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        leaderboardTable = new QTableWidget(page_5);
        if (leaderboardTable->columnCount() < 5)
            leaderboardTable->setColumnCount(5);
        QFont font13;
        font13.setFamilies({QString::fromUtf8("Engravers MT")});
        font13.setPointSize(14);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font13);
        leaderboardTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font13);
        leaderboardTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font13);
        leaderboardTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font13);
        leaderboardTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font13);
        leaderboardTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        leaderboardTable->setObjectName("leaderboardTable");
        leaderboardTable->setGeometry(QRect(120, 100, 841, 401));
        leaderboardTable->setFont(font11);
        leaderboardTable->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 225, 255);"));
        leaderboardTable->setShowGrid(false);
        label_9 = new QLabel(page_5);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(40, 20, 571, 51));
        label_9->setFont(font8);
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Back_fromLB_toMenu = new QPushButton(page_5);
        Back_fromLB_toMenu->setObjectName("Back_fromLB_toMenu");
        Back_fromLB_toMenu->setGeometry(QRect(60, 530, 241, 51));
        QFont font14;
        font14.setFamilies({QString::fromUtf8("Monotype Corsiva")});
        font14.setPointSize(20);
        font14.setBold(true);
        Back_fromLB_toMenu->setFont(font14);
        Back_fromLB_toMenu->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 196, 94);"));
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        textEdit_HistoryView = new QTextEdit(page_6);
        textEdit_HistoryView->setObjectName("textEdit_HistoryView");
        textEdit_HistoryView->setGeometry(QRect(80, 140, 791, 381));
        QFont font15;
        font15.setFamilies({QString::fromUtf8("Times New Roman")});
        font15.setPointSize(17);
        textEdit_HistoryView->setFont(font15);
        textEdit_HistoryView->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 225, 255);"));
        pushButton_BackFromHistory = new QPushButton(page_6);
        pushButton_BackFromHistory->setObjectName("pushButton_BackFromHistory");
        pushButton_BackFromHistory->setGeometry(QRect(80, 550, 161, 41));
        pushButton_BackFromHistory->setFont(font7);
        pushButton_BackFromHistory->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 196, 94);"));
        label_10 = new QLabel(page_6);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(0, 20, 491, 81));
        QFont font16;
        font16.setFamilies({QString::fromUtf8("Stencil")});
        font16.setPointSize(20);
        font16.setBold(false);
        font16.setItalic(false);
        label_10->setFont(font16);
        label_10->setStyleSheet(QString::fromUtf8("font: 20pt \"Stencil\";"));
        label_10->setScaledContents(false);
        label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_11 = new QLabel(page_6);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(900, 140, 111, 121));
        QFont font17;
        font17.setPointSize(14);
        label_11->setFont(font17);
        label_11->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 225, 255);"));
        label_11->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(page_6);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1186, 47));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Enter User Name :", nullptr));
        RegisterButton->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Login and Registration System", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Enter Password :", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "THE MAIN MENU", nullptr));
        pushButton_PvC->setText(QCoreApplication::translate("MainWindow", "Player Vs Computer", nullptr));
        pushButton_PvP->setText(QCoreApplication::translate("MainWindow", "Player 1 Vs Player 2", nullptr));
        LeaderBoardButton->setText(QCoreApplication::translate("MainWindow", "Leader Board", nullptr));
        pushButton_Exit->setText(QCoreApplication::translate("MainWindow", "Exit Game", nullptr));
        pushButton_GRules->setText(QCoreApplication::translate("MainWindow", "Game Rules", nullptr));
        pushButton_ViewHistory->setText(QCoreApplication::translate("MainWindow", "View My History", nullptr));
        pushButton_ReplayMatch->setText(QCoreApplication::translate("MainWindow", "Replay My Last Match", nullptr));
        pushButton_ViewTutorial->setText(QCoreApplication::translate("MainWindow", "View Tutorial", nullptr));
        pushButton_Back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Game Rules", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; color:#000000;\">1. Each player takes turns placing their mark (X or O).</span></p><p><span style=\" font-size:18pt; color:#000000;\">2. The first player to align 3 marks horizontally, </span></p><p><span style=\" font-size:18pt; color:#000000;\">vertically, or diagonally wins.<br/>3. If the grid fills up with no winner, it's a draw.</span></p></body></html>", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Game Board", nullptr));
        cell00->setText(QString());
        cell01->setText(QString());
        cell02->setText(QString());
        cell10->setText(QString());
        cell11->setText(QString());
        cell12->setText(QString());
        cell20->setText(QString());
        cell21->setText(QString());
        cell22->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Player 1 :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Player 2 :", nullptr));
        pushButton_BackToMenuFromGame->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pushButton_NewG->setText(QCoreApplication::translate("MainWindow", "New Game", nullptr));
        label_turn->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        QTableWidgetItem *___qtablewidgetitem = leaderboardTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Rank", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = leaderboardTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Player", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = leaderboardTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Wins", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = leaderboardTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Losses", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = leaderboardTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Draws", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Leader Board", nullptr));
        Back_fromLB_toMenu->setText(QCoreApplication::translate("MainWindow", "Back to Menu", nullptr));
        pushButton_BackFromHistory->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "my history", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">1    2   3</p><p align=\"center\">4   5   6</p><p align=\"center\">7   8   9</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
