/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MenuPanel.hxx
 * Author: d0odman
 *
 * Created on December 19, 2017, 8:48 PM
 */

#ifndef MENUPANEL_HXX
#define MENUPANEL_HXX

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/panel.h>
#include "MinePanel.hxx"

class MinePanel;

class MenuPanel: public wxPanel {
public:
    MenuPanel(wxPanel *parent);
    void setMinePanel(MinePanel *minePanel);
    void setMinesRem(int i);
    void resetTimer();
    void startTimer();
    void stopTimer();

private:
    wxArrayString *gameDiff;
    wxBoxSizer *verticalSizer;
    wxBoxSizer *container;
    wxPanel *topLevel;
    MinePanel *minePanel;
    wxComboBox *diff;
    wxStaticText *minesRem;
    wxStaticText *timer;
    wxTimer *gameTimer;

    void doSetup();
    void restartGame(std::string difficulty);
    void handleTimer(wxTimerEvent& event);
    void handleComboBox(wxCommandEvent& event);
};

#endif /* MENUPANEL_HXX */
