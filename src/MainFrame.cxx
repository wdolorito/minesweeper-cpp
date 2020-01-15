/* MainFrame.cxx */
#include "MainFrame.hxx"

const int MainFrame::nID = wxNewId();
const int MainFrame::iID = wxNewId();
const int MainFrame::eID = wxNewId();
const int MainFrame::set1ID = wxNewId();
const int MainFrame::set2ID = wxNewId();
const int MainFrame::padding = 10;
wxMenuBar *MainFrame::menuBar = new wxMenuBar();
wxMenu *MainFrame::tileSet = new wxMenu();
wxMenu *MainFrame::game = new wxMenu();
wxMenu *MainFrame::help = new wxMenu();

MainFrame::MainFrame(const wxString& title) :
    wxFrame(NULL,
            wxID_ANY,
            title,
            wxDefaultPosition,
            wxDefaultSize,
            wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)) {
    doSetup();
}

/*
 *  Setup fns
 *
 */

void MainFrame::doSetup() {
    wxImage::AddHandler(new wxPNGHandler);
    menuPanel = new MenuPanel(this);

    setupMenus();
    setupMinePanel();
    minePanel->newGame("Novice");
    setupFrame(true);
    redrawAll();
}

void MainFrame::setupMenus() {
    tileSet->Append(set1ID, "Set 1");
    tileSet->Append(set2ID, "Set 2");

    game->Append(wxID_ABOUT, "&About Minesweeper\tCTRL+A");
    game->Append(nID, "Novice");
    game->Append(iID, "Intermediate");
    game->Append(eID, "Expert");
    game->Append(-1, "Tile Set", tileSet);
    game->Append(wxID_EXIT, "&Quit Minesweeper\tCTRL+Q");
    menuBar->Append(game, "&Game");

    help = new wxMenu();
    help->Append(wxID_HELP, "Minesweeper Help");
    menuBar->Append(help, "Help");

    SetMenuBar(menuBar);
}

void MainFrame::setupMinePanel() {
    minePanel = new MinePanel(this);
    minePanel->setMenuPanel(menuPanel);
}

void MainFrame::setupFrame(bool firstRun) {
    if(firstRun) {
        hSizer = new wxBoxSizer(wxHORIZONTAL);
        vSizer = new wxBoxSizer(wxVERTICAL);
    } else {
        hSizer->Clear();
        vSizer->Clear();
    }

    vSizer->AddSpacer(padding);
    vSizer->Add(menuPanel, 2, wxALIGN_CENTER);
    vSizer->AddSpacer(padding);
    vSizer->Add(minePanel, 8, wxALIGN_CENTER);
    vSizer->AddSpacer(padding);

    hSizer->AddSpacer(padding);
    hSizer->Add(vSizer, wxALIGN_CENTER);
    hSizer->AddSpacer(padding);

    SetSizer(hSizer);
    hSizer->SetSizeHints(this);
}

/*
 *  Private fns
 *
 */

void MainFrame::redrawAll() {
    menuPanel->Fit();
    wxSize menuSize = menuPanel->GetBestSize();
    wxSize mineSize = minePanel->GetClientSize();

    int width = mineSize.GetWidth() + 25;
    int height = menuSize.GetHeight() + mineSize.GetHeight() + 25;

    wxSize minSize = wxSize(width, height);

    SetSize(minSize);
}

/*
 *  Public fns
 *
 */

 void MainFrame::newGameFromCombo(wxString difficulty) {
     OnGame(difficulty);
 }

/*
 *  Event Handlers
 *
 */

void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event)) {
    wxString msg = "wdolorito@gmail.com";
    msg += "\n\nIcons made by Freepik";
    msg += "\n\thttps://www.flaticon.com/authors/freepik";
    msg += "\n\nfrom Flaticon";
    msg += "\n\thttps://www.flaticon.com/";
    wxMessageBox(msg, "About Minesweeper", wxOK | wxICON_INFORMATION );
}

void MainFrame::OnGame(wxCommandEvent& event) {
    int id = event.GetId();

    if(id == nID) OnGame("Novice");
    if(id == iID) OnGame("Intermediate");
    if(id == eID) OnGame("Expert");
}

void MainFrame::OnGame(wxString difficulty) {
    menuPanel->setDiff(difficulty);
    minePanel->Destroy();
    setupMinePanel();
    minePanel->newGame(difficulty);
    setupFrame(true);
    redrawAll();
}

void MainFrame::OnTile(wxCommandEvent& event) {
    int id = event.GetId();

    if(id == set1ID) OnTile("set1/");
    if(id == set2ID) OnTile("set2/");
}

void MainFrame::OnTile(wxString set) {
    minePanel->setTileIcons(set, false);
}

void MainFrame::OnHelp(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox("Reveal tiles with left click\nMark mines with right click",
                 "Help", wxOK | wxICON_INFORMATION );
}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event)) {
    Close(true);
}

/*
 *  Event Table
 *
 */

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
