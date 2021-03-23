#include "Board.hpp"
#include "doctest.h"
#include <string>
#include "Direction.hpp"
using ariel::Direction;
using ariel::Board;
#include <iostream>
#include <stdexcept>
using namespace std;
ariel::Board board;

TEST_CASE("check deafult"){
    CHECK(board.read(50,50,Direction:: Vertical,1)==string("_"));
}

TEST_CASE("checking post and read together")
{
    CHECK_NOTHROW(board.post(0,0,Direction::Horizontal,"first"));
    CHECK(board.read(0,0,Direction::Horizontal,11)==string("first"));
    CHECK_NOTHROW(board.post(2,1,Direction::Vertical,"ariel"));
}
TEST_CASE("check randomaly posting"){
    int loops=10;
    unsigned int row = (rand() % 101); // return number between 0 to 100
    unsigned int col = (rand() % 101);
    for(int i=0;i<loops;i++){
        if(i%2==0){
            CHECK_NOTHROW(board.post(row,col,Direction::Vertical,"a"));
        }
        else{
            CHECK_NOTHROW(board.post(row,col,Direction::Horizontal,"b"));
        }
}
}
TEST_CASE("checking overiding"){
    board.post(12,12,Direction:: Vertical,"-----");
    board.post(12,12,Direction::Vertical,"+++++");
    CHECK(board.read(12,12,Direction::Vertical,5)==string("+++++"));
}

TEST_CASE("check random empty locations"){
    int loops=10;
    unsigned int row = (rand() % 101);
    unsigned int col = (rand() % 101);
    for(int i=0;i<loops;i++){
        CHECK(board.read(row,col,Direction::Vertical,1)==string("_"));
    }
}
TEST_CASE("checking length 0"){
    CHECK(board.read(12, 12, Direction::Horizontal, 0) == "");
    CHECK(board.read(10, 10, Direction::Vertical, 0) == "");
    CHECK(board.read(10, 30, Direction::Horizontal, 0) == "");
    CHECK(board.read(30, 10, Direction::Vertical, 0) == "");
    CHECK(board.read(15, 12, Direction::Horizontal, 0) == "");
    CHECK(board.read(51, 12, Direction::Vertical, 0) == "");
}