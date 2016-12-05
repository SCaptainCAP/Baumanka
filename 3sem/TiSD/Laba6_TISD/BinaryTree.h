//
// Created by serych on 05.12.16.
//
using namespace std;
template <class T>
class BinaryTree {
private:
    struct Node {
        Node* left = NULL;
        Node* right = NULL;
        T data;
        Node(T dat) : data(dat) {}
    };
    Node* root = NULL;
public:
    void addNode(T data);
};

template <class T>
void BinaryTree::addNode(T data) {
    Node* newNode = new(nothrow)  Node(data);
    if (!newNode)
        throw ("Cannot allocate memory");
    if (root == NULL) {
        root = newNode;
        return;
    }
    Node* tmp = root;
    while (tmp) {
        if (tmp->data <= data)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    tmp = newNode;
}
