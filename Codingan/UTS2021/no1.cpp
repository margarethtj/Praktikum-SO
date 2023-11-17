#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node *next = nullptr;
};

class Queue {
    public:
        Node *front = nullptr;
        Node *rear = nullptr;
        int numOfItems = 0;
    
    void enqueue(int val) {
        Node *newNode = new Node();
        newNode->value = val;

        if (numOfItems > 0){
            rear->next = newNode;
        }
        else {
            front = newNode;
        }
        rear = newNode;
        numOfItems++;
    }

    void dequeue() {
        if (numOfItems > 0) {
            Node *pointer;
            pointer = front;

            if (numOfItems == 1){
                front = nullptr;
                rear = nullptr;
            }
            else {
                front = pointer->next;
            }
            delete pointer;           
            numOfItems--;
        }
    }

    void display(){
        Node *pointer;
        pointer = front;

        for(int i = 0; i < numOfItems; i++) {
            cout << pointer->value << endl;
            pointer = pointer->next;
        }
    }
    
    void showFrontVal() {
        cout << front->value << endl;
    }

    // untuk merandom angka
    int random() {
        int ran = 1 + (rand() % numOfItems);
        return ran;
    }

    // untuk menukar angka di index tertentu
    Queue switching(int index1, int index2) {
        if (index1 != index2) {
            Node *pointer1;
            pointer1 = front;
            for (int i = 0; i < index1-1; i++) {
                pointer1 = pointer1->next;
            }

            Node *pointer2;
            pointer2 = front;
            for(int i = 0; i < index2-1; i++) {
                pointer2 = pointer2->next;
            }

            Queue que;
            Node *temp;
            temp = front;
            for (int i = 0; i < numOfItems; i++){
                if (temp == pointer1) {
                    que.enqueue(pointer2->value);
                }
                else if (temp == pointer2) {
                    que.enqueue(pointer1->value);
                }
                else {
                    que.enqueue(temp->value);
                }
                temp = temp->next;
            }
            return que;
        }
    }
};

int main() {
    // membuat queue dan isinya
    Queue qq;
    qq.enqueue(3);
    qq.enqueue(4);
    qq.enqueue(10);
    qq.enqueue(8);
    qq.enqueue(23);

    qq.display();

    // membuat randoman angka
    int random1;
    int random2;
    random1 = qq.random();
    random2 = qq.random();

    cout << endl;
    cout << "Hasil random : " << endl;
    cout << random1 << endl;
    cout << random2 << endl;
    
    // switching
    cout << endl;
    cout << "Hasil : " << endl;
    qq = qq.switching(random1, random2);
    
    qq.display();
}