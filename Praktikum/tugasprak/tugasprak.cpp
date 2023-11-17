#include <iostream>
using namespace std;

class Node {
    public:
        char karakter;
        int jumlah;
        Node *prev;

        Node()
        {
            karakter = '.';
            jumlah = 0;
            prev = nullptr;
        }

        Node(char c, int i)
        {
            karakter = c;
            jumlah = i;
            prev = nullptr;
        }
};

class Stack {
public:
    Node *top;

    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (!isEmpty())
        {
            Node *node = pop();
            delete node;
        }
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    Node *pop()
    {
        if (isEmpty())
        {
            cout << "Stack Kosong Bro" << endl;
            return nullptr;
        }
        Node *del = top;
        top = del->prev;
        del->prev = nullptr;
        return del;
    }

    void normalPush(Node *node)
    {
        node->prev = top;
        top = node;
    }

    void push(char karakter, int jumlah)
    {
        Node *newNode = new Node(karakter, jumlah);
        if (!isEmpty())
        {
            Stack temp;
            while (top != nullptr && top->karakter < karakter)
            {
                Node *tempNode = pop();
                temp.normalPush(tempNode);
            }
            if (top != nullptr && top->karakter == karakter)
            {
                top->jumlah += jumlah;
            }
            else
            {
                normalPush(newNode);
            }
            while (!temp.isEmpty())
            {
                Node *tempNode = temp.pop();
                normalPush(tempNode);
            }
        }
        else
        {
            top = newNode;
        }
    }

    void print()
    {
        Stack temporary = *this;
        if (!temporary.isEmpty())
        {
            while (temporary.top->prev != nullptr)
            {
                Node *res = temporary.pop();
                cout << "[" << res->karakter << "," << res->jumlah << "], ";
            }
            Node *res = temporary.pop();
            cout << "[" << res->karakter << "," << res->jumlah << "]" << endl;
        }
    }
};

int main()
{
    string kalimat = "Aku besok akan makan nasi goreng lalu karena tidak habis akan kubungkus pulang dan kupanasin dirumah.";
    Stack newStack;
    for (char k : kalimat)
    {
        if (isalpha(k))
        {
            newStack.push(tolower(k), 1);
        }
    }
    newStack.print();
    return 0;
}
