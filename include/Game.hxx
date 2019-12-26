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
        void setSolved(bool b);
        std::vector<int> * returnCheckMines(int tile);

    protected:
        void setEdgeMines();
        void generateMines();
        void populateField();

    public:
        Game();
        std::vector<char> * getMinefield();
        void resetMines();
        void checkTile(int tile);
        bool getSolved();
        virtual int getNumberOfMines() = 0;
        virtual wxSize * getBoardSize() = 0;
        virtual int getTRC() = 0;
        virtual int getBLC() = 0;
        virtual int getBRC() = 0;
        virtual int getRows() = 0;
};

#endif /* GAME_HXX */
