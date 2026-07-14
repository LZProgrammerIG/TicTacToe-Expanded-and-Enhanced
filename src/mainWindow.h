#include <QWidget>

class QGridLayout;

class MainWindow : public QWidget {
public:
    MainWindow(QWidget* parent = nullptr);

private:
    QGridLayout* GridLayout;
};