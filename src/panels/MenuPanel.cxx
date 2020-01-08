/* MenuPanel.cxx */
#include "MenuPanel.hxx"

const int MenuPanel::padding = 10;
wxArrayString *MenuPanel::gameDiff = new wxArrayString();

MenuPanel::MenuPanel(wxFrame * parent):
    wxPanel(parent,
            wxID_ANY,
            wxDefaultPosition,
            wxDefaultSize) {
    doSetup();
}

/*
 *  Setup fns
 *
 */

void MenuPanel::doSetup() {
    setupComboBox();
    setupStaticText();
    setupPanel();
}

void MenuPanel::setupComboBox() {
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
                             wxALIGN_RIGHT | wxST_NO_AUTORESIZE);

    minesRem = new wxStaticText(this,
                                wxID_ANY,
                                "0",
                                wxDefaultPosition,
                                wxDefaultSize,
                                wxALIGN_LEFT | wxST_NO_AUTORESIZE);
}

void MenuPanel::setupPanel() {
    int quadPadding = 4 * padding;
    hSizer = new wxBoxSizer(wxHORIZONTAL);
    vSizer = new wxBoxSizer(wxVERTICAL);

    hSizer->AddSpacer(padding);
    hSizer->Add(timer, 2, wxALIGN_CENTER);
    hSizer->AddSpacer(quadPadding);
    hSizer->Add(diff, 2, wxALIGN_CENTER);
    hSizer->AddSpacer(quadPadding);
    hSizer->Add(minesRem, 2, wxALIGN_CENTER);
    hSizer->AddSpacer(padding);
    vSizer->Add(hSizer, wxALIGN_CENTER);

    setMinesRem(10);

    SetSizer(vSizer);
    Show();
}

/*
 *  Public fns
 *
 */

void MenuPanel::restartGame(std::string difficulty) {
    std::cout << difficulty << std::endl;
    // minePanel->newGame(difficulty, false);
    // setMinesRem(minePanel->getNumMines());
}

int MenuPanel::getMinesRem() {
    wxString rem = minesRem->GetLabelText();
    return wxAtoi(rem);
}

void MenuPanel::setMinesRem(int i) {
    minesRem->SetLabelText(wxString::Format("%i", i));
}

int MenuPanel::getTime() {
    bool wasRunning = gameTimer->IsRunning();
    stopTimer();
    wxString time = timer->GetLabel();
    int currTime = wxAtoi(time);
    if(wasRunning) gameTimer->Start();
    return currTime;
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

/*
 *  Event Handlers
 *
 */

void MenuPanel::handleComboBox(wxCommandEvent& event) {
    // restartGame(event.GetString().ToStdString());
}

void MenuPanel::handleTimer(wxTimerEvent& event) {
    wxString prevStr = timer->GetLabel();
    int prevInt = wxAtoi(prevStr);
    prevInt += 1;
    timer->SetLabelText(wxString::Format("%i", prevInt));
}
