#include <QWidget>


class QPushButton;
class QLabel;
class MainWindow;

class MainMenu : public QWidget {
    Q_OBJECT

public:
    MainMenu(QWidget* parent = nullptr);

private:
    QWidget* Panel = nullptr;
    QPushButton* PlayWithAiButton = nullptr;
    QPushButton* PlayWithFriendButton = nullptr;
    QLabel* MenuText = nullptr;
    MainWindow* GameWindow = nullptr;

public Q_SLOT:
    void OnButtonClicked();

};