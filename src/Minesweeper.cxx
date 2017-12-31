#include "Minesweeper.hxx"

IMPLEMENT_APP(Minesweeper)

bool Minesweeper::OnInit() {
    mainFrame = new MainFrame(wxT("Minesweeper!!!!!"));
    mainFrame->Show(true);

    return true;
}
