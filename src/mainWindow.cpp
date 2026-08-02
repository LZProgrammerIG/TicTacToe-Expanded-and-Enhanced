#include "mainWindow.h"
#include "gameStateManager.h"
#include <QGridLayout>
#include <QPushButton>
#include <QThread>
#include <QMessageBox>


MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
    GridLayout = new QGridLayout(this);
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            QPushButton* Button = new QPushButton(this);
            Button -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            Button -> setObjectName(QString::number(row * 3 + col));
            GridLayout -> addWidget(Button, row, col);

            // Both are correct.
            connect(Button, SIGNAL(clicked()), this, SLOT(OnButtonClicked()) );
            //connect(Button, &QPushButton::clicked, this, &MainWindow::OnButtonClicked);
        }
    }

    setObjectName("GameWindow");
    setStyleSheet("#GameWindow {background-color: #333333; }");
    setLayout(GridLayout);

    GameManager = new GameStateManager();
}

MainWindow::~MainWindow() {
    delete GameManager;
}


void MainWindow::Reset(int result) {
    QString GameOverMessage;
    switch (result) {
    case 1:
        GameOverMessage = QString("Player X won !!");
        break;
    
    case -1:
        GameOverMessage = QString("Player O won !!");
        break;

    case 0:
        GameOverMessage = QString("The game was a tie.");
        break;
    }
    QMessageBox::information(this, QString("Game Over"), GameOverMessage);


    QThread::msleep(500);
    
    for (int i = 0; i < GridLayout -> count(); i++) {
        QPushButton* Button = qobject_cast<QPushButton*> (GridLayout -> itemAt(i) -> widget());
        if (!Button) {
            continue;
        }
        Button -> setText(QString(""));
        connect(Button, SIGNAL(clicked()), this, SLOT(OnButtonClicked()) );
        GameManager -> Initialise();
    }
}


void MainWindow::OnButtonClicked() {
    QPushButton* Button = qobject_cast<QPushButton*> (QObject::sender());
    if (!Button || !GameManager) {
        return;
    }

    QString text = (GameManager -> Player == EPlayer::MAX) ? QString("X") : QString("O");
    Button -> setText(text);
    int index = Button -> objectName().toInt();
    GameManager -> Board[index] = (GameManager -> Player == EPlayer::MAX) ? 1 : -1;
    GameManager -> Player = (GameManager -> Player == EPlayer::MAX) ? EPlayer::MIN : EPlayer::MAX;
    disconnect(Button, SIGNAL(clicked()), this, SLOT(OnButtonClicked()) );    

    int result = 0;
    if (GameManager -> GameMode == EGameMode::AI) {
        // Player is always MAX (X).
        GameManager -> Player = EPlayer::MAX;

        index = -1;
        // AI is always going to be a MIN Player (O).
        result = GameManager -> Minimax(EPlayer::MIN, index);
        if (index == -1) {
            Reset(result);
            return;
        }
        GameManager -> Board[index] = -1;

        Button = qobject_cast<QPushButton*> (GridLayout -> itemAt(index) -> widget());
        if (!Button) {
            return;
        }
        Button -> setText(QString("O"));
        disconnect(Button, SIGNAL(clicked()), this, SLOT(OnButtonClicked()) );
    }

    if (GameManager -> IsTerminalState(result)) {
        Reset(result);
    }
}
