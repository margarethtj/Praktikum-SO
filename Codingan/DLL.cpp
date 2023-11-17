#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoubleLinkedList {
private:
    Node* head, * tail;

public:
    DoubleLinkedList() {
        head = tail = nullptr;
    }

    bool isEmpty() {
        if (head == nullptr) {
            return true;
        }
        return false;
    }

    void insert(int data) {
        Node* temp = new Node;
        temp->data = data;

        if (isEmpty()) {
            head = temp;
            tail = temp;
            head->next = nullptr;
            head->prev = nullptr;
        }
        else {
            tail->next = temp;
            temp->prev = tail;

            tail = temp;
            tail->next = nullptr;
        }
    }

    void print() {
        Node* temp = head;

        if (!isEmpty()) {
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    void balik() {

        //Buatlah coding disini.
        cout << "~ Menjalankan Fungsi Balik ~";
    }
};

int main() {
    DoubleLinkedList DLL;
    DLL.insert(1);
    DLL.insert(3);
    DLL.insert(4);
    DLL.insert(7);
    DLL.print();

    DLL.balik();
    DLL.print();

    DLL.balik();
    DLL.print();

    return 0;
}