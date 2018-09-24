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
  
  int matrix_rows {0};
  int matrix_cols {0};

  std::cout << "Please enter vector dimensions:\n";
  
  bool valid_row {false};
  while(!valid_row) {
    std::cout << "How many rows? ";
    std::cin >> matrix_rows;
    if(matrix_rows <= 0) {
      std::cout << "Invalid number of rows. Must be positive.\n";
    } else {
      valid_row = true;
    }
  }
  
  bool valid_col {false};
  while(!valid_col) {
    std::cout << "How many columns? ";
    std::cin >> matrix_cols;
    if(matrix_cols <= 0) {
      std::cout << "Invalid number of columns. Must be positive.\n";
    } else {
      valid_col = true;
    }
  }

  
  // enter matrix values
  std::string matrix_str_vals;
  int val {0};
  std::vector<int> matrix_vals;
  std::cout << "Please enter the elements for your " << matrix_rows << " x " << matrix_cols << " matrix: ";
  if(std::cin.peek()) {
    std::cin.ignore();
  }
  std::getline(std::cin, matrix_str_vals);
  std::istringstream stream(matrix_str_vals);
  while(stream >> val) {
    //check type?
    //check num of elements
    matrix_vals.push_back(val);
  }
  
  //create Matrix obj
  Matrix matrix1 {matrix_rows, matrix_cols, matrix_vals};

  // display matrix info
  std::cout << "Matrix rows: " << matrix1.get_num_rows() << "\n";
  std::cout << "Matrix cols: " << matrix1.get_num_cols() << "\n";
  matrix1.show_dimensions();
  std::cout << "Matrix values are: \n";
  matrix1.display();
  
  //add 2 matrices
  Matrix matrix2{ 2, 2, {1, 2, 3, 4}};
  Matrix matrix3 = matrix1 + matrix2;
  matrix3.display();
    
  return 0;
}
