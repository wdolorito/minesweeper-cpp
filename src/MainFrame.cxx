/* MainFrame.cxx */
#include "MainFrame.hxx"

const int MainFrame::nID = wxNewId();
const int MainFrame::iID = wxNewId();
const int MainFrame::eID = wxNewId();

MainFrame::MainFrame(const wxString& title):
    wxFrame(NULL,
            wxID_ANY,
            title,
            wxDefaultPosition,
            wxDefaultSize) {
    padding = 10;

    setupMenus();
    setupPanels();
    setupFrame();
}

void MainFrame::setupFrame() {
    hSizer = new wxBoxSizer(wxHORIZONTAL);
    vSizer = new wxBoxSizer(wxVERTICAL);

    vSizer->AddSpacer(padding);
    vSizer->Add(menuPanel, 2, wxALIGN_CENTER);
    vSizer->AddSpacer(padding);
    vSizer->Add(minePanel, 8, wxALIGN_CENTER);
    vSizer->AddSpacer(padding);

    hSizer->AddSpacer(padding);
    hSizer->Add(vSizer);
    hSizer->AddSpacer(padding);

    topLevel->SetSizer(hSizer);
    // hSizer->SetSizeHints(this);
}

void MainFrame::setupMenus() {
    menuBar = new wxMenuBar;
    game = new wxMenu;
    game->Append(wxID_ABOUT, "&About Minesweeper\tCTRL+A");
    game->Append(nID, "Novice");
    game->Append(iID, "Intermediate");
    game->Append(eID, "Expert");
    game->Append(wxID_EXIT, "&Quit Minesweeper\tCTRL+Q");
    menuBar->Append(game, "&Game");

    help = new wxMenu;
    help->Append(wxID_HELP, "Minesweeper Help");
    menuBar->Append(help, "Help");

    SetMenuBar(menuBar);
}

void MainFrame::setupPanels() {
    topLevel = new wxPanel(this, wxID_ANY);
    menuPanel = new MenuPanel(topLevel);
    minePanel = new MinePanel(topLevel);

    menuPanel->setMinePanel(minePanel);
    minePanel->setMenuPanel(menuPanel);

    menuPanel->setMainFrame(this);
    minePanel->setMainFrame(this);
}

void MainFrame::redrawAll() {
    int screenWidth = wxSystemSettings::GetMetric ( wxSYS_SCREEN_X );
    int screenHeight = wxSystemSettings::GetMetric ( wxSYS_SCREEN_Y );

    wxSize currentSize = GetSize();
    wxSize menuSize = menuPanel->GetSize();
    wxSize mineSize = minePanel->GetSize();

    int width = mineSize.GetWidth();
    int height = menuSize.GetHeight() + mineSize.GetHeight();

    wxSize minSize = wxSize(width, height);
    wxSize maxSize = wxSize(width + 1, height + 1);

    // if(currentSize.GetWidth() < width) {
    //     SetMaxSize(minSize);
    //     SetMinSize(minSize);
    // } else {
        SetMinSize(minSize);
        SetMaxSize(maxSize);
    // }
    // SetSize(minSize);
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

void MainFrame::OnGame(wxCommandEvent& event) {
    int id = event.GetId();
    std::cout << id << std::endl;

    if(id == nID) OnGame("Novice");
    if(id == iID) OnGame("Intermediate");
    if(id == eID) OnGame("Expert");
}

void MainFrame::OnGame(std::string difficulty) {
    std::string msg = difficulty + " game";
    wxMessageBox(msg, difficulty, wxOK | wxICON_INFORMATION );
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
    EVT_MENU(nID, MainFrame::OnGame)
    EVT_MENU(iID, MainFrame::OnGame)
    EVT_MENU(eID, MainFrame::OnGame)
wxEND_EVENT_TABLE()
