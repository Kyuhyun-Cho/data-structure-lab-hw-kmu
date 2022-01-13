//조규현 20191669 Lab6-2

#include<iostream>

using namespace std;

class Node {
private:
    char data;
    Node *next;
    Node(char value) { data = value; next = 0; }
    friend class linkedStack;
};

class qnode {
private:
    char data;
    qnode *next;
    qnode(char value) {data = value; next = 0; }
    friend class linkedQueue;
};

class NodeOflist3 {
private:
    char data;
    NodeOflist3 *next;
    friend class con;
};

class linkedStack {
private:
    Node *head;
public:
    linkedStack () {head = 0;}
    ~linkedStack() {};
    void createStack();
    void push(char);
    char pop();
    int isEmpty();
    void displayStack();
    void searchStack(char);
    char getlist1(int);
};

class linkedQueue {
private:
    qnode *front;
    qnode *rear;
public:
    linkedQueue () {front = 0; rear = 0;}
    ~linkedQueue() {};
    void createQueue();
    void enqueue(char);
    char dequeue();
    int isEmpty();
    void displayQueue();
    void searchQueue(char);
    char getlist2(int);
};

class con {
private:
    NodeOflist3 *head;
public:
    con() {head = NULL;}
    void insertNode(char);
    void displaylist3();
    void Concatenate(class linkedStack, class linkedQueue);
    void invert();
    bool isEmpty();
};

int main() {
    linkedStack ls;
    linkedQueue lq;
    con l3;


    ls.push('a');
    ls.push('e');
    ls.displayStack();
    lq.enqueue('b');
    lq.enqueue('c');
    lq.enqueue('d');
    lq.displayQueue();

    l3.Concatenate(ls, lq);
    l3.displaylist3();
    l3.invert();
}


void linkedStack::createStack() { head = 0; }

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
        cout << "Stack is empty";
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

void linkedStack::displayStack() {
    Node *p, *q, *r;
/*   p = head;
   q = NULL;

   while (p) {
      r = q;
      q = p;
      p = p->next;
      q->next = r;
   }
   head = q;
*/
    p= NULL;
    if (!isEmpty()) {
        p = head;
        while (p) {
            cout << p->data << " ";
            p = p->next; }
        cout << endl; }
    else
        cout << "Stack Empty!" << endl;
/*
   p = head;
   q = NULL;

   while (p) {
      r = q;
      q = p;
      p = p->next;
      q->next = r;
   }
   head = q;
   */
}

char linkedStack::getlist1(int num) {
    Node *p;
    if(!isEmpty()) {
        p = head;
        if(num == 0) return p->data;
        for(int i =0; i < num; i++) {
            p = p->next;
            if(p == NULL) {             //num이 스택안의 데이터의 개수보다 많을 경우
                cout << "없어요!" << endl;
                return false;
            }
        }
        return p->data;
    }
    else cout << "Stack Empty!" << endl;
}

bool con::isEmpty() {
    if(head == NULL) return true;
    else return false;
}

void con::insertNode(char data) {
    NodeOflist3 *temp = new NodeOflist3();
    temp->data = data;
    NodeOflist3 *p = NULL, *q = NULL;

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

void con::displaylist3() {

    NodeOflist3 *p = NULL;

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

void con::Concatenate(linkedStack ls, linkedQueue lq) {
    for(int i = 0; i < 2; i++){
        insertNode(ls.getlist1(i));
    }
    for(int i = 0; i < 3; i++){
        insertNode(lq.getlist2(i));
    }
}
void con::invert(){
    NodeOflist3 *p, *q, *r;
    p = head;
    q = NULL;

    while (p) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
    displaylist3();
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

int linkedQueue::isEmpty() {
    if (front == 0) return 1;
    else return 0;
}

void linkedQueue::createQueue() {
    front = 0;
    rear = 0;
}

void linkedQueue::enqueue(char data) {
    qnode *temp = new qnode(data);
    if (front == 0){
        front = temp;
        rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

char linkedQueue::dequeue() {
    if(isEmpty()) {
        cout << "Queue Empty" ;
        return 0;
    }
    qnode *p;
    char num;
    num = front->data;
    p = front;
    if (front == rear) { front = 0; rear = 0; }
    else front = front->next;
    delete p;
    return num;
}

void linkedQueue::displayQueue() {
    qnode *p;
    if (!isEmpty()) {
        p = front;
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    else
        cout << "Queue is empty!" << endl;
}

char linkedQueue::getlist2(int num){
    qnode *p;
    if(!isEmpty()) {
        p = front;
        if(num == 0) return p->data;
        for(int i = 0; i < num; i++) {
            p = p->next;
            if(p == NULL) {             //num이 큐안의 데이터의 개수보다 많을 경우
                cout << "없어요!" << endl;
                return false;
            }
        }
        return p->data;
    }
    else cout << "Queue is empty!" << endl;
}
