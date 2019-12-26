#include "MinePanel.hxx"

MinePanel::MinePanel(wxPanel * parent):
    wxPanel(parent,
            wxID_ANY,
            wxDefaultPosition,
            wxDefaultSize) {
    runningGame = new std::vector<int>();
    mineField = new wxGridSizer(0, 0, 0);
}

void MinePanel::setMenuPanel(MenuPanel * menuPanel) {
    this->menuPanel = menuPanel;
}

void MinePanel::setMainFrame(MainFrame *mainFrame) {
    topLevel = mainFrame;

    newGame();
    setTileIcons();
    setupBoard();
    setupPanel();
}

void MinePanel::newGame() {
    newGame("Novice");
}

void MinePanel::newGame(std::string diff, bool firstRun) {
    if(!diff.compare("Intermediate")) {
        currentGame = new Intermediate();
    } else if(!diff.compare("Expert")) {
        currentGame = new Expert();
    } else {
        currentGame = new Novice();
    }

    if(!mineField->IsEmpty()) {
        mineField->Clear(true);
    }

    mineField->SetRows(currentGame->getRows());
    mineField->SetCols(currentGame->getTRC());

    gameRunning = false;
    if(!firstRun) setupBoard();
}

void MinePanel::setTileIcons() {
    setTileIcons("set1/");
}

void MinePanel::setTileIcons(std::string setName) {
    wxImage::AddHandler(new wxPNGHandler);
    std::string path = "assets/" + setName;

    initial = new wxImage(path + "default.png", wxBITMAP_TYPE_PNG);
    initial->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    empty = new wxImage(path + "empty.png", wxBITMAP_TYPE_PNG);
    empty->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    one = new wxImage(path + "1.png", wxBITMAP_TYPE_PNG);
    one->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    two = new wxImage(path + "2.png", wxBITMAP_TYPE_PNG);
    two->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    three = new wxImage(path + "3.png", wxBITMAP_TYPE_PNG);
    three->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    four = new wxImage(path + "4.png", wxBITMAP_TYPE_PNG);
    four->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    five = new wxImage(path + "5.png", wxBITMAP_TYPE_PNG);
    five->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    six = new wxImage(path + "6.png", wxBITMAP_TYPE_PNG);
    six->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    seven = new wxImage(path + "7.png", wxBITMAP_TYPE_PNG);
    seven->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    eight = new wxImage(path + "8.png", wxBITMAP_TYPE_PNG);
    eight->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    flag = new wxImage(path + "flag.png", wxBITMAP_TYPE_PNG);
    flag->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    bomb = new wxImage(path + "bomb.png", wxBITMAP_TYPE_PNG);
    bomb->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    exploded = new wxImage(path + "exploded.png", wxBITMAP_TYPE_PNG);
    exploded->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
}

void MinePanel::setupBoard() {
    for(int i = 0; i < currentGame->getBRC(); i++) {
        wxButton *temp = getMineButton(i);
        mineField->Add(temp, 0, wxALL | wxEXPAND, 0);
    }
    SetMinSize(*currentGame->getBoardSize());
    InvalidateBestSize();
    topLevel->redrawAll();
}

wxButton* MinePanel::getMineButton(int pos) {
    wxButton *newButton = new wxButton(this,
                                       wxID_ANY,
                                       wxEmptyString,
                                       wxDefaultPosition,
                                       wxDefaultSize,
                                       wxBU_EXACTFIT |
                                       wxBU_NOTEXT |
                                       wxBORDER_NONE);
    newButton->SetBitmap(*initial);
    newButton->SetLabel(wxString::Format(wxT("%i"), pos));
    newButton->Bind(wxEVT_LEFT_UP, &MinePanel::doLeftClick, this);
    newButton->Bind(wxEVT_RIGHT_UP, &MinePanel::doRightClick, this);

    return newButton;
}

void MinePanel::setupPanel() {
    container = new wxBoxSizer(wxHORIZONTAL);
    container->Add(mineField, wxCENTER);

    SetSizer(container);
    Show();
}

int MinePanel::getNumMines() {
    return currentGame->getNumberOfMines();
}

int MinePanel::getUnflaggedMines() {
    return 0;
}

void MinePanel::doLeftClick(wxMouseEvent& event) {
    wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());
    // int pos = wxAtoi(button->GetLabel());
    // std::cout << pos << std::endl;
    // currentGame->checkTile(pos);
    // std::cout << "left click" << std::endl;
    // std::cout << button->GetLabel() << std::endl;

    std::vector<char> *sol = currentGame->getMinefield();
    int size = sol->size();
    for(int i = 0; i < size; i++) {
        std::cout << sol->at(i) << ' ';
    }
    std::cout << std::endl;
}

void MinePanel::doRightClick(wxMouseEvent& event) {
    wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());
    std::cout << "right click" << std::endl;
    std::cout << button->GetLabel() << std::endl;
}

void MinePanel::validateGame() {
    std::cout << "validating game" << std::endl;
}

void MinePanel::endGame(int buttonIndex) {
    std::cout << "ending game" << std::endl;
}

void MinePanel::winGame() {
    std::cout << "winning game" << std::endl;
}
