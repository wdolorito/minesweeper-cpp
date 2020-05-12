/* MenuPanel.cxx */
#include "MenuPanel.hxx"

const int MenuPanel::padding = 10;

MenuPanel::MenuPanel(wxFrame * parent) :
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
    gameDiff = new wxArrayString();
    setupChoice();
    setupStaticText();
    setupPanel();
}

void MenuPanel::setupChoice() {
    gameDiff->Add("Novice");
    gameDiff->Add("Intermediate");
    gameDiff->Add("Expert");

    wxCArrayString helper(*gameDiff);
    diff = new wxChoice(this,
                        wxID_ANY,
                        wxDefaultPosition,
                        wxDefaultSize,
                        gameDiff->GetCount(),
                        helper.GetStrings());

    diff->Bind(wxEVT_CHOICE,
               &MenuPanel::handleChoice,
               this,
               diff->GetId());

   diff->SetSelection(0);
}

void MenuPanel::setupStaticText() {
    gameTimer = new wxTimer();
    gameTimer->Bind(wxEVT_TIMER, &MenuPanel::handleTimer, this);

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
    hSizer = new wxBoxSizer(wxHORIZONTAL);
    vSizer = new wxBoxSizer(wxVERTICAL);

    hSizer->Add(timer, 1, wxALIGN_CENTER);
    hSizer->AddSpacer(padding);
    hSizer->Add(diff, 1, wxALIGN_CENTER);
    hSizer->AddSpacer(padding);
    hSizer->Add(minesRem, 1, wxALIGN_CENTER);
    vSizer->Add(hSizer, wxALIGN_CENTER);

    setMinesRem(10);

    SetSizer(vSizer);
    Show();
}

/*
 *  Public fns
 *
 */

void MenuPanel::restartGame(wxString difficulty) {
    MainFrame *parent = dynamic_cast<MainFrame*>(GetParent());

    parent->newGameFromChoice(difficulty);
}

int MenuPanel::getMinesRem() {
    wxString rem = minesRem->GetLabelText();
    return wxAtoi(rem);
}

void MenuPanel::setMinesRem(int i) {
    minesRem->SetLabelText(wxString::Format("%i", i));
}

void MenuPanel::setDiff(wxString difficulty) {
    if(!difficulty.Cmp("Intermediate")) {
        diff->SetSelection(1);
    } else if(!difficulty.Cmp("Expert")) {
        diff->SetSelection(2);
    } else {
        diff->SetSelection(0);
    }
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
    stopTimer();
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

void MenuPanel::handleChoice(wxCommandEvent& event) {
    restartGame(event.GetString());
}

void MenuPanel::handleTimer(wxTimerEvent& event) {
    wxString prevStr = timer->GetLabel();
    int prevInt = wxAtoi(prevStr);
    prevInt += 1;
    timer->SetLabelText(wxString::Format("%i", prevInt));
}
