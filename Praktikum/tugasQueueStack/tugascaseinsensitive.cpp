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
    int arrchar[26]; 

public:
    Stack() {
        top = nullptr;
        for (int i = 0; i < 26; i++) {
            arrchar[i] = 0;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(char alfabet) {
        if (isalpha(alfabet)) {
            char lowercaseData = tolower(alfabet);
            int index = lowercaseData - 'a';
            arrchar[index]++;

            Node* temp = new Node;
            temp->alfabet = lowercaseData;
            temp->jumlah = arrchar[index];
            temp->next = top;
            top = temp;
        }
    }
    void pop() {
    if (!isEmpty()) {
        Node* temp = top;
        char value = top->alfabet;
        int index = value - 'a';

        arrchar[index]--;

        top = top->next;
        delete temp;
        }
    }

    void printAll() {
        for (char c = 'a'; c <= 'z'; c++) {
            int index = c - 'a';
            if (arrchar[index] > 0) {
                cout << "[" << c << "," << arrchar[index] << "] ";
            }
        }
        cout << endl;
    }
};

int main() {
    Stack coba1;
    string kalimat = "Aku besok akan makan nasi goreng lalu karena tidak habis akan kubungkus pulang dan kupanasin dirumah.";

    for (char c : kalimat) {
        coba1.push(c);
    }

    coba1.printAll();

    return 0;
}