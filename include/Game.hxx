#ifndef GAME_HXX
#define GAME_HXX

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <vector>

class Game
{
    private:
        std::vector <char> mines;
        std::vector <int> topMines,
                          leftMines,
                          rightMines,
                          bottomMines,
                          solution;
        int trc,
            blc,
            brc;

        bool solved;

    public:
        std::vector<char> getMines();
        void resetMines();
        void setEdgeMines();
        void generateMines();
        std::vector<int> returnSolution();
//        std::vector<int> returnCheckMines(int tile);
        void checkTile(int tile);
        virtual int getNumberOfMines() = 0;
        virtual wxSize getBoardSize() = 0;
        virtual int getTRC() = 0;
        virtual int getBLC() = 0;
        virtual int getBRC() = 0;
        virtual int getRows() = 0;
};

#endif

