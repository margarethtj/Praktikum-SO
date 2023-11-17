#include <iostream>
using namespace std;

class Node {
    public:
        int value[4][4];
        Node *next;
};

class Stack {
    public:
        Node *top = nullptr;
        int numOfItems = 0;

    // Fungsi memasukkan matrix ke stack
    void push(){
        Node *newNode = new Node();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                newNode->value[i][j] = rand() % 100;
            }
        }
        newNode->next = top;
        top = newNode;
        numOfItems++;
    }

    // Fungsi menghitung perkalian matriks dalam stack
    void multiply() {
        if(numOfItems <= 1) {
            cout << "Error!" << endl;
        }
        else {
            Node *pointer = top;

            // masukkan matrix pertama (top) ke dalam stack 
            int matrix1[4][4];
            for(int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    matrix1[i][j] = pointer->value[i][j];
                }
            }

            // mendapatkan matrix ke dua
            pointer = pointer->next;

            int hasil[4][4];
            while (pointer != nullptr){
                // melakukan perkalian
                for(int i = 0; i < 4; i++) {
                    for (int j = 0; j < 4; j++) {
                        hasil[i][j] = 0;
                        for(int k = 0; k < 4; k++) {
                            hasil[i][j] += matrix1[i][k] * pointer->value[k][j];
                        }
                    }
                }

                pointer = pointer->next;
            }

            // menampilkan hasil perkalian
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    cout << hasil[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
};

int main(){
    Stack stack;

    while (true){
        // menu
        cout << "--: MENU :--" << endl;
        cout << "1. Insert Matrix" << endl;
        cout << "2. Perkalian dari akhir" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan : " << endl;
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1) {
            stack.push();
        }
        else if(pilihan == 2) {
            stack.multiply();
        }
        else {
            break;
        }
    }
}