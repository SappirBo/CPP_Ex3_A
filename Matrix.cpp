#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include "Matrix.hpp"

using namespace std;
using namespace zich;

// Helpers
void dim_check_Addition( const Matrix &m1, const Matrix &m2){
    if(m1.rows != m2.rows ||m1.colums !=m2.colums){
        throw invalid_argument("Matrixes Dimentions Must be Equals!.");
    }
    else{
        // return true;
    }
}
void dim_check_Mult(const Matrix &m1,const  Matrix &m2){
    if(m1.colums !=m2.rows){
        throw invalid_argument("The first Matrix Column Dimention Must be Equal to the second Matrix Row Dimention!");
    }
    else{
        // return true;
    }
}
void Matrix::printMat(){
    int row = this->rows;
    int col = this->colums;
    for(size_t i=0; i<row; i++){
        cout << "["; 
        for(size_t j=0; j<col; j++){
            if(j==col-1){
                cout << mat[i][j]; 
            }else{
                cout << mat[i][j] << ","; 
            }   
        }
        cout << "]"<<endl; 
    }
    cout <<endl; 
}
double row_col_mult(Matrix m1, Matrix m2, int row,int col){
    double ans = 0;
    for(int i=0; i<m1.colums; i++){
        ans += m1.mat[row][i]*m2.mat[i][col];
    }
    return ans;
}
double sum_of_matrix(Matrix m){
    double ans =0;
    for(size_t i=0; i<m.rows; i++){
        for(size_t j=0; j<m.colums; j++){
            ans += m.mat[i][j];
        }
    }
    return ans;
}

// Constractors
Matrix::Matrix(){
    this->colums = 0;
    this->rows = 0;
    this->mat = NULL;
}
Matrix::Matrix(int Row,int Colums){
    this->rows = Row;
    this->colums = Colums;
    this->mat = new double*[(size_t)Row];
    for(int i=0; i<Row;i++){
        this->mat[i] = new double[(size_t)Colums]; 
    }
    size_t x=0;
    for(int i=0; i<Row; i++){
        for(int j=0; j<Colums; j++){
            if(i == j){
                this->mat[i][j] = 1;
            }
            this->mat[i][j] = 0;
        }
    }
}
Matrix::Matrix(std::vector<double> values, int row, int col){
    this->rows = row;
    this->colums = col;
    this->mat = new double*[(size_t)row];
    for(size_t i=0; i<row;i++){
        this->mat[i] = new double[(size_t)col]; 
    }
    size_t x=0;
    for(size_t i=0; i<row; i++){
        for(size_t j=0; j<col; j++){
            this->mat[i][j] = values[x++];
        }
    }
}
Matrix::~Matrix(){
    for(size_t i=0; i< this->rows; i++){
        delete[] this->mat[i];
    }
    delete[] this->mat;
}


Matrix& zich::Matrix::operator=(const Matrix& matrix){
    Matrix old_mat = +(*this);
    
    for(size_t i=0; i<this->rows; i++){
        delete [] this->mat[i];
    }
    delete [] this->mat;
    
    size_t Rows = (size_t) matrix.rows;
    size_t Cols =  (size_t) matrix.colums;
    this->rows = Rows;
    this->colums = Cols;
    this->mat = new double*[Rows];
    for(size_t i=0;i<Rows; i++){
        this->mat[i] = new double[Cols];
    }
    for(size_t i=0;i<Rows; i++){
        for(size_t j=0; j<Cols; j++){
            this->mat[i][j] = matrix.mat[i][j];
        }
    }
    return *this;
}


// Arithmetic actions between two Matrix.
Matrix zich::operator+(const Matrix &matrix1,const Matrix &matrix2){
    dim_check_Addition(matrix1, matrix2);
    std::vector<double> arr;
    arr.resize((size_t)(matrix1.colums * matrix1.rows));

    int row = matrix1.rows;
    int col = matrix1.colums;

    int curr =0;
    for(size_t i=0; i<row; i++){
        for(size_t j=0; j<col; j++){
            arr[(size_t)curr++] = matrix1.mat[i][j] + matrix2.mat[i][j];
        }
    }
    return Matrix(arr,row,col);
}
void zich::Matrix::operator+=( const Matrix &matrix2){
    dim_check_Addition(*this, matrix2);
    for(size_t i=0; i<this->rows; i++){
        for(size_t j=0; j<matrix2.colums; j++){
            this->mat[i][j] += matrix2.mat[i][j];
        }
    }
}
Matrix zich::operator-(const Matrix &matrix1, const Matrix &matrix2){
    dim_check_Addition(matrix1, matrix2);
    Matrix tmp(matrix1.rows,matrix1.colums);
    int row = matrix1.rows;
    int col = matrix1.colums;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            tmp.mat[i][j] = matrix1.mat[i][j] - matrix2.mat[i][j];
        }
    }
    return tmp;

}
Matrix zich::operator-=(const Matrix &matrix1, const Matrix &matrix2){
    dim_check_Addition(matrix1, matrix2);
    for(size_t i=0; i<matrix1.rows; i++){
        for(size_t j=0; j<matrix2.colums; j++){
            matrix1.mat[i][j] -= matrix2.mat[i][j];
        }
    }
    return matrix1;
}
Matrix zich::operator*(const Matrix &matrix1, const Matrix &matrix2){
    dim_check_Mult(matrix1,matrix2);
    Matrix tmp(matrix1.rows,matrix2.colums);
    for(size_t i=0; i<matrix1.rows; i++){
        for(size_t j=0; j<matrix2.colums; j++){
            tmp.mat[i][j] = row_col_mult(matrix1,matrix2,i,j);
        }
    }
    return tmp;
}
void Matrix::operator*=( const Matrix &matrix2){
    if(this->colums != matrix2.rows){throw invalid_argument("Matrixes sizes must be equal!");}
    // Matrix tmp(this->rows, matrix2.colums);
    for(size_t i=0; i< this->rows; i++){
        for(size_t j=0; j<matrix2.colums; j++){
            double x=0;
            for(size_t k=0; k<this->colums; k++){
                x += this->mat[i][k]*matrix2.mat[k][j];
            }
            this->mat[i][j] = x;
        }
    }
    // this->colums = tmp.colums;
    // this->rows = tmp.rows;
    // this->mat = tmp.mat;
}


Matrix & zich::Matrix::operator++(){
    for(size_t i=0;i<this->rows; i++){
        for(size_t j=0; j< this->colums; j++){
            this->mat[i][j]++;
        }
    }
    return *this;
}
Matrix Matrix::operator++(int){
    Matrix tmp = +(*this);
    ++(*this);
    return tmp;
}
Matrix & zich::Matrix::operator--(){
    for(size_t i=0;i<this->rows; i++){
        for(size_t j=0; j< this->colums; j++){
            this->mat[i][j]++;
        }
    }
    return *this;
}
Matrix zich::Matrix::operator--(int){
    Matrix tmp = +(*this);
    ++(*this);
    return tmp;
}


// Arithmetic actions between Matrix and scalar.
Matrix zich::operator*(const double s ,const Matrix &matrix1){
    std::vector<double> arr;
    arr.resize((size_t)(matrix1.colums * matrix1.rows));
    size_t curr = 0;
    int rows = matrix1.rows;
    int col = matrix1.colums;
    for(size_t i=0; i< rows; i++){
        for(size_t j=0; j<col; j++){
            arr[curr++] = matrix1.mat[i][j]*s; 
        }
    }
    return Matrix(arr,rows,col);
}
Matrix zich::operator*(const Matrix &matrix1,double s ){
    return s*matrix1;
}
void Matrix::operator*=(double s ){
    // Matrix tmp(this->rows,this->colums);
    for(size_t i=0; i< this->rows; i++){
        for(size_t j=0; j<this->colums; j++){
            this->mat[i][j] *= s; 
        }
    }
    // this->mat = tmp.mat;
}

// Unary Actions
Matrix zich::Matrix::operator-()const{
    std::vector<double> arr;
    arr.resize((size_t)(this->colums * this->rows));
    int rows = this->rows;
    int col = this->colums;
    size_t curr = 0;
    for(size_t i=0; i< rows; i++){
        for(size_t j=0; j<col; j++){
            if(this->mat[i][j] != 0){
                arr[curr++]= this->mat[i][j] * -1; 
            }else{
                arr[curr++]=0;
            }
        }
    }
    return Matrix(arr,rows,col);
}
Matrix zich::Matrix::operator+()const{
    std::vector<double> arr;
    arr.resize((size_t)(this->colums * this->rows));
    int rows = this->rows;
    int col = this->colums;
    size_t curr = 0;
    for(size_t i=0; i< rows; i++){
        for(size_t j=0; j<col; j++){
            if(this->mat[i][j] != 0){
                arr[curr++]= this->mat[i][j] * 1; 
            }else{
                arr[curr++]=0;
            }
        }
    }
    return Matrix(arr,rows,col);
}

// Compare Operator between two matrix.
bool zich::operator<(const Matrix &matrix1, const Matrix &matrix2){
    bool ans = false;
    if(sum_of_matrix(matrix1)<sum_of_matrix(matrix2)){
        ans = true;
    }
    return ans;
}
bool operator<=(const Matrix &matrix1, const Matrix &matrix2){
    bool ans = false;
    if(sum_of_matrix(matrix1)<=sum_of_matrix(matrix2)){
        ans = true;
    }
    return ans;
}
bool operator>(const Matrix &matrix1, const Matrix &matrix2){
    bool ans = false;
    if(sum_of_matrix(matrix1)>sum_of_matrix(matrix2)){
        ans = true;
    }
    return ans;
}
bool operator>=(const Matrix &matrix1, const Matrix &matrix2){
    bool ans = false;
    if(sum_of_matrix(matrix1)>=sum_of_matrix(matrix2)){
        ans = true;
    }
    return ans;
}
bool operator==(const Matrix &matrix1, const Matrix &matrix2){
    bool ans = false;
    if(sum_of_matrix(matrix1)==sum_of_matrix(matrix2)){
        ans = true;
    }
    return ans;
}
bool operator!=(const Matrix &matrix1, const Matrix &matrix2){
    bool ans = false;
    if(sum_of_matrix(matrix1)!=sum_of_matrix(matrix2)){
        ans = true;
    }
    return ans;
}

// Ostream/Istream
std::ostream& zich::operator<<(std::ostream &o, const Matrix &matrix){
    int row = matrix.rows;
    int col = matrix.colums;
    for(size_t i=0; i<row; i++){
        o << "["; 
        for(size_t j=0; j<col; j++){
            if(j==col-1){
                o << matrix.mat[i][j]; 
            }else{
                o << matrix.mat[i][j] << ","; 
            }   
        }
        o << "]"<<endl; 
    }
    return o;
}
istream & operator>>(std::istream &o, Matrix &matrix){
    return o;
}



