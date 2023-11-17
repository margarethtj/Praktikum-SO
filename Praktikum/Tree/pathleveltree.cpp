#include <iostream>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val){
            data = val;
            left = nullptr;
            right = nullptr;
        }

        ~TreeNode(){
            if(left){
                delete left;
            }

            if(right){
                delete right;
            }
        }
};

class BinarySearchTree{
    public:
    TreeNode* root;

    BinarySearchTree(){
        root = nullptr;
    }

    TreeNode* createRoot(int data){
        if(root == nullptr){
            root = new TreeNode(data);
            return root;
        } 
        else {
            cout << "Root already exist" << endl;
        }
    }

    TreeNode* insert(TreeNode* node, int data){
        if(node == nullptr){
            return new TreeNode(data);
        }

        if(data < node->data){
            node->left = insert(node->left, data);
        } 
        else if(data > node->data){
            node->right = insert(node->right, data);
        }

        return node;
    }

    void printTree(const TreeNode* root, const string& prefix, bool isLeft){
        if(root != nullptr){{
            cout << prefix;

            if(isLeft){
                cout << "L---";
            } 
            else {
                cout << "R---";
            }

            cout << root->data << endl;

            printTree(root->left, prefix + (isLeft ? "| ":" "), true);
            printTree(root->right, prefix + (isLeft ? "| ":" "), false);
        }}
    }

    void printTree(){
        if(root != nullptr){
            printTree(root,"",false);
        }
    }

    // L, Root, R
    void inorder(const TreeNode* root){
        if(root == nullptr){
            return;
        }

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // Root, L, R
    void preorder(const TreeNode* root){
        if(root == nullptr){
            return;
        }

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    // L, R, Root
    void postorder(const TreeNode* root){
        if(root == nullptr){
            return;
        }

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    // Fungsi Search
    void searching(int value) {
        TreeNode* pointer = root;
        int level = 0;
        while (pointer!= nullptr) {
            // Nemu data
            if (pointer->data == value) {
                cout << value << ", levelnya " << level;
                return;
            }
            // Data lebih kecil, jadi pointer pindah kiri
            else if (pointer->data > value) {
                cout << pointer->data << '-';
                pointer = pointer->left;
                level++;
            }
            // Data lebih besar, jadi pointer pindah kanan
            else {
                cout << pointer->data << '-';
                pointer = pointer->right;
                level++;
            }
        }
    } 
};

int main() {
    BinarySearchTree tree;
    TreeNode* root = nullptr;

    root = tree.createRoot(25);
    root = tree.insert(root, 28);
    root = tree.insert(root, 20);
    root = tree.insert(root, 15);
    root = tree.insert(root, 5);
    root = tree.insert(root, 19);
    root = tree.insert(root, 10);
    root = tree.insert(root, 12);
    root = tree.insert(root, 30);
    root = tree.insert(root, 37);

    tree.printTree();

    cout << endl;
    cout << "Inorder: ";
    tree.inorder(tree.root);

    cout << endl;
    cout << "Preorder: ";
    tree.preorder(tree.root);

    cout << endl;
    cout << "Postorder: ";
    tree.postorder(tree.root);

    cout << endl;
    cout << "Searching: ";
    tree.searching(12);

    return 0;
}