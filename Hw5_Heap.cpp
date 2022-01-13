/***********************************************************************************************************************
* Name: 조규현
* Student ID: 20191669
* Program: Hw#5

* Description: MAX HEAP에 적용할 수 있는 여러 ADT들을 테스트하는 것을 목표로 한다.

* Algorithm: 1. Insert Heap - Heap에 데이터 삽입
             2. Delete Heap - Heap에서 top element 데이터 삭제
             3. Search Heap - Heap에서 원하는 데이터 값이 존재하는지 판단
             4. Level Test - Heap의 Level 출력
             5. Print Heap - Heap의 전체 데이터 출력
             6. Make Heap - Binary Tree를 Max Heap으로 변환
             7. Heap Sort - Heap의 데이터 값을 오름차순으로 정렬하여 출력

* Variables:
 typedef struct { int key; } element: Heap에 적용시키기 위해 key값을 가지고 있는 구조체 선언
 element heap[100]: 데이터 값을 넣을 Heap 선언
 int arr[11]: Heap으로 변환하게 될 Binary Tree 선언
 int n: Heap에 삽입된 데이터 개수를 파악하기 위한 변수
 int k: Binary Tree에 삽입된 데이터 개수를 파악하기 위한 변수
***********************************************************************************************************************/

#include<iostream>

using namespace std;

typedef struct {
    int key;
} element;

element heap[100];
int arr[11];
int n = 0;
int k = 0;

/***********************************************************************************************************************
* fucntion: int EmptyHeap()
* description: Heap에 삽입된 데이터 개수가 0개일 때는 true를, 1개 이상일 때는 false를 return 하여 Heap이 비어있는 상태인지 파악해준다.
* variables: X
***********************************************************************************************************************/

int EmptyHeap() {
    if (n == 0) return 1;
    else return 0;
}

/***********************************************************************************************************************
* fucntion: int FullHeap() {
* description: Heap에 삽입된 데이터 개수가 11개일 때는 true를, 10개 이하일 때는 false를 return 하여 Heap이 꽉 차있는 상태인지 파악해준다.
* variables: X
***********************************************************************************************************************/

int FullHeap() {
    if (n == 11) return 1;
    else return 0;
}

/***********************************************************************************************************************
* fucntion: void insertarr(int num)
* description: Binary Tree에 데이터 값을 삽입함과 동시에 해당 Tree에 총 몇 개의 데이터가 들어있는지 파악하기 위해 k의 값을 증가시켜준다.
* variables:
 int num: 삽입할 데이터 값
***********************************************************************************************************************/

void insertarr(int num) {
    arr[k++] = num;
}

/***********************************************************************************************************************
* fucntion: void insertHeap(int num)
* description: Heap에 데이터를 삽입해준다. 이 떄 Heap이 꽉 차있는 상태라면 데이터를 삽입하지 않고 오류 메세지를 출력한다.
* variables:
 int num: 삽입할 데이터 값
***********************************************************************************************************************/

void insertHeap(int num) {
    int i;
    if (FullHeap()) cout << "Heap is Full" << endl;
    else {
        i = ++n;
        while ((i != 1) && (num > heap[i / 2].key)) {
            heap[i] = heap[i / 2];
            i = i / 2;
        }
        heap[i].key = num;
    }
}

/***********************************************************************************************************************
* fucntion: void deleteHeap()
* description: Heap의 top element 데이터를 삭제한다. 이 때 Heap이 비어있는 상태라면 데이터를 삭제하지 않고 오류 메세지를 출력한다.
* variables:
 int parent: 부모 노드 변수
 int child: 자식 노드 변수
 element temp: 데이터 값의 누락을 막기 위해 선언한 구조체
***********************************************************************************************************************/

void deleteHeap() {
    int parent, child;
    element temp;

    temp = heap[n--];
    parent = 1;
    child = 2;

    if (EmptyHeap()) {
        cout << "Heap is Empty" << endl;
    }
    while (child <= n) {
        if ((child < n) && (heap[child].key < heap[child + 1].key))
            child++;

        if (temp.key >= heap[child].key)
            break;

        heap[parent] = heap[child];
        parent = child;
        child = child * 2;
    }
    heap[parent] = temp;
}

/***********************************************************************************************************************
* fucntion: void printHeap(int m)
* description: Heap의 전체 데이터 값을 출력한다.
* variables: X
***********************************************************************************************************************/

void printHeap(int m) {
    if (EmptyHeap()) cout << "Heap is Empty" << endl;
    else {
        cout << "Heap: ";
        for (int i = 1; i <= m; i++) {
            cout << heap[i].key << " ";
        }
        cout << endl;
    }
}

/***********************************************************************************************************************
* fucntion: int leveltest()
* description: Heap의 데이터 개수를 통해 Heap의 레벨을 파악한다.
* variables: X
***********************************************************************************************************************/

int leveltest() {
    if (n == 1) return 1;
    else if (2 <= n && n <= 3) return 2;
    else if (4 <= n && n <= 7) return 3;
    else if (8 <= n && n <= 11) return 4;
}

/***********************************************************************************************************************
* fucntion: bool searchHeap(int num)
* description: Heap의 전체 데이터를 탐색하여 원하는 데이터 값이 존재하는지 파악한다. 이 때 Heap이 비어있다면 데이터를 탐색하지 않고 오류 메세지를 출력한다.
* variables:
 int num: Heap에 존재하는지 탐색하고자 하는 데이터 값
 int flag: 원하는 데이터 값의 존재 유무를 true/false 값으로 알려주는 변수
***********************************************************************************************************************/

bool searchHeap(int num) {
    int flag = false;
    if (EmptyHeap())
        cout << "Heap is Empty" << endl;
    else {
        for (int i = 1; i <= n; i++) {
            if (heap[i].key == num) {
                flag = true;
                break;
            }
        }
    }
    return flag;
}

/***********************************************************************************************************************
* fucntion: void heap_to_arr(int m)
* description: Heap의 정렬을 좀 더 수월하게 하기 위해 Binary Tree의 데이터 값을 Heap의 데이터 값에 따라 적절하게 조절한다.
* variables: X
***********************************************************************************************************************/

void heap_to_arr(int m) {
    int i;
    for(i = 1; i <= m; i++){
        arr[i - 1] = heap[i].key;
    }
    k = m;
    n = 0;
}

/***********************************************************************************************************************
* fucntion: void heapify(int m)
* description: Binary Tree에 있는 전체 데이터 값을 Heap으로 옮겨준다.
* variables: X
***********************************************************************************************************************/

void heapify(int m) {
    int i;
    heap_to_arr(m);
    for(i = 1; i <= m - 1; i++){
        insertHeap(arr[i - 1]);
    }
}

/***********************************************************************************************************************
* fucntion: int sortHeap()
* description: Heap에 존재하는 데이터 값들을 오름차순으로 정렬하여 출력한다.
* variables:
 int temp: Heap을 정렬하면서 swap할 때 데이터 값이 누락되지 않도록 임시로 저장시켜놓기 위한 변수
 int curr: Heap의 정렬 과정을 차례대로 출력하기 위해 선언한 변수
***********************************************************************************************************************/

int sortHeap() {
    int i, temp;
    int curr = n;
    for(i = n; i >= 1; i--){
        temp = heap[i].key;
        heap[i].key = heap[1].key;
        heap[1].key = temp;

        heapify(i);
        if(i != 1)
            printHeap(curr);
    }
    n = curr;
}

/***********************************************************************************************************************
* fucntion: int main()
* description: (1) ~ (8)까지 각각의 ADT를 switch 문을 통해 메뉴로 만들어 실행할 수 있도록 해준다.
* variables:
 int a: 몇 번째 ADT를 실행할지 정해주는 변수
***********************************************************************************************************************/

int main() {
    insertarr(26); insertarr(5); insertarr(77); insertarr(1); insertarr(61);
    insertarr(11); insertarr(59); insertarr(15); insertarr(48); insertarr(19);

    cout << "Heap: ";
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < k; i++) {
        insertHeap(arr[i]);
    }

    while (true) {
        cout << "1.Insert 2.Delete 3.Search 4.Print 5.LevelTest 6.HeapSort 7.MakeHeap 8.Quit: ";
        int a;
        cin >> a;
        switch (a) {
            case 1: {
                int num;
                cout << "Enter a number to insert: ";
                cin >> num;
                insertHeap(num);
                printHeap(n);
                break;
            }
            case 2: {
                deleteHeap();
                printHeap(n);
                break;
            }
            case 3: {
                int num;
                cout << "Enter a number to search: ";
                cin >> num;
                if (searchHeap(num)) cout << num << " is found" << endl;
                else cout << "Not found" << endl;
                break;
            }
            case 4: {
                printHeap(n);
                break;
            }
            case 5: {
                cout << "Level of Heap is " << leveltest() << endl;
                break;
            }
            case 6: {
                sortHeap();
                break;
            }
            case 7: {
                n = 0;
                for (int i = 0; i < k; i++) {
                    insertHeap(arr[i]);
                }
                printHeap(n);
                break;
            }
            case 8: {
                return 0;
            }
        }
    }
}