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
    game->Append(wxID_ABOUT);
    game->Append(wxID_EXIT);
    menuBar->Append(game, wxT("&Game"));

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