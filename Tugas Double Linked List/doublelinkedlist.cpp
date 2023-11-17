#include <iostream>
using namespace std;


class Node {
    public:
        int value;
        Node *next;
        Node *prev;
};

class LinkedList {
    public:
        Node *head = NULL;
        Node *tail = NULL;
        int numOfItems = 0;

    void addNodeBegin(int val) {
        Node *newNode = new Node();
        newNode->value = val;
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        numOfItems++;
    };

    void addNodeEnd(int val) {
        Node *newNode = new Node();
        newNode->value = val;
        newNode->prev = tail;
        if (tail != NULL) {
            tail->next = newNode;
        }
        if (head == NULL) {
            head = newNode;
        }
        tail = newNode;
        numOfItems++;
    };

    void printAllItems() {
        Node *ptr;
        ptr = head;
        for (int i=0;i<numOfItems;i++) { 
            cout << ptr->value << endl;
            ptr = ptr->next; 
        }
    };
};

int main() {
    LinkedList ll;

    ll.addNodeBegin(5);
    ll.addNodeBegin(6);
    ll.addNodeBegin(7);
    ll.addNodeBegin(8);

    LinkedList dl;
    dl.addNodeEnd(5);
    dl.addNodeEnd(6);
    dl.addNodeEnd(7);
    dl.addNodeEnd(8);

    ll.printAllItems();
    dl.printAllItems();

    cout << "Number of items on the list: " << ll.numOfItems << endl;
}
