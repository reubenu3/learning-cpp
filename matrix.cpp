//
//  matrix.cpp
//  
//
//  Created by Reuben Urias on 8/29/18.
//

#include "matrix.h"

// Overloaded constructor
Matrix::Matrix(int rows, int cols)
: num_of_rows{rows}, num_of_cols{cols} {
    std::cout << "Constructor called for class Matrix.\n";
}

// Overloaded constructor
Matrix::Matrix(int rows, int cols, std::vector<int> matrix_vals)
    : num_of_rows{rows}, num_of_cols{cols}, matrix{matrix_vals} {
    std::cout << "Constructor called for class Matrix.\n";
}

// Copy constructor
Matrix::Matrix(const Matrix &source)
    : num_of_rows{source.num_of_rows}, num_of_cols{source.num_of_cols}, matrix{source.matrix} {
    std::cout << "Copy constructor called.\n";
}

    
// Destructor
Matrix::~Matrix() {
    std::cout << "Destructor called for class Matrix\n";
}
 
// Add matrices
Matrix Matrix::operator+(const Matrix &rhs) const {
    //check rows/cols match
    if(num_of_rows != rhs.num_of_rows || num_of_cols != rhs.num_of_cols) {
        throw "Dimension mismatch!";
    }
    
    //proceed with addition
    Matrix tmp_matrix{*this};
    for(auto el=0; el < (num_of_rows * num_of_cols); ++el) {
        tmp_matrix.matrix[el] += rhs.matrix[el];
    }
    return tmp_matrix;
}
 
    
// display matrix values
void Matrix::display() {
    std::cout << "{\n";
    for(auto row=0; row < num_of_rows; ++row) {
        std::cout << "\t{ ";
        for(auto col=0; col < num_of_cols; ++col) {
            std::cout << matrix[(row * num_of_cols) + col] << ((col==num_of_cols-1) ? " " : ", ");
        }
        std::cout << "}\n";
    }
    std::cout << "}\n";
}

// get num rows
int Matrix::get_num_rows() {
    return num_of_rows;
}


// get num cols
int Matrix::get_num_cols() {
    return num_of_cols;
}
    
// show dimensions
void Matrix::show_dimensions() {
    std::cout << "Matrix dimensions: " << num_of_rows << " x " << num_of_cols << "\n";
}
