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

TEST_CASE("THROWS Input")
{
	// Test Case --> Negative dimention numbers.
	std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    CHECK_THROWS(Matrix a(identity,-3,3));
	CHECK_THROWS(Matrix a(identity,3,-3));
	CHECK_THROWS(Matrix a(-1,1));
	CHECK_THROWS(Matrix a(1,-1));
	// Test Case --> Zero dimention number.
	CHECK_THROWS(Matrix a(identity,0,3));
	CHECK_THROWS(Matrix a(identity,3,0));
	CHECK_THROWS(Matrix a(0,1));
	CHECK_THROWS(Matrix a(1,0));
	// // Test Case -->  Non-Natural number dimention numbers.
	// CHECK_THROWS(Matrix a(identity,1.5,3));
	// CHECK_THROWS(Matrix a(identity,3,2.2));
	// CHECK_THROWS(Matrix a(-3.1476,1));
	// CHECK_THROWS(Matrix a(1,2.71828182846));
	
	// Test Case --> The vector dont match the dimention given.
	std::vector<double> v1 = {1, 0,};
	std::vector<double> v2 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	std::vector<double> v3 = {1, 0, 0, 0, 11};
	CHECK_THROWS(Matrix a(v1,1,3));
	CHECK_THROWS(Matrix a(v2,2,2));
	CHECK_THROWS(Matrix a(v3,3,2));

	// __________Arithmetic Operators__________
	std::vector<double> m3x3 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	std::vector<double> m4x3 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1};
	std::vector<double> m2x3 = {1, 0, 0, 0, 1, 0};
	std::vector<double> m2x1 = {1, 0};
	std::vector<double> m4x4 = {1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4};
	Matrix mat3x3(m3x3,3,3);
	Matrix mat4x3(m4x3,4,3);
	Matrix mat2x3(m2x3,2,3);
	Matrix mat2x1(m2x1,2,1);
	Matrix mat4x4(m4x4,4,4);
	// Test Case --> check * with unmatched matrixes (that dont match).
	CHECK_THROWS(mat2x3*mat2x3);
	CHECK_THROWS(mat3x3*mat4x3);
	CHECK_THROWS(mat2x1*mat4x3);
	CHECK_THROWS(mat4x3*mat4x4);
	CHECK_THROWS(mat2x3*mat2x1);
	// Test Case --> check *= with unmatched matrixes (that dont match).
	CHECK_THROWS(mat2x1*=mat2x1);
	CHECK_THROWS(mat2x3*=mat4x4);
	CHECK_THROWS(mat4x4*=mat3x3);
	CHECK_THROWS(mat4x3*=mat2x3);
	// Test Case --> check + with unmatched matrixes (that dont match).
	CHECK_THROWS(mat2x1+mat2x3);
	CHECK_THROWS(mat3x3+mat4x3);
	CHECK_THROWS(mat2x1+mat4x3);
	CHECK_THROWS(mat4x3+mat4x4);
	CHECK_THROWS(mat2x3+mat2x1);
	// Test Case --> check *= with unmatched matrixes (that dont match).
	CHECK_THROWS(mat2x3+=mat2x1);
	CHECK_THROWS(mat2x3+=mat4x4);
	CHECK_THROWS(mat4x4+=mat3x3);
	CHECK_THROWS(mat4x3+=mat2x3);
	// Test Case --> check - with unmatched matrixes (that dont match).
	CHECK_THROWS(mat2x1-mat2x3);
	CHECK_THROWS(mat3x3-mat4x3);
	CHECK_THROWS(mat2x1-mat4x3);
	CHECK_THROWS(mat4x3-mat4x4);
	CHECK_THROWS(mat2x3-mat2x1);
	// Test Case --> check -= with unmatched matrixes (that dont match).
	CHECK_THROWS(mat2x3-=mat2x1);
	CHECK_THROWS(mat2x3-=mat4x4);
	CHECK_THROWS(mat4x4-=mat3x3);
	CHECK_THROWS(mat4x3-=mat2x3);
	

	





    CHECK_THROWS(Matrix a(identity,-3,3));




	// Check write for bad input  --> 
	CHECK_THROWS();

	// Check write for bad input  --> 
	CHECK_THROWS();

	// Check read for bad input  page/ row/ column.
    CHECK_THROWS();
}