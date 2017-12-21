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

/*MinePanel::MinePanel(wxFrame * parent):
        wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN) {
    topLevel = parent;
}*/

void MinePanel::setMenuPanel(MenuPanel * menuPanel) {
    this->menuPanel = menuPanel;
}

int MinePanel::getNumMines() {
    return 0;
}

int MinePanel::getUnflaggedMines() {
    return 0;
}

void MinePanel::newGame() {
    newGame("Novice");
}

void MinePanel::newGame(std::string diff) {
    if(!diff.compare("Intermediate")) {
        std::cout << "set up Intermediate" << std::endl;
    } else if(!diff.compare("Expert")) {
        std::cout << "set up Expert" << std::endl;
    } else {
        std::cout << "set up Novice" << std::endl;
    }
}

void MinePanel::initPanel() {
}

void MinePanel::setTileIcons() {
}

void MinePanel::setTileIcons(std::string setName) {
}

void MinePanel::initBoard() {
}

void MinePanel::doLeftClick(int buttonIndex) {
}

void MinePanel::doRightClick(int buttonIndex) {
}

void MinePanel::validateGame() {
}

void MinePanel::endGame(int buttonIndex) {
}

void MinePanel::winGame() {
}
