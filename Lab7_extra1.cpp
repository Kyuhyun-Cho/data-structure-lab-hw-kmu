//조규현 20191669 Lab7

#include<iostream>

using namespace std;

class Node {
    char data;
    Node *next;
    Node(char value) { data = value; next = NULL; }
    friend class linkedStack;
    friend class linkedQueue;
    friend class List;
    Node() { this->next = nullptr; }
    Node(const Node *n) {
        Node *p = this;
        while (n) {
            p->data = n->data;

            if (n->next) {
                Node *temp = new Node();
                temp->next = nullptr
                        ;
                p->next = temp;
                p = p->next;
            }
            n = n->next;
        }
    }
};

class List {
private :
    Node* head;
public :
    List() { head = NULL; }
    void InsertNode(int num);
};

void List::InsertNode(int num) {
    Node *temp = new Node();
    temp->data = num;
    temp->next = nullptr;
    Node *p, *q;

    if (head == NULL) {
        temp->data = num;
        head = temp;
    }
    else if (temp->data < head->data) {
        temp->next = head;
        head = temp;
    }
    else {
        p = head;
        while (p != NULL && temp->data > p->data) {
            q = p;
            p = p->next;
        }
        if (p != NULL) {
            temp->next = p;
            q->next = temp;
        }
        else {
            q->next = temp;
        }
    }

}

class linkedStack {
private:
    Node *head;
public:
    linkedStack() { head = NULL; }
    ~linkedStack();
    void push(char);
    char pop();
    int isEmpty();
    void displayStack();
    int getLength();
};

void linkedStack::push(char data) {
    Node *temp = new Node(data);
    temp->data = data;
    if (head == NULL)
        head = temp;
    else {
        temp->next = head;
        head = temp;
    }
}

char linkedStack::pop() {
    Node *p;
    char num;
    if (isEmpty())
    {
        cout << "Stack is Empty" << endl;
        return 0;
    }
    else {
        num = head->data;
        p = head;
        head = head->next;
        delete p;
        return num;
    }
}

int linkedStack::isEmpty() {
    if (head == NULL) return 1;
    else return 0;
}

void linkedStack::displayStack() {
    Node *p;

    if (!isEmpty()) {
        p = head;
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    else
        cout << "Stack is Empty" << endl;
}

int linkedStack::getLength() {
    Node *p;
    p = head;
    int count = 0;
    while (p) {
        p = p->next;
        count++;
    }
    return count;
}

linkedStack::~linkedStack() {
    Node* p;
    while (head)
    {
        p = head;
        head = head->next;
        delete p;
    }
}

class linkedQueue {
private:
    Node *front;
    Node *rear;
    friend class linkedStack;
public:
    linkedQueue() { front = 0; rear = 0; }
    ~linkedQueue();
    void enQueue(char);
    char deQueue();
    int isEmpty();
    void displayQueue();
    int getLength();
};

int linkedQueue::isEmpty() {
    if (front == 0)	return 1;
    else return 0;
}

void linkedQueue::enQueue(char data) {

    Node *temp = new Node(data);

    if (front == 0) {
        front = temp;
        rear = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }
}

char linkedQueue::deQueue() {
    Node *p;
    if (isEmpty()) {
        cout << "Queue is Empty" << endl;
        return 0;
    }
    char num;
    num = front->data;
    p = front;
    if (front == rear) {
        front = 0; rear = 0;
    }
    else {
        front = front->next;
    }
    delete p;
    return num;
}

void linkedQueue::displayQueue() {
    Node *p;
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

int linkedQueue::getLength() {
    Node *p;
    p = front;
    int count = 0;
    while (p) {
        p = p->next;
        count++;
    }
    return count;
}

linkedQueue::~linkedQueue() {
    Node *p = front;
    while (p) {
        p = front;
        front = front->next;
        delete p;
    }
}

int main() {
    linkedStack *s = new linkedStack();
    linkedQueue *q = new linkedQueue();

    int t;
    while (true) {
        cout << "1.PUSH 2.POP 3.ENQUE 4.DEQUE 5.DISPLAY 6.LENGTH 7.QUIT " << endl;
        cin >> t;
        switch (t) {
            case 1: {
                char data;
                cout << "Input data: ";
                cin >> data;
                s->push(data);
                break;
            }
            case 2: {
                char a;
                a = s->pop();
                cout << a << endl;
                break;
            }case 3: {
                char data;
                cout << "Input data: ";
                cin >> data;
                q->enQueue(data);
                break;
            }
            case 4: {
                char b;
                b = q->deQueue();
                cout << b << endl;
                break;
            }
            case 5: {
                cout << "Stack: ";
                s->displayStack();
                cout << "Queue: ";
                q->displayQueue();
                break;
            }case 6: {
                int a, b;
                a = s->getLength();
                b = q->getLength();
                cout << "Stack Length: " << a << endl;
                cout << "Queue Length: " << b << endl;
                break;
            }case 7: {
                return 0;
            }
        }
    }
}