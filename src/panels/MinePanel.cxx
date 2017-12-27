#include "MinePanel.hxx"

MinePanel::MinePanel(wxPanel * parent):
        wxPanel(parent,
                wxID_ANY,
                wxDefaultPosition,
                wxDefaultSize) {
    topLevel = parent;
    runningSolution = new std::vector<int>();
    mineField = new wxGridSizer(0, 0, 0, 0);

    newGame();
    setupImages();
    setTileIcons();
    setupPanel();
}

void MinePanel::setMenuPanel(MenuPanel * menuPanel) {
    this->menuPanel = menuPanel;
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

    if(!mineField->IsEmpty()) {
        std::cout << "remove all elements" << std::endl;
        mineField->Clear(true);
    }

    mineField->SetRows(currentGame->getRows());
    mineField->SetCols(currentGame->getTRC());

    gameRunning = false;
    solution = currentGame->returnSolution();
    setupBoard();
}

void MinePanel::setupImages() {
    initial = new wxImage();
    empty = new wxImage();
    one = new wxImage();
    two = new wxImage();
    three = new wxImage();
    four = new wxImage();
    five = new wxImage();
    six = new wxImage();
    seven = new wxImage();
    eight = new wxImage();
    flag = new wxImage();
    bomb = new wxImage();
    exploded = new wxImage();
}

void MinePanel::setTileIcons() {
    setTileIcons("set1/");
}

void MinePanel::setTileIcons(std::string setName) {
    wxImage::AddHandler(new wxPNGHandler);
    std::string path = "assets/" + setName;

    if(!initial->IsOk()) {
        initial  = new wxImage(path + "default.png", wxBITMAP_TYPE_PNG);
        initial->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    } else {
        initial->Create(20, 20, true);
    }
    if(!empty->IsOk()) {
        empty    = new wxImage(path + "empty.png", wxBITMAP_TYPE_PNG);
        empty->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    } else {
        empty->Create(20, 20, true);
    }
    if(!one->IsOk()) {
        one      = new wxImage(path + "1.png", wxBITMAP_TYPE_PNG);
        one->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    } else {
        one->Create(20, 20, true);
    }
    if(!two->IsOk()) {
        two      = new wxImage(path + "2.png", wxBITMAP_TYPE_PNG);
        two->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    } else {
        two->Create(20, 20, true);
    }
    if(!three->IsOk()) {
        three    = new wxImage(path + "3.png", wxBITMAP_TYPE_PNG);
        three->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    } else {
        three->Create(20, 20, true);
    }
    if(!four->IsOk()) {
        four     = new wxImage(path + "4.png", wxBITMAP_TYPE_PNG);
        four->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    } else {
        four->Create(20, 20, true);
    }
    if(!five->IsOk()) {
        five     = new wxImage(path + "5.png", wxBITMAP_TYPE_PNG);
        five->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    } else {
        five->Create(20, 20, true);
    }
    if(!six->IsOk()) {
        six      = new wxImage(path + "6.png", wxBITMAP_TYPE_PNG);
        six->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    } else {
        six->Create(20, 20, true);
    }
    if(!seven->IsOk()) {
        seven    = new wxImage(path + "7.png", wxBITMAP_TYPE_PNG);
        seven->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    } else {
        seven->Create(20, 20, true);
    }
    if(!eight->IsOk()) {
        eight    = new wxImage(path + "8.png", wxBITMAP_TYPE_PNG);
        eight->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    } else {
        eight->Create(20, 20, true);
    }
    if(!flag->IsOk()) {
        flag     = new wxImage(path + "flag.png", wxBITMAP_TYPE_PNG);
        flag->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    } else {
        flag->Create(20, 20, true);
    }
    if(!bomb->IsOk()) {
        bomb     = new wxImage(path + "bomb.png", wxBITMAP_TYPE_PNG);
        bomb->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    } else {
        bomb->Create(20, 20, true);
    }
    if(!exploded->IsOk()) {
        exploded = new wxImage(path + "exploded.png", wxBITMAP_TYPE_PNG);
        exploded->Rescale(20, 20, wxIMAGE_QUALITY_HIGH);
    } else {
        exploded->Create(20, 20, true);
    }
}

void MinePanel::setupBoard() {
    for(int i = 0; i < currentGame->getBRC(); i++) {
        wxButton *temp = new wxButton(this,
                                    wxID_ANY,
                                    wxEmptyString,
                                    wxDefaultPosition,
                                    wxDefaultSize,
                                    wxBU_NOTEXT);
        if(initial->IsOk()) temp->SetBitmap(*initial);
        mineField->Add(temp);
    }
    mineField->Layout();
    Refresh();
    topLevel->Layout();
    topLevel->Refresh();
}

void MinePanel::setupPanel() {
    container = new wxBoxSizer(wxVERTICAL);
    container->Add(mineField, 0, wxEXPAND);
    SetSizer(container);
    Center();
//    menuPanel->startTimer();
}

int MinePanel::getNumMines() {
    return currentGame->getNumberOfMines();
}

int MinePanel::getUnflaggedMines() {
    return 0;
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
