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
    int numOfItems = 0;

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
        numOfItems++;
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
        // jika kosong, ga dibalik
        if (isEmpty() || head == tail) {
            return; 
        }

        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {
            temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = temp;
        }

        temp = head;
        head = tail;
        tail = temp;
        
        cout << "~ Menjalankan Fungsi Balik ~" << endl;
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