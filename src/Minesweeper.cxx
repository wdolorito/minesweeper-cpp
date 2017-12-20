#include "Minesweeper.hxx"
#include "Novice.hxx"
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <vector>

//IMPLEMENT_APP(Minesweeper)

///bool Minesweeper::OnInit() {
int main() {
    Novice novice = Novice();
    std::vector<char> temp = novice.getMines();
    int size = temp.size();
    int trc = novice.getTRC();
    for(int i = 0; i < size; i++) {
        std::cout << temp[i] << " ";
        if(((i + 1) % trc) == 0) std::cout << std::endl;
    }
    return 0;
//    return true;
}
