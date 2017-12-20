/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MinePanel.cxx
 * Author: d0odman
 *
 * Created on December 19, 2017, 8:49 PM
 */

#include "MinePanel.hxx"

MinePanel::MinePanel(wxPanel * parent):
        wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN) {
    topLevel = parent;
}

void MinePanel::setMenuPanel(MenuPanel * menuPanel) {
    this->menuPanel = menuPanel;
}