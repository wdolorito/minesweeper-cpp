#include "MinePanel.hxx"

MinePanel::MinePanel(wxPanel * parent):
        wxPanel(parent,
                wxID_ANY,
                wxDefaultPosition,
                wxDefaultSize) {
    topLevel = parent;

    setupHandler();
    setTileIcons();
    setupBoard();
    setupPanel();
}

void MinePanel::setMenuPanel(MenuPanel * menuPanel) {
    this->menuPanel = menuPanel;
    runningSolution = new std::vector<int>();
}

void MinePanel::setupHandler() {
    wxImage::AddHandler(new wxPNGHandler);
}

void MinePanel::setTileIcons() {
    setTileIcons("set1/");
}

void MinePanel::setTileIcons(std::string setName) {
    std::string path = "assets/" + setName;

    initial  = new wxImage(path + "default.png", wxBITMAP_TYPE_PNG);
    empty    = new wxImage(path + "empty.png", wxBITMAP_TYPE_PNG);
    one      = new wxImage(path + "1.png", wxBITMAP_TYPE_PNG);
    two      = new wxImage(path + "2.png", wxBITMAP_TYPE_PNG);
    three    = new wxImage(path + "3.png", wxBITMAP_TYPE_PNG);
    four     = new wxImage(path + "4.png", wxBITMAP_TYPE_PNG);
    five     = new wxImage(path + "5.png", wxBITMAP_TYPE_PNG);
    six      = new wxImage(path + "6.png", wxBITMAP_TYPE_PNG);
    seven    = new wxImage(path + "7.png", wxBITMAP_TYPE_PNG);
    eight    = new wxImage(path + "8.png", wxBITMAP_TYPE_PNG);
    flag     = new wxImage(path + "flag.png", wxBITMAP_TYPE_PNG);
    bomb     = new wxImage(path + "bomb.png", wxBITMAP_TYPE_PNG);
    exploded = new wxImage(path + "exploded.png", wxBITMAP_TYPE_PNG);
}

int MinePanel::getNumMines() {
    return currentGame->getNumberOfMines();
}

int MinePanel::getUnflaggedMines() {
    return 0;
}

void MinePanel::newGame() {
    newGame("Novice");
}

void MinePanel::newGame(std::string diff) {
    if(!diff.compare("Intermediate")) {
        std::cout << "set up Intermediate" << std::endl;
        currentGame = new Intermediate();
    } else if(!diff.compare("Expert")) {
        std::cout << "set up Expert" << std::endl;
        currentGame = new Expert();
    } else {
        std::cout << "set up Novice" << std::endl;
        currentGame = new Novice();
    }

    gameRunning = false;
    solution = currentGame->returnSolution();
}

void MinePanel::setupPanel() {
    container = new wxBoxSizer(wxVERTICAL);
    container->Add(mineField, 0, wxEXPAND);
    SetSizer(container);
    Center();
//    menuPanel->startTimer();
}

void MinePanel::setupBoard() {
    mineField = new wxGridSizer(9, 9, 0, 0);
    for(int i = 0; i < 81; i++) {
        wxButton *temp = new wxButton(this,
                                    wxID_ANY,
                                    wxEmptyString,
                                    wxDefaultPosition,
                                    wxDefaultSize,
                                    wxBU_NOTEXT);
        if(initial->IsOk()) temp->SetBitmap(*initial);
        mineField->Add(temp);
    }
}

void MinePanel::doLeftClick(int buttonIndex) {
}

void MinePanel::doRightClick(int buttonIndex) {
}

void MinePanel::validateGame() {
}

void MinePanel::endGame(int buttonIndex) {
}

void MinePanel::winGame() {
}
