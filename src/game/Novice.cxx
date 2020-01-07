/* Novice.cxx */
#include "Novice.hxx"

Novice::Novice() {
    MINES = 10;
    TRC = 9;
    ROWS = TRC;
    BRC = TRC * ROWS;
    BLC = BRC - TRC + 1;
    BOARD = new wxSize(TRC * imageScale, ROWS * imageScale);

    resetMines();
}

int Novice::getNumberOfMines() {
    return MINES;
}

const wxSize * Novice::getBoardSize() {
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
