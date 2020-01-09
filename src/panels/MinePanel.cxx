/* MinePanel.cxx */
#include "MinePanel.hxx"

const int MinePanel::imageScale = 24;
const wxString MinePanel::delimiter = ",";

MinePanel::MinePanel(wxFrame * parent):
    wxPanel(parent,
            wxID_ANY,
            wxDefaultPosition,
            wxDefaultSize) {
    mineField = new wxGridSizer(0, 0, 0);
}

void MinePanel::setTileIcons() {
    setTileIcons("set1/", true);
}

void MinePanel::setupBoard() {
    for(int i = 0; i < currentGame->getBRC(); i++) {
        wxButton *temp = getMineButton(i);
        mineField->Add(temp, 0, wxALL | wxEXPAND, 0);
    }
    wxSize boardSize = *currentGame->getBoardSize();
    int h = boardSize.GetHeight();
    int w = boardSize.GetWidth();
    SetClientSize(boardSize);
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
    wxString label = wxString::Format("%i", pos) + delimiter + "initial";
    newButton->SetLabel(label);
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

void MinePanel::drawBoard() {
    int size = mineField->GetItemCount();

    for(int i = 0; i < size; i++) {
        wxSizerItem* item = mineField->GetItem(i);
        wxButton* button = dynamic_cast<wxButton*>(item->GetWindow());
        updateButton(button, i);
    }
}

void MinePanel::updateButton(wxButton* button, int pos) {
    char currTile = mines->at(pos);

    switch(currTile) {
        case '0':
            mineField->Remove(pos);
            mineField->Insert(pos, getStaticBitmap(empty));
            break;
        case '1':
            mineField->Remove(pos);
            mineField->Insert(pos, getStaticBitmap(one));
            break;
        case '2':
            mineField->Remove(pos);
            mineField->Insert(pos, getStaticBitmap(two));
            break;
        case '3':
            mineField->Remove(pos);
            mineField->Insert(pos, getStaticBitmap(three));
            break;
        case '4':
            mineField->Remove(pos);
            mineField->Insert(pos, getStaticBitmap(four));
            break;
        case '5':
            mineField->Remove(pos);
            mineField->Insert(pos, getStaticBitmap(five));
            break;
        case '6':
            mineField->Remove(pos);
            mineField->Insert(pos, getStaticBitmap(six));
            break;
        case '7':
            mineField->Remove(pos);
            mineField->Insert(pos, getStaticBitmap(seven));
            break;
        case '8':
            mineField->Remove(pos);
            mineField->Insert(pos, getStaticBitmap(eight));
            break;
        case 'x':
            mineField->Remove(pos);
            mineField->Insert(pos, getStaticBitmap(exploded));
            break;
        case 'm':
            mineField->Remove(pos);
            mineField->Insert(pos, getStaticBitmap(bomb));
            break;
        default:
            break;
    }
    Layout();
}

wxStaticBitmap* MinePanel::getStaticBitmap(wxImage* image) {
    wxStaticBitmap *newSBM = new wxStaticBitmap(this, wxID_ANY, *image);
    return newSBM;
}

void MinePanel::endGame(int buttonIndex, bool loss) {
    wxString msg = "Final time: ";
    msg << menuPanel->getTime();
    if(loss) {
        wxMessageBox(msg, "You Lost :(", wxOK | wxICON_INFORMATION );
    } else {
        wxMessageBox(msg, "You Won!", wxOK | wxICON_INFORMATION );
    }
}

/*
 *  Public fns
 *
 */

void MinePanel::setMenuPanel(MenuPanel *menuPanel) {
    this->menuPanel = menuPanel;
}

int MinePanel::getNumMines() {
    return currentGame->getNumberOfMines();
}

void MinePanel::newGame(std::string diff) {
    menuPanel->resetTimer();
    setTileIcons();

    if(!diff.compare("Intermediate")) {
        currentGame = new Intermediate();
    } else if(!diff.compare("Expert")) {
        currentGame = new Expert();
    } else {
        currentGame = new Novice();
    }

    mines = currentGame->getRunningGame();

    mineField->SetRows(currentGame->getRows());
    mineField->SetCols(currentGame->getTRC());

    gameRunning = currentGame->getRunning();

    setupBoard();
    setupPanel();
}

void MinePanel::setTileIcons(std::string setName, bool firstRun) {
    wxLogNull suppressor;
    std::string path = "assets/" + setName;

    initial = new wxImage(path + "default.png", wxBITMAP_TYPE_PNG);
    initial->Rescale(imageScale, imageScale, wxIMAGE_QUALITY_HIGH);
    empty = new wxImage(path + "empty.png", wxBITMAP_TYPE_PNG);
    empty->Rescale(imageScale, imageScale, wxIMAGE_QUALITY_HIGH);
    one = new wxImage(path + "1.png", wxBITMAP_TYPE_PNG);
    one->Rescale(imageScale, imageScale, wxIMAGE_QUALITY_HIGH);
    two = new wxImage(path + "2.png", wxBITMAP_TYPE_PNG);
    two->Rescale(imageScale, imageScale, wxIMAGE_QUALITY_HIGH);
    three = new wxImage(path + "3.png", wxBITMAP_TYPE_PNG);
    three->Rescale(imageScale, imageScale, wxIMAGE_QUALITY_HIGH);
    four = new wxImage(path + "4.png", wxBITMAP_TYPE_PNG);
    four->Rescale(imageScale, imageScale, wxIMAGE_QUALITY_HIGH);
    five = new wxImage(path + "5.png", wxBITMAP_TYPE_PNG);
    five->Rescale(imageScale, imageScale, wxIMAGE_QUALITY_HIGH);
    six = new wxImage(path + "6.png", wxBITMAP_TYPE_PNG);
    six->Rescale(imageScale, imageScale, wxIMAGE_QUALITY_HIGH);
    seven = new wxImage(path + "7.png", wxBITMAP_TYPE_PNG);
    seven->Rescale(imageScale, imageScale, wxIMAGE_QUALITY_HIGH);
    eight = new wxImage(path + "8.png", wxBITMAP_TYPE_PNG);
    eight->Rescale(imageScale, imageScale, wxIMAGE_QUALITY_HIGH);
    flag = new wxImage(path + "flag.png", wxBITMAP_TYPE_PNG);
    flag->Rescale(imageScale, imageScale, wxIMAGE_QUALITY_HIGH);
    bomb = new wxImage(path + "bomb.png", wxBITMAP_TYPE_PNG);
    bomb->Rescale(imageScale, imageScale, wxIMAGE_QUALITY_HIGH);
    exploded = new wxImage(path + "exploded.png", wxBITMAP_TYPE_PNG);
    exploded->Rescale(imageScale, imageScale, wxIMAGE_QUALITY_HIGH);

    if(!firstRun) drawBoard();
}

/*
 *  Event Handlers
 *
 */

void MinePanel::doLeftClick(wxMouseEvent& event) {
    wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());
    wxString label = button->GetLabel();
    wxArrayString labelTokens = wxStringTokenize(label, delimiter);
    wxString pos = labelTokens.Item(0);
    wxString type = labelTokens.Item(1);
    mines = currentGame->checkPos(wxAtoi(pos));
    drawBoard();
    if(currentGame->getRunning()) {
        menuPanel->startTimer();
    } else {
        menuPanel->stopTimer();
    }

    bool isRunning = currentGame->getRunning();
    bool isSolved = currentGame->getSolved();
    bool loss = std::find(mines->begin(), mines->end(), 'x') != mines->end();
    if(!isRunning && isSolved) {
        endGame(wxAtoi(pos), loss);
    }
}

void MinePanel::doRightClick(wxMouseEvent& event) {
    wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());
    int minesRem = menuPanel->getMinesRem();
    wxString label = button->GetLabel();
    wxArrayString labelTokens = wxStringTokenize(label, delimiter);
    wxString pos = labelTokens.Item(0);
    wxString type = labelTokens.Item(1);

    wxString rename = pos + delimiter;
    wxSizerItem *item = mineField->GetItem(wxAtoi(pos));
    wxButton *cbutton = dynamic_cast<wxButton*>(item->GetWindow());

    if(type == "initial") {
        if(minesRem > 0) {
            cbutton->SetBitmap(*flag);
            rename += "flag";
            cbutton->SetLabel(rename);
            --minesRem;
        }
    } else {
        cbutton->SetBitmap(*initial);
        rename += "initial";
        cbutton->SetLabel(rename);
        ++minesRem;
    }

    menuPanel->setMinesRem(minesRem);
}
