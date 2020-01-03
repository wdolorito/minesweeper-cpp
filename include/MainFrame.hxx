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
        int padding;
        wxBoxSizer *hSizer;
        wxBoxSizer *vSizer;
        wxPanel *topLevel;
        wxMenuBar *menuBar;
        wxMenu *game;
        wxMenu *help;
        MenuPanel *menuPanel;
        MinePanel *minePanel;

        void OnAbout(wxCommandEvent& event);
        void OnHelp(wxCommandEvent& event);
        void OnQuit(wxCommandEvent& event);

        wxDECLARE_EVENT_TABLE();

    public:
        MainFrame(const wxString& title);
        void redrawAll();
};

#endif /* MAINFRAME_HXX */
