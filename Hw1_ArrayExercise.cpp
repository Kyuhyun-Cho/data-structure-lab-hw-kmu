//조규현 20191669 Hw1_ArrayExercise

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define MAX_COL 50

struct term{
    int row;
    int col;
    int value;
};

void transpose(term a[], term b[]);
void fast_transpose(term a[], term b[]);

int main(){
    term a[MAX_COL], b[MAX_COL];

    ifstream inFile;
    inFile.open("Hw1.txt");

    int oriMatrix[6][6];

    cout << "1) Original Matrix: A" << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            inFile >>oriMatrix[i][j];
            cout << oriMatrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "2) Transpose of Original Matrix A" << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << oriMatrix[j][i] << " ";
        }
        cout << endl;
    }


    int num = 1;

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++) {
            if (oriMatrix[i][j] != 0) {
                a[num].row = i;
                a[num].col = j;
                a[num].value = oriMatrix[i][j];
                num++;
            }
    }

    a[0].row = 6;
    a[0].col = 6;
    a[0].value = num - 1;

    cout << endl;

    cout << "3) Spares Matrix of A - row major" << endl;
    for (int i = 1; i < 9; i++) {
        cout << a[i].row << " " << a[i].col << " " << a[i].value << endl;
    }

    cout << endl;

    transpose(a, b);
    cout << "4) Transpose of Spares Matrix A - column major" << endl;
    for (int i = 1; i < 9; i++) {
        cout << b[i].row << " " << b[i].col << " " << b[i].value << endl;
    }

    cout << endl;

    fast_transpose(a, b);
    cout << "5) Fast Transpose of Spares Matrix A" << endl;
    for (int i = 1; i < 9; i++) {
        cout << b[i].row << " " << b[i].col << " " << b[i].value << endl;
    }
}

void transpose(term a[], term b[]) {
    int i, j, currentb; // 6 6 8
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;

    if(a[0].value > 0) { // 0이 아닌 행렬
        currentb = 1;
        for (i = 0; i < a[0].col; i++) { // a에서 열별로 전치
            for (j = 1; j <= a[0].value; j++) {
                // 현재의 열로부터 원소를 찾는다
                if (a[j].col == i) {
                    // 현재 열에 있는 원소를 b에 첨가
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb++;
                }
            }
        }
    }
}

void fast_transpose(term a[], term b[]) {
    int row_terms[MAX_COL], starting_pos[MAX_COL];
    int i, j, num_cols = a[0].col, num_terms = a[0].value;

    b[0].row = num_cols; // 6
    b[0].col = a[0].row; // 6
    b[0].value = num_terms; // 8

    if (num_terms > 0) { // 0이 아닌 행렬
        for (i = 0 ; i < num_cols ; i++) {
            row_terms[i] = 0; // number of terms 초기화
        }
        for (i = 1 ; i <= num_terms ; i++) { // 각 row terms 위한 값
            row_terms[a[i].col]++;
        }
    }
    starting_pos[0] = 1; // 각 row terms 시작점 구함

    for (i = 1 ; i < num_cols ; i++) {
        starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
    }
    for (i = 1 ; i <= num_terms ; i++) { // A를 B로 옮김
        j = starting_pos[a[i].col]++;
        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;
    }
}

