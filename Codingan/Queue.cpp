#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
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

    void enQueue(int data) {
        Node* temp = new Node;
        temp->data = data;
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
            int value = hapus->data;
            front = front->next;

            delete hapus;
            return value;
        }
        return -1;
    }

    void printAll() {
        Node* currentNode = front;
        while (currentNode != nullptr) {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;
    queue.enQueue(10);
    queue.enQueue(20);
    queue.enQueue(30);
    queue.enQueue(40);

    queue.printAll();

    cout << queue.deQueue() << endl;
    queue.printAll();

    return 0;
}

Modifikasilah class queue yang diberikan untuk bisa mengerjakan aplikasi berikut:
Queue akan menyimpan data object berisi nama barang (string) dan tanggal expired (Cdate)
3 | Page

Universitas Kristen Petra Surabaya
Fakultas Teknologi Industri
Program Studi Informatika
Aplikasi mempunyai menu untuk
● Menambah data (data nama barang dan tanggal expired). Tidak perlu ada pengecekan terhadap
tanggal, diasumsikan user menginputkan data dengan tanggal yang urut. (Isi queue urut
berdasarkan tanggalnya)
● Fungsi untuk mengganti hari. Misal hari + 30 hari maka tanggal saat ini menjadi +30 hari.
Asumsikan tanggal pertama kali adalah 11 Oktober 2023.
● Fungsi menghapus data barang yang sudah expired. Data pada queue yang tanggal expired nya
sebelum atau sama dengan hari ini, di dequeue.