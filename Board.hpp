#pragma once
/**
 * h file for message-board exercise.
 * 
 * sources used:
 * https://stackoverflow.com/questions/2333728/stdmap-default-value
 * 
 * Author: Mark Michaely
 * Since : 2021-03
 */


#include "Direction.hpp"
#include <string>
#include <map>

struct makeEmptyValuesToUnderscore{
    char def = '_';
};

using ariel::Direction;
using namespace std;

namespace ariel {
    class Board {
        private:
            uint min_row, max_row, min_column, max_column;
            std::map<uint, std::map<uint, makeEmptyValuesToUnderscore>> board;
        
        public:
            Board() {
                max_row=0;
                max_column=0;
                min_column=INT8_MAX;
                min_row=INT8_MAX;
            }
            ~Board(){

            }
            void post (uint row, uint column, Direction direction, std::string const &messsage);
            std::string read (uint row, uint column, Direction direction, uint length);
            void show();
    };
}