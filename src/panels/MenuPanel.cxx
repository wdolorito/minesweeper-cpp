#include "MenuPanel.hxx"

MenuPanel::MenuPanel(wxPanel * parent):
        wxPanel(parent,
                wxID_ANY,
                wxDefaultPosition,
                wxDefaultSize) {
    topLevel = parent;

    doSetup();
}

void MenuPanel::doSetup() {
    setupComboBox();
    setupStaticText();
    setupPanel();
}

void MenuPanel::setupComboBox() {
    gameDiff = new wxArrayString();
    gameDiff->Add("Novice");
    gameDiff->Add("Intermediate");
    gameDiff->Add("Expert");

    diff = new wxComboBox(this,
                          wxID_ANY,
                          "",
                          wxDefaultPosition,
                          wxDefaultSize,
                          *gameDiff);

    diff->Bind(wxEVT_COMMAND_COMBOBOX_SELECTED, &MenuPanel::handleComboBox, this, diff->GetId());
}

void MenuPanel::setupStaticText() {
    timer = new wxStaticText(this,
                             wxID_ANY,
                             "0",
                             wxDefaultPosition,
                             wxDefaultSize,
                             wxALIGN_RIGHT);

    minesRem = new wxStaticText(this,
                                wxID_ANY,
                                "0",
                                wxDefaultPosition,
                                wxDefaultSize,
                                wxALIGN_LEFT);
}

void MenuPanel::setupPanel() {
    container = new wxBoxSizer(wxHORIZONTAL);
    verticalSizer = new wxBoxSizer(wxVERTICAL);

    verticalSizer->Add(container, wxCENTER);
    container->AddStretchSpacer(5);
    container->Add(timer, 2, wxCENTER);
    container->AddSpacer(20);
    container->Add(diff, 2, wxCENTER);
    container->AddSpacer(20);
    container->Add(minesRem, 2, wxCENTER);
    container->AddStretchSpacer(5);

    SetSizer(verticalSizer);
}

void MenuPanel::restartGame(std::string difficulty) {
    minePanel->newGame(difficulty);
    setMinesRem(minePanel->getNumMines());
}

void MenuPanel::handleTimer(wxTimerEvent& event) {
    wxString prevStr = timer->GetLabel();
    int prevInt = wxAtoi(prevStr);
    prevInt += 1;
    timer->SetLabelText(wxString::Format(wxT("%i"), prevInt));
}

void MenuPanel::setMinePanel(MinePanel * minePanel) {
    this->minePanel = minePanel;

//    setMinesRem(minePanel->getNumMines());
    container = new wxBoxSizer(wxHORIZONTAL);
    verticalSizer = new wxBoxSizer(wxVERTICAL);

    gameTimer = new wxTimer();
    gameTimer->Bind(wxEVT_TIMER, &MenuPanel::handleTimer, this, gameTimer->GetId());
//    doSetup();
}

void MenuPanel::setMinesRem(int i) {
    minesRem->SetLabelText(wxString::Format(wxT("%i"), i));
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

void MenuPanel::handleComboBox(wxCommandEvent& event) {
    restartGame(event.GetString().ToStdString());
}
