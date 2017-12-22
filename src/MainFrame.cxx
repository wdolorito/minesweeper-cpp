/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MainFrame.cxx
 * Author: d0odman
 *
 * Created on December 20, 2017, 10:25 PM
 */

#include "MainFrame.hxx"

MainFrame::MainFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150)) {
    topLevel = new wxPanel(this, wxID_ANY);

    wxBoxSizer *container = new wxBoxSizer(wxVERTICAL);

    menuPanel = new MenuPanel(topLevel);
    minePanel = new MinePanel(topLevel);

    wxSize menuPanelSize = wxSize(480, 10);
    wxSize minePanelSize = wxSize(480, 400);
    menuPanel->SetMinSize(menuPanelSize);
    menuPanel->SetMaxSize(menuPanelSize);
    minePanel->SetMinSize(minePanelSize);
    minePanel->SetMaxSize(minePanelSize);

    minePanel->newGame("abc");

    wxSize *boardSize = minePanel->currentGame->getBoardSize();

    container->Add(menuPanel, 1, wxEXPAND | wxALL, 5);
    container->Add(minePanel, 9, wxEXPAND | wxALL, 5);

    topLevel->SetSizer(container);
    wxSize maxSize = wxSize(480, 410);
    topLevel->SetMinSize(maxSize);
    topLevel->SetMaxSize(maxSize);
    container->SetSizeHints(this);

    menuBar = new wxMenuBar;
    game = new wxMenu;
    game->Append(wxID_EXIT, wxT("&Quit\tCtrl-Q"));
    menuBar->Append(game, wxT("&Game"));

    #ifdef __WXMAC__
    menuBar->Remove(0);
    #endif

    SetMenuBar(menuBar);

    Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED,
      wxCommandEventHandler(MainFrame::OnQuit));
    Center();
}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}