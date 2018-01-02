/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MainFrame.hxx
 * Author: d0odman
 *
 * Created on December 20, 2017, 10:25 PM
 */

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

class MainFrame : public wxFrame
{
    public:
        MainFrame(const wxString& title);
        void redrawAll();

    private:
        int padding;
        wxBoxSizer *hSizer;
        wxBoxSizer *vSizer;
        wxPanel *topLevel;
        wxMenuBar *menuBar;
        wxMenu *game;
        MenuPanel *menuPanel;
        MinePanel *minePanel;

        void OnAbout(wxCommandEvent& event);
        void OnQuit(wxCommandEvent& event);

        wxDECLARE_EVENT_TABLE();
};

#endif /* MAINFRAME_HXX */

