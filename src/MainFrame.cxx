/* MainFrame.cxx */
#include "MainFrame.hxx"

MainFrame::MainFrame(const wxString& title):
    wxFrame(NULL,
            wxID_ANY,
            title,
            wxDefaultPosition,
            wxDefaultSize) {
    topLevel = new wxPanel(this, wxID_ANY);

    padding = 10;
    hSizer = new wxBoxSizer(wxHORIZONTAL);
    vSizer = new wxBoxSizer(wxVERTICAL);

    menuPanel = new MenuPanel(topLevel);
    minePanel = new MinePanel(topLevel);

    menuPanel->setMinePanel(minePanel);
    minePanel->setMenuPanel(menuPanel);

    menuPanel->setMainFrame(this);
    minePanel->setMainFrame(this);

    vSizer->AddSpacer(padding);
    vSizer->Add(menuPanel, 2, wxALIGN_CENTER);
    vSizer->AddSpacer(padding);
    vSizer->Add(minePanel, 8, wxALIGN_CENTER);
    vSizer->AddSpacer(padding);

    hSizer->AddSpacer(padding);
    hSizer->Add(vSizer);
    hSizer->AddSpacer(padding);

    topLevel->SetSizer(hSizer);

    menuBar = new wxMenuBar;
    game = new wxMenu;
    game->Append(wxID_ABOUT, "&About Minesweeper\tCTRL+A");
    game->Append(wxID_EXIT, "&Quit Minesweeper\tCTRL+Q");
    menuBar->Append(game, "&Game");

    help = new wxMenu;
    help->Append(wxID_HELP, "Minesweeper Help");
    menuBar->Append(help, "Help");

    #ifdef __WXMAC__
    // menuBar->Remove(0);
    // delete game;
    #endif

    SetMenuBar(menuBar);
}

void MainFrame::redrawAll() {
    int screenWidth = wxSystemSettings::GetMetric ( wxSYS_SCREEN_X );
    int screenHeight = wxSystemSettings::GetMetric ( wxSYS_SCREEN_Y );

    // wxSize currentSize = GetSize();
    wxSize menuSize = menuPanel->GetBestSize();
    wxSize mineSize = minePanel->GetSize();

    int width = mineSize.GetWidth();
    int height = menuSize.GetHeight() + mineSize.GetHeight();

    wxSize minSize = wxSize(width, height);

    // if(currentSize.GetWidth() < width) {
    //     SetMaxSize(minSize);
    //     SetMinSize(minSize);
    // } else {
        SetMinSize(minSize);
        SetMaxSize(minSize);
    // }
    SetSize(20, 20, width, height, wxSIZE_FORCE);
    // Layout();
    // Refresh();
    // Update();


    std::cout << "screen\theight:\t" << screenHeight << std::endl;
    std::cout << "screen\twidth:\t" << screenWidth << std::endl;

    std::cout << "mine\theight:\t" << minePanel->GetSize().GetHeight() << std::endl;
    std::cout << "mine\twidth:\t" << minePanel->GetSize().GetWidth() << std::endl;
    std::cout << "menu\theight:\t" << menuPanel->GetSize().GetHeight() << std::endl;
    std::cout << "menu\twidth:\t" << menuPanel->GetSize().GetWidth() << std::endl;
}

void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox("wdolorito@gmail.com",
                 "About Minesweeper", wxOK | wxICON_INFORMATION );
}

void MainFrame::OnHelp(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox("Reveal tiles with left click\nMark mines with right click",
                 "Help", wxOK | wxICON_INFORMATION );
}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event)) {
    Close(true);
}

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(wxID_EXIT,  MainFrame::OnQuit)
    EVT_MENU(wxID_HELP,  MainFrame::OnHelp)
    EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
wxEND_EVENT_TABLE()
