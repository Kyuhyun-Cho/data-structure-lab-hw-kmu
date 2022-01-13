//조규현 20191669 Lab3

#include <iostream>

using namespace std;
int square[100][100], k, l;
void magicLeft();
void magicRight();
int n;

int main() {
    while (true) {
        cout << "Enter number of square: ";
        cin >> n;
        cout << endl;

        if (n % 2 == 1) {
            magicLeft();
            cout << "Magic square size is " << n << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << square[i][j] << " ";
                }
                cout << endl;
            }

            cout << endl;

            magicRight();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << square[i][j] << " ";
                }
                cout << endl;
            }
            break;
        }
        else {
            cout << "---Wrong Number---" << endl;
            continue;
        }
    }
}

void magicLeft() {
    int key = 2;
    int i = 0;
    int j = n / 2;
    int row, col;
    square[i][j] = 1;

    while (key <= n * n) {
        if (i - 1 < 0) {
            row = n - 1;
        }
        else {
            row = i - 1;
        }
        if (j - 1 < 0) {
            col = n - 1;
        }
        else {
            col = j - 1;
        }
        if (square[row][col]) {
            i = (i + 1) % n;
        }
        else {
            i = row;
            j = col;
        }
        square[i][j] = key++;
    }
}

void magicRight() {
    int key = 2;
    int i = 0;
    int j = n / 2;
    square[i][j] = 1;

    while (key <= n * n) {
        if ((key - 1) % n == 0) {
            i++;
            square[i][j] = key;
            key++;
        }
        else {
            if (i - 1 < 0) {
                i = n - 1;
                j++;
                square[i][j] = key;
                key++;
            }
            else if (j + 1 > n-1) {
                i--;
                j = 0;
                square[i][j] = key;
                key++;
            }
            else {
                i--;
                j++;
                square[i][j] = key;
                key++;
            }
        }
    }
}
