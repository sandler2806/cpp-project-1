#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));


    CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces(
        "@@@@@@@@@@@@@"
        "@-----------@"
        "@-@@@@@@@@@-@"
        "@-----------@"
        "@@@@@@@@@@@@@"));
    // two inputs with one small and large number
    CHECK(nospaces(mat(3, 19, '@', '-')) == nospaces(
        "@@@"
        "@-@"
        "@-@"
        "@-@"
        "@-@"
        "@-@"
        "@-@"
        "@-@"
        "@-@"
        "@-@"
        "@-@"
        "@-@"
        "@-@"
        "@-@"
        "@-@"
        "@-@"
        "@-@"
        "@-@"
        "@@@"));


    CHECK(nospaces(mat(21, 3, '@', '-')) == nospaces(
        "@@@@@@@@@@@@@@@@@@@@@"
        "@-------------------@"
        "@@@@@@@@@@@@@@@@@@@@@"));

    //two big numbers as inputs 
    CHECK(nospaces(mat(17, 19, '@', '-')) == nospaces(
        "@@@@@@@@@@@@@@@@@"
        "@---------------@"
        "@-@@@@@@@@@@@@@-@"
        "@-@-----------@-@"
        "@-@-@@@@@@@@@-@-@"
        "@-@-@-------@-@-@"
        "@-@-@-@@@@@-@-@-@"
        "@-@-@-@---@-@-@-@"
        "@-@-@-@-@-@-@-@-@"
        "@-@-@-@-@-@-@-@-@"
        "@-@-@-@-@-@-@-@-@"
        "@-@-@-@---@-@-@-@"
        "@-@-@-@@@@@-@-@-@"
        "@-@-@-------@-@-@"
        "@-@-@@@@@@@@@-@-@"
        "@-@-----------@-@"
        "@-@@@@@@@@@@@@@-@"
        "@---------------@"
        "@@@@@@@@@@@@@@@@@"));
        


}

TEST_CASE("Bad input") {
    // one or both of the variables is even
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(1, 4, '$', '%'));
    CHECK_THROWS(mat(6, 8, '$', '%'));
    // one or both of the variables equals to zero
    CHECK_THROWS(mat(0, 5, '$', '%'));
    CHECK_THROWS(mat(3, 0, '$', '%'));
    CHECK_THROWS(mat(0, 0, '$', '%'));
    // one or both of the variables is negative
    CHECK_THROWS(mat(9, -1, '$', '%'));
    CHECK_THROWS(mat(-1, 7, '$', '%'));
    CHECK_THROWS(mat(-1, -1, '$', '%'));
}
TEST_CASE("Edge cases") {

    // only 1 row or collum \ both 1 
    CHECK(nospaces(mat(1, 5, '@', '-')) == nospaces(
        "@"
        "@"
        "@"
        "@"
        "@"));

    CHECK(nospaces(mat(3, 1, '@', '-')) == nospaces(
        "@@@"));

    CHECK(nospaces(mat(1, 1, '@', '-')) == nospaces(
        "@"));

    // both variables with the same sigh
    CHECK(nospaces(mat(5, 3, '@', '@')) == nospaces(
        "@@@@@"
        "@@@@@"
        "@@@@@"));
    // same number for the variables
    CHECK(nospaces(mat(7, 7, '@', '-')) == nospaces(
        "@@@@@@@"
        "@-----@"
        "@-@@@-@"
        "@-@-@-@"
        "@-@@@-@"
        "@-----@"
        "@@@@@@@"));   
    CHECK(nospaces(mat(9, 9, '@', '-')) == nospaces(
        "@@@@@@@@@"
        "@-------@"
        "@-@@@@@-@"
        "@-@---@-@"
        "@-@-@-@-@"
        "@-@---@-@"
        "@-@@@@@-@"
        "@-------@"
        "@@@@@@@@@")); 

}