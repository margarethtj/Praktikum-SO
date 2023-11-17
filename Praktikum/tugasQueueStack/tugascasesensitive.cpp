//case sensitive
#include <iostream>
using namespace std;

struct Node {
    char alfabet;
    int jumlah;
    Node* next;
};

class Stack {
private:
    Node* top;
    int arrchar[52];

public:
    Stack() {
        top = nullptr;
        for (int i = 0; i < 52; i++) {
            arrchar[i] = 0;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(char alfabet) {
        if (isalpha(alfabet)) {
            int index;
            if (isupper(alfabet)) {
                index = alfabet - 'A';
            } else {
                index = alfabet - 'a' + 26; 
            }
            arrchar[index]++;

            Node* temp = new Node;
            temp->alfabet = alfabet;
            temp->jumlah = arrchar[index];
            temp->next = top;
            top = temp;
        }
    }

    void pop() {
        if (!isEmpty()) {
            Node* temp = top;
            char value = top->alfabet;
            int index;

            if (isupper(value)) {
                index = value - 'A';
            } else {
                index = value - 'a' + 26;
            }

            int jumlah = top->jumlah;
            top = top->next;
            delete temp;

            cout << "[" << value << "," << jumlah << "] ";
        }
    }

    void printAll() {
    for (char c = 'A'; c <= 'Z'; c++) {
        int index = c - 'A';
        if (arrchar[index] > 0) {
            cout << "[" << c << "," << arrchar[index] << "] ";
        }
    }
    for (char c = 'a'; c <= 'z'; c++) {
        int index = c - 'a' + 26;
        if (arrchar[index] > 0) {
            cout << "[" << c << "," << arrchar[index] << "] ";
        }
    }
    cout << endl;
    }
};

int main() {
    Stack coba1;
    string kalimat = "Aku Besok akan makan nasi goreng lalu karena tidak habis akan kubungkus pulang dan kupanasin dirumah.";

    for (char c : kalimat) {
        coba1.push(c);
    }

    coba1.printAll();

    return 0;
}