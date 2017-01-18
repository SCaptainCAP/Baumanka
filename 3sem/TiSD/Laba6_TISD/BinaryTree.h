//
// Created by serych on 05.12.16.
//
#ifndef LABA6_TISD_BINARYTREE_H
#define LABA6_TISD_BINARYTREE_H

#include <vector>
#include "Deque.h"


#define DEFAULT_MIDDLE 80
#define DEFAULT_ELEM_WIDTH 1
using namespace std;
template <class T>
struct Node {
    Node<T>* left = NULL;
    Node<T>* right = NULL;
    T data;
    Node(T dat) : data(dat) {}
};

template <class T>
struct Visualizer {
    Node<T>* elem;
    int depth;
    bool left;
    Visualizer(Node<T>* _elem, int _depth, bool _left) : elem(_elem), depth(_depth), left(_left){}
};
template <class T>
class BinaryTree {
private:
    //void printWays(int elemWidth = 1, int cencerTab = 40);
    Node<T>* root = NULL;
    void CLRrecursiveVector(Node<T> *node, vector<T>& vect);
    void LCRrecursiveVector(Node<T> *node, vector<T>& vect);
    void RCLrecursiveVector(Node<T> *node, vector<T>& vect);
    vector<T> AcrossWalkVector();
public:
    void addNode(T data);
    void visualize(int middle = DEFAULT_MIDDLE, int elem_width = DEFAULT_ELEM_WIDTH);
};

template <class T>
void BinaryTree<T>::addNode(T data) {
    Node<T>* newNode = new(nothrow)  Node<T>(data);
    if (!newNode)
        throw ("Cannot allocate memory");
    if (root == NULL) {
        root = newNode;
        return;
    }
    Node<T>* tmp = root;
    while (1) {
        if (data <= tmp->data) {
            if (tmp->left != NULL) {
                tmp = tmp->left;
            }
            else {
                tmp->left = newNode;
                break;
            }
        }
        else {
            if (tmp->right != NULL) {
                tmp = tmp->right;
            }
            else {
                tmp->right = newNode;
                break;
            }
        }
    }
}

template <class T>
void BinaryTree<T>::CLRrecursiveVector(Node<T> *node, vector<T>& vect) {
    if (node != NULL) {
        vect.push_back(node->data);
        CLRrecursiveVector(node->left, vect);
        CLRrecursiveVector(node->right, vect);
    }
}

template <class T>
void BinaryTree<T>::LCRrecursiveVector(Node<T> *node, vector<T>& vect) {
    if (node != NULL) {
        LCRrecursiveVector(node->left, vect);
        vect.push_back(node->data);
        LCRrecursiveVector(node->right, vect);
    }
}

template <class T>
void BinaryTree<T>::RCLrecursiveVector(Node<T> *node, vector<T>& vect) {
    if (node != NULL) {
        RCLrecursiveVector(node->right, vect);
        vect.push_back(node->data);
        RCLrecursiveVector(node->left, vect);
    }
}

template <class T>
vector<T> BinaryTree<T>::AcrossWalkVector() {
    Deque<Node<T>*> queue;
    vector<T> answer;
    if (root == NULL)
        return answer;
    queue.PushBack(root);
    while (!queue.IsEmpty()) {
        if (queue.GetFront()->left != NULL) {
            queue.PushBack(queue.GetFront()->left);
        }
        if (queue.GetFront()->right != NULL) {
            queue.PushBack(queue.GetFront()->right);
        }
        answer.push_back(queue.PopFront()->data);
    }
    return answer;
}

template <class T>
void BinaryTree<T>::visualize(int middle, int elem_width) {
    if (root == NULL)
        return;
    Deque<Node<T>*> queue;
    vector<T*> answer;
    queue.PushBack(root);
    while (!queue.IsEmpty()) {
        /*if (queue.GetFront()->left != NULL) {
            queue.PushBack(queue.GetFront()->left);
        }
        if (queue.GetFront()->right != NULL) {
            queue.PushBack(queue.GetFront()->right);
        }*/
        if (queue.GetFront() != NULL) {
            queue.PushBack(queue.GetFront()->left);
            queue.PushBack(queue.GetFront()->right);
        }
        if (queue.GetFront() != NULL)
            answer.push_back(&(queue.GetFront()->data));
        else
            answer.push_back(NULL);
        queue.PopFront();
    }
    vector<T> v = AcrossWalkVector();
    int elems_on_layer = 1;
    int i = 0;
   /* while (i < answer.size()) {
        for (int j = 0; j < middle; j++) {
            cout << " ";
        }
        for (int j = 0; j < elems_on_layer; j++) {
            if (answer[i] != NULL) {
                cout << *(answer[i]);
            }
            else {
                for (int k = 0; k < elem_width; k++)
                    cout << " ";
            }
            i++;
            for (int k = 0; k < middle * 2; k++) {
                cout << " ";
            }
        }
        middle /= 2;
        elems_on_layer *= 2;
        cout << endl;
    }*/

     while (i < answer.size()) {
        for (int j = 0; j < middle / 2; j++) {
            cout << " ";
        }
        for (int j = 0; j < elems_on_layer; j++) {
            cout << "|";
            for (int k = 0; k < middle / 2; k++)
                cout << "-";
            if (answer[i] != NULL) {
                cout << *(answer[i]);
            }
            else {
                for (int k = 0; k < elem_width; k++)
                    cout << "-";
            }
            for (int k = 0; k < middle / 2; k++)
                cout << "-";
            cout << "|";
            i++;
            for (int k = 0; k < middle; k++) {
                cout << " ";
            }
        }
        middle /= 2;
        elems_on_layer *= 2;
        cout << endl;
    }
}

#endif