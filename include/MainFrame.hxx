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
        static const int nID;
        static const int iID;
        static const int eID;
        static const int set1ID;
        static const int set2ID;
        static const int padding;
        static wxMenuBar *menuBar;
        static wxMenu *tileSet;
        static wxMenu *game;
        static wxMenu *help;

        MenuPanel *menuPanel;
        wxBoxSizer *hSizer;
        wxBoxSizer *vSizer;
        MinePanel *minePanel;

        void doSetup();
        void setupMenus();
        void setupMinePanel();
        void setupFrame(bool firstRun);
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
        void newGameFromCombo(wxString difficulty);
};

#endif /* MAINFRAME_HXX */
