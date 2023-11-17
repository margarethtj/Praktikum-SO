#include <iostream>
#include <string>

using namespace std;

// LINKED LIST
// jadi ini list nya isinya value sama pointer next, yang pointer nextnya juga pointer value di tempat laen, dan seterusnya.
// circular linked list --> jadi ntik kek saling berkaitan satu sama lain sampe muter.
// double linked list --> pny 2 pointer (ada prev dan next)
// kelemahan linked list sederhana (single): hanya bisa satu arah (dri depan ke blakang), tdk bisa kembali

// (PENULISAN BENAR)
class Node { // memiliki dua member yaitu value dan pointer next
    public:
        int value;
        Node *next = NULL; 
        // next mrupakan pointer (berisi alamat dri value di linked list selanjutnya.), 
        // kalo selanjute gada, dee pointer e null.
};

Node *addNode(Node *headptr, int val) {
    Node *newNode = new Node();
    newNode-> value = val;
    newNode-> next = headptr;
    return newNode;
};

int main() {
    Node *head; // tipe data nya hrs sama dgn pointer. head berisi alamate dari linklist yang paling awal. (ntik ndak dipake buat simpan value)

    Node *nodeA = new Node(); // menyimpan alamat dr node
    nodeA -> value = 6; // mengisi value node a

    head = nodeA; // disalin ke head (sama kayak value node A yaitu 6)

    cout << head -> value << endl; // output : 6
    cout << head -> next << endl; // output : 0 (null)

    Node *nodeB = new Node();
    nodeB->value = 7;
    nodeB->next = head; // pointer sbelah kanan dicopy ke sbelah kiri, maka pointer next menunjuk pd alamat sblmnya(alamate sg head)
    head = nodeB; // membuat nodeB menjadi head

    cout << head -> value << endl; // output : 7
    cout << head -> next << endl; // output : alamate node A
    cout << head -> next -> value << endl; // output : 6


    Node *head;

    head = addNode(head, 5); // value : 5, next = null
    head = addNode(head, 6); // value : 6, next = alamate value 5
    head = addNode(head, 7); // value : 7, next = alamate value 6 (dia jadi head)
    
    cout << head -> value << endl; // output : 7
    cout << head -> next -> value << endl; // output : 6
    cout << head -> next -> next -> value << endl; // output : 5
};


// (PENULISAN YG BENAR)
class Node { 
    public:
        int value;
        Node *next = NULL; 
};

class LinkedList {
    public :
        Node *head;
        int numOfItems = 0; // gaharus

    void addNodeBegin(int val) { // (lbh enak) menaruk head diperbarui trus (head adalah yg trakir di input) / menambahkan linked list dibagian depan
    // bisa lgsg diambil soale tinggal ambil head e
        Node *newNode = new Node();
        newNode->value = val;
        newNode->next = head;
        head = newNode;
        numOfItems++;
    }

    void addNodeEnd(int val) { // menaruk head di depan, jdi ne sg baru ditaruk diblakang trus, lebih susah.
    // soale disini dee harus nyari trus sampe di blakang baru bisa dipake lebih lama prosese
        Node *newNode = new Node();
        newNode->value = val;

        Node *ptr;
        ptr = head;

        if(numOfItems > 0) {
            for (int i =0; i < numOfItems-1; i++) {
                ptr = ptr->next; // menunjuk ke next(alamat setelahnya)
            }
            ptr -> next = newNode;
        }
        else{
            head = newNode;
        }

        numOfItems++;
    }

    void printAllItems() {
        Node *ptr;
        ptr = head;

        // loop mendapatkan value semuane (dee lebih gmpg dri while)
        for (int i =0; i < numOfItems; i++) {
            cout << ptr->value << endl;
            ptr = ptr->next; // menunjuk ke next(alamat setelahnya)
        }

        // atau bisa kek gini loop nya.
        while (ptr !=NULL) {
            cout << ptr->value << endl;
            ptr = ptr->next;
        }
    }

    int main() {
        LinkedList ll;

        ll.addNodeBegin(5);
        ll.addNodeBegin(6);
        ll.addNodeBegin(7);
        ll.addNodeBegin(8);

        ll.printAllItems();

        cout << "Number of items on the list : " << ll.numOfItems << endl;
    }
};