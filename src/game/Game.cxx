/* Game.cxx */
#include "Game.hxx"

void Game::checkTile(int tile, std::vector <char> *board) {
    if(board->at(tile) != 'm') {
        int mineCounter = 0;
        std::vector<int> *toCheck = returnCheckMines(tile);

        int checkSize = toCheck->size();
        for(int i = 0; i < checkSize; i++) {
            if(board->at(toCheck->at(i)) == 'm') mineCounter += 1;
        }
        board->at(tile) = '0' + mineCounter;
    }
}

std::vector<int> * Game::returnCheckMines(int tile) {
    std::vector<int> *toReturn = new std::vector<int>();
    bool checked = false;

    // Top left corner:  return 3 surrounding tiles
    if(tile == 0) {
        toReturn->push_back(tile + 1);
        toReturn->push_back(tile + trc + 1);
        toReturn->push_back(tile + trc + 2);
        checked = true;
    }

    // Top edge mines:  return 5 surrounding tiles
    if(std::find(topMines->begin(),
                 topMines->end(),
                 tile) != topMines->end()) {
        toReturn->push_back(tile - 1);
        toReturn->push_back(tile + 1);
        toReturn->push_back(tile + trc);
        toReturn->push_back(tile + trc + 1);
        toReturn->push_back(tile + trc + 2);
        checked = true;
    }

    // Top right corner:  return 3 surrounding tiles
    if(tile == trc) {
        toReturn->push_back(tile - 1);
        toReturn->push_back(tile + trc);
        toReturn->push_back(tile + trc + 1);
        checked = true;
    }

    // Left edge mines:  return 5 surrounding tiles
    if(std::find(leftMines->begin(),
                 leftMines->end(),
                 tile) != leftMines->end()) {
        toReturn->push_back(tile - trc - 1);
        toReturn->push_back(tile - trc);
        toReturn->push_back(tile + 1);
        toReturn->push_back(tile + trc + 1);
        toReturn->push_back(tile + trc + 2);
        checked = true;
    }

    // Bottom left corner:  return 3 surrounding tiles
    if(tile == blc) {
        toReturn->push_back(tile - trc - 1);
        toReturn->push_back(tile - trc);
        toReturn->push_back(tile + 1);
        checked = true;
    }

    // Bottom edge mines:  return 5 surrounding tiles
    if(std::find(bottomMines->begin(),
                 bottomMines->end(),
                 tile) != bottomMines->end()) {
        toReturn->push_back(tile - trc - 2);
        toReturn->push_back(tile - trc - 1);
        toReturn->push_back(tile - trc);
        toReturn->push_back(tile - 1);
        toReturn->push_back(tile + 1);
        checked = true;
    }

    // Bottom right corner:  return 3 surrounding tiles
    if(tile == brc) {
        toReturn->push_back(tile - trc - 2);
        toReturn->push_back(tile - trc - 1);
        toReturn->push_back(tile - 1);
        checked = true;
    }

    // Right edge mines:  return 5 surrounding tiles
    if(std::find(rightMines->begin(),
                 rightMines->end(),
                 tile) != rightMines->end()) {
        toReturn->push_back(tile - trc - 2);
        toReturn->push_back(tile - trc - 1);
        toReturn->push_back(tile - 1);
        toReturn->push_back(tile + trc);
        toReturn->push_back(tile + trc + 1);
        checked = true;
    }

    // Everywhere else:  return 8 surrounding tiles
    if(!checked) {
        toReturn->push_back(tile - trc - 2);
        toReturn->push_back(tile - trc - 1);
        toReturn->push_back(tile - trc);
        toReturn->push_back(tile - 1);
        toReturn->push_back(tile + 1);
        toReturn->push_back(tile + trc);
        toReturn->push_back(tile + trc + 1);
        toReturn->push_back(tile + trc + 2);
    }

    return toReturn;
}

void Game::generateMines() {
    srand(time(NULL));
    int rando;
    int numMines = getNumberOfMines();

    for(int i = 0; i < numMines; i++) {
        rando = rand() % brc;
        if(mines->at(rando) != 'm') {
            mines->at(rando) = 'm';
        } else {
            i--;
        }
    }
}

void Game::populateField() {
    for(int i = 0; i < mines->size(); i++) {
        checkTile(i, mines);
    }
}

void Game::setEdgeMines() {
    trc = getTRC() - 1;
    blc = getBLC() - 1;
    brc = getBRC() - 1;

    topMines = new std::vector<int>();
    leftMines = new std::vector<int>();
    rightMines = new std::vector<int>();
    bottomMines = new std::vector<int>();

    for(int i = 1; i < trc; i++) {
        topMines->push_back(i);
    }

    for(int i = trc + 1; i < blc; i += trc + 1) {
        leftMines->push_back(i);
    }

    for(int i = trc + trc + 1; i < brc - trc; i += trc + 1) {
        rightMines->push_back(i);
    }

    for(int i = blc + 1; i < brc; i++) {
        bottomMines->push_back(i);
    }
}

Game::Game() {
    solved = false;
    gameRunning = true;
}

std::vector<char> * Game::checkPos(int i) {
    if(runningGame->at(i) == '.' && mines->at(i) != 'm') {
        char currTile = mines->at(i);
        runningGame->at(i) = currTile;
        std::cout << currTile << std::endl;
        if(currTile == '0') {
            std::vector<int> *toCheck = returnCheckMines(i);
            int cSize = toCheck->size();
            for(int j = 0; j < cSize; j++) {
                int newPos = toCheck->at(j);
                if(mines->at(newPos) != 'm') checkPos(newPos);
            }
        }

        solved = std::equal(mines->begin(), mines->end(), runningGame->begin());
        if(solved) gameRunning = false;
    } else {
        runningGame->at(i) = mines->at(i);
        gameRunning = false;
    }

    return runningGame;
}

std::vector<char> * Game::getRunningGame() {
    return runningGame;
}

bool Game::getRunning() {
    return gameRunning;
}

bool Game::getSolved() {
    return solved;
}

void Game::resetMines() {
    setEdgeMines();

    int vSize = ((trc + 1) * getRows());
    mines = new std::vector<char>(vSize);
    runningGame = new std::vector<char>(vSize);
    for(int i = 0; i < vSize; i++) {
        mines->at(i) = '.';
        runningGame->at(i) = '.';
    }

    generateMines();
    populateField();
}
