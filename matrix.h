//
//  matrix.h
//
//
//  Created by Reuben Urias on 8/29/18.
//

#pragma once

#include <iostream>
#include <vector>
#include <sstream>

class Matrix {
private:
    int _nrows;
    int _ncols;
    std::vector<int> matrix;
    std::string matrix_vals;
    
public:
    Matrix();
    Matrix(int rows, int cols);
    Matrix(int rows, int cols, std::vector<int> matrix_vals);
    Matrix(const Matrix &source);
    ~Matrix();
    
    // operator overload --> + - *(num) *(matrix) << >> [] ^
    friend std::ostream &operator<<(std::ostream &os, const Matrix &rhs);
    friend std::istream &operator>>(std::istream &in, Matrix &rhs);
    Matrix operator+(const Matrix &rhs) const;
    Matrix operator*(int n) const;
    
    void create_matrix(const std::string &mvals);
    int get_num_rows();
    int get_num_cols();
    
};




/** TODO
 
 - templatize class
 - add boundary checks in methods
 - negate, subtract, scale, multiply, divide, transpose methods
 - gemm/gemv
 - display take  a stream input
 -opencl/metal
 - design patterns
 algorithms
 data structures
 
 
 
 
 **/
