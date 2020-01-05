/* Expert.hxx */
#ifndef EXPERT_HXX
#define EXPERT_HXX

#include "Game.hxx"

class Expert : public Game {
    private:
        int MINES;
        int TRC;
        int ROWS;
        int BRC;
        int BLC;

        wxSize *BOARD;

    public:
        Expert();
        int getNumberOfMines();
        const wxSize * getBoardSize();
        int getTRC();
        int getBLC();
        int getBRC();
        int getRows();
};
#endif /* EXPERT_HXX */
