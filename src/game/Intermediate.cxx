/* Intermediate.cxx */
#include "Intermediate.hxx"

Intermediate::Intermediate() {
    MINES = 40;
    TRC = 16;
    ROWS = TRC;
    BRC = TRC * ROWS;
    BLC = BRC - TRC + 1;
    BOARD = new wxSize(TRC * imageScale, ROWS * imageScale);

    resetMines();
}

int Intermediate::getNumberOfMines() {
    return MINES;
}

const wxSize * Intermediate::getBoardSize() {
    return BOARD;
}

int Intermediate::getTRC() {
    return TRC;
}

int Intermediate::getBLC() {
    return BLC;
}

int Intermediate::getBRC() {
    return BRC;
}

int Intermediate::getRows() {
    return ROWS;
}
