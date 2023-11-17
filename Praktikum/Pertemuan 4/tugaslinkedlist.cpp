#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class SLI
{
private:
    Node *head;

public:
    SLI()
    {
        head = nullptr;
    }
    void insertDepan(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        if (head == nullptr)
        {
            head = newNode;
            head->next = nullptr;
        }

        else
        {
            Node *temp = head;
            head = newNode;
            head->next = temp;
        }
    }
    void insertBelakang(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;

        if (head == nullptr)
        {
            head = newNode;
            head->next = nullptr;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = nullptr;
        }
    }
    void hapusDepan()
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    void hapusBelakang()
    {
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
    }
    void insertTengah(int indeks, int data)
    {
        Node *newNode = new Node();
        Node *temp = head;
        Node *temp2, *temp3;

        int count = 0;

        while (count != indeks)
        {
            temp2 = temp;
            temp3 = temp->next;
            count = count + 1;
            temp = temp->next;
        }
        temp2->next = newNode;
        newNode->data = data;
        newNode->next = temp3;
    }
    void hapusTengah(int indeks)
    {
        Node *temp = head;
        Node *temp2;
        int count = 0;

        while (count != indeks)
        {
            temp2 = temp;
            count = count + 1;
            temp = temp->next;
        }
        temp2->next = temp2->next->next;
    }
    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

     void sorting() {
            for(int i = 0; i < 12; i++) {
                Node *pointer1 = head;
                Node *pointer2 = pointer1->next;
                Node *temp = nullptr;
                for (int j = 0; j < 12; j++) {
                    // memindah angka kelipatan 3 ke depan
                    if((pointer1->data % 3 != 0 and pointer2->data % 3 == 0) or (((pointer1->data % 3 == 0 and pointer2->data % 3 == 0) or (pointer1->data % 3 != 0 and pointer2->data % 3 != 0)) and pointer2->data < pointer1->data)) {
                        if(pointer1 == head) {
                            head = pointer2;
                        }
                        else {
                            temp->next = pointer2;
                        }
                        
                        pointer1->next = pointer2->next;
                        pointer2->next = pointer1;
                        temp = pointer2;
                        
                        pointer2 = pointer1->next;
                    }
                    
                    else {
                        temp = pointer1;
                        pointer1 = pointer1->next;
                        pointer2 = pointer1->next;
                    }
                }
            }
     }
};

int main()
{
    int arr[] = {10,19,18,88,17,66,12,1,14,6,90,98,99};
    
    // memasukkan data ke dalam linked list
    SLI sli;
    for (int i = 0; i < 13; i++) {
        sli.insertBelakang(arr[i]);
    }
    
    sli.sorting();
    sli.print();

    return 0;
}