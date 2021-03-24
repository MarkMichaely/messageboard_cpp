#pragma once
#include "Direction.hpp"
#include <string>
#include <vector>

using ariel::Direction;
using namespace std;

namespace ariel {
    class Board {
        private:
            std::vector<std::vector<std::string>> board;
        
        public:
            Board() {

            }
            ~Board(){

            }
            void post (uint row, uint column, Direction direction, std::string messsage);
            std::string read (uint row, uint column, Direction direction, uint length);
            void show();
    };
}