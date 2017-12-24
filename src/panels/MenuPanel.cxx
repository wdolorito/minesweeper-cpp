#include "MenuPanel.hxx"

MenuPanel::MenuPanel(wxPanel * parent):
        wxPanel(parent,
                wxID_ANY,
                wxDefaultPosition,
                wxDefaultSize) {
    topLevel = parent;

    container = new wxBoxSizer(wxHORIZONTAL);
    verticalSizer = new wxBoxSizer(wxVERTICAL);

    gameTimer = new wxTimer();
    gameTimer->Bind(wxEVT_TIMER, &MenuPanel::handleTimer, this, gameTimer->GetId());

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
                                wxDefaultSize,
                                wxALIGN_RIGHT);

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

    verticalSizer->Add(container, wxCENTER);
    container->AddStretchSpacer(5);
    container->Add(timer, 2, wxCENTER);
    container->AddSpacer(20);
    container->Add(diff, 2, wxCENTER);
    container->AddSpacer(20);
    container->Add(minesRem, 2, wxCENTER);
    container->AddStretchSpacer(5);

    SetSizer(verticalSizer);
/*    wxStaticText *minesRem;
    wxStaticText *timer;
    wxTimer *gameTimer;*/
}

void MenuPanel::restartGame(std::string difficulty) {
}

void MenuPanel::handleTimer(wxTimerEvent& event) {
    wxString prevStr = timer->GetLabel();
    int prevInt = wxAtoi(prevStr);
    prevInt += 1;
    timer->SetLabelText(wxString::Format(wxT("%i"), prevInt));
}

void MenuPanel::setMinePanel(MinePanel * minePanel) {
    this->minePanel = minePanel;
}

void MenuPanel::setMinesRem(int i) {
}

void MenuPanel::resetTimer() {
    timer->SetLabelText("0");
}

void MenuPanel::startTimer() {
    gameTimer->Start(1000);
}

void MenuPanel::stopTimer() {
    gameTimer->Stop();
}