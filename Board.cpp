/**
 * program for message-board exercise.
 * 
 * Author: Mark Michaely
 * Since : 2021-03
 */



#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;

namespace ariel{
    void Board::post (uint row, uint column, Direction direction, std::string messsage) {

    }
    std::string Board::read (uint row, uint column, Direction direction, uint length){
        return "blabla";
    }
    void Board::show(){
        std::cout<< "bla"<<std::endl;
    }
}

