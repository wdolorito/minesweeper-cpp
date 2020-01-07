/* Expert.cxx */
#include "Expert.hxx"

Expert::Expert() {
    MINES = 99;
    TRC = 30;
    ROWS = 16;
    BRC = TRC * ROWS;
    BLC = BRC - TRC + 1;
    BOARD = new wxSize(TRC * 20, ROWS * 20);

    resetMines();
}

int Expert::getNumberOfMines() {
    return MINES;
}

const wxSize * Expert::getBoardSize() {
    return BOARD;
}

int Expert::getTRC() {
    return TRC;
}

int Expert::getBLC() {
    return BLC;
}

int Expert::getBRC() {
    return BRC;
}

int Expert::getRows() {
    return ROWS;
}
