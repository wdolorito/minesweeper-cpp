/* MinePanel.hxx */
#ifndef MINEPANEL_HXX
#define MINEPANEL_HXX

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/panel.h>
#include <vector>
#include "MenuPanel.hxx"
#include "Game.hxx"
#include "Novice.hxx"
// #include "Intermediate.hxx"
// #include "Expert.hxx"

class MainFrame;
class MenuPanel;
class Game;

class MinePanel : public wxPanel {
    public:
        MinePanel(wxPanel *parent);
        void setMenuPanel(MenuPanel *menuPanel);
        void setMainFrame(MainFrame *mainFrame);
        int getNumMines();
        int getUnflaggedMines();
        void newGame(std::string diff, bool firstRun = true);
        void setTileIcons(std::string setName);

    private:
        Game *currentGame;
        wxBoxSizer *container;
        wxGridSizer *mineField;
        MainFrame *topLevel;
        MenuPanel *menuPanel;

        std::vector<int> *runningGame;
        std::vector<char> *mines;
        int unflaggedMines;
        bool gameRunning;

        wxImage *initial,
                *empty,
                *one,
                *two,
                *three,
                *four,
                *five,
                *six,
                *seven,
                *eight,
                *flag,
                *bomb,
                *exploded;

        void newGame();
        void setTileIcons();
        void setupBoard();
        void setupPanel();

        wxButton* getMineButton(int pos);
        void doLeftClick(wxMouseEvent& event);
        void doRightClick(wxMouseEvent& event);

        void validateGame();
        void endGame(int buttonIndex);
        void winGame();
};

#endif /* MINEPANEL_HXX */
