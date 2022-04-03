#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Matrix.hpp"

using namespace std;
using namespace zich;


int main(){
    vector<double> value = {1,1,2,1,3,3};
    vector<double> value2 = {0,1,1,0,0,2,0,1,1,3,1,5};
    Matrix m{value,2,3};
    Matrix m2{value2,3,4};
   
    m2.printMat();
    
    (2*m2).printMat();
    m2.printMat();
    
    m2 *= 2;
    m2.printMat();
    (-m2).printMat();

    bool a = -m2 < m2 ;
    bool b = m2 < (-m2) ;

    cout<< a << endl;
    cout<< b << endl;

    cout<<"End"<<endl;


}