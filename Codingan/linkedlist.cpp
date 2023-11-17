#include <iostream>
using namespace std;


class Node {
    public:
        int value;
        Node *next;
};

class LinkedList {
    public:
        Node *head = NULL;
        int numOfItems = 0;

    void addNodeBegin(int val) {
        Node *newNode = new Node();
        newNode->value = val;
        newNode->next = head;
        head = newNode;
        numOfItems++;
    };

    void addNodeEnd(int val) {
        Node *newNode = new Node();
        newNode->value = val;

        Node *ptr; ptr = head;
        if (numOfItems>0){
            for (int i=0;i<numOfItems-1;i++) { 
                ptr = ptr->next; 
            }
            ptr->next = newNode;
        } else {
            head = newNode;
        }
        
        numOfItems++;
    };

    void printAllItems() {
        Node *ptr;
        ptr = head;
        for (int i=0;i<numOfItems;i++) { 
            cout << ptr->value << endl;
            ptr = ptr->next; 
        }

        // // -------------------------------------------------------
        // // Alternatif dari for () dalam menuju ke node terakhir
        // while (ptr != NULL) {
        //     cout << ptr->value << endl;
        //     ptr = ptr->next;
        // }
        // // -------------------------------------------------------

    };
};

int main() {
    LinkedList ll;

    ll.addNodeBegin(5);
    ll.addNodeBegin(6);
    ll.addNodeBegin(7);
    ll.addNodeBegin(8);

    ll.printAllItems();

    cout << "Number of items on the list: " << ll.numOfItems << endl;
}