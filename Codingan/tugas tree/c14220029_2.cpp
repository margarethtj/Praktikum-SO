#include <iostream>
#include <list>
using namespace std;

class Node {
    public:
        char value;
        Node *kiri = nullptr;
        Node *kanan = nullptr;

        Node (char val) { 
            value = val; 
        }
};

// BST (Binary Search Tree) --> Tree yang urut dari kiri ke kanan
void addNode(Node* tree, char val) {
    // jika value lebih kecil dari tree, maka dia menambahkan val ke kiri
    if (val < tree->value) {
        // jika dia paling kiri, maka dia ditambahkan ke kirinya
        if (tree->kiri == nullptr) {
            tree->kiri = new Node(val);
        }
        // jika dia tidak paling kiri, maka dia cari ke sebelah kirinya
        else {
            addNode(tree->kiri, val);
        }
    }

    // jika val lebih besar dari tree, maka dia menambahkan val ke kanan
    else {
        // jika dia paling kanan, maka dia ditambahkan ke kanannya
        if (tree->kanan == nullptr) {
            tree->kanan = new Node(val);
        }
        // jika dia tidak paling kanan, maka dia cari ke sebelah kanannya
        else {
            addNode(tree->kanan, val);
        }
    }
}

// fungsi print
void traverse(Node* node) {
    // pakai cara inorder (Kiri, Value, Kanan)
    // silakan diubah bila ingin menggunakan preorder/postorder
    if (node == NULL) return;
    traverse(node->kiri);
    cout << node->value << endl;
    traverse(node->kanan);
}

int main() {
    Node *tree = new Node('H');
    addNode(tree, 'F');
    addNode(tree, 'C');
    addNode(tree, 'Q');
    addNode(tree, 'S');
    addNode(tree, 'G');
    traverse(tree);
}