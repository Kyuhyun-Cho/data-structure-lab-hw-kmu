//조규현 20191669 Lab5

#include <iostream>

using namespace std;

const int StackSize = 2;
const int QueueSize = 3;

class Stack {
private:
    int top = -1;
    char stack[StackSize];
public:
    void push(char item);
    void pop();
    bool StackFull();
    bool StackEmpty();
    void DisplayStack();
};

class Queue {
private:
    int front = -1;
    int rear= -1;
    char queue[QueueSize];
public:
    void ENQUE(char item);
    void DEQUE();
    bool QueueFull();
    bool QueueEmpty();
    void DisplayQ();
};

class CQueue{
private:
    int front = 1;
    int rear = 1;
    int flag = -1;
    char Cqueue[QueueSize];
public:
    void CEnque(char item);
    void CDeque();
    void displayCQ();
};

void Stack::push(char item) {
    if (StackFull()) {
        cout << "StackFull";
    } else {
        stack[++top] = item;
    }
}

void Stack::pop() {
    if (StackEmpty()) {
        cout << "StackEmpty";
    }
    else {
        cout << stack[top--] << " ";
    }
}

bool Stack::StackFull() {
    if (top == StackSize - 1) {
        return true;
    }
    else {
        return false;
    }
}

bool Stack::StackEmpty() {
    if (top == -1) {
        return true;
    } else {
        return false;
    }
}

void Stack::DisplayStack() {
    int i;
    if (StackEmpty()) {
        cout << "StackEmpty";
    }
    else {
        i = top;
        cout << "Stack: ";
        while (i >= 0) {
            cout << stack[i] << " ";
            i--;
        }
    }
}

void Queue::ENQUE(char item) {
    if (QueueFull()) {
        cout << "QueueFull";
    }
    else {
        queue[++rear] = item;
    }
}

void Queue::DEQUE() {
    if (QueueEmpty()) {
        cout << "QueueEmpty";
    }
    else {
        cout << queue[++front] << " ";
    }
}

bool Queue::QueueFull() {
    if (rear == QueueSize - 1) {
        return true;
    } else {
        return false;
    }
}

bool Queue::QueueEmpty() {
    if (rear == front) {
        return true;
    }
    else {
        return false;
    }
}

void Queue::DisplayQ() {
    int i;
    if (QueueEmpty()) {
        cout << "QueueEmpty";
    }
    else {
        i = front + 1;
        cout << "Queue: ";
        while (i <= rear) {
            cout << queue[i] << " ";
            i = i + 1;
        }
    }
}

void CQueue::CEnque(char item) {
    if (front == rear && flag == 1) {
        cout << "QueueFull";
    }
    else {
        Cqueue[rear] = item;
        rear = (rear + 1) % QueueSize;
        flag = 1;
    }
}

void CQueue::CDeque() {
    if (front == rear && flag == 0) {
        cout << "QueueEmpty";
    }
    else {
        front = (front + 1) % QueueSize;
        flag = 0;
    }
}

void CQueue::displayCQ() {
    int count = 0;
    for(int index = front; count < QueueSize; index = (index + 1) % QueueSize) {
        cout << Cqueue[index] << " ";
        count++;
    }
}

int main() {
    Stack s;
    Queue q;
    CQueue cq;

    // 1
    s.push('a');
    q.ENQUE('b');
    q.ENQUE('c');
    q.ENQUE('d');
    s.push('e');

    // 2
    s.push('F');
    cout << ", ";
    q.ENQUE('G');
    cout << endl;

    // 3
    s.DisplayStack();
    cout << " ";

    // 4
    q.DisplayQ();
    cout << endl;

    // 5
    cout << "Output: ";
    s.pop();
    q.DEQUE();
    q.DEQUE();
    q.DEQUE();
    s.pop();
    cout << endl;

    // 6
    s.pop();
    cout << ", ";
    q.DEQUE();
    cout << endl;

    // 7
    cq.CEnque('A');
    cq.CEnque('B');
    cq.CEnque('C');
    cq.CDeque();
    cq.CEnque('D');

    // 8
    cq.displayCQ();
    cout << endl;

    // 9
    cq.CDeque();
    cq.CDeque();
    cq.CDeque();
    cq.CDeque();
}




