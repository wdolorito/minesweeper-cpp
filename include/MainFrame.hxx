/* MainFrame.hxx */
#ifndef MAINFRAME_HXX
#define MAINFRAME_HXX

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "MenuPanel.hxx"
#include "MinePanel.hxx"

class MenuPanel;
class MinePanel;

class MainFrame : public wxFrame {
    private:
        static const int padding;
        static const wxColour *BACKGROUND;

        static int nID;
        static int iID;
        static int eID;
        static int set1ID;
        static int set2ID;

        wxMenuBar *menuBar;
        wxMenu *tileSet;
        wxMenu *game;
        wxMenu *help;
        wxIcon icon;

        MenuPanel *menuPanel;
        wxBoxSizer *hSizer;
        wxBoxSizer *vSizer;
        MinePanel *minePanel;

        void doSetup();
        void setupMenus();
        void setupMinePanel();
        void setupFrame();
        void redrawAll();

        void OnAbout(wxCommandEvent& event);
        void OnGame(wxCommandEvent& event);
        void OnGame(wxString difficulty);
        void OnTile(wxCommandEvent& event);
        void OnTile(wxString set);
        void OnHelp(wxCommandEvent& event);
        void OnQuit(wxCommandEvent& event);

        wxDECLARE_EVENT_TABLE();

    public:
        MainFrame(const wxString& title);
        void newGameFromChoice(wxString difficulty);
};

#endif /* MAINFRAME_HXX */
