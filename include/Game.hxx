/* Game.hxx */
#ifndef GAME_HXX
#define GAME_HXX

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <algorithm>
#include <ctime>
#include <vector>

class Game {
    private:
        std::vector <char> *mines,
                           *runningGame;

        std::vector <int> *topMines,
                          *leftMines,
                          *rightMines,
                          *bottomMines;

        int trc,
            blc,
            brc;

        bool solved,
             gameRunning;

        void checkTile(int tile, std::vector <char> *board);
        std::vector<int> * returnCheckMines(int tile);

    protected:
        void generateMines();
        void populateField();
        void setEdgeMines();

    public:
        Game();
        std::vector<char> * checkPos(int i);
        std::vector<char> * getRunningGame();
        bool getRunning();
        bool getSolved();
        void resetMines();

        virtual int getNumberOfMines() = 0;
        virtual const wxSize * getBoardSize() = 0;
        virtual int getTRC() = 0;
        virtual int getBLC() = 0;
        virtual int getBRC() = 0;
        virtual int getRows() = 0;
};

#endif /* GAME_HXX */
