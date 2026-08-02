#include "gameStateManager.h"


GameStateManager::GameStateManager() {
    GameMode = EGameMode::AI;
    Initialise();
}

void GameStateManager::Initialise() {
    for (int i = 0; i < 9; i++) {
        Board[i] = 0;
    }
    Player = EPlayer::MAX;
}


bool GameStateManager::IsTerminalState(int& Result) {
    // Check for horizontal match.
    for (int row = 0; row <= 6; row += 3) {
        if (Board[row] != 0 && Board[row] == Board[row + 1] && Board[row] == Board[row + 2]) {
            Result = Board[row];
            return true;
        }
    }

    // Check for vertical match.
    for (int row = 0; row < 3; row++) {
        if (Board[row] != 0 && Board[row] == Board[row + 3] && Board[row] == Board[row + 6]) {
            Result = Board[row];
            return true;
        }
    }

    // Check for diagonals.
    if (Board[0] != 0 && Board[0] == Board[4] && Board[0] == Board[8]) {
        Result = Board[0];
        return true;
    }
    if (Board[2] != 0 && Board[2] == Board[4] && Board[2] == Board[6]) {
        Result = Board[2];
        return true;
    }

    Result = 0;
    // Check if there are no moves left.
    for (int i = 0; i < 9; i++) {
        if (Board[i] == 0) {
            return false;
        }
    }
    return true;
}


int GameStateManager::Minimax(EPlayer PlayerTurn, int& OptimalIndex) {
    // Base Case
    int temp;
    if (IsTerminalState(temp)) {
        return temp;
    }
    
    
    // Main Code.
    int favResult = (PlayerTurn == EPlayer::MAX) ? -1 : 1;
    for (int i = 0; i < 9; i++) {
        if (Board[i] != 0) {
            continue;
        }

        Board[i] = (PlayerTurn == EPlayer::MAX) ? 1 : -1;
        EPlayer nextPlayer = (PlayerTurn == EPlayer::MAX) ? EPlayer::MIN : EPlayer::MAX;
        int uselessIndex = -1;
        temp = Minimax(nextPlayer, uselessIndex);

        if (PlayerTurn == EPlayer::MAX) {
            if (temp >= favResult) {
                favResult = temp;
                OptimalIndex = i;
            }
        }
        else {
            if (temp <= favResult) {
                favResult = temp;
                OptimalIndex = i;
            }
        }
         
        Board[i] = 0;
    }

    return favResult;
}
