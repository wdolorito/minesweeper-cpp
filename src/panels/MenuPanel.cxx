#include "MenuPanel.hxx"

MenuPanel::MenuPanel(wxPanel * parent):
        wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN) {
    topLevel = parent;
    container = new wxBoxSizer(wxHORIZONTAL);

    doSetup();
}

void MenuPanel::doSetup() {
    gameDiff = new wxArrayString();
    gameDiff->Add(wxT("Novice"));
    gameDiff->Add(wxT("Intermediate"));
    gameDiff->Add(wxT("Expert"));

    diff = new wxComboBox();
//    diff->Set(*gameDiff);

//    container->Add(diff, 1, wxEXPAND | wxALL, 5);
    SetSizer(container);

/*    wxStaticText *minesRem;
    wxStaticText *timer;
    wxTimer *gameTimer;*/
}

void MenuPanel::restartGame(std::string difficulty) {
}

void MenuPanel::setMinePanel(MinePanel * minePanel) {
    this->minePanel = minePanel;
}

void MenuPanel::setMinesRem(int i) {
}

void MenuPanel::resetTimer() {
}

void MenuPanel::startTimer() {
}

void MenuPanel::stopTimer() {
}