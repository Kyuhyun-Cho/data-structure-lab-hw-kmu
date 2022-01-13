//조규현 20191669 Lab4-extra1

#include <iostream>
#include <cstring>
#define MAX_SIZE 100

using namespace std;

class Stack {
private:
    int *sarray;
    int top;
    const int size;
public:
    Stack(int size);
    virtual ~Stack();
    bool isFull() const;
    bool isEmpty() const;
    void push(int value);
    char pop();
    //void print() const;
    int get_top();
    int set_stackTop();
};

typedef enum {lParen, rParen, pplus, mminus, times, divide, mod, eos, operand} precedence;
void postfix(char *infix, int len);
int eval(char *str);
precedence get_token(char *symbol, int *n, char *infix);
Stack a(MAX_SIZE);
char buffer[MAX_SIZE] = {};

using namespace std;

Stack::Stack(int size) :size(size) { // 데이터 초기화
    sarray = new int[size];
    top = -1;
}

Stack::~Stack() {
    delete sarray;
}

bool Stack::isFull() const {
    if (top == size - 1) {
        return true;
    }
    else {
        return false;
    }
}

bool Stack::isEmpty() const {
    if (top == -1) {
        return true;
    }
    else {
        return false;
    }
}

void Stack::push(int value) {
    if (isFull() == true) {
        cout << "Stack is Full" << endl;
    }
    else {
        ++top;
        sarray[top] = value;
    }
}

char Stack::pop() {
    if (isEmpty() == true) {
        cout << "Stack is Empty" << endl;
    }
    else {
        return sarray[top--];
    }
}

int Stack::get_top() {
    return top;
}

int Stack::set_stackTop() {
    return sarray[top];
}

int main() {
    char formula[MAX_SIZE];
    cin >> formula;

    int len;
    len = strlen(formula);

    cout << "Echo data (infix form): ";
    for (int i = 0; i < len; i++) {
        cout << formula[i];
    }
    cout << endl;
    cout << "Conversion (postfix form): ";
    postfix(formula, len);
    int k = 0;
    while (buffer[k] != NULL) {
        cout << buffer[k++];
    }
    cout << endl;
    cout << "Result: " << eval(buffer) << endl;

    return 0;
}

void postfix(char *infix, int len) {
    int j = 0;
    for (int i = 0; i < len; i++) {
        switch (infix[i]) {
            case '(':
                a.push(infix[i]);
                break;
            case '+':
                while (a.get_top() >= 0 && a.set_stackTop() != '(') {
                    buffer[j++] = a.pop();
                }
                a.push(infix[i]);
                break;
            case '-':
                while (a.get_top() >= 0 && a.set_stackTop() != '(') {
                    buffer[j++] = a.pop();
                }
                a.push(infix[i]);
                break;
            case '*':
                while (a.get_top() >= 0 && a.set_stackTop() != '(' && a.set_stackTop() != '-' && a.set_stackTop() != '+') {
                    buffer[j++] = a.pop();
                }
                a.push(infix[i]);
                break;
            case '/':
                while (a.get_top() >= 0 && a.set_stackTop() != '(' && a.set_stackTop() != '-' && a.set_stackTop() != '+') {
                    buffer[j++] = a.pop();
                }
                a.push(infix[i]);
                break;
            case ')':
                while (a.set_stackTop() != '(') {
                    buffer[j++] = a.pop();
                }
                a.pop();
                break;
            default:
                buffer[j++] = infix[i];
        }
    }
    while (!a.isEmpty()) {
        buffer[j++] = a.pop();
    }
}

int eval(char *str) {
    precedence token;
    char symbol;
    int op1, op2;
    int n = 0;
    token = get_token(&symbol, &n, str);

    while (token != eos) {
        if (token == operand) {
            a.push(symbol - '0');
        }
        else {
            op2 = a.pop();
            op1 = a.pop();

            switch (token) {
                case pplus:
                    a.push(op1 + op2);
                    break;
                case mminus:
                    a.push(op1 - op2);
                    break;
                case times:
                    a.push(op1 * op2);
                    break;
                case divide:
                    a.push(op1 / op2);
                    break;
                case mod:
                    a.push(op1 % op2);
            }
        }
        token = get_token(&symbol, &n, str);
    }
    return a.pop();
}

precedence get_token(char *symbol, int *n, char *infix) {
    *symbol = infix[(*n)++];

    switch (*symbol) {
        case '(': return lParen;
        case ')': return rParen;
        case '+': return pplus;
        case '-': return mminus;
        case '/': return divide;
        case '*': return times;
        case '%': return mod;
        case NULL: return eos;
        default: return operand;
    }
}