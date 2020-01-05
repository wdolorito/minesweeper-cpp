/* Novice.hxx */
#ifndef NOVICE_HXX
#define NOVICE_HXX

#include "Game.hxx"

class Novice : public Game {
    private:
        int MINES;
        int TRC;
        int ROWS;
        int BRC;
        int BLC;

        wxSize *BOARD;

    public:
        Novice();
        int getNumberOfMines();
        const wxSize * getBoardSize();
        int getTRC();
        int getBLC();
        int getBRC();
        int getRows();
};
#endif /* NOVICE_HXX */
