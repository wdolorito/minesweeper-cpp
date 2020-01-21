/* MinePanel.cxx */
#include "MinePanel.hxx"

const int MinePanel::imageScale = 24;
const wxString MinePanel::delimiter = ",";

MinePanel::MinePanel(wxFrame * parent) :
    wxPanel(parent,
            wxID_ANY,
            wxDefaultPosition,
            wxDefaultSize) {
    mineField = new wxGridSizer(0, 0, 0);
}

/*
 *  Setup fns
 *
 */

void MinePanel::setTileIcons() {
    setTileIcons("set1/", true);
}

void MinePanel::setupBoard() {
    int size = currentGame->getBRC();
    for(int i = 0; i < size; i++) {
        wxStaticBitmap *temp = getBitmapTile(i);
        mineField->Add(temp, 0, wxALL | wxEXPAND, 0);
    }
    wxSize boardSize = *currentGame->getBoardSize();
    int h = boardSize.GetHeight();
    int w = boardSize.GetWidth();
    SetClientSize(boardSize);
}

wxStaticBitmap* MinePanel::getBitmapTile(int pos) {
    wxBitmap *temp = new wxBitmap(*initial);
    wxStaticBitmap *newSBBM = new wxStaticBitmap(this, wxID_ANY, *temp);
    wxString label = wxString::Format("%i", pos) + delimiter + "initial";
    newSBBM->SetLabel(label);
    newSBBM->Bind(wxEVT_LEFT_UP, &MinePanel::doLeftClick, this);
    newSBBM->Bind(wxEVT_RIGHT_UP, &MinePanel::doRightClick, this);
    return newSBBM;
}

void MinePanel::setupPanel() {
    container = new wxBoxSizer(wxHORIZONTAL);
    container->Add(mineField, wxCENTER);

    SetSizer(container);
    Show();
}

/*
 *  Private fns
 *
 */

void MinePanel::drawBoard() {
    int size = mineField->GetItemCount();
    for(int i = 0; i < size; i++) {
        wxSizerItem* item = mineField->GetItem(i);
        wxWindow* window = item->GetWindow();
        updateTile(window, i);
    }
}

void MinePanel::updateTile(wxWindow* window, int pos) {
    char currTile = mines->at(pos);
    wxStaticBitmap* tile = dynamic_cast<wxStaticBitmap*>(window);

    switch(currTile) {
        case '0':
            tile->SetBitmap(*empty);
            break;
        case '1':
            tile->SetBitmap(*one);
            break;
        case '2':
            tile->SetBitmap(*two);
            break;
        case '3':
            tile->SetBitmap(*three);
            break;
        case '4':
            tile->SetBitmap(*four);
            break;
        case '5':
            tile->SetBitmap(*five);
            break;
        case '6':
            tile->SetBitmap(*six);
            break;
        case '7':
            tile->SetBitmap(*seven);
            break;
        case '8':
            tile->SetBitmap(*eight);
            break;
        case 'x':
            tile->SetBitmap(*exploded);
            break;
        case 'm':
            tile->SetBitmap(*bomb);
            break;
        default:
            break;
    }
}

void MinePanel::endGame(bool loss) {
    int size = mineField->GetItemCount();
    for(int i = 0; i < size; i++) {
        wxSizerItem* item = mineField->GetItem(i);
        wxWindow* window = item->GetWindow();
        wxStaticBitmap* tile = dynamic_cast<wxStaticBitmap*>(window);
        tile->SetEvtHandlerEnabled(false);
        tile->SetEvtHandlerEnabled(false);
    }

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

void MinePanel::newGame(wxString diff) {
    menuPanel->resetTimer();
    setTileIcons();

    if(!diff.Cmp("Intermediate")) {
        currentGame = new Intermediate();
    } else if(!diff.Cmp("Expert")) {
        currentGame = new Expert();
    } else {
        currentGame = new Novice();
    }

    menuPanel->setMinesRem(currentGame->getNumberOfMines());
    mines = currentGame->getRunningGame();

    mineField->SetRows(currentGame->getRows());
    mineField->SetCols(currentGame->getTRC());

    gameRunning = currentGame->getRunning();

    setupBoard();
    setupPanel();
}

void MinePanel::setTileIcons(wxString setName, bool firstRun) {
    wxLogNull suppressor;
    wxString path = "assets/" + setName;
    #if __WXOSX__
        path = wxStandardPaths::Get().GetResourcesDir().ToStdString() + "/assets/" + setName;
    #endif

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
    wxStaticBitmap* tile = dynamic_cast<wxStaticBitmap*>(event.GetEventObject());
    wxString label = tile->GetLabel();
    wxArrayString labelTokens = wxStringTokenize(label, delimiter);
    wxString pos = labelTokens.Item(0);
    wxString type = labelTokens.Item(1);

    tile->SetEvtHandlerEnabled(false);
    tile->SetEvtHandlerEnabled(false);

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
        endGame(loss);
    }
}

void MinePanel::doRightClick(wxMouseEvent& event) {
    wxStaticBitmap* tile = dynamic_cast<wxStaticBitmap*>(event.GetEventObject());
    int minesRem = menuPanel->getMinesRem();
    wxString label = tile->GetLabel();
    wxArrayString labelTokens = wxStringTokenize(label, delimiter);
    wxString pos = labelTokens.Item(0);
    wxString type = labelTokens.Item(1);

    wxString rename = pos + delimiter;
    wxSizerItem *item = mineField->GetItem(wxAtoi(pos));
    wxStaticBitmap *ctile = dynamic_cast<wxStaticBitmap*>(item->GetWindow());

    if(type == "initial") {
        if(minesRem > 0) {
            ctile->SetBitmap(*flag);
            rename += "flag";
            ctile->SetLabel(rename);
            --minesRem;
        }
    } else {
        ctile->SetBitmap(*initial);
        rename += "initial";
        ctile->SetLabel(rename);
        ++minesRem;
    }

    menuPanel->setMinesRem(minesRem);
}
