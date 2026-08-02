#include <QApplication>
#include "mainMenu.h"


int main(int argc, char** argv) {
    QApplication app(argc, argv);
    
    MainMenu window;
    window.setMinimumSize(300, 300);
    window.show();
    
    return app.exec();
}