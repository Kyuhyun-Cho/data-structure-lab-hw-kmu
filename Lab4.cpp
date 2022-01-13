#include <iostream>
#include <fstream>
#include <string>

using namespace std;
bool check(char exp[]);
bool match(char a, char b);

const int stackSize = 100;
class Stack {
private:
    int stack[stackSize]; int top;
public:
    Stack() {top = - 1;}
    void push(char val) {stack[++top] = val;}
    int pop() {return stack[top--];}
    bool isEmpty() {
        if(top == -1) return true;
        else return false;
    }
};

int main() {
    ifstream in("Lab4.txt");
    char buffer[80];
    if (in.is_open()) {
        while (in.getline(buffer, 80)) {
            for (int i = 0; i < strlen(buffer); i++) {
                cout << buffer[i];
            }
            cout << endl;

            bool validity = check(buffer);
            if (validity == true) {
                cout << "The Expression is Valid";
            }
            cout << endl;
        }
    }
}


bool check(char exp[]) {
    Stack s;
    for(int i = 0; i < strlen(exp); i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') s.push(exp[i]);
        if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(s.isEmpty() == true) {
                cout << "The Expression has unbalanced parentheses";
                return false;
            }
            else {
                char temp = s.pop();
                if(match(temp, exp[i]) == false){
                    cout << "The Mismatched Parenthses in the Expression are " << temp << " and " << exp[i];
                    return false;
                }
            }
        }
    }
    if(s.isEmpty() == true) return true;
    else {
        cout << "The Expression has unbalanced parentheses";
        return false;
    }
}

bool match(char a, char b) {
    if(a == '('){
        if(b == ')') return true;
        else return false;
    }
    if(a == '{'){
        if(b == '}') return true;
        else return false;
    }
    if(a == '['){
        if(b == ']') return true;
        else return false;
    }
}