//
//  matrix.h
//  
//
//  Created by Reuben Urias on 8/29/18.
//

#pragma once

#include <iostream>
#include <vector>

class Matrix {
private:
    int num_of_rows;
    int num_of_cols;
    std::vector<int> matrix;
public:
    Matrix(int rows, int cols);
    Matrix(int rows, int cols, std::vector<int> matrix_vals);
    Matrix(const Matrix &source);
    ~Matrix();
    
    // operator overload --> + - *(num) *(matrix) << >> [] ^
    Matrix operator+(const Matrix &rhs) const;
    
    void display();
    int get_num_rows();
    int get_num_cols();
    void show_dimensions();
    
};




/** TODO
 
 - templatize class
 - dynamic row/col size
 - add boundary checks in methods
 - negate, subtract, scale, multiply, divide, transpose methods
 - pretty print method
 - gemm/gemv
 - display take  a stream input
 -opencl/metal
 - design patterns
 algorithms
 data structures
 
 
 
 
 **/
