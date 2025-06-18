#include "leaderboard_qt.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

extern QString getProjectFilePath(const QString& fileName, bool createIfNotFound = false);

void LeaderboardQt::updateLeaderboard(const std::string& player1, const std::string& player2, const std::string& result) {
    QString scorePath = getProjectFilePath("score.txt", true);
    qDebug() << "Writing to score.txt at:" << scorePath;
    if (scorePath.isEmpty()) {
        qDebug() << "Error: Could not locate or create score.txt";
        return;
    }

    QFile file(scorePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        qDebug() << "Error: Could not open score.txt at:" << scorePath;
        return;
    }

    QTextStream out(&file);
    out << QString::fromStdString(player1) << "\t"
        << QString::fromStdString(player2) << "\t"
        << QString::fromStdString(result) << "\n";
    file.close();
}
