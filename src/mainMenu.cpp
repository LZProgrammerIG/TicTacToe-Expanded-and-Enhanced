#include "mainMenu.h"
#include "mainWindow.h"
#include "gameStateManager.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>



MainMenu::MainMenu(QWidget *parent) : QWidget(parent) {
    GameWindow = new MainWindow(this);
    GameWindow -> hide();

    Panel = new QWidget(this);

    MenuText = new QLabel(QString("Tic Tac Toe"), Panel);
    PlayWithAiButton = new QPushButton(QString("Play with AI"), Panel);
    PlayWithFriendButton = new QPushButton(QString("Play with Friend"), Panel);

    QVBoxLayout* VerticalBox = new QVBoxLayout(Panel);
    VerticalBox -> addWidget(MenuText);
    VerticalBox -> addSpacing(100);
    VerticalBox -> addWidget(PlayWithAiButton);
    VerticalBox -> addSpacing(20);
    VerticalBox -> addWidget(PlayWithFriendButton);

    Panel -> setLayout(VerticalBox);

    connect(PlayWithAiButton, &QPushButton::clicked, this, &MainMenu::OnButtonClicked);
    connect(PlayWithFriendButton, &QPushButton::clicked, this, &MainMenu::OnButtonClicked);

    Panel -> show();
}


void MainMenu::OnButtonClicked() {
    QPushButton* Button = qobject_cast<QPushButton*> (sender());
    if (!Button || !GameWindow || GameWindow -> GameManager == nullptr) {
        return;
    }

    if (Button == PlayWithAiButton) {
        GameWindow -> GameManager -> GameMode = EGameMode::AI;
    }
    else if (Button == PlayWithFriendButton) {
        GameWindow -> GameManager -> GameMode = EGameMode::COOP;
    }

    Panel -> hide();
    GameWindow -> show();
}