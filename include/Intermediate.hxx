#ifndef INTERMEDIATE_HXX
#define INTERMEDIATE_HXX

#include "Game.hxx"

class Intermediate: public Game {
    private:
        int MINES,
            TRC,
            ROWS,
            BRC,
            BLC;

        wxSize BOARD;

    public:
        Intermediate();
        int getNumberOfMines();
        wxSize getBoardSize();
        int getTRC();
        int getBLC();
        int getBRC();
        int getRows();
};
#endif /* INTERMEDIATE_HXX */

