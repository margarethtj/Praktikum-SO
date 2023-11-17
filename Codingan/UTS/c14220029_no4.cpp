#include <iostream>
using namespace std;

struct Node {
    public:
    int counterbulan = 0;
    string namabarang;
    int tanggalexpired;
    Node *next;
};

class Queue {
private:
    Node* front;

public:
    Queue() {
        front = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enQueue(string namabarang,int tanggalexpired) {
        Node* temp = new Node;
        temp->tanggalexpired = tanggalexpired;
        temp->namabarang = namabarang;
        temp->next = nullptr;
        if (isEmpty()) {
            front = temp;
        }
        else {
            Node* currentNode = front;
            while (currentNode->next != nullptr) {
                currentNode = currentNode->next;
            }
            currentNode->next = temp;
        }
    }

    int deQueue() {
        if (!isEmpty()) {
            Node* hapus = front;
            string namabarang = hapus->namabarang;
            int tanggalexpired = hapus->tanggalexpired;
            front = front->next;

            delete hapus;
            return tanggalexpired;
        }
        return -1;
    }

    void printAll() {
        Node *pointer = front;
        while (pointer != nullptr) {
            if(pointer->counterbulan == 0){
                cout << pointer->namabarang << " " << pointer->tanggalexpired << " Oktober 2023" << endl;
                pointer = pointer->next;
            }else{
                cout << pointer->namabarang << " " << pointer->tanggalexpired << " November 2023" << endl;
                pointer = pointer->next;
            }
        }
        cout << endl;
    }

    void ubahhari(int val){
        Node *pointer = front;
        while(pointer != nullptr){
            pointer->tanggalexpired = pointer->tanggalexpired + val;
            if(pointer->tanggalexpired >31){
                pointer->tanggalexpired = pointer->tanggalexpired - 31;
                pointer->counterbulan = pointer->counterbulan + 1;
                pointer = pointer->next;
            }
            else {
                pointer = pointer->next;
            }
        }
    }
};

int main() {
    Queue queue;
    queue.enQueue("baju",1);
    queue.enQueue("celana",2);
    queue.enQueue("rok",3);
    queue.enQueue("dress",4);
    queue.printAll();

    queue.ubahhari(30);
    queue.printAll();

    cout << queue.deQueue() << endl;
    queue.printAll();

    return 0;
}