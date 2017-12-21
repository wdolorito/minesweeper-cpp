#include "Minesweeper.hxx"

IMPLEMENT_APP(Minesweeper)

bool Minesweeper::OnInit() {
    MainFrame *mainFrame = new MainFrame(wxT("Minesweeper!!!!!"));
    mainFrame->Show(true);

    MinePanel *minePanel = new MinePanel();//mainFrame);
    minePanel->newGame("Novice");
    minePanel->newGame("Intermediate");
    minePanel->newGame("Expert");
    minePanel->newGame("gibbajabba");
    return true;
}

MainFrame::MainFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150)) {
    Centre();
}