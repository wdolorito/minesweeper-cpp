#ifndef MINESWEEPER_HXX
#define MINESWEEPER_HXX

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "MinePanel.hxx"

class Minesweeper : public wxApp {
  public:
    virtual bool OnInit();
};

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);

};
#endif

