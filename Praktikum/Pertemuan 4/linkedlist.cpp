#include <iostream>
using namespace std;

class Node{
    public :
    int data;
    Node* next;
};

class SingleLinkedList {
    private:
    Node* head;

    public:
        SingleLinkedList(){
            head = nullptr;
        };

        void insertDepan(int data) {
            Node* newNode = new Node();
            newNode->data = data;

            if(head == nullptr) {
                head = newNode;
                head->next = nullptr;
            }
            else{
                Node* temp = head;
                head = newNode;
                head->next = temp;
            }
        }

        void insertBelakang(int data){
            Node* newNode = new Node();
            newNode->data = data;

            if(head == nullptr) {
                head = newNode;
                head->next = nullptr;
            }
            else {
                Node* temp = head;
                while(temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->next = nullptr;
            }
        }

        void print() {
            Node* temp = head;
            while(temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
};

int main() {
    return 0;
}