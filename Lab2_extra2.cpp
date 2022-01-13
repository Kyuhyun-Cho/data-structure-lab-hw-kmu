//조규현 20191669 Lab2-extra2

#include <iostream>

using namespace std;

int sum(int n);

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Result is: " << sum(num);
}

int sum(int num) {

    if (num == 0) {
        return 0;
    }
    else {
        if (num == 1) {
            cout << num << " = ";
            return num + sum(num - 1);
        }
        else {
            cout << num << "+";
            return num + sum(num - 1);
        }
    }
}
