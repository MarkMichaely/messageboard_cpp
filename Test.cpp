/**
 * unit test of board.cpp
 * 
 * 
 *
 * AUTHORS: <Mark Michaely>
 * 
 * Date: 2021-03
 */

#include "doctest.h"
#include "Board.hpp"
using namespace ariel;

//#include <boost/algorithm/string.hpp>
#include <string>
#include <algorithm>
using namespace std;

TEST_CASE("1: testing wether function propelry working")
{
	Board b;
	uint rand_row = rand() % 100;
	uint rand_col = rand() % 100;
	CHECK(b.read(0, 0, Direction::Vertical, 0) == "");
	CHECK(b.read(0, 0, Direction::Vertical, 3).size() == 3);
	CHECK(b.read(0, 0, Direction::Vertical, 3) == "___");
	CHECK(b.read(0, 0, Direction::Horizontal, 3) == "___");
	b.post(0, 0, Direction::Vertical, "");
	CHECK(b.read(0, 0, Direction::Vertical, 3) == "___");
	CHECK(b.read(rand_row, rand_col, Direction::Horizontal, 10) == "__________");
	CHECK(b.read(rand_row, rand_col, Direction::Vertical, 10) == "__________");
	b.post(0, 0, Direction::Vertical, "aaaaa");
	CHECK(b.read(0, 0, Direction::Vertical, 3) == "aaa");
	CHECK(b.read(0, 0, Direction::Horizontal, 3) == "a__");
}

TEST_CASE("2: overiding of spaces")
{
	Board b;
	b.post(0, 0, Direction::Vertical, "aaaaa");
	CHECK(b.read(0, 0, Direction::Vertical, 3) == "aaa");
	CHECK(b.read(3, 0, Direction::Vertical, 3) == "aa_");
	b.post(0, 0, Direction::Vertical, "bbbbb");
	CHECK(b.read(0, 0, Direction::Vertical, 3) == "bbb");
	CHECK(b.read(3, 0, Direction::Vertical, 3) == "bb_");
	b.post(1, 0, Direction::Vertical, "ccccc");
	b.post(2, 3, Direction::Vertical, "blabla");
	b.post(3, 2, Direction::Vertical, "123456");
	CHECK(b.read(0, 0, Direction::Vertical, 5) == "bbbbb");
	CHECK(b.read(2, 0, Direction::Vertical, 5) == "__bla");
	CHECK(b.read(3, 3, Direction::Horizontal, 3) == "b1_");
	b.post(3, 3, Direction::Horizontal, "aaaaa");
	CHECK(b.read(0, 0, Direction::Vertical, 5) == "aaa");
	CHECK(b.read(0, 0, Direction::Horizontal, 5) == "a__");
}

TEST_CASE("3: heavy overiding of spaces")
{
	Board b;
	b.post(0, 2, Direction::Vertical, "0000000000");
	b.post(1, 2, Direction::Vertical, "0000000000");
	b.post(2, 2, Direction::Vertical, "0000000000");
	b.post(3, 2, Direction::Vertical, "0000000000");
	b.post(4, 2, Direction::Vertical, "0000000000");
	b.post(5, 2, Direction::Vertical, "0000000000");
	b.post(6, 2, Direction::Vertical, "0000000000");
	CHECK(b.read(3, 1, Direction::Vertical, 12) == "_0000000000");
	b.post(0, 4, Direction::Horizontal, "1111111111");
	CHECK(b.read(3, 1, Direction::Vertical, 12) == "_0010000000");
	b.post(0, 5, Direction::Horizontal, "2222222222");
	CHECK(b.read(3, 1, Direction::Vertical, 12) == "_0012000000");
	b.post(0, 6, Direction::Horizontal, "3333333333");
	CHECK(b.read(3, 1, Direction::Vertical, 12) == "_0012300000");
	b.post(0, 7, Direction::Horizontal, "4444444444");
	CHECK(b.read(3, 1, Direction::Vertical, 12) == "_0012340000");
	b.post(0, 8, Direction::Horizontal, "5555555555");
	CHECK(b.read(3, 1, Direction::Vertical, 12) == "_0012345000");
	b.post(0, 9, Direction::Horizontal, "6666666666");
	CHECK(b.read(3, 1, Direction::Vertical, 12) == "_0012345600");
	b.post(0, 10, Direction::Horizontal, "7777777777");
	CHECK(b.read(3, 1, Direction::Vertical, 12) == "_0012345670");
	b.post(0, 11, Direction::Horizontal, "8888888888");
	CHECK(b.read(3, 1, Direction::Vertical, 12) == "_0012345678");
	b.post(0, 12, Direction::Horizontal, "9999999999");
	CHECK(b.read(3, 1, Direction::Vertical, 12) == "_0012345678");
	b.post(1, 1, Direction::Horizontal, "oneone");
	CHECK(b.read(3, 1, Direction::Vertical, 12) == "_e0012345678");
	b.post(2, 2, Direction::Horizontal, "twotwo");
	CHECK(b.read(3, 1, Direction::Vertical, 12) == "_ew012345678");
	b.post(3, 3, Direction::Horizontal, "threethree");
	CHECK(b.read(3, 1, Direction::Vertical, 12) == "_ewt12345678");
	b.post(5, 5, Direction::Horizontal, "fivefive");
	CHECK(b.read(6, 1, Direction::Vertical, 12) == "_ewe1i345678");
	b.post(6, 6, Direction::Horizontal, "sixsix");
	CHECK(b.read(6, 1, Direction::Vertical, 12) == "_ewe1is45678");
	CHECK(b.read(7, 0, Direction::Vertical, 10) == "___oe_vi__");
	
}

/* Add more test cases here */
