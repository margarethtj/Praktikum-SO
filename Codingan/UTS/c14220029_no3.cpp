#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int data) {
        Node* pointer = new Node;
        pointer->data = data;

        if (isEmpty() || data <= top->data) {
            pointer->next = top;
            top = pointer;
        }
        else {
            Stack temp;
            while (!isEmpty() && data > top->data) {
                temp.push(pop());
            }
            push(data);

            while (!temp.isEmpty()) {
                push(temp.pop());
            }
        }
    }

    int pop() {
        if (!isEmpty()) {
            Node* temp = top;
            int value = top->data;
            top = top->next;
            delete temp;
            return value;
        }
        return -1;
    }

    void printAll() {
        if (!isEmpty()) {
            Node* temp = top;
            while (temp != nullptr) {
                cout << temp->data << endl;
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Stack coba1;
    coba1.push(130);
    coba1.push(100);
    coba1.push(50);
    coba1.push(200);
    coba1.printAll();

    int temp = coba1.pop();
    coba1.printAll();
    cout << temp << endl;
    cout << coba1.pop();

    coba1.printAll();

    return 0;
}
