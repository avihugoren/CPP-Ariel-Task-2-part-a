#include <string>
#include "Direction.hpp"
namespace ariel
{
    class Board{
    public:
        int i;
        Board();
        
        ~Board();

        void post(unsigned int row,unsigned int column,Direction direction,const std::string &message);

        std::string read(unsigned int row,unsigned int column,Direction direction,int length);

        void show();
    };
    
}