#include "Board.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;
namespace ariel{
    Board::Board()
    {
          i=0;

    }
    Board:: ~Board()
    {
        
    }
    void Board::post(unsigned int row, unsigned int column, Direction direction, const std::string &message)
    {
        cout << "post" <<endl;
         i++;

    }
    std::string Board::read(unsigned int row, unsigned int column, Direction direction, int length)
    {
        cout << "read" <<endl;
         i++;
        return "";
    }
    void Board::show()
    {
        cout << "show" <<endl;
        i++;

    }
}


