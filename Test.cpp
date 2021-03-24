/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Avihu Goren>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "Board.hpp"
#include <random>
#include <math.h> 
using namespace ariel;
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
using namespace std;

ariel::Direction VerticalOrHorizi()
{
    int my_rand = rand() % 2;
    if (my_rand == 0)
        return Direction::Horizontal;
    return  Direction::Vertical;
}
 int RandomUnsigned(int LowerBound,int UpperBound)
{
    int my_rand = (rand() + LowerBound) % UpperBound+1;
    return my_rand;
}
ariel::Board board;
TEST_CASE("WriteAndRead") {
    // CHECK((snowman(33232124)) == ("   -   \n  /_\\  \n\\(o_O)\n (] [)> \n (   )"));
    /* Add more checks here */ 
    	
        
	board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "abcd");
}
TEST_CASE("Post and read without override")
 {
    board.post(100,100, Direction::Horizontal,"hello");
    CHECK((board.read(100,100,Direction::Horizontal,5)) == ("hello"));

     board.post(200,200, Direction::Vertical,"hello");
    CHECK((board.read(200,200,Direction::Vertical,5)) == ("hello"));

     board.post(300,300, Direction::Horizontal,"   ");
    CHECK((board.read(300,300,Direction::Horizontal,3)) == ("   "));
    board.post(10000000,10000000, Direction::Horizontal,"   ");
    CHECK((board.read(10000000,10000000,Direction::Horizontal,3)) == ("   "));
 }
    TEST_CASE("Post and read with override")
    {
     board.post(400,400, Direction::Vertical,"   ");
     board.post(400,400, Direction::Vertical,"over");
     CHECK((board.read(100,100,Direction::Vertical,4)) == ("over"));

     board.post(100,100, Direction::Horizontal,"hello");
     board.post(100,100, Direction::Horizontal,"aa");
    CHECK((board.read(100,100,Direction::Horizontal,5)) == ("aallo"));

     board.post(200,200, Direction::Horizontal,"hello");
     board.post(200,203, Direction::Horizontal,"helaa");
    CHECK((board.read(200,200,Direction::Horizontal,5)) == ("helaa"));

     board.post(7000,7000, Direction::Horizontal,"hello");
     board.post(7000,7001, Direction::Horizontal,"a");
    CHECK((board.read(100,100,Direction::Horizontal,5)) == ("hallo"));

     board.post(100,100, Direction::Horizontal,"hello");
    CHECK((board.read(100,100,Direction::Horizontal,5)) == ("hello"));
}
 TEST_CASE("Random")
    {
        for (int i = 0 ; i < 100 ; i++)
        {
            unsigned int x = unsigned(RandomUnsigned(0,3000));
            unsigned int y = unsigned(RandomUnsigned(0,3000));
            Direction dir = VerticalOrHorizi();
            board.post(x,y, dir,"hello");
            CHECK((board.read(x,y,dir,5)) == ("hello"));
        }

    }
