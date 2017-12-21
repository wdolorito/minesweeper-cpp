#ifndef NOVICE_HXX
#define NOVICE_HXX

#include "Game.hxx"

class Novice: public Game {
    private:
        int MINES,
            TRC,
            ROWS,
            BRC,
            BLC;

        wxSize *BOARD;

    public:
        Novice();
        int getNumberOfMines();
        wxSize * getBoardSize();
        int getTRC();
        int getBLC();
        int getBRC();
        int getRows();
};
#endif /* NOVICE_HXX */
