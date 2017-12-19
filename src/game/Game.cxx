#include "Game.hxx"

Game::Game() {
    solved = false;
}

std::vector<char> Game::getMines() {
    return mines;
}

void Game::resetMines() {
    mines = std::vector<char>((trc + 1) * getRows());
    for(int i = 0; i < mines.size(); i++) {
        mines[i] = '0';
    }
}

void Game::setEdgeMines() {
    trc = getTRC() - 1;
    blc = getBLC() - 1;
    brc = getBRC() - 1;

    for(int i = 1; i < trc; i++) {
        topMines.push_back(i);
    }

    for(int i = trc + 1; i < blc; i += trc + 1) {
        leftMines.push_back(i);
    }

    for(int i = trc + trc + 1; i < brc - trc; i += trc + 1) {
        rightMines.push_back(i);
    }

    for(int i = blc + 1; i < brc; i++) {
        bottomMines.push_back(i);
    }
}

void Game::generateMines() {
    srand(time(NULL));
    int rando;
    int numMines = getNumberOfMines();
    resetMines();
    for(int i = 0; i < numMines; i++) {
        rando = rand() % brc;
        if(mines[rando] != 'm') {
            mines[rando] = 'm';
            solution.push_back(rando);
        } else {
            i--;
        }
    }
    std::sort(solution.begin(), solution.end());
}

std::vector<int> Game::returnSolution() {
    return solution;
}

std::vector<int> Game::returnCheckMines(int tile) {
    std::vector<int> toReturn;
    bool checked = false;

    // Top left corner:  return 3 surrounding tiles
    if(tile == 0) {
        toReturn.push_back(tile + 1);
        toReturn.push_back(tile + trc + 1);
        toReturn.push_back(tile + trc + 2);
        checked = true;
    }
    
    // Top edge mines:  return 5 surrounding tiles
    if(std::find(topMines.begin(), topMines.end(), tile) != topMines.end()) {
        toReturn.push_back(tile - 1);
        toReturn.push_back(tile + 1);
        toReturn.push_back(tile + trc);
        toReturn.push_back(tile + trc + 1);
        toReturn.push_back(tile + trc + 2);
        checked = true;
    }
    
    // Top right corner:  return 3 surrounding tiles
    if(tile == trc) {
        toReturn.push_back(tile - 1);
        toReturn.push_back(tile + trc);
        toReturn.push_back(tile + trc + 1);
        checked = true;
    }
    
    // Left edge mines:  return 5 surrounding tiles
    if(std::find(leftMines.begin(), leftMines.end(), tile) != leftMines.end()) {
        toReturn.push_back(tile - trc - 1);
        toReturn.push_back(tile - trc);
        toReturn.push_back(tile + 1);
        toReturn.push_back(tile + trc + 1);
        toReturn.push_back(tile + trc + 2);
        checked = true;
    }
    
    // Bottom left corner:  return 3 surrounding tiles
    if(tile == blc) {
        toReturn.push_back(tile - trc - 1);
        toReturn.push_back(tile - trc);
        toReturn.push_back(tile + 1);
        checked = true;
    }
    
    // Bottom edge mines:  return 5 surrounding tiles
    if(std::find(bottomMines.begin(), bottomMines.end(), tile) != bottomMines.end()) {
        toReturn.push_back(tile - trc - 2);
        toReturn.push_back(tile - trc - 1);
        toReturn.push_back(tile - trc);
        toReturn.push_back(tile - 1);
        toReturn.push_back(tile + 1);
        checked = true;
    }
    
    // Bottom right corner:  return 3 surrounding tiles
    if(tile == brc) {
        toReturn.push_back(tile - trc - 2);
        toReturn.push_back(tile - trc - 1);
        toReturn.push_back(tile - 1);
        checked = true;
    }
    
    // Right edge mines:  return 5 surrounding tiles
    if(std::find(rightMines.begin(), rightMines.end(), tile) != rightMines.end()) {
        toReturn.push_back(tile - trc - 2);
        toReturn.push_back(tile - trc - 1);
        toReturn.push_back(tile - 1);
        toReturn.push_back(tile + trc);
        toReturn.push_back(tile + trc + 1);
        checked = true;
    }
    
    // Everywhere else:  return 8 surrounding tiles
    if(!checked) {
        toReturn.push_back(tile - trc - 2);
        toReturn.push_back(tile - trc - 1);
        toReturn.push_back(tile - trc);
        toReturn.push_back(tile - 1);
        toReturn.push_back(tile + 1);
        toReturn.push_back(tile + trc);
        toReturn.push_back(tile + trc + 1);
        toReturn.push_back(tile + trc + 2);
    }
    
    return toReturn;
}

void Game::checkTile(int tile) {
    if(mines[tile] == 'm') {
        int mineCounter = 0;
        std::vector<int> toCheck = returnCheckMines(tile);
        for(int i = 0; i < toCheck.size(); i++) {
            if(mines[i] == 'm') mineCounter++;
        }
        mines[tile] = '0' + mineCounter;
    }
}

bool Game::getSolved() {
    return solved;
}

void Game::setSolved(bool b) {
    solved = b;
}

