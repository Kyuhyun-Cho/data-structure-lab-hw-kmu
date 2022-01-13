//조규현 20191669 Lab6

#include<iostream>

using namespace std;

class Node {
private:
    int data;
    Node *next;
    friend class List;
};

class List{
private:
    Node *head;
public:
    List() {head = NULL;}
    void insertNode(int);
    void deleteNode(int);
    void searchList(int);
    bool isEmpty();
    void traverseList();
    void printLast();
    void printNth(int);
};

int main() {
    List sll;
    int n, c;
    while(true){
        cout << "1.insert, 2.delete, 3.search, 4.print, 5.PrintLast, 6.PrintNth, 7.Quit => " ;
        cin >> c;

        switch(c){
            case 1:
                cout << "Input a number: ";
                cin >> n;
                sll.insertNode(n);
                break;
            case 2:
                cout << "Input a number: ";
                cin >> n;
                sll.deleteNode(n);
                break;
            case 3:
                cout << "Enter a number: ";
                cin >> n;
                sll.searchList(n);
                break;
            case 4:
                sll.traverseList();
                break;
            case 5:
                sll.printLast();
                break;
            case 6:
                cout << "Enter Nth: ";
                cin >> n;
                sll.printNth(n);
                break;
            case 7:
                return 0;
        }
    }
}

bool List::isEmpty() {
    if(head == NULL) return true;
    else return false;
}

void List::insertNode(int data){
    Node *temp = new Node();
    temp->data = data;
    Node *p = NULL, *q = NULL;

    if(head == NULL) head = temp;
    else if(temp->data < head->data) {
        temp->next = head;
        head = temp;
    }
    else{
        p = head;
        while((p != NULL) && (p->data < temp->data)) {
            q = p;
            p = p->next;
        }
        if(p != NULL) {
            temp->next = p;
            q->next = temp;
        }
        else {
            q->next = temp;
        }
    }
}

void List::deleteNode(int num){
    if(isEmpty()){
        cout << "List is Empty" <<endl;
        return;
    }
    Node *p = NULL, *q = NULL;
    if(head->data == num) {
        p = head;
        head = head->next;
        delete p;
    }
    else {
        p = head;
        while(p != NULL && p->data != num) {
            q = p;
            p = p->next;
        }
        if(p != NULL) {
            q->next = p->next;
            delete p;
        }
        else cout << num << "not Found" << endl;
    }
}

void List::searchList(int num) {
    Node *p = NULL;

    if(head != NULL) {
        p = head;
        while(p != NULL && p->data != num)
            p = p->next;
        if(p->data == num) cout << p->data << " is found" << endl;
        else cout << num << "not found" << endl;
    }
    else cout << "List is empty" << endl;
}

void List::traverseList() {
    Node *p = NULL;

    if(!isEmpty()) {
        p = head;
        while(p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    else cout << "List empty" << endl;
}

void List::printLast() {

    Node *p = NULL;

    if(head != NULL) {
        p = head;
        while(p != NULL ){
            p = p->next;
            if(p->next == NULL) {
                cout << "Last node: " << p->data <<endl;
                return;
            }
        }
    }
    else cout << "List is empty" << endl;
}

void List::printNth(int num) {
    Node *p, *q;
    int count = 0;
    if (!isEmpty()) {
        p = head;
        q = head;
        int i;
        while (p) {
            p = p->next;
            count++;
        }
        for (i = 1; i < count+1 ; i++) {

            if (num != i) {
                q = q->next;
            }
            else if (num == i) {
                cout << num << "번째 노드 "<< q->data << endl;
            }
        }
        if (num > count)
            cout << "not found" << endl;
    }
    else {
        cout << "List is Empty" << endl;
    }
}


