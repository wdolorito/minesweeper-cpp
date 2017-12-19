#include "Novice.hxx"

Novice::Novice() {
    MINES = 10;
    TRC = 9;
    ROWS = TRC;
    BRC = TRC * ROWS;
    BLC = BRC - TRC + 1;
    BOARD = wxSize(TRC * 20 + 60, ROWS * 20 + 60);
    resetMines();
}

int Novice::getNumberOfMines() {
    return MINES;
}

wxSize Novice::getBoardSize() {
    return BOARD;
}

int Novice::getTRC() {
    return TRC;
}

int Novice::getBLC() {
    return BLC;
}

int Novice::getBRC() {
    return BRC;
}

int Novice::getRows() {
    return ROWS;
}

