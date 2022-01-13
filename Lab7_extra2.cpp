//조규현 20191669 Lab7

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct info {
    string name;
    int weight;
    int height;
};

class Node {
    struct info data;
    Node *next;
    Node *prev;
    Node(info data){
        this->data = data; next = 0; prev = 0;
    }
    friend class List;
};

class List {
private :
    Node *head;
public:
    List() { head = 0; }
    ~List();
    void insertList(info);
    void deleteList(info);
    void forwardList();
    void backwardList();
    void searchList(info a);
    void Locate(int Nth);
    int isEmpty();
    void insertAfter(int Nth,info);
};

int List::isEmpty() {
    return (head == 0);
}

List::~List() {
    Node *p;

    while (head != 0) {
        p = head;
        head = head->next;
        delete p;
    }
}

void List::insertList(info a) {
    Node *temp = new Node(a);

    Node *p, *q;
    if (head == 0) {
        head = temp;
    }
    else if (temp->data.name < head->data.name) {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else {
        p = head;
        q = head;
        while (p != 0 && (p->data.name < temp->data.name)) {
            q = p;
            p = p->next;
        }
        if (p != 0) {
            temp->next = p;
            temp->prev = q;
            q->next = temp;
            p->prev = temp;
        }
        else {
            q->next = temp;
            temp->prev = q;
        }
    }
}

void List::deleteList(info a) {
    Node *p, *q;

    if (isEmpty()) {
        cout << "List is empty" << endl;
    }

    if(!isEmpty()) {
        if (head->data.name == a.name) {
            if (head->next != 0) {
                p = head;
                head = head->next;
                head->prev = 0;
                delete p;
            }
            else
                head = 0;
        }
        else {
            q = head;
            p = head;
            while (p != 0 && p->data.name != a.name) {
                q = p;
                p = p->next;
            }
            if (p->next != 0 && p->data.name == a.name) {
                q->next = p->next;
                p->next->prev = q;
                delete p;
            }
            else if (p->next == 0 && p->data.name == a.name) {
                q->next = 0;
                delete p;
            }
            else
                cout << "Not Found" << endl;
        }
    }
}

void List::forwardList() {
    if (!isEmpty()) {
        Node *p = head;
        cout << "name weight height" << endl;
        while (p != 0) {
            cout << p->data.name << " " << p->data.weight << " " << p->data.height <<" ";
            cout << endl;
            p = p->next;
        }
    }
    else
        cout << "List is empty" << endl;
}

void List::backwardList() {
    if (!isEmpty()) {
        Node *p = head;
        while (p->next != 0) {
            p = p->next;
        }

        cout << "name weight height" << endl;
        while (p != 0) {
            cout << p->data.name << " " << p->data.weight << " " << p->data.height << " ";
            cout << endl;
            p = p->prev;
        }
    }
    else
        cout << "List is empty" << endl;
}

void List::searchList(info a) {
    if (!isEmpty()) {
        Node *p = head;
        while (p != 0 && p->data.name != a.name) {
            p = p->next;
        }
        if (p != 0) {
            cout << "Found" << endl;
        }
        else
            cout << "Not Found" << endl;
    }
    else
        cout << "List is empty" << endl;
}

void List::Locate(int Nth) {
    Node *p, *q;
    if (isEmpty())
        cout << " Not Found" << endl;
    else {
        p = head;
        for (int i = 1; i < Nth; i++) {
            p = p->next;
        }
        cout << p->data.name << " " << p->data.weight << " " << p->data.height << endl;
    }
}

void List::insertAfter(int Nth, info a)
{
    Node *p = new Node(a);
    Node *q = head;
    p->data = a;

    if (head == NULL) {
        head = p;
        p->next = p;
        p->prev = p;
    }
    else {
        for (int i = 1; i < Nth; i++)
            q = q->next;

        p->prev = q;
        p->next = q->next;
        q->next->prev = p;
        q->next = p;
    }
}

int main() {
    List List;
    info b;

    int Nth;
    char buffer[80];

    ifstream infile;
    infile.open("Lab7-3.txt", ios::in);
    if (infile.fail()) {
        cout << "No data file" << endl;
        exit(1);
    }
    while (infile.getline(buffer,80)) {
        infile >> b.name >> b.weight >> b.height;
        List.insertList(b);
    }
    infile.close();
    while (true) {
        int t;
        cout << "1.Insert-after(Nth) 2.Delete, 3.Forward 4.Backward 5.Search 6.Find-Nth" << endl;
        cin >> t;
        switch (t) {
            case 1: {
                cout << "Nth: ";
                cin >> Nth;
                cout << "data: ";
                cin >> b.name;
                cin >> b.weight;
                cin >> b.height;
                List.insertAfter(Nth, b);
                List.forwardList();
                break;
            }case 2: {
                cout << "Delete: ";
                cin >> b.name;
                List.deleteList(b);
                List.forwardList();
                break;
            }case 3: {
                List.forwardList();
                break;
            }case 4: {
                List.backwardList();
                break;
            }case 5: {
                cout << "Search: ";
                cin >> b.name;
                List.searchList(b);
                break;
            }
            case 6: {
                cout << "Find Nth: ";
                cin >> Nth;
                List.Locate(Nth);
                break;
            }
        }
    }
}
