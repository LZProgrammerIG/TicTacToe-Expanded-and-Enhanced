#include "mainWindow.h"
#include <QGridLayout>
#include <QPushButton>


MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
    GridLayout = new QGridLayout(this);
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            QPushButton* Button = new QPushButton(this);
            Button -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            GridLayout -> addWidget(Button, row, col);
        }
    }

    setObjectName("Window");
    setStyleSheet("#Window {background-color: #333333; }");
    setLayout(GridLayout);
}