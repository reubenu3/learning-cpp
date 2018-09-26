//
//  main.cpp
//
//
//  Created by Reuben Urias on 8/29/18.
//

#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "matrix.h"



int main() {
    
    //    //create Matrix obj
    //    Matrix matrix1;
    //    std::cin >> matrix1;
    //    std::cout << matrix1;
    //
    //    //add 2 matrices
    //    Matrix matrix2{2, 2, {1, 2, 3, 4}};
    //    Matrix matrix3 = matrix1 + matrix2;
    //    std::cout << matrix3;
    //
    //    // multiply matrix by scalar
    //    Matrix matrix4{2, 2, {1, 1, 1, 1}};
    //    matrix4 = matrix4 * 3;
    //    std::cout << matrix4;
    
    // dot product
    Matrix matrix1(2, 3, {1, 2, 3, 4, 5, 6});
    Matrix matrix2(3, 2, {1, 2, 3, 4, 5, 6});
    Matrix matrix3 = matrix1 ^ matrix2;
    std::cout << matrix3;
    
    return 0;
}
