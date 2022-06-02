#include "matrix.h"
#include <stdexcept>
#include <sstream>

#define EPSILON 10E-5

Matrix::Matrix(): num_rows(0), num_cols(0){}

Matrix::Matrix(size_t num_rows, size_t num_cols): num_rows(num_rows), num_cols(num_cols) {arr = std::vector< std::vector<double> >(num_rows, std::vector<double>(num_cols));}

void Matrix::Reset(size_t new_num_rows, size_t new_num_cols){
    num_rows = new_num_rows; num_cols=new_num_cols;
    arr = std::vector< std::vector<double> >(new_num_rows, std::vector<double>(new_num_cols));
}

double Matrix::At(size_t row, size_t col) const {
    if(row>=num_rows || col>=num_cols) throw std::out_of_range("ERROR: Out of range!");
    return arr[row][col];
}

double &Matrix::At(size_t row, size_t col) {
    if(row>=num_rows || col>=num_cols) throw std::out_of_range("ERROR: Out of range!");
    return arr[row][col];
}

double Matrix::GetNumRows() const {
    return num_rows;
}

double Matrix::GetNumColumns() const {
    return num_cols;
}

std::ostream& operator<<(std::ostream& o, const Matrix& A){
    size_t n=A.GetNumRows(),m=A.GetNumColumns();
    o<<n<<" "<<m<<std::endl;
    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<m; j++){
            if(j!=m-1) o<<A.At(i,j)<<" ";
            else o<<A.At(i, j)<<std::endl;
        }
    }
    return o;
}

std::istream& operator>>(std::istream& o, Matrix& A){
    size_t n,m;
    double newEl;
    o>>n>>m;
    A.Reset(n,m);

    for(size_t i = 0; i<n; i++){
        for(size_t j = 0; j<m; j++){
            o>>newEl;
            A.At(i,j) = newEl;
        }
    }
    return o;
}

bool Matrix::operator==(const Matrix& a){
    size_t firstNumOfRows = a.GetNumRows(), firstNumOfCols = a.GetNumColumns(), secondNumOfRows = num_rows, secondNumOfCols = num_cols;   
    if(firstNumOfRows != secondNumOfRows || firstNumOfCols != secondNumOfCols){
        return false;
    }
    return std::equal(arr.begin(), arr.end(), a.arr.begin(), [](const std::vector<double>& v1, const std::vector<double>& v2){
        return std::equal(v1.begin(), v1.end(), v2.begin(), [](double num1, double num2){ 
            return std::fabs(num1-num2) < EPSILON;
        });
    });
}

Matrix Matrix::operator+(const Matrix& a){
    size_t firstNumOfRows = a.GetNumRows(), firstNumOfCols = a.GetNumColumns(), secondNumOfRows = num_rows, secondNumOfCols = num_cols;
    if(firstNumOfRows != secondNumOfRows || firstNumOfCols != secondNumOfCols){
        throw std::invalid_argument("ERROR: Incorrect matrix sizes!");
    }

    Matrix newMatrix(firstNumOfRows, firstNumOfCols);
    std::transform(arr.begin(), arr.end(), a.arr.begin(), newMatrix.arr.begin(), [&firstNumOfCols](const std::vector<double>& v1, const std::vector<double>& v2){
        std::vector<double> newVec(firstNumOfCols);
        std::transform(v1.begin(), v1.end(), v2.begin(), newVec.begin(), [](double num1, double num2){
            return num1+num2;
        }); 
        return newVec;
    });
    return newMatrix;
}
