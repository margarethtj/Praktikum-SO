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

    int getSize() {
        int size = 0;
        Node* current = top;
        while (current != nullptr) {
            size++;
            current = current->next;
        }
        return size;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;

        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            return -1; // Return a sentinel value for an empty stack
        } else {
            int value = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return value;
        }
    }

    void printAll() {
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

int main() {
    Stack stack;
    stack.push(50);
    stack.push(100);
    stack.push(150);
    stack.push(200);

    cout << "Stack Contents:" << endl;
    stack.printAll();
    
    int poppedValue = stack.pop();
    cout << "Popped Value: " << poppedValue << endl;
    
    cout << "Stack Contents after Pop:" << endl;
    stack.printAll();

    return 0;
}
