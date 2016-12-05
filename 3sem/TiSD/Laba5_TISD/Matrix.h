using namespace std;
#include <vector>
#include <iostream>

struct Matrix {
public:
    void create(vector<vector<int>> vect);
    Matrix operator+(const Matrix& other);
    vector<vector<int>> matr;
    int get(int stolb, int str)const;
    void print();
    unsigned long getMemUsage();
};

void Matrix::create(vector<vector<int>> vect) {
    matr = vect;
}

Matrix Matrix::operator+(const Matrix &other) {
    if (matr.size() != other.matr.size() || matr[0].size() != other.matr[0].size()) {
        throw "Cannot add matrixes of different sizes";
    }
    Matrix ans = Matrix();
    for (int i = 0; i < matr.size(); i++) {
        vector<int> tmp;
        for (int j = 0; j < matr[i].size(); j++) {
            tmp.push_back(matr[i][j] + other.matr[i][j]);
        }
        ans.matr.push_back(tmp);
    }
    return ans;
}

int Matrix::get(int sstolb, int sstr)const {
    return matr[sstolb][sstr];
}

void Matrix::print() {
    for (int i = 0; i < matr.size(); i++) {
        for (int j = 0; j < matr[i].size(); j++) {
            cout << matr[i][j] << " ";
        }
        cout << endl;
    }
}

unsigned long Matrix::getMemUsage() {
    return (sizeof(this) + sizeof(int) * (matr.size() * matr[0].size()));
}