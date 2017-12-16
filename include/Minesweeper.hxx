#ifndef MINESWEEPER_HXX
#define MINESWEEPER_HXX

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class Minesweeper : public wxApp
{
  public:
    virtual bool OnInit();
};

#endif

