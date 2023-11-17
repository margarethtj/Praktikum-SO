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

void addNode(Node* tree, char parentVal, char val, int pos) {
    // jika tree adalah parent value nya, maka dia menambahkan val sesuai pos nya
    if (parentVal == tree->value) {
        // tambah di kiri
        if (pos == 1) {
            tree->kiri = new Node(val);
        }
        // tambah di kanan
        else {
            tree->kanan = new Node(val);
        }
    }
    else {
        // jika parent value tidak ketemu, maka dia cari ke sebelah kirinya
        if (tree->kiri != nullptr) {
            addNode(tree->kiri, parentVal, val, pos);
        }
        // jika parent value tidak ketemu, maka dia cari ke sebelah kanannya
        if (tree->kanan != nullptr) {
            addNode(tree->kanan, parentVal, val, pos);
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
    Node *tree = new Node('A');
    addNode(tree, 'A', 'B', 1);
    addNode(tree, 'A', 'C', 2);
    addNode(tree, 'B', 'D', 1);
    addNode(tree, 'B', 'E', 2);
    addNode(tree, 'C', 'F', 1);
    traverse(tree);
}