#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <typename T>
struct Node {
    T value;
    Node* left; 
    Node* right; 
    Node(T value) : value {value}, left {nullptr}, right {nullptr} {}
};

template <typename T>
Node<T>* createBST(vector<T>& data, int start, int end) {
    if (start > end) return nullptr;
    int middle = start + (end - start) / 2;
    auto root = new Node<T> {data[middle]};
    root->left = createBST(data, start, middle - 1);
    root->right = createBST(data, middle + 1, end);
    return root;
}

template <typename T>
void printInorder(Node<T>* BTS) {
    if (BTS) {
        printInorder(BTS->left);
        cout << "(" << BTS->value << ")";
        printInorder(BTS->right);
    }
}
