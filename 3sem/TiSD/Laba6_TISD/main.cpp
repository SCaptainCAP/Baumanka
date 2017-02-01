#include <iostream>
#include "BinaryTree.h"

#include <string>
#include <chrono>
#include <vector>
using namespace std;

void removeEqualitiesFromString(string& input) {
    for (int i = 0; i < input.size(); i++) {
        vector<int> positions;
        positions.push_back(i);
        for (int j = i + 1; j < input.size(); j++) {
            if (input[i] == input[j]) {
                positions.push_back(j);
            }
        }
        if (positions.size() != 1) {
            for (int j = 0; j < positions.size(); j++) {
                for (int k = positions[j] - j; k < input.size() - 1; k++) {
                    input[k] = input[k + 1];
                }
            }
            input = input.substr(0, input.size() - positions.size());
            i--;
        }
    }
}


int main() {
    BinaryTree<char> tree;
    string input = "";
    vector<int> a;
    a.push_back(0);
    cout << "Введите строку\n";
    while (input == "") {
        getline(cin, input);
        if (input == "")
            cout << "Строка не должна быть пустой\n";
    }
    for (int i = 0; i  < input.size(); i++) {
        tree.addNode(input[i]);
    }

    vector<char> v = tree.LRCVector();
    std::cout << "\nЭлементы дерева при постфиксном обходе: \n";
    if (v.size() == 0) {
        std::cout << "<Ни одного элемента>";
    }
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }

    tree.visualizeColorRepeating();
    auto start = std::chrono::high_resolution_clock::now();
    tree.removeDublicates();
    auto finish = std::chrono::high_resolution_clock::now();

    v = tree.LRCVector();
    std::cout << "\nОставшиеся после удаления повторяющихся элементы дерева при постфиксном обходе: \n";
    if (v.size() == 0) {
        std::cout << "<Ни одного элемента>";
    }
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";

    std::cout << "\nВремя удаления повторяющихся узлов (ДЕРЕВО  ): " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " наносекунд\n";

    start = std::chrono::high_resolution_clock::now();
    removeEqualitiesFromString(input);
    finish = std::chrono::high_resolution_clock::now();
    std::cout << "\nВремя удаления повторяющихся узлов (СТАНДАРТ): " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " наносекунд\n";


    return 0;
}

