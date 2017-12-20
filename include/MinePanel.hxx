/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MinePanel.hxx
 * Author: d0odman
 *
 * Created on December 19, 2017, 8:49 PM
 */

#ifndef MINEPANEL_HXX
#define MINEPANEL_HXX

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/panel.h>
#include "MenuPanel.hxx"

class MenuPanel;

class MinePanel: public wxPanel {
public:
    MinePanel(wxPanel *parent);
    void setMenuPanel(MenuPanel *menuPanel);

private:
    wxPanel *topLevel;
    MenuPanel *menuPanel;
};

#endif /* MINEPANEL_HXX */