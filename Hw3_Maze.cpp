/***********************************************************************************************************************
* Name: 조규현
* Student ID: 20191669
* Program: Hw#3

* Description: 주어진 matrix 안에서 stack을 이용하여 도착점까지 찾아가는 경로를 찾는 것을 목표로 한다. 이 때 시작점과 도착점은 제공된다.

* Algorithm: 1. 수직, 수평성분을 가지고 있는 구조체를 이용하여 도착점을 찾는 과정까지 이동할 수 있는 8개의 방위를 선언해준다.
             2. 선언한 방위 배열을 이용하여 row 변수와 col 변수에 적절한 값을 더해주고 빼는 과정을 통해 도착점까지의 경로를 탐색해준다.
             3. 이 때 탐색 과정은 북쪽부터 시계방향으로 진행되며 현위치를 stack에 저장해준다.
             4. 잘못된 경로일 경우 스택에 저장했던 직전 좌표를 pop 하여 되돌아가며 잘못된 경로의 좌표는 1로 표시해주어 재탐색 되지 않도록 한다.
             5. 도착점에 도착할 시 미로 탐색이 종료되며 stack을 이용하여 거쳐간 좌표의 row, col, 경로를 출력해준다.

* Variables:
 element: row, col, dir 값으로 구성된 구조체
 offsets: 방위를 이용하여 탐색할 때 이용되는 vert, horiz 값으로 구성된 구조체
 bool found: 도착점에 도착했을 때를 표시해주기 위해 선언한 변수
 int isEmpty(): 스택이 비어있는지 확인하는 함수
 void push(element item): 스택에 row, col, dir 값을 저장하는 함수
 element pop(): 스택의 top에 있는 좌표값을 꺼내주는 함수
 int maze[6][6]: 주어진 미로
 int mark[6][6]: 도착점을 찾을 때까지 거쳐간 경로를 표시하는 배열
***********************************************************************************************************************/

#include <iostream>

#define MAX_SIZE 100

using namespace std;

typedef struct  {
    int row;
    int col;
    int dir;
} element;

typedef struct {
    int vert;
    int horiz;
}  offsets;

element stack[MAX_SIZE];
int top = 0;
bool found = false;

bool isEmpty() {
    if (top == -1) return true;
    else return false;
}

void push(element item) {
    stack[++top] = item;
}

element pop() {
    return stack[top--];
}

int maze[6][6] = { 0,1,1,1,1,1,
                   1,0,1,1,1,1,
                   1,0,0,0,0,1,
                   1,1,0,1,1,1,
                   1,0,1,0,0,1,
                   1,1,1,1,1,0 };

int mark[6][6] = { 0,0,0,0,0,0,
                   0,0,0,0,0,0,
                   0,0,0,0,0,0,
                   0,0,0,0,0,0,
                   0,0,0,0,0,0,
                   0,0,0,0,0,0 };

/***********************************************************************************************************************
* fucntion: void MIRO_PATH(int maze[6][6], int mark[6][6])
* description: MIRO_PATH 함수는 stack을 이용하여 도착점을 찾고, 그 과정에서 거쳐간 경로를 저장한다. next_row 와 next_col 의 값이
               maze 와 mark 에서 동시에 '1'이 아닐 때 즉, true 값이 아닐 때 해당 좌표로 이동하며 경로를 탐색하고 더 이상 이동할 수 없는
               좌표일 때에는 stack에 저장한 직전 좌표값으로 돌아가며 경로를 재탐색한다.
* variables:
 int row, col, dir: 행, 열, 방위값을 이용하기 위해 선언한 변수
 int next_row, next_col: 이동하고자 하는 좌표의 행, 열 값을 이용하기 위해 선언한 변수
 int EXIT_ROW, EXIT_COL: 도착점의 행, 열 값
 element position: 현 위치를 표시하고자 선언한 변수
 offsets move[8]: 방위값을 이용하여 좌표를 이동하고자 선언한 배열
***********************************************************************************************************************/

void MIRO_PATH(int maze[6][6], int mark[6][6]) {
    int row, col, dir;
    int next_row, next_col;
    int EXIT_ROW = 5;
    int EXIT_COL = 5;
    mark[0][0] = 1;

    element position;

    offsets move[8];
    move[0].vert = -1; move[0].horiz = 0; // N    0
    move[1].vert = -1; move[1].horiz = 1; // NE   1
    move[2].vert = 0; move[2].horiz = 1; // E     2
    move[3].vert = 1; move[3].horiz = 1; // SE    3
    move[4].vert = 1; move[4].horiz = 0; // S     4
    move[5].vert = 1; move[5].horiz = -1; // SW   5
    move[6].vert = 0; move[6].horiz = -1; // W    6
    move[7].vert = -1; move[7].horiz = -1; // NW  7

    while (!isEmpty() && !found) {
        position = pop();
        row = position.row; col = position.col; dir = position.dir;

        while (dir < 8 && !found) {
            next_row = row + move[dir].vert;
            next_col = col + move[dir].horiz;

            if (next_row == EXIT_ROW && next_col == EXIT_COL) {
                mark[next_row][next_col] = 1;
                found = true;
            }
            else if (!maze[next_row][next_col] && !mark[next_row][next_col]) {
                mark[next_row][next_col] = 1;
                position.row = row; position.col = col; position.dir = ++dir;

                push(position);

                row = next_row; col = next_col; dir = 0;
            }
            else ++dir;
        }
    }
    push(position);
}

/***********************************************************************************************************************
* fucntion: int main()
* description: main 함수는 MIRO_PATH 함수를 이용하여 도착점을 찾는 과정까지 거쳐간 경로와, 그 경로의 행, 열 값을 출력한다.
* variables: X
***********************************************************************************************************************/

int main() {
    MIRO_PATH(maze, mark);

    if (found == true) {
        cout << "The Path is" << endl;
        cout << endl;

        cout << "row" << "   " << "col" << endl;
        cout << "---------" << endl;
        for (int r = 0; r < 6; r++) {
            for (int c = 0; c < 6; c++) {
                if (mark[r][c] == 1) {
                    cout << " " << r << "     " << c << endl;
                }
            }
        }
        cout << endl;

        cout << "Marked Matrix" << endl;
        cout << "-------------" << endl;
        for (int r = 0; r < 6; r++) {
            cout << " ";
            for (int c = 0; c < 6; c++) {
                cout << mark[r][c] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
