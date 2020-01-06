/* MinePanel.cxx */
#include "MinePanel.hxx"

MinePanel::MinePanel(wxPanel * parent):
    wxPanel(parent,
            wxID_ANY,
            wxDefaultPosition,
            wxDefaultSize) {
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
    newGame("Novice", true);
}

void MinePanel::newGame(std::string diff, bool firstRun) {
    if(firstRun) {
        std::cout << "First run" << std::endl;
    } else {
        std::cout << "Subsequent run" << std::endl;
    }

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

    mines = currentGame->getRunningGame();

    mineField->SetRows(currentGame->getRows());
    mineField->SetCols(currentGame->getTRC());

    gameRunning = currentGame->getRunning();
}

void MinePanel::setTileIcons() {
    setTileIcons("set1/");
}

void MinePanel::setTileIcons(std::string setName) {
    wxImage::AddHandler(new wxPNGHandler);
    std::string path = "assets/" + setName;

    initial = new wxImage(path + "default.png", wxBITMAP_TYPE_PNG);
    empty = new wxImage(path + "empty.png", wxBITMAP_TYPE_PNG);
    one = new wxImage(path + "1.png", wxBITMAP_TYPE_PNG);
    two = new wxImage(path + "2.png", wxBITMAP_TYPE_PNG);
    three = new wxImage(path + "3.png", wxBITMAP_TYPE_PNG);
    four = new wxImage(path + "4.png", wxBITMAP_TYPE_PNG);
    five = new wxImage(path + "5.png", wxBITMAP_TYPE_PNG);
    six = new wxImage(path + "6.png", wxBITMAP_TYPE_PNG);
    seven = new wxImage(path + "7.png", wxBITMAP_TYPE_PNG);
    eight = new wxImage(path + "8.png", wxBITMAP_TYPE_PNG);
    flag = new wxImage(path + "flag.png", wxBITMAP_TYPE_PNG);
    bomb = new wxImage(path + "bomb.png", wxBITMAP_TYPE_PNG);
    exploded = new wxImage(path + "exploded.png", wxBITMAP_TYPE_PNG);
}

void MinePanel::setupBoard() {
    for(int i = 0; i < currentGame->getBRC(); i++) {
        wxButton *temp = getMineButton(i);
        mineField->Add(temp, 0, wxALL | wxEXPAND, 0);
    }
    wxSize boardSize = *currentGame->getBoardSize();
    int h = boardSize.GetHeight();
    int w = boardSize.GetWidth();
    std::cout << "board h: " << h << "\tboard w: " << w << std::endl;
    SetClientSize(boardSize);
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
    newButton->SetLabel(wxString::Format("%i", pos));
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
    button->Enable(false);
    wxString pos = button->GetLabel();
    mines = currentGame->checkPos(wxAtoi(pos));
    std::cout << "button " << pos << " clicked" << std::endl;
    drawBoard();
}

void MinePanel::doRightClick(wxMouseEvent& event) {
    wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());
    std::cout << "right click" << std::endl;
    std::cout << button->GetLabel() << std::endl;
}

void MinePanel::drawBoard() {
    std::cout << "drawing board" << std::endl;
    int size = mineField->GetItemCount();
    std::cout << size << std::endl;

    for(int i = 0; i < size; i++) {
        wxSizerItem* item = mineField->GetItem(i);
        wxButton* button = dynamic_cast<wxButton*>(item->GetWindow());
        updateButton(button, i);
    }
}

void MinePanel::updateButton(wxButton* button, int pos) {
    char currTile = mines->at(pos);

    std::cout << button->GetLabel() << " ";

    switch(currTile) {
        case '.':
            button->SetBitmap(*initial);
            break;
        case '0':
            button->SetBitmap(*empty);
            break;
        case '1':
            button->SetBitmap(*one);
            break;
        case '2':
            button->SetBitmap(*two);
            break;
        case '3':
            button->SetBitmap(*three);
            break;
        case '4':
            button->SetBitmap(*four);
            break;
        case '5':
            button->SetBitmap(*five);
            break;
        case '6':
            button->SetBitmap(*six);
            break;
        case '7':
            button->SetBitmap(*seven);
            break;
        case '8':
            button->SetBitmap(*eight);
            break;
        case 'm':
            button->SetBitmap(*exploded);
            break;
        default:
            break;
    }
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
