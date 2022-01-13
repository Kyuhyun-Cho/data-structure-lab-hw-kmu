#include<iostream>

using namespace std;

class Node {
    char data;
    Node *next;
    Node(char value) { data = value; next = 0; }
    friend class linkedStack;
};

class QNode {
private:
    char data;
    QNode *next;
    QNode(char value) {data = value; next = 0; }
    friend class linkedQueue;
};

class NodeOfList {
private:
    char data;
    NodeOfList *next;
    friend class con;
};

class linkedStack {
private:
    Node *head;
public:
    linkedStack () {head = 0;}
    ~linkedStack() {};
    void push(char);
    char pop();
    int isEmpty();
    void printStack();
    char getSList(int);
};

class linkedQueue {
private:
    QNode *front;
    QNode *rear;
public:
    linkedQueue () {front = 0; rear = 0;}
    ~linkedQueue() {};
    void enQueue(char);
    char deQueue();
    int isEmpty();
    void printQueue();
    char getQList(int);
};

class con {
private:
    NodeOfList *head;
public:
    con() {head = NULL;}
    void insertNode(char);
    void printList();
    void merge(class linkedStack, class linkedQueue);
    void invert();
    bool isEmpty();
};

void linkedStack::push(char data) {
    Node *temp = new Node(data);
    if (head == 0) head = temp;
    else {
        temp->next = head;
        head = temp;
    }
}

char linkedStack::pop() {
    if(isEmpty()) {
        cout << "Stack is Empty";
        return 0;
    }
    Node *p= NULL;
    char num;
    num = head->data;
    p = head;
    head = head->next;
    delete p;
    return num;
}

int linkedStack::isEmpty() {
    if (head == 0) return 1;
    else return 0;
}

void linkedStack::printStack() {
    Node *p, *q, *r;
    p= NULL;
    if (!isEmpty()) {
        p = head;
        while (p) {
            cout << p->data << " ";
            p = p->next; }
        cout << endl; }
    else
        cout << "Stack is Empty" << endl;
}

char linkedStack::getSList(int num) {
    Node *p;
    if(!isEmpty()) {
        p = head;
        if(num == 0) return p->data;
        for(int i =0; i < num; i++) {
            p = p->next;
            if(p == NULL) {
                cout << "Not Found" << endl;
                return false;
            }
        }
        return p->data;
    }
    else cout << "Stack is Empty" << endl;
}


int linkedQueue::isEmpty() {
    if (front == 0) return 1;
    else return 0;
}

void linkedQueue::enQueue(char data) {
    QNode *temp = new QNode(data);
    if (front == 0){
        front = temp;
        rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

char linkedQueue::deQueue() {
    if(isEmpty()) {
        cout << "Queue is Empty" ;
        return 0;
    }
    QNode *p;
    char num;
    num = front->data;
    p = front;
    if (front == rear) { front = 0; rear = 0; }
    else front = front->next;
    delete p;
    return num;
}

void linkedQueue::printQueue() {
    QNode *p;
    if (!isEmpty()) {
        p = front;
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    else
        cout << "Queue is Empty" << endl;
}

char linkedQueue::getQList(int num){
    QNode *p;
    if(!isEmpty()) {
        p = front;
        if(num == 0) return p->data;
        for(int i = 0; i < num; i++) {
            p = p->next;
            if(p == NULL) {
                cout << "Not Found!" << endl;
                return false;
            }
        }
        return p->data;
    }
    else cout << "Queue is Empty" << endl;
}

bool con::isEmpty() {
    if(head == NULL) return true;
    else return false;
}

void con::insertNode(char data) {
    NodeOfList *temp = new NodeOfList();
    temp->data = data;
    NodeOfList *p = NULL, *q = NULL;

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

void con::printList() {

    NodeOfList *p = NULL;

    if(!isEmpty()) {
        p = head;
        while(p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    else cout << "List is Empty" << endl;
}

void con::merge(linkedStack ls, linkedQueue lq) {
    for(int i = 0; i < 2; i++){
        insertNode(ls.getSList(i));
    }
    for(int i = 0; i < 3; i++){
        insertNode(lq.getQList(i));
    }
}

void con::invert(){
    NodeOfList *p, *q, *r;
    p = head;
    q = NULL;

    while (p) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
    printList();
    p = head;
    q = NULL;

    while (p) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}


int main() {
    linkedStack ls;
    linkedQueue lq;
    con l3 ;

    int t;
    while (true) {
        cout << "1.PUSH 2.POP 3.PRINTST 4.ENQUEUE 5.DEQUEUE 6.RPINTQU 7.MERGE 8.INVERT 9.PRINTLIST 10.QUIT: " ;
        cin >> t;
        switch (t) {
            case 1: {
                char data;
                cout << "Enter a data to push: ";
                cin >> data;
                ls.push(data);
                break;
            }
            case 2: {
                char a;
                a = ls.pop();
                cout << a << " is popped" << endl;
                break;
            }case 3: {
                cout << "Stack: ";
                ls.printStack();
                break;
            }
            case 4: {
                char data;
                cout << "Enter a data to enque: ";
                cin >> data;
                lq.enQueue(data);
                break;
            }
            case 5: {
                char b;
                b = lq.deQueue();
                cout << b << " is dequed" << endl;
                break;
            }
            case 6: {
                cout << "Queue: ";
                lq.printQueue();
                break;
            }
            case 7: {
                cout << "List: ";
                l3.merge(ls, lq);
                l3.printList();
                break;
            }
            case 8: {
                cout << "List: ";
                l3.invert();
                break;
            }
            case 9: {
                cout << "List: ";
                l3.printList();
                break;
            }
            case 10: {
                return 0;
            }
        }
    }
}

