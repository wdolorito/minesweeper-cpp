/* Novice.hxx */
#ifndef NOVICE_HXX
#define NOVICE_HXX

#include "Game.hxx"

class Novice : public Game {
    private:
        static const int MINES;
        static const int TRC;
        static const int ROWS;
        static const int BRC;
        static const int BLC;

        static const wxSize *BOARD;

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
