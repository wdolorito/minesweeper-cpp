#include "Minesweeper.hxx"
#include "Novice.hxx"
#include <iostream>
#include <vector>

//IMPLEMENT_APP(Minesweeper)

//bool Minesweeper::OnInit()
int main() {
    Novice novice = Novice();
    std::cout << novice.getNumberOfMines() << std::endl;
    wxSize size = novice.getBoardSize();
    std::cout << size.GetHeight() << std::endl;
    std::cout << size.GetWidth() << std::endl;
    std::cout << novice.getTRC() << std::endl;
    std::cout << novice.getBLC() << std::endl;
    std::cout << novice.getBRC() << std::endl;
    std::cout << novice.getRows() << std::endl;
    std::cout << novice.getSolved() << std::endl;
    std::vector<char> temp = novice.getMines();
    for(int i = 0; i < temp.size(); i++) {
        if(temp[i] == 'm') {
            std::cout << "Mine on " << i << ":";
        } else {

        }
            std::cout << temp[i] << ":";
    }
    std::cout << std::endl;
    std::vector<int> temp2 = novice.returnSolution();
    for(int i = 0; i < temp2.size(); i++) {
        std::cout << i << ": " << temp2[i] << std::endl;
    }
    return 0;
//    return true;
}
