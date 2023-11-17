#include <iostream>
using namespace std;


class Node {
    public:
        int value;
        Node *prev;
        Node *next;
};

class CDLList {
    public:
        Node *head = nullptr;
        Node *tail = nullptr;
        int numOfItems = 0;

    void addFront(int val) {  
        Node *newNode = new Node();
        newNode->value = val;

        if (numOfItems != 0) { 
            head->prev = newNode;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head = newNode;
        } else {
            newNode->next = newNode;
            newNode->prev = newNode;
            tail = newNode;
            head = newNode;
        }

        numOfItems++;
    };

    void addIndex(int val, int index) {
        if (index > numOfItems - 1 or index < 0) {
            return;
        }
        else if (index == 0) {
            addFront(val);
        }
        else if (index == numOfItems - 1) {
            addBelakang(val);
        } 
        else {
            Node *newNode = new Node();
            newNode->value = val;

            Node *currentPtr = head;
            for (int i = 0; i < index; i++) {
                currentPtr = currentPtr->next;
            }

            Node *A = currentPtr;
            Node *B = currentPtr->next;
            newNode->prev = A;
            newNode->next = B;
            A->next = newNode;

            if (B == nullptr) { 
                head->prev = newNode;
                newNode->next = head;
                tail = newNode;
            } else {
                newNode->next = B;
                B->prev = newNode;
            }

            numOfItems++;
        }
    };

    void addBelakang(int val) {  
        Node *newNode = new Node();
        newNode->value = val;

        if (numOfItems != 0) { 
            head->prev = newNode;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            tail = newNode;
        } else {
            newNode->next = newNode;
            newNode->prev = newNode;
            tail = newNode;
            head = newNode;
        }

        numOfItems++;
    };

    void delFront() {
        Node *currentPtr = head;
        currentPtr->prev->next = currentPtr->next;
        currentPtr->next->prev = currentPtr->prev;
        head = currentPtr->next;
        delete currentPtr;
        numOfItems--;
    }

    void delIndex(int index) {
        Node *currentPtr = head;
        
        if (index > numOfItems - 1 or index < 0) {
            return;
        }
        else if (index == 0){
            delFront();
        }
        else if(index == numOfItems-1) {
            delBelakang();
        }
        else {
            for (int i = 0; i < index; i++) {
                currentPtr = currentPtr->next;
            }
            currentPtr->prev->next = currentPtr->next;
            currentPtr->next->prev = currentPtr->prev;
            delete currentPtr;
            numOfItems--;
        }
    }

    void delBelakang() {
        Node *currentPtr = tail;
        currentPtr->prev->next = currentPtr->next;
        currentPtr->next->prev = currentPtr->prev;
        tail = currentPtr->prev;
        delete currentPtr;
        numOfItems--;
    }

    void print() {
        Node *ptr;
        ptr = head;
        for (int i=0;i<numOfItems;i++) { 
            cout << ptr->value << endl;
            ptr = ptr->next; 
        }
    };

    void Move(int indexA, int indexB) {
        Node *A = head;
        for (int i = 0; i < indexA; i++) {
            A = A->next;
        }
        
        Node *B = head;
        for (int i = 0; i < indexB; i++) {
            B = B->next;
        }

        

        Node *temp = nullptr;
        
        if(A->next == B) {
            A->prev->next = B;
            B->next->prev = A;
            
            temp = B->next;
            A->next = temp;
            B->next = A;
            
            temp = A->prev;
            B->prev = temp;
            A->prev = B;
        }
        else {
            A->prev->next = B;
            A->next->prev = B;
            B->prev->next = A;
            B->next->prev = A;
            
            temp = A->next;
            A->next = B->next;
            B->next = temp;
            
            temp = A->prev;
            A->prev = B->prev;
            B->prev = temp;
        }
        
        

        if (A == head){
            head = B;
        }
        else if (B == head){
            head = A;
        }
        else if (A == tail){
            tail = B;
        }
        else if (B == tail){
            tail = A;
        }
        
    };
};

int main() {
    CDLList ll;

    cout << "Add Front" << endl;
    ll.addFront(6);
    ll.addFront(5);
    ll.print();
    
    cout << "Add Belakang" << endl;
    ll.addBelakang(8);
    ll.addBelakang(9);
    ll.print();
    
    cout << "Add Index" << endl;
    ll.addIndex(7,-10);
    ll.print();
    
    cout << "Move" << endl;
    ll.Move(0,-10);
    ll.print();
    
    cout << "Delete Front" << endl;
    ll.delFront();
    ll.print();
    
    cout << "Delete Index" << endl;
    ll.delIndex(-10);
    ll.print();
    
    cout << "Delete Belakang" << endl;
    ll.delBelakang();
    ll.print();
    ll.delBelakang();
    ll.delBelakang();
    ll.print();


    cout << "Number of items on the list: " << ll.numOfItems << endl;
}