#include <iostream>
#include "BinaryTree.h"
#include <string>
#include <chrono>
#include <vector>
using namespace std;


int main() {
    string input = "";
    vector<int> a;
    a.push_back(0);
    cout << "Введите строку\n";
    cin >> input;
    if (input == "") {
        cin.ignore(255);
        cin.clear();
        cout << "Строка не должна быть пустой\n";
    }
    return 0;
}

