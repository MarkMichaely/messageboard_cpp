/**
 * program for message-board exercise.
 * 
 * sources used:
 * https://www.techiedelight.com/append-char-end-string-cpp/
 * https://www.techiedelight.com/iterate-over-characters-string-cpp/
 * Author: Mark Michaely
 * Since : 2021-03
 */



#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
using namespace std;

namespace ariel{
    void Board::post (uint row, uint column, Direction direction, std::string const &messsage) {
        this->min_row = min(this->min_row,row);
        this->max_row = max(this->max_row,row);
        this->min_column = min(this->min_column,column);
        this->max_column = max(this->max_column,column);
        for (char c: messsage){
            this->board[row][column].def = c;
            if (direction == Direction::Horizontal) {
                column++;
            }
            else{
                row++;
            }
        }
    }
    std::string Board::read (uint row, uint column, Direction direction, uint length){
        std::string ans;
        for (size_t i = 0; i < length; i++)
        {
            ans += this->board[row][column].def;
            if (direction == Direction::Horizontal) {
                column++;
            }
            else{
                row++;
            }
        }
        
        return ans;
    }
    void Board::show(){
        cout << "|";
        for (size_t i = 0; i <= this->max_row-this->min_row; i++){
            cout << "=";
        }
        cout << "|\n";
        for (size_t i = this->min_row; i <= this->max_row; i++) {
            cout << "|";
            for (size_t j = this->min_column; j <= this->max_column; j++) {
                cout << this->board[i][j].def;
            }
            cout << "|\n";
            
    }
        cout << "|";
        for (size_t i = 0; i <= this->max_row-this->min_row; i++){
            cout << "=";
        }
        cout << "|\n";    
}
}
