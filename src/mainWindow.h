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
    QGridLayout* GridLayout;
    GameStateManager* GameManager;

private Q_SLOTS:
    void OnButtonClicked();
};