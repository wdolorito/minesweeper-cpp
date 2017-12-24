#include "MainFrame.hxx"

MainFrame::MainFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxDefaultSize) {
    topLevel = new wxPanel(this, wxID_ANY);

    wxBoxSizer *container = new wxBoxSizer(wxVERTICAL);

    menuPanel = new MenuPanel(topLevel);
    minePanel = new MinePanel(topLevel);

    menuPanel->setMinePanel(minePanel);
    minePanel->setMenuPanel(menuPanel);

    container->Add(menuPanel, 1, wxEXPAND);
    container->Add(minePanel, 9, wxEXPAND);

    topLevel->SetSizer(container);

    menuBar = new wxMenuBar;
    game = new wxMenu;
    game->Append(wxID_ABOUT, "&About Minesweeper\tCTRL+A");
    game->Append(wxID_EXIT, "&Quit Minesweeper\tCTRL+Q");
    menuBar->Append(game, "&Game");

    #ifdef __WXMAC__
//    menuBar->Remove(0);
    #endif

    SetMenuBar(menuBar);

    Center();
}

void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox( "wdolorito@gmail.com",
                  "About Minesweeper", wxOK | wxICON_INFORMATION );
}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(wxID_EXIT,  MainFrame::OnQuit)
    EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
wxEND_EVENT_TABLE()
