/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Novice.hxx
 * Author: d0odman
 *
 * Created on December 17, 2017, 9:03 AM
 */

#ifndef NOVICE_HXX
#define NOVICE_HXX

#include "Game.hxx"
#include <wx/gdicmn.h>

class Novice: public Game {
    private:
        int MINES,
            TRC,
            ROWS,
            BRC,
            BLC;
        
        wxSize BOARD;

    public:
        Novice();
        int getNumberOfMines();
        wxSize getBoardSize();
        int getTRC();
        int getBLC();
        int getBRC();
        int getRows();
};
#endif /* NOVICE_HXX */

