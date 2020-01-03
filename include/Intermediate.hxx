/* Intermediate.hxx */
#ifndef INTERMEDIATE_HXX
#define INTERMEDIATE_HXX

#include "Game.hxx"

class Intermediate : public Game {
    private:
        static const int MINES;
        static const int TRC;
        static const int ROWS;
        static const int BRC;
        static const int BLC;

        static const wxSize *BOARD;

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
