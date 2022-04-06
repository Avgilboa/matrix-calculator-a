#include "Matrix.hpp"
using namespace zich;
int main(){
    std::vector<double> identity = {1, 0, 2, 0, 1, 0, 0, 0, 1};
    std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix a{identity, 3, 3};
    Matrix b{arr,3,3};

    std::cout <<--a<< "\n* \n" << b-- << "\n = \n"<< b;
    return 0;
}