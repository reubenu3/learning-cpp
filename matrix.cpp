//
//  matrix.cpp
//
//
//  Created by Reuben Urias on 8/29/18.
//

#include "matrix.h"

// default constructor
Matrix::Matrix()
: _nrows{0}, _ncols{0} {
    std::cout << "Default constructor called.\n";
    }
    
    // Overloaded constructor
    Matrix::Matrix(int rows, int cols)
    : _nrows{rows}, _ncols{cols} {
        std::cout << "2-arg constructor called for class Matrix.\n";
    }
    
    // Overloaded constructor
    Matrix::Matrix(int rows, int cols, std::vector<int> matrix_vals)
    : _nrows{rows}, _ncols{cols}, matrix{matrix_vals} {
        std::cout << "3-arg constructor called for class Matrix.\n";
    }
    
    // Copy constructor
    Matrix::Matrix(const Matrix &source)
    : _nrows{source._nrows}, _ncols{source._ncols}, matrix{source.matrix} {
        std::cout << "Copy constructor called.\n";
    }
    
    // Destructor
    Matrix::~Matrix() {
        std::cout << "Destructor called for class Matrix\n";
    }
    
    // Overload insertion operator
    std::ostream &operator<<(std::ostream &os, const Matrix &rhs) {
        os << "{\n";
        for(size_t row=0; row < rhs._nrows; ++row) {
            os << "\t{ ";
            for(size_t col=0; col < rhs._ncols; ++col) {
                os << rhs.matrix[(row * rhs._ncols) + col] << ((col==rhs._ncols-1) ? " " : ", ");
            }
            os << "}\n";
        }
        os << "}\n";
        
        return os;
    }
    
    // Overload extraction operator
    std::istream &operator>>(std::istream &in, Matrix &rhs) {
        std::cout << "Enter number of rows: ";
        in >> rhs._nrows;
        std::cout << "Enter number of columns: ";
        in >> rhs._ncols;
        std::cout << "Enter the values (space delimited): ";
        if(std::cin.peek()) {
            std::cin.ignore();
        }
        std::string matrix_str_vals;
        std::getline(in, matrix_str_vals);
        rhs.create_matrix(matrix_str_vals);
        
        return in;
    }
    
    // Add matrices
    Matrix Matrix::operator+(const Matrix &rhs) const {
        //check rows/cols match
        if(_nrows != rhs._nrows || _ncols != rhs._ncols) {
            throw "Dimension mismatch!";
        }
        
        //proceed with addition
        Matrix tmp{*this};
        for(size_t i=0; i < (_nrows * _ncols); ++i) {
            tmp.matrix[i] += rhs.matrix[i];
        }
        return tmp;
    }
    
    // Multiply matrix by scalar
    Matrix Matrix::operator*(int n) const {
        Matrix temp{*this};
        for(size_t i=0; i<temp.matrix.size(); ++i) {
            temp.matrix[i] *= n;
        }
        return temp;
    }
    
    // create matrix
    void Matrix::create_matrix(const std::string &mvals) {
        int val{0};
        std::istringstream stream(mvals);
        while(stream >> val) {
            //check type?
            //check num of elements
            matrix.push_back(val);
        }
    }
    
    // get num rows
    int Matrix::get_num_rows() {
        return _nrows;
    }
    
    
    // get num cols
    int Matrix::get_num_cols() {
        return _ncols;
    }
    
    
#ifdef OPENCL
    _kernel void matrix_add(__global int *in, __global int *b) {
        int id = get_global_id(0);
        in[id] += b[id];
    }
    
    clEnqueueNDRangeKernel(queue, matrix_add, 1, {rows*cols});
#endif
