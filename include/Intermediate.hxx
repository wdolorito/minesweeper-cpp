/* Intermediate.hxx */
#ifndef INTERMEDIATE_HXX
#define INTERMEDIATE_HXX

#include "Game.hxx"

class Intermediate : public Game {
    private:
        int MINES;
        int TRC;
        int ROWS;
        int BRC;
        int BLC;

        wxSize *BOARD;

    public:
        Intermediate();
        int getNumberOfMines();
        const wxSize * getBoardSize();
        int getTRC();
        int getBLC();
        int getBRC();
        int getRows();
};
#endif /* INTERMEDIATE_HXX */
