#include "MenuPanel.hxx"

MenuPanel::MenuPanel(wxPanel * parent):
        wxPanel(parent,
                wxID_ANY,
                wxDefaultPosition,
                wxDefaultSize) {
    topLevel = parent;
    container = new wxBoxSizer(wxHORIZONTAL);

    SetSizer(container);

    doSetup();
}

void MenuPanel::doSetup() {
    gameDiff = new wxArrayString();
    gameDiff->Add("Novice");
    gameDiff->Add("Intermediate");
    gameDiff->Add("Expert");

    minesRem = new wxStaticText(this,
                                wxID_ANY,
                                "0",
                                wxDefaultPosition,
                                wxDefaultSize);

    diff = new wxComboBox(this,
                          wxID_ANY,
                          "",
                          wxDefaultPosition,
                          wxDefaultSize,
                          *gameDiff);

    timer = new wxStaticText(this,
                             wxID_ANY,
                             "0",
                             wxDefaultPosition,
                             wxDefaultSize);

    container->Add(minesRem, 0, wxCENTER);
    container->AddSpacer(20);
    container->Add(diff, 0, wxCENTER);
    container->AddSpacer(20);
    container->Add(timer, 0, wxCENTER);

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