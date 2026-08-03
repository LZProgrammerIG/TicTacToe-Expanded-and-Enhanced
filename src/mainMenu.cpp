#include "mainMenu.h"
#include "mainWindow.h"
#include "gameStateManager.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>



MainMenu::MainMenu(QWidget *parent) : QWidget(parent) {
    QVBoxLayout* OuterVerticalBox = new QVBoxLayout(this);
    
    GameWindow = new MainWindow(this);
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
    VerticalBox -> setContentsMargins(10, 10, 10, 10);

    Panel -> setLayout(VerticalBox);

    OuterVerticalBox -> addWidget(Panel);
    OuterVerticalBox -> addWidget(GameWindow);
    OuterVerticalBox -> setContentsMargins(0, 0, 0, 0);
    setLayout(OuterVerticalBox);
    GameWindow -> hide();
    Panel -> show();

    connect(PlayWithAiButton, &QPushButton::clicked, this, &MainMenu::OnButtonClicked);
    connect(PlayWithFriendButton, &QPushButton::clicked, this, &MainMenu::OnButtonClicked);
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