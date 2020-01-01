/* Minesweeper.cxx */
#include "Minesweeper.hxx"

IMPLEMENT_APP(Minesweeper)

bool Minesweeper::OnInit() {
    #ifdef __WXMAC__
    wxApp::SetExitOnFrameDelete(false);
    #endif

    mainFrame = new MainFrame("Minesweeper!!!!!");
    mainFrame->Show(true);

    return true;
}
