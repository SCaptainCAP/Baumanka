#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <stdlib.h>
#include "MatrixRare.h"
#include "Matrix.h"

using namespace std;

vector<vector<int>> create_random_map(int stolb, int str, int zero_percent);
vector<vector<int>> create_map(int stolb, int str);

void printDoubleVector(vector<vector<int>> vect);

void handleException(std::runtime_error e) {
    std::cout << e.what() << std::endl;
    exit(EXIT_FAILURE);
}

int main() {
    srand(time(NULL));
    int str = -1;
    int stolb = -1;
    int percent = -1;
    int mode = -1;

    cout << "СЛОЖЕНИЕ МАТРИЦ. ДЕМОНСТРАЦИЯ РАЗНЫХ ФОРМАТОВ ХРАНЕНИЯ МАТРИЦ v1.0\n";
    cout << "Программа складывает две матрицы. Матрицы могут быть представлены в\n";
    cout << "cтандартном или разреженном виде. Программа предполагает ввод параметров\n";
    cout << "матриц, которые будут использованы для заполнения в разных представлениях\n\n";

    while (str == -1) {
        cout << "Введите количество строк матриц: " << endl;
        cin >> str;
        if (str == -1 || str <= 0) {
            cout << "Неправильный ввод, попробуйте снова" << endl;
            str = -1;
            cin.clear();
            cin.ignore(512, '\n');
        }
    }
    while (stolb == -1) {
        cout << "Введите количество столбцов матриц: " << endl;
        cin >> stolb;
        if (stolb == -1 || stolb <= 0) {
            cout << "Неправильный ввод, попробуйте снова" << endl;
            stolb = -1;
            cin.clear();
            cin.ignore(512, '\n');
        }
    }
    cout << "\nВыберите режим ввода значений ПЕРВОЙ матрицы: автоматический (1), ручной (2) или поэлементный (3)\n";
    while (mode == -1) {
        cin >> mode;
        if (!(mode == 1 || mode == 2 || mode == 3)) {
            cout << "Неправильный ввод, попробуйте снова" << endl;
            mode = -1;
            cin.clear();
            cin.ignore(512, '\n');
        }
    }
    if (mode == 1)
        printf("Выбран автоматический режим\n");
    if (mode == 2)
        printf("Выбран ручной режим\n");
    if (mode == 3)
        printf("Выбран поэлементный режим\n");
    vector<vector<int>> a;
    if (mode == 1) {
        while (percent == -1) {
            cout << "Введите процент нулей в массивах: " << endl;
            cin >> percent;
            if (percent == -1 || percent < 0 || percent > 100) {
                cout << "Неправильный ввод, попробуйте снова" << endl;
                percent = -1;
                cin.clear();
                cin.ignore(512, '\n');
            }
        }
        a = create_random_map(stolb, str, percent);
    }
    if (mode == 2) {
        a = create_map(stolb, str);
    }
    if (mode == 3) {
        a.clear();
        for (int i = 0; i < str; i++) {
            vector<int> tmp;
            for (int j = 0; j < stolb; j++) {
                tmp.push_back(0);
            }
            a.push_back(tmp);
        }
        cout << "Чтобы закончить ввод напишите отрицательное значение номера строки" << endl;
        int d = 0,e = 0,c = 0;
        while (true) {
            cout << "Введите номер строки, стобца и значение через пробел" << endl;
            cin >> d;
            if (d == -1)
                break;
            cin >> e;
            if (e == -1)
                break;
            cin >> c;
            a[d][e] = c;
        }
    }

    MatrixRare matrixRareA;
    matrixRareA.create(a);
    Matrix matrixA;
    matrixA.create(a);
//**********************************************************************************************************************
    mode = -1;
    percent = -1;
    cout << "\nВыберите режим ввода значений ВТОРОЙ матрицы: автоматический (1), ручной (2) или поэлементный (3)\n";
    while (mode == -1) {
        cin >> mode;
        if (!(mode == 1 || mode == 2 || mode == 3)) {
            cout << "Неправильный ввод, попробуйте снова" << endl;
            mode = -1;
            cin.clear();
            cin.ignore(512, '\n');
        }
    }
    if (mode == 1)
        printf("Выбран автоматический режим\n");
    if (mode == 2)
        printf("Выбран ручной режим\n");
    if (mode == 3)
        printf("Выбран поэлементный режим\n");

    vector<vector<int>> b;
/*    vector<vector<int>> b;
    vector<vector<int>> sum;*/
    if (mode == 1) {
        while (percent == -1) {
            cout << "Введите процент нулей в массивах: " << endl;
            cin >> percent;
            if (percent == -1 || percent < 0 || percent > 100) {
                cout << "Неправильный ввод, попробуйте снова" << endl;
                percent = -1;
            }
        }
        //a = create_random_map(stolb, str, percent);
        b = create_random_map(stolb, str, percent);
    }

    if (mode == 1) {
        while (percent == -1) {
            cout << "Введите процент нулей в массивах: " << endl;
            cin >> percent;
            if (percent == -1 || percent < 0 || percent > 100) {
                cout << "Неправильный ввод, попробуйте снова" << endl;
                percent = -1;
            }
        }
        //a = create_random_map(stolb, str, percent);
        b = create_random_map(stolb, str, percent);
    }
    if (mode == 2) {
        b = create_map(stolb, str);
    }
    if (mode == 3) {
        b.clear();
        for (int i = 0; i < str; i++) {
            vector<int> tmp;
            for (int j = 0; j < stolb; j++) {
                tmp.push_back(0);
            }
            b.push_back(tmp);
        }
        cout << "Чтобы закончить ввод напишите отрицательное значение номера строки" << endl;
        int d = 0,e = 0,c = 0;
        while (true) {
            cout << "Введите номер строки, стобца и значение через пробел" << endl;
            cin >> d;
            if (d == -1)
                break;
            cin >> e;
            if (e == -1)
                break;
            cin >> c;
            b[d][e] = c;
        }
    }
    MatrixRare matrixRareB;
    matrixRareB.create(b);
    Matrix matrixB;
    matrixB.create(b);
//**********************************************************************************************************************


    auto start = std::chrono::high_resolution_clock::now();
    MatrixRare matrixRareSum = matrixRareA + matrixRareB;
    auto finish = std::chrono::high_resolution_clock::now();

    std::cout << "\n\nСложение матриц...";
    std::cout << "\nВремя сложения в разреженном представлении: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " наносекунд\n";
    cout << "Размер ПЕРВОЙ матрцы в разреженном представлении: " << matrixRareA.getMemUsage() << endl;
    cout << "Размер ВТОРОЙ матрцы в разреженном представлении: " << matrixRareB.getMemUsage() << endl;
    cout << "Размер МАТРИЦЫ-СУММЫ в разреженном представлении: " << matrixRareSum.getMemUsage() << endl;

    //matrixRareSum.print();
    cout << endl;
    auto startN = std::chrono::high_resolution_clock::now();
    Matrix matrixSum = matrixA + matrixB;
    auto finishN = std::chrono::high_resolution_clock::now();
    std::cout << "Время сложения в обычном представлении:     " << std::chrono::duration_cast<std::chrono::nanoseconds>(finishN-startN).count() << " наносекунд\n";
    cout << "Размер ПЕРВОЙ матрцы в обычном представлении:     " << matrixA.getMemUsage() << endl;
    cout << "Размер ВТОРОЙ матрцы в обычном представлении:     " << matrixB.getMemUsage() << endl;
    cout << "Размер МАТРИЦЫ-СУММЫ в обычном представлении:     " << matrixSum.getMemUsage() << endl;

    cout << "\n\nВведите 0 для выхода из программы" << endl;
    cout << "Введите 1 для просмотра ПЕРВОЙ матрицы в стандартном представлении" << endl;
    cout << "Введите 2 для просмотра ПЕРВОЙ матрицы в разреженном представлении" << endl;
    cout << "Введите 3 для просмотра ВТОРОЙ матрицы в стандартном представлении" << endl;
    cout << "Введите 4 для просмотра ВТОРОЙ матрицы в разреженном представлении" << endl;
    cout << "Введите 5 для просмотра МАТРИЦЫ-СУММЫ  в стандартном представлении" << endl;
    cout << "Введите 6 для просмотра МАТРИЦЫ-СУММЫ  в разреженном представлении" << endl;

    int inptmp = -1;
    while (inptmp != 0) {
        cin >> inptmp;
        if (inptmp == 0)
            break;
        switch (inptmp) {
            case 1:
                matrixA.print();
                break;
            case 2:
                matrixRareA.printRare();
                break;
            case 3:
                matrixB.print();
                break;
            case 4:
                matrixRareB.printRare();
                break;
            case 5:
                matrixSum.print();
                break;
            case 6:
                matrixRareSum.printRare();
                break;
            default:
                cout << "Неизвестная команда\n";
                cin.clear();
                cin.ignore(512, '\n');
        }
        cout << "\n\nВведите 0 для выхода из программы" << endl;
        cout << "Введите 1 для просмотра ПЕРВОЙ матрицы в стандартном представлении" << endl;
        cout << "Введите 2 для просмотра ПЕРВОЙ матрицы в разреженном представлении" << endl;
        cout << "Введите 3 для просмотра ВТОРОЙ матрицы в стандартном представлении" << endl;
        cout << "Введите 4 для просмотра ВТОРОЙ матрицы в разреженном представлении" << endl;
        cout << "Введите 5 для просмотра МАТРИЦЫ-СУММЫ  в стандартном представлении" << endl;
        cout << "Введите 6 для просмотра МАТРИЦЫ-СУММЫ  в разреженном представлении" << endl;
    }

    return 0;
}


int myRand() {
    return 1 + (rand() % (int) (5 - 1 + 1));
}
int myRand100() {
    return 1 + (rand() % (int) (100 - 1 + 1));
}

vector<vector<int>> create_random_map(int stolb, int str, int zero_percent) {
    vector<vector<int>> ans;
    int tmprand = 0;
    int zero = 0;
    for (int i = 0; i < str; i++) {
        vector<int> tmp;
        for (int j = 0; j < stolb; j++) {
            tmprand = myRand();
            zero = myRand100();
            if (zero < zero_percent)
                tmprand = 0;
            tmp.push_back(tmprand);
        }
        ans.push_back(tmp);
    }
    return ans;
}

vector<vector<int>> create_map(int stolb, int str) {
    vector<vector<int>> ans;
    int tmprand = 0;
    int zero = 0;
    for (int i = 0; i < str; i++) {
        cout << "Введите " << (i + 1) << " строку через пробел\n";
        vector<int> tmp;
        for (int j = 0; j < stolb; j++) {
            cin >> tmprand;
            tmp.push_back(tmprand);
        }
        ans.push_back(tmp);
    }
    return ans;
}

void printDoubleVector(vector<vector<int>> vect) {
    for (int i = 0; i < vect.size(); i++) {
        for (int j = 0; j < vect[0].size(); j++) {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }
}

