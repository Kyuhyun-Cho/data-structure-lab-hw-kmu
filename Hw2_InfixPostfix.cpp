/***********************************************************************************************************************
* Name: 조규현
* Student ID: 20191669
* Program: Hw#2

* Description: 수식 데이터 값을 입력받아 중위표기식을 후위표기식으로 변환한 뒤 이를 postfix evaluation 알고리즘을 통해 최종 계산 값을 출력한다.

* Algorithm: 1. 중위표기식 데이터 값을 입력 받아온다.
             2. 숫자가 나올 시에는 화면에 출력해준다.
             3. 연산자 우선순위를 정하여 *, /, +, -, (, ) 각각의 기호가 나올 시 정해진 상황에 맞게 스택에 push 하거나 pop 해준다.
             4. 스택이 비워질 때까지 pop을 해주면 후위표기식이 결과값으로 나온다.
             5. 이 후위표기식을 임시버퍼배열 변수에 저장한다.
             6. 숫자가 나올 경우 스택에 쌓고, 연산자가 나올 경우 두 수를 pop한 후 계산하는 과정을 반복하면 식의 결과값이 나온다.

* Variables:
 class Stack: 식을 담을 스택 클래스 선언
 int top: 스택의 인덱스 값
 int size: 스택의 길이 값
 typedef enum {lParen, rParen, pplus, mminus, times, divide, eos, operand} precedence: 연산자 자료형 재정의
 void postfix(char *infix, int len): 중위표기식을 후위표기식으로 변환하는 함수 선언
 int eval(char *str): 후위표기식을 계산해주는 함수 선언
 Stack a
 char buffer[]
 precedence get_token(char *symbol, int *n, char *infix)
 bool Stack::isFull() const
 bool Stack::isEmpty() const
 void Stack::push(int value)
 char Stack::pop()
 int Stack::get_top()
 int Stack::set_stackTop(): 중위표기식을 후위표기식으로 변환하는데 필요한 변수 및 함수들
***********************************************************************************************************************/
#include <iostream>
#include <fstream>
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
    int get_top();
    int set_stackTop();
};

typedef enum {lParen, rParen, pplus, mminus, times, divide, eos, operand} precedence;
void postfix(char *infix, int len);
int eval(char *str);
precedence get_token(char *symbol, int *n, char *infix);
Stack a(MAX_SIZE);
char buffer[MAX_SIZE] = {};

Stack::Stack(int size) :size(size) {
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
/***********************************************************************************************************************
* fucntion: int main()
* description: main의 사용 목적은 입력받은 중위표기식 데이터를 배열로 입력받아 postfix 함수를 사용하여 후위표기식으로 변환한 후 각각을 출력한 뒤,
               eval 함수를 사용하여 식의 결과값을 계산하 출력하는 것이다.
* variables:
 int len: 식의 길이를 의미하는 변수
***********************************************************************************************************************/
int main() {
    char str[MAX_SIZE] = {};
    int len;

    ifstream infile;
    infile.open("Hw2.txt", ios::in);
    if (infile.fail()) {cout << "can't open the input file" << endl; exit(1);}

    while (infile.getline(str,100)) {
        len = strlen(str);
        cout << "Enter data (infix form): ";
        for (int i = 0; i < len; i++)
            cout << str[i];
        cout << endl << "Conversion (postfix form): ";
        postfix(str, len);
        int k = 0;
        while (buffer[k] != NULL)
            cout << buffer[k++];
        cout << endl;
        cout << "Result: " << eval(buffer) << endl;
    }
    return 0;
}

/***********************************************************************************************************************
* fucntion: void postfix(char *infix, int len)
* description: '*', '/' > '+', '-' > '(' 순서의 연산자 우선순위로 '('가 나올 경우 push, '+', '-'가 나올 경우 '*', '/'보다 우선순위가
               낮으므로 top이 0이상, '('가 나올 때까지 pop을 해준 후 '+', '-'를 push 해준다. '*', '/'가 나올 경우 '+', '-'보다
               우선순위가 높으므로 위의 조건에 '+' 또는 '-'가 나올 떄까지 pop 해준 뒤 이를 push 해준다 조건을 추가한다. 만약 우선순위가 가장 낮은
               ')'가 나올 경우 '(' 나올 때까지 pop 해준다. 이 때 '('를 없애주기 위해 한 번 더 pop을 해주는 것이 필요하다. 식을 끝까지 비교한 후
               스택이 비워질 때까지 pop을 해주면 중위표기식에서 후위표기식으로 변환 된 값을 얻을 수 있다.
* variables:
 char *infix: 데이터로 입력받은 식을 가리키는 배열
 int len: 데이터로 입력받은 식의 길이를 의마하는 변수
***********************************************************************************************************************/
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

/***********************************************************************************************************************
* fucntion: int eval(char *str)
* description: postfix 함수에서 변환된 후위표기식을 바탕으로 숫자가 나오면 이를 ascii 코드값에 맞춰 변환 환 뒤 스택에 push 해주고, 연산자가 나오면
               앞에 두 수를 pop 해준 뒤 해당 연산자에 맞는 계산을 하여 다시 push 해준다. 이를 식이 끝날 때까지 반복하여 마지막에 남는 값을 pop 해주면
               계산이 완료된다.
* variables:
 prcedence token: 위의 enum{}에서 기호에 맞는 것을 문자로 변환시켜 이를 비교하기 위해 설정한 변수
 char symbol: 식을 읽기 위해 설정한 변수
 int op1, op2: 스택에 저장한 숫자를 pop 해준 뒤 이를 해당 변수에 저장하여 계산하기 위해 설정한 변수
***********************************************************************************************************************/
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
            }
        }
        token = get_token(&symbol, &n, str);
    }
    return a.pop();
}

/***********************************************************************************************************************
* fucntion: precedence get_token(char *symbol, int *n, char *infix)
* description: char *symbol, int *n, char *infix를 매개변수로 받아 이를 이용하여 postfix 함수에서 변환한 식을 각각 숫자, 연산자 혹은 NULL값
               을 비교하여 이를 문자로 변환시켜 반환한다.
* variables:
 symbol: postfix 함수에서 변환한 식을 처음부터 차례대로 읽어 숫자 혹은 연산자를 가져오기 위해 설정한 변수
 case NULL: 식이 종료되는 시점을 알리기 위한 case
***********************************************************************************************************************/
precedence get_token(char *symbol, int *n, char *infix) {
    *symbol = infix[(*n)++];

    switch (*symbol) {
        case '(': return lParen;
        case ')': return rParen;
        case '+': return pplus;
        case '-': return mminus;
        case '/': return divide;
        case '*': return times;
        case NULL: return eos;
        default: return operand;
    }
}