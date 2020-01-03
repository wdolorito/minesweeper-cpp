/* Expert.cxx */
#include "Expert.hxx"

const int Expert::MINES = 99;
const int Expert::TRC = 30;
const int Expert::ROWS = 16;
const int Expert::BRC = Expert::TRC * Expert::ROWS;
const int Expert::BLC = Expert::BRC - Expert::TRC + 1;

const wxSize * Expert::BOARD = new wxSize(Expert::TRC * 40, Expert::ROWS * 40);

Expert::Expert() {
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
