// задание таблицы с произвольным типом данных T
#include <vector>
#include <algorithm>

template<typename T>
class Table {
    size_t numRows, numCols;
    std::vector< std::vector<T> > v;
    public:
        Table(size_t row, size_t col) : numRows(row), numCols(col){ v = std::vector< std::vector<T> >(row,  std::vector<T>(col)); }; // конструктор, задание размера
        std::vector<T> operator[](const size_t i) const{ // реализация оператора [] (в итоге возможно обращение [][])
            return v[i];
        }
        std::vector<T>& operator[](const size_t i){
            return v[i];
        }
        void Resize(size_t newN, size_t newM){ // изменение размера
            numRows = newN; numCols = newM;
            v.resize(numRows);
            for(auto& it : v)
                it.resize(numCols);
        }
        std::pair<size_t, size_t> Size() const{ // возвращение размера
            return {numRows, numCols};
        }
};
