//조규현 20191669 Lab2-1

#include <iostream>

using namespace std;

int binSearch(int list[], int searchNum, int left, int right);
int recSearch(int list[], int searchNum, int left, int right);

int main() {
    int list[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int SIZE = 10;
    int searchNum;
    int choice;
    bool power = true;

    cout << "Numbers in the List: ";
    for (int i = 0; i < SIZE; i++) {
        cout << list[i] << " ";
    }
    cout << "\n\n";


    while (power = true) {
        cout << "Enter methods of Search: 1.Bin-Search 2.Recursive Search 3.Exit: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter an integer to search: ";
            cin >> searchNum;
            int count = 0;
            for (int i = 0; i < 10; i++) {
                if (list[i] == searchNum) {
                    count++;
                }
            }
            if (count == 0) {
                cout << "   => " << searchNum << " is not in the list" << endl;
            }
            else {
                int position = recSearch(list, searchNum, 0, 9);
                cout << "   => " << searchNum << " is at position " << position + 1 << endl;
            }
        }
        else if (choice == 2){
            cout << "Enter an integer to search: ";
            cin >> searchNum;
            int count = 0;
            for (int i = 0; i < 10; i++) {
                if (list[i] == searchNum) {
                    count++;
                }
            }
            if (count == 0) {
                cout << "   => " << searchNum << " is not in the list" << endl;
            }
            else {
                int position = binSearch(list, searchNum, 0, 9);
                cout << "   => " << searchNum << " is at position " << position + 1 << endl;
            }
        }
        else if (choice == 3){
            break;
        }
        else {
            cout << "---Wrong Number---" << endl;
        }
    }
}

int binSearch(int list[], int searchNum, int left, int right) {
    int mid = (left + right) / 2;
    while (right >= left) {
        if (list[mid] == searchNum) {
            return mid;
        }
        else if (list[mid] > searchNum) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
        mid = (left + right) / 2;
    }
}

int recSearch(int list[], int searchNum, int left, int right) {
    int mid = (left + right) / 2;
    if (list[mid] > searchNum) {
        return recSearch(list, searchNum, left, mid - 1);
    }
    else if (list[mid] < searchNum) {
        return recSearch(list, searchNum, mid + 1, right);
    }
    else if (list[mid] == searchNum) {
        return mid;
    }
    else {
        cout << searchNum << " is NOT FOUND" << endl;
        return 0;
    }
}