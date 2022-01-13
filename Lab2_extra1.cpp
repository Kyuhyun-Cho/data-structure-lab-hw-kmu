//조규현 20191669 Lab2-extra1

#include <iostream>
#include <string>

using namespace std;

int recursiveAdd(int n, int m);
int recursiveDif(int n, int m);

int main() {
    int n, m;
    cout << "Enter number 1: ";
    cin >> n;
    cout << "Enter number 2: ";
    cin >> m;

    cout << "Addition Result is: " << recursiveAdd(n, m) << endl;
    cout << "Difference Result is: " << recursiveDif(n, m) << endl;
}

int recursiveAdd(int n, int m) {
    int sum;
    if (n <= 0 || m <= 0) {
        sum = n + m;
        return sum;
    }
    else {
        return recursiveAdd(n-1, m+1);
    }
}

int recursiveDif(int n, int m) {
    int diff;
    if (n <= 0 || m <= 0) {
        if (n > m) {
            diff = n - m;
            return diff;
        }
        else {
            diff = m - n;
            return diff;
        }
    }
    else {
        return recursiveDif(n-1, m-1);
    }
}