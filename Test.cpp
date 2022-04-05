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


TEST_CASE("Constractor")
{
	// Test Case 1 --> Constractor - full parameters
	std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  	std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
  	Matrix a{identity, 3, 3};
	CHECK(a.colums == 3);
	CHECK(a.rows == 3);
	CHECK(a.mat[0][0] == 1);
	CHECK(a.mat[1][1] == 1);
	CHECK(a.mat[2][2] == 1);
	// Test Case 2 --> Constractor - By row and columns values only
	Matrix b(3,5);
	CHECK(b.colums == 5);
	CHECK(b.rows == 3);
	CHECK(b.mat[0][0] == 1);
	CHECK(b.mat[1][1] == 1);
	CHECK(b.mat[2][2] == 1);
	// Test Case 3 --> Defult Constractor
	Matrix c;
	CHECK(b.colums == 1);
	CHECK(b.rows == 1);
	CHECK(b.mat[0][0] == 1);



}
TEST_CASE("Arithmetic Operators")
{

	// Test Case 1.1 --> +
	std::vector<double> identity = {1,0,0,2,3,4};
	Matrix a1(identity,2,3);
	Matrix a2(2,3);
	CHECK((a1+a2).mat[0][0] == 2);
	CHECK((a1+a2).mat[1][0] == 2);
	CHECK(((a1+a2).rows == 2));
	CHECK(((a1+a2).colums == 3));
	// Test Case 1.2 --> +=
	a1 += a2;
	CHECK(a1.mat[0][0] == 2);
	CHECK(a1.mat[1][0] == 2);
	CHECK((a1.rows == 2));
	CHECK((a1.colums == 3));
	// Test Case 2.1 --> -
	Matrix b1(identity,2,3);
	Matrix b2(2,3);
	CHECK((b1-b2).mat[0][0] == 0);
	CHECK((b1-b2).mat[1][0] == 2);
	CHECK(((b1-b2).rows == 2));
	CHECK(((b1-b2).colums == 3));
	// Test Case 2.2 --> -=
	b1 += b2;
	CHECK(b1.mat[0][0] == 0);
	CHECK(b1.mat[1][0] == 2);
	CHECK((b1.rows == 2));
	CHECK((b1.colums == 3));

	// // Test Case 2.1 --> ++
	Matrix c1(identity,2,3);
	Matrix c2(identity,2,3);

	++c1;
	c1++;
	CHECK(c1.mat[0][0] == 1);
	CHECK((c1).mat[1][0] == 2);
	CHECK(((b1-b2).rows == 2));
	CHECK(((b1-b2).colums == 3));
	// Test Case 2.2 --> --
	b1 += b2;
	CHECK(b1.mat[0][0] == 0);
	CHECK(b1.mat[1][0] == 2);
	CHECK((b1.rows == 2));
	CHECK((b1.colums == 3));

	
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
}