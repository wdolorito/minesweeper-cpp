// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include "Minesweeper.hxx"
#include "Game.hxx"

enum
{
    ID_Hello = 1
};

wxBEGIN_EVENT_TABLE(Game, wxFrame)
    EVT_MENU(ID_Hello,   Game::OnHello)
    EVT_MENU(wxID_EXIT,  Game::OnExit)
    EVT_MENU(wxID_ABOUT, Game::OnAbout)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(Minesweeper);

bool Minesweeper::OnInit()
{
    Game *frame = new Game( "Hello World", wxPoint(50, 50), wxSize(450, 340) );
    frame->Show( true );
    return true;
}
