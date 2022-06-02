#include <vector>
#include <algorithm>

template<typename T>
class Table {
    size_t numRows, numCols;
    std::vector< std::vector<T> > v;
    public:
        Table(size_t row, size_t col) : numRows(row), numCols(col){ v = std::vector< std::vector<T> >(row,  std::vector<T>(col)); };
        std::vector<T> operator[](const size_t i) const{
            return v[i];
        }
        std::vector<T>& operator[](const size_t i){
            return v[i];
        }
        void Resize(size_t newN, size_t newM){
            numRows = newN; numCols = newM;
            v.resize(numRows);
            for(auto& it : v)
                it.resize(numCols);
        }
        std::pair<size_t, size_t> Size() const{
            return {numRows, numCols};
        }
};
