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
#include <vector>
#include "MenuPanel.hxx"
#include "Game.hxx"
#include "Novice.hxx"
#include "Intermediate.hxx"
#include "Expert.hxx"

class MenuPanel;
class Game;

class MinePanel: public wxPanel {
public:
    Game *currentGame;
    MinePanel(wxPanel *parent);
    void setMenuPanel(MenuPanel *menuPanel);
    int getNumMines();
    int getUnflaggedMines();
    void newGame(std::string diff);

private:
    wxPanel *topLevel;
    MenuPanel *menuPanel;

    std::vector<int> *solution,
                     *runningSolution;
    std::vector<char> *mines;
    int unflaggedMines;
    bool gameRunning;

    void newGame();
    void initPanel();
    void setTileIcons();
    void setTileIcons(std::string setName);
    void initBoard();
    void doLeftClick(int buttonIndex);
    void doRightClick(int buttonIndex);
    void validateGame();
    void endGame(int buttonIndex);
    void winGame();
};

#endif /* MINEPANEL_HXX */