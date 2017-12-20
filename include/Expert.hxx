#ifndef EXPERT_HXX
#define EXPERT_HXX

#include "Game.hxx"

class Expert: public Game {
    private:
        int MINES,
            TRC,
            ROWS,
            BRC,
            BLC;

        wxSize BOARD;

    public:
        Expert();
        int getNumberOfMines();
        wxSize getBoardSize();
        int getTRC();
        int getBLC();
        int getBRC();
        int getRows();
};
#endif /* EXPERT_HXX */

