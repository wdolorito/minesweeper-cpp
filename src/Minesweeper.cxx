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
/*    for(int i = 0; i < size; i++) {
        std::cout << temp[i] << ":";
        if(((i + 1) % trc) == 0) std::cout << std::endl;
    }
    std::vector<int> temp2 = novice.returnSolution();
    for(int i = 0; i < temp2.size(); i++) {
        std::cout << i << ": " << temp2[i] << std::endl;
    }*/
    std::cout << std::endl;
    for(int i = 0; i <= 80; i++) {
        std::cout << std::setw(2) << i << " ";
        if((i + 1) % 9 == 0) std::cout << std::endl;
    }
    return 0;
//    return true;
}
