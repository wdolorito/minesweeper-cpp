#include "MinePanel.hxx"

MinePanel::MinePanel(wxPanel * parent):
        wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize) {
    topLevel = parent;
}

void MinePanel::setMenuPanel(MenuPanel * menuPanel) {
    this->menuPanel = menuPanel;
    runningSolution = new std::vector<int>();
    newGame();
    initPanel();
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
    initBoard();
}

void MinePanel::initPanel() {
    container = new wxBoxSizer(wxVERTICAL);
    mineField = new wxGridSizer(9, 9, 0, 0);

    for(int i = 0; i < 81; i++) {
        mineField->Add(new wxStaticText(this,
                                    wxID_ANY,
                                    "0",
                                    wxDefaultPosition,
                                    wxDefaultSize,
                                    wxALIGN_CENTER));
    }

    container->Add(mineField, 0, wxEXPAND);
    SetSizer(container);
    Center();
    menuPanel->startTimer();
}

void MinePanel::setTileIcons() {
}

void MinePanel::setTileIcons(std::string setName) {
}

void MinePanel::initBoard() {
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
