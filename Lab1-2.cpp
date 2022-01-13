//조규현 20191669 Lab1-2

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void findMin(int [], int);
void findMax(int [], int);

int main() {
    int number, count, data[8];
    ifstream infile;
    int position;
    infile.open("Lab1-2.dat");

    while (infile >> number) {
        data[count++] = number;
    }

    findMin(data, count);
    findMax(data, count);

    return 0;
}

void findMin(int data[], int n) {
    int min = data[0];
    int minPosition = 1;
    for (int i = 1; i < n; i++) {
        if (data[i] < min) {
            min = data[i];
            minPosition = i + 1;
        }
    }
    cout << "Minimum number is " << min << " at position " << minPosition << endl;
}

void findMax(int data[], int n) {
    int max = data[0];
    int maxPosition = 1;
    for (int i = 1; i < n; i++) {
        if (data[i] > max) {
            max = data[i];
            maxPosition = i + 1;
        }
    }
    cout << "Maximum number is " << max << " at position " << maxPosition << endl;
}

