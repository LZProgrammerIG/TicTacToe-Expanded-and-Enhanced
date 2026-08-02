enum class EGameMode {
    COOP,
    AI
};

enum class EPlayer {
    MAX,
    MIN
};


class GameStateManager {
public:
    int Board[9];
    EGameMode GameMode;
    EPlayer Player;

private:
    int Result;

public:
    GameStateManager();
    void Initialise();

    bool IsTerminalState(int& Result);


    int Minimax(EPlayer PlayerTurn, int& OptimalIndex);
};