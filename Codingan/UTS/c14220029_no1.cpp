#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }
    Node* getHead()
    {
        return head;
    }
    bool isEmpty() {
        if (head == nullptr) {
            return true;
        }
        return false;
    }

    void insert(int data) {
        Node* temp = new Node;
        temp->data = data;        
        temp->next = nullptr;
        if (isEmpty()) {
            head = temp;
            head->next = nullptr;            
        }
        else {
            Node* temp2 = new Node;
            temp2 = head;
            while (temp2->next != nullptr) {
                temp2 = temp2->next;
            }
            temp2->next = temp;
        }
    }

    void print() {
        Node* temp = head;
        if (!isEmpty()) {
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }    
};

void OutputKurang(Node* head){
    int hasil = 0;
    bool pertama = true;
    while (head != nullptr) {
        if (pertama) {
            hasil = head->data;
            pertama = false;
        } else {
            hasil -= head->data;
        }
        head = head->next;
    }
    cout << "Output Kurang : " << hasil << endl;
}

void OutputJumlah(Node* head)
{
    int hasil = 0;
    while (head != nullptr) {
        hasil += head->data;
        head = head->next;
    }
    cout << "Output Jumlah : " << hasil << endl;
}

int main()
{
    LinkedList SLL;
    SLL.insert(1);
    SLL.insert(3);
    SLL.insert(4);
    SLL.insert(7);
    
    OutputJumlah(SLL.getHead());
    OutputKurang(SLL.getHead());
    
    LinkedList SLL2;
    SLL2.insert(1);
    SLL2.insert(4);
    SLL2.insert(5);
    SLL2.insert(8);
    
    OutputJumlah(SLL2.getHead());
    OutputKurang(SLL2.getHead());
    
    return 0;
}
