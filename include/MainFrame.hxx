/* MainFrame.hxx */
#ifndef MAINFRAME_HXX
#define MAINFRAME_HXX

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "MinePanel.hxx"
#include "MenuPanel.hxx"

class MinePanel;
class MenuPanel;

class MainFrame : public wxFrame {
    private:
        static const int nID;
        static const int iID;
        static const int eID;
        static const int set1ID;
        static const int set2ID;
        int padding;
        wxBoxSizer *hSizer;
        wxBoxSizer *vSizer;
        wxPanel *topLevel;
        wxMenuBar *menuBar;
        wxMenu *game;
        wxMenu *help;
        wxMenu *tileSet;
        MenuPanel *menuPanel;
        MinePanel *minePanel;

        void setupFrame();
        void setupMenus();
        void setupPanels();
        void OnAbout(wxCommandEvent& event);
        void OnGame(wxCommandEvent& event);
        void OnGame(std::string difficulty);
        void OnTile(wxCommandEvent& event);
        void OnTile(std::string set);
        void OnHelp(wxCommandEvent& event);
        void OnQuit(wxCommandEvent& event);

        wxDECLARE_EVENT_TABLE();

    public:
        MainFrame(const wxString& title);
        void redrawAll();
};

#endif /* MAINFRAME_HXX */
