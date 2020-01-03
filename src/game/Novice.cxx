/* Novice.cxx */
#include "Novice.hxx"

const int Novice::MINES = 10;
const int Novice::TRC = 9;
const int Novice::ROWS = Novice::TRC;
const int Novice::BRC = Novice::TRC * Novice::ROWS;
const int Novice::BLC = Novice::BRC - Novice::TRC + 1;

const wxSize * Novice::BOARD = new wxSize(Novice::TRC * 40, Novice::ROWS * 40);

Novice::Novice() {
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
