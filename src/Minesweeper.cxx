/* Minesweeper.cxx */
#include "Minesweeper.hxx"

IMPLEMENT_APP(Minesweeper)

bool Minesweeper::OnInit() {
    mainFrame = new MainFrame("Minesweeper!!!!!");
    mainFrame->Show(true);

    return true;
}
