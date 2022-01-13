//조규현 20191669 Lab10

#include<iostream>

using namespace std;

typedef struct {
    int key;
} element;

element heap[200];
int arr[8];
int n = 0; int k = 0;

int EmptyHeap() {
    if (n == 0) return 1;
    else return 0;
}

int FullHeap() {
    if (n == 8) return 1;
    else return 0;
}

void insertarr(int num) {
    arr[k++] = num;
}

void insertHeap(int num) {
    int i;
    if (FullHeap()) cout << "Heap is full!" << endl;
    else {
        i = ++n;
        while ((i != 1) && (num > heap[i / 2].key)) {
            heap[i] = heap[i / 2];
            i = i / 2;
        }
        heap[i].key = num;
    }
}

void deleteMinHeap() {
    int parent, child;
    element item, temp;

    item = heap[1];
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

void printHeap() {
    if (EmptyHeap())
        cout << "Heap is Empty" << endl;
    else {
        cout << "Heap: ";
        for (int i = 1; i <= n; i++) {
            cout << heap[i].key << " ";
        }
        cout << endl;
    }
}

int leveltest() {
    if (n == 1) return 1;
    else if (2 <= n && n <= 3) return 2;
    else if (4 <= n && n <= 7) return 3;
    else if (8 <= n) return 4;
}

int searchHeap(int num) {
    int k = 0;
    if (EmptyHeap())
        cout << "Heap is Empty" << endl;
    else {
        for (int i = 1; i <= n; i++) {
            if (heap[i].key == num) {
                k = 1;
                break;
            }
        }
    }
    return k;
}

int main() {
    insertarr(8); insertarr(6); insertarr(4); insertarr(2); insertarr(5); insertarr(3);

    for (int i = 0; i < k; i++) {
        insertHeap(arr[i]);
    }

    while (true) {
        cout << "1.Insert 2.Delete 3.Search 4.Print 5.Empty 6.Full 7.LevelTest 8.Quit: ";
        int a;
        cin >> a;
        switch (a) {
            case 1: {
                int num;
                cout << "Enter a number to insert: ";
                cin >> num;
                insertHeap(num);
                printHeap();
                break;
            }
            case 2: {
                deleteMinHeap();
                printHeap();
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
                printHeap();
                break;
            }
            case 5: {
                if (EmptyHeap()) cout << "Heap is Empty" << endl;
                else cout << "Heap is not Empty" << endl;
                break;
            }
            case 6: {
                if (FullHeap()) cout << "Heap is Full" << endl;
                else cout << "Not Full" << endl;
                break;
            }
            case 7: {
                cout << "Level of Heap is " << leveltest() << endl;
                break;
            }
            case 8: {
                return 0;
            }
        }
    }
}