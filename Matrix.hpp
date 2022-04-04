#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;



namespace zich
{
    class Matrix{
        private:
        public:

        double** mat;
        int colums;
        int rows;

        Matrix();
        Matrix(vector<double> values,int Rows, int Colums);
        Matrix(int Row,int Colums);
        ~Matrix();

        // Getters / Setters
        int getCols(){
            return this->colums;
        }
        int getRows(){
            return this->rows;
        }

        // Helpers 
        void printMat();

        // Arithmetic actions on single Matrix.
        friend Matrix operator++(Matrix &m);
        friend Matrix operator--(Matrix &m);

        // Arithmetic actions between two Matrix.
        friend Matrix operator+(const Matrix &matrix1, const Matrix &matrix2);
        friend Matrix operator+=(const Matrix &matrix1, const Matrix &matrix2);
        friend Matrix operator-(const Matrix &matrix1, const Matrix &matrix2);
        friend Matrix operator-=(const Matrix &matrix1, const Matrix &matrix2);
        friend Matrix operator*(const Matrix &matrix1, const Matrix &matrix2);
        void operator*=(const Matrix &matrix2);
        
        // Arithmetic actions between Matrix and scalar.
        friend Matrix operator*(double s ,const Matrix &matrix1);
        friend Matrix operator*(const Matrix &matrix1,double s );
        void operator*=(double s);
        
        // Compare Operator between two matrix.
        friend bool operator<(const Matrix &matrix1, const Matrix &matrix2);
        friend bool operator<=(const Matrix &matrix1, const Matrix &matrix2);
        friend bool operator<(const Matrix &matrix1, const Matrix &matrix2);
        friend bool operator<=(const Matrix &matrix1, const Matrix &matrix2);
        friend bool operator==(const Matrix &matrix1, const Matrix &matrix2);
        friend bool operator!=(const Matrix &matrix1, const Matrix &matrix2);


        // Onitery Actions
        Matrix& operator-();
        Matrix& operator+();


        // Ostream/Istream
        friend ostream & operator<<(std::ostream &o, Matrix &matrix);
        friend istream & operator>>(std::istream &o, Matrix &matrix);

    };
    
} 
