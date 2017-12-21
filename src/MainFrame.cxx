/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MainFrame.cxx
 * Author: d0odman
 *
 * Created on December 20, 2017, 10:25 PM
 */

#include "MainFrame.hxx"

MainFrame::MainFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150)) {
    topLevel = new wxPanel(this, wxID_ANY);

    wxBoxSizer *container = new wxBoxSizer(wxVERTICAL);

    menuPanel = new MenuPanel(topLevel);
    minePanel = new MinePanel(topLevel);

    container->Add(menuPanel, 1, wxEXPAND | wxALL, 5);
    container->Add(minePanel, 9, wxEXPAND | wxALL, 5);
    
    topLevel->SetSizer(container);

    Center();
}