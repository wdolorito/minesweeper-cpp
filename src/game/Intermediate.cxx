/* Intermediate.cxx */
#include "Intermediate.hxx"

const int Intermediate::MINES = 40;
const int Intermediate::TRC = 16;
const int Intermediate::ROWS = Intermediate::TRC;
const int Intermediate::BRC = Intermediate::TRC * Intermediate::ROWS;
const int Intermediate::BLC = Intermediate::BRC - Intermediate::TRC + 1;

const wxSize * Intermediate::BOARD = new wxSize(Intermediate::TRC * 40, Intermediate::ROWS * 40);

Intermediate::Intermediate() {
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
