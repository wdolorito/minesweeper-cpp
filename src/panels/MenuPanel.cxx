/* MenuPanel.cxx */
#include "MenuPanel.hxx"

MenuPanel::MenuPanel(wxPanel * parent):
    wxPanel(parent,
            wxID_ANY,
            wxDefaultPosition,
            wxDefaultSize) {
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
                          "Novice",
                          wxDefaultPosition,
                          wxDefaultSize,
                          *gameDiff,
                          wxCB_READONLY);

    diff->Bind(wxEVT_COMMAND_COMBOBOX_SELECTED,
               &MenuPanel::handleComboBox,
               this,
               diff->GetId());
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
    int quadPad = 4 * padding;
    hSizer = new wxBoxSizer(wxHORIZONTAL);
    vSizer = new wxBoxSizer(wxVERTICAL);

    hSizer->AddStretchSpacer(padding);
    hSizer->Add(timer, 2, wxALIGN_CENTER);
    hSizer->AddSpacer(quadPad);
    hSizer->Add(diff, 2, wxALIGN_CENTER);
    hSizer->AddSpacer(quadPad);
    hSizer->Add(minesRem, 2, wxALIGN_CENTER);
    hSizer->AddStretchSpacer(padding);
    vSizer->Add(hSizer, wxALIGN_CENTER);

    setMinesRem(10);

    SetSizer(vSizer);
    Show();
}

void MenuPanel::restartGame(std::string difficulty) {
    minePanel->newGame(difficulty, false);
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

    gameTimer = new wxTimer();
    gameTimer->Bind(wxEVT_TIMER,
                    &MenuPanel::handleTimer,
                    this,
                    gameTimer->GetId());
}

void MenuPanel::setMainFrame(MainFrame *mainFrame) {
    topLevel = mainFrame;
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
