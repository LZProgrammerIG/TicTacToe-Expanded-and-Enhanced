#include <QWidget>

class QGridLayout;
class GameStateManager;

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void Reset(int result);

private:
    QGridLayout* GridLayout = nullptr;

public:
    GameStateManager* GameManager = nullptr;

private Q_SLOTS:
    void OnButtonClicked();
};