/* Minesweeper.hxx */
#ifndef MINESWEEPER_HXX
#define MINESWEEPER_HXX

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "MainFrame.hxx"
#include "MinePanel.hxx"

class MainFrame;

class Minesweeper : public wxApp {
    private:
        MainFrame *mainFrame;

    public:
        virtual bool OnInit();
};

#endif /* MINESWEEPER_HXX */
