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

class Game;
class MenuPanel;

class MinePanel : public wxPanel {
    private:
        static const int imageScale;
        static const wxString delimiter;

        Game *currentGame;
        MenuPanel *menuPanel;
        bool gameRunning;
        std::vector<char> *mines;
        wxBoxSizer *container;
        wxGridSizer *mineField;
        wxImage *initial;
        wxImage *empty;
        wxImage *one;
        wxImage *two;
        wxImage *three;
        wxImage *four;
        wxImage *five;
        wxImage *six;
        wxImage *seven;
        wxImage *eight;
        wxImage *flag;
        wxImage *bomb;
        wxImage *exploded;

        void newGame();
        void setTileIcons();
        void setupBoard();
        void setupPanel();

        wxButton* getMineButton(int pos);
        wxStaticBitmap* getStaticBitmap(wxImage *image);

        void doLeftClick(wxMouseEvent& event);
        void doRightClick(wxMouseEvent& event);

        void drawBoard();
        void updateButton(wxButton* button, int pos);
        void endGame(int buttonIndex, bool loss);
        void winGame();

    public:
        MinePanel(wxFrame *parent);
        void setMenuPanel(MenuPanel *menuPanel);
        int getNumMines();
        void newGame(std::string diff, bool firstRun);
        void setTileIcons(std::string setName, bool firstRun);
};

#endif /* MINEPANEL_HXX */
