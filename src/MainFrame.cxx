/* MainFrame.cxx */
#include "MainFrame.hxx"

const int MainFrame::nID = wxNewId();
const int MainFrame::iID = wxNewId();
const int MainFrame::eID = wxNewId();
const int MainFrame::set1ID = wxNewId();
const int MainFrame::set2ID = wxNewId();

MainFrame::MainFrame(const wxString& title):
    wxFrame(NULL,
            wxID_ANY,
            title,
            wxDefaultPosition,
            wxDefaultSize,
            wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)) {
    Refresh();
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
    hSizer->Add(vSizer, wxALIGN_CENTER);
    hSizer->AddSpacer(padding);

    topLevel->SetSizer(hSizer);
    hSizer->SetSizeHints(this);
}

void MainFrame::setupMenus() {
    menuBar = new wxMenuBar;

    tileSet = new wxMenu();
    tileSet->Append(set1ID, "Set 1");
    tileSet->Append(set2ID, "Set 2");

    game = new wxMenu;
    game->Append(wxID_ABOUT, "&About Minesweeper\tCTRL+A");
    game->Append(nID, "Novice");
    game->Append(iID, "Intermediate");
    game->Append(eID, "Expert");
    game->Append(-1, "Tile Set", tileSet);
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
    wxSize menuSize = menuPanel->GetClientSize();
    wxSize mineSize = minePanel->GetClientSize();

    int width = mineSize.GetWidth();
    int height = menuSize.GetHeight() + mineSize.GetHeight();

    wxSize minSize = wxSize(width, height);

    SetSize(minSize);

    std::cout << "mine\theight:\t" << minePanel->GetSize().GetHeight() << std::endl;
    std::cout << "mine\twidth:\t" << minePanel->GetSize().GetWidth() << std::endl;
    std::cout << "menu\theight:\t" << menuPanel->GetSize().GetHeight() << std::endl;
    std::cout << "menu\twidth:\t" << menuPanel->GetSize().GetWidth() << std::endl;
    std::cout << "new\theight:\t" << height << std::endl;
    std::cout << "new\twidth:\t" << width << std::endl;
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

void MainFrame::OnTile(wxCommandEvent& event) {
    int id = event.GetId();
    std::cout << id << std::endl;

    if(id == set1ID) OnTile("set1");
    if(id == set2ID) OnTile("set2");
}

void MainFrame::OnTile(std::string set) {
    std::string msg = set + " tile set";
    wxMessageBox(msg, set, wxOK | wxICON_INFORMATION );
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
    EVT_MENU(set1ID, MainFrame::OnTile)
    EVT_MENU(set2ID, MainFrame::OnTile)
wxEND_EVENT_TABLE()
