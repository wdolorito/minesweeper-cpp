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
        std::vector <char> *mines;
        std::vector <int> *topMines,
                          *leftMines,
                          *rightMines,
                          *bottomMines,
                          *solution;
        int trc,
            blc,
            brc;

        bool solved;

    protected:
        void setEdgeMines();
        void generateMines();
        void populateField();

    public:
        Game();
        std::vector<char> * getMines();
        void resetMines();
        std::vector<int> * returnSolution();
        std::vector<int> * returnCheckMines(int tile);
        void checkTile(int tile);
        bool getSolved();
        void setSolved(bool b);
        virtual int getNumberOfMines() = 0;
        virtual wxSize * getBoardSize() = 0;
        virtual int getTRC() = 0;
        virtual int getBLC() = 0;
        virtual int getBRC() = 0;
        virtual int getRows() = 0;
};

#endif /* GAME_HXX */
