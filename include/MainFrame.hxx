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
        int padding;
        wxBoxSizer *hSizer;
        wxBoxSizer *vSizer;
        wxPanel *topLevel;
        wxMenuBar *menuBar;
        wxMenu *game;
        wxMenu *help;
        MenuPanel *menuPanel;
        MinePanel *minePanel;

        void setupFrame();
        void setupMenus();
        void setupPanels();
        void OnAbout(wxCommandEvent& event);
        void OnGame(wxCommandEvent& event);
        void OnGame(std::string difficulty);
        void OnHelp(wxCommandEvent& event);
        void OnQuit(wxCommandEvent& event);

        wxDECLARE_EVENT_TABLE();

    public:
        MainFrame(const wxString& title);
        void redrawAll();
};

#endif /* MAINFRAME_HXX */
