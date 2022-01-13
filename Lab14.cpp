//조규현 20191669 Lab14
#include<iostream>
#include<string>

using namespace std;

const int SIZE = 7;
const int divi = 7;

class Node {
    int data;
    Node *next;
    friend class Hash;
};
class Hash {
private:
    Node *head[SIZE];
    int value;
    int key;
public:
    Hash() {
        for (int i = 0; i<SIZE; i++)
            head[i] = 0;

        value = 0; key = 0;
    }
    void insert_(int value) {
        Node *temp = new Node();
        Node *p;
        temp->data = value;
        key = value % divi;
        if (head[key] == 0) {
            head[key] = temp;
        }
        else {
            p = head[key];
            while (p->next != 0) {
                p = p->next;
            }
            p->next = temp;
        }
    }

    void delete_(int value) {
        key = value % divi;
        Node *p, *q;
        p = NULL;
        q = NULL;
        if (head[key]->data == value) {
            p = head[key];
            head[key] = head[key]->next;
            delete p;
        }
        else {
            p = head[key];
            while (p != 0 && p->data != value) {
                q = p;
                p = p->next;
            }
            if (p != 0) {
                q->next = p->next;
                delete p;
            }
            else
                cout << value << " is Not Found" << endl;
        }
    }

    void search_(int value) {
        key = value % divi;
        Node *p;
        if (head[key] != 0) {
            p = head[key];
            while (p->next != 0 && p->data != value)
                p = p->next;
            if (p->data == value)
                cout << p->data << " is Found" << endl;
            else if (p->next == 0)
                cout << value << " is Not Found" << endl;
        }
        else
            cout << value <<" is Not Found" << endl;
    }

    void printtable() {
        Node *p;
        for (int i = 0; i<SIZE; i++) {
            cout << "Htable[" << i << "]: ";
            if (head[i] != 0) {
                p = head[i];
                while (p != 0) {
                    cout << p->data << " ";
                    p = p->next;
                }
            }
            else
                cout << "";
            cout << endl;
        }
    }
};

int main() {
    Hash h;
    int num = 0;
    int input;
    while (true) {
        cout << "1.Find 2.Insert 3.Delete 4.Quit: ";
        cin >> input;
        if(input == 1) {
            cout << "Find data: ";
            cin >> num;
            h.search_(num);
        }
        else if(input == 2) {
            cout << "Insert data: ";
            cin >> num;
            h.insert_(num);
            h.printtable();
        }
        else if (input == 3) {
            cout << "Delete data: ";
            cin >> num;
            h.delete_(num);
            h.printtable();
        }
        else if (input == 4) {
            break;
        }
        else
            cout << "Wrong Number" << endl;
    }
}
