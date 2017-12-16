#include "Minesweeper.hxx"
#include "Communicate.hxx"

IMPLEMENT_APP(Minesweeper)

bool Minesweeper::OnInit()
{
    Communicate *communicate = new Communicate(wxT("Widgets communicate"));
    communicate->Show(true);
    
    return true;
}
