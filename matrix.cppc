#pragma once

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>


class Matrix {
   //TODO: implement me
   size_t num_rows, num_cols;
   std::vector< std::vector<double> > arr;

   public:
   Matrix();
   Matrix(size_t num_rows, size_t num_cols);

   void Reset(size_t new_num_rows, size_t new_num_cols);
   double At(size_t i, size_t j) const;

   double &At(size_t i, size_t j);
   double GetNumRows() const;

   double GetNumColumns() const;
   Matrix operator+(const Matrix& a);
   bool operator==(const Matrix& a);

};

std::ostream& operator<<(std::ostream& o, const Matrix& A);
