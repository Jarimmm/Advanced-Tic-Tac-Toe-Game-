#include "MainMenuWidget.h"
#include <QPushButton>
#include <QVBoxLayout>

MainMenuWidget::MainMenuWidget(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout();

    pvpButton = new QPushButton("Play vs Player");
    pvcButton = new QPushButton("Play vs Computer");
    leaderboardButton = new QPushButton("View Leaderboard");
    exitButton = new QPushButton("Exit");

    layout->addWidget(pvpButton);
    layout->addWidget(pvcButton);
    layout->addWidget(leaderboardButton);
    layout->addWidget(exitButton);

    setLayout(layout);

    connect(pvpButton, &QPushButton::clicked, this, [=]() {
        emit startPVP("CurrentUser");
    });
    connect(pvcButton, &QPushButton::clicked, this, [=]() {
        emit startPVC("CurrentUser");
    });
    connect(leaderboardButton, &QPushButton::clicked, this, &MainMenuWidget::showLeaderboard);
    connect(exitButton, &QPushButton::clicked, this, &MainMenuWidget::quitGame);
}
