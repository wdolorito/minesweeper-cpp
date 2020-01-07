/* MinePanel.hxx */
#ifndef MINEPANEL_HXX
#define MINEPANEL_HXX

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/panel.h>
#include <wx/tokenzr.h>
#include <vector>
#include "MenuPanel.hxx"
#include "Game.hxx"
#include "Novice.hxx"
#include "Intermediate.hxx"
#include "Expert.hxx"

class MainFrame;
class MenuPanel;
class Game;

class MinePanel : public wxPanel {
    private:
        Game *currentGame;
        wxBoxSizer *container;
        wxGridSizer *mineField;
        MainFrame *topLevel;
        MenuPanel *menuPanel;
        wxString delimiter;

        std::vector<char> *mines;
        int imageScale;
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

        void drawBoard();
        void updateButton(wxButton* button, int pos);
        void validateGame();
        void endGame(int buttonIndex, bool loss);
        void winGame();

    public:
        MinePanel(wxPanel *parent);
        void setMenuPanel(MenuPanel *menuPanel);
        void setMainFrame(MainFrame *mainFrame);
        int getNumMines();
        void newGame(std::string diff, bool firstRun = true);
        void setTileIcons(std::string setName);
};

#endif /* MINEPANEL_HXX */
