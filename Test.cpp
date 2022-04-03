#include "doctest.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Matrix.hpp"

using namespace std;
using namespace zich;


TEST_CASE("Case 1")
{
	// Test Case 1 --> 
	CHECK(true == true);
}
TEST_CASE("Case 2")
{
	// Test Case 2 --> 
	CHECK_FALSE(true == false);
	CHECK(true == true);
}

TEST_CASE("Bad Input")
{
	// Test Case 3 -->
    CHECK_THROWS();

	// Check write for bad input  --> 
	CHECK_THROWS();

	// Check write for bad input  --> 
	CHECK_THROWS();

	// Check read for bad input  page/ row/ column.
    CHECK_THROWS();
}