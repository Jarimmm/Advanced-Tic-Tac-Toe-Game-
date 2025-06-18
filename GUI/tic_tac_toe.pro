QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    StyleManager.cpp \
    main.cpp \
    mainwindow.cpp \
    leaderboard_qt.cpp \
    UserManager_qt.cpp \
    ai_logic.cpp \
   game_logic.cpp \
    game_ui.cpp \
    User.cpp \

HEADERS += \
    StyleManager.h \
    mainwindow.h \
 leaderboard_qt.h \
    UserManager_qt.h \
    ai_logic.h \
    game_constants.h \
   game_logic.h \
    game_ui.h \
    User.h

FORMS += \
    mainwindow.ui

DISTFILES += \
    history.txt \
    score.txt \
   users.txt

#CONFIG += testcase
#QT += testlib
  #  SOURCES += mainwindow.cpp \
              # test_ailogic.cpp
              #  test_leaderboard.cpp
             #  test_usermanager.cpp
