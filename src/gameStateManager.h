enum class EPlayer {
    MAX,
    MIN
};


class GameStateManager {
public:
    int Board[9];

private:
    EPlayer Player;
    int Result;

public:
    GameStateManager();
    void Initialise();

    bool IsTerminalState(int& Result);


    int Minimax(EPlayer PlayerTurn, int& OptimalIndex);
};