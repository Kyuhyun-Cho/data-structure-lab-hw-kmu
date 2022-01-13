/***********************************************************************************************************************
* Name: 조규현
* Student ID: 20191669
* Program: Hw#7

* Description: Kruskal 알고리즘을 활용하여 원하는 결과값을 출력한다.

* Algorithm: 1. 한번에 한 간선씩 최소비용 신장트리를 구축한다.
             2. 최소비용 신장트리에 포함될 간선을 비용의 크기 순으로 선택한다.
             3. 최소비용 신장트리에 n-1개의 간선이 포함될 때까지 간선을 추가한다.

* Variables:
 char start: 시작 정점
 char end: 도착 정점
 int cost: 두 정점 사이의 비용
 int vertNum: 정점을 뜻하는 변수
 int edgeNum: 간선을 뜻하는 변수
 int parent[]: 부모 노드를 표시하는 배열
***********************************************************************************************************************/

#include <iostream>
#include <fstream>
#define MAX_SIZE 6

using namespace std;

class Node {
public:
    char start;
    char end;
    int cost;
    Node *next;

    Node(char s, char e, int c) {
        start = s;
        end = e;
        cost = c;
        next = NULL;
    }
};

class AdjacentList {
public:
    Node *list[MAX_SIZE];
    int vertNum;
    int edgeNum;

    AdjacentList(int vert, int edge) : vertNum(vert), edgeNum(edge) {
        for (int i = 0; i < MAX_SIZE; i++) {
            list[i] = NULL;
        }
    }
    bool addNode(char, char, int);
};

class Kruskal {
public:
    Node *kruskal;
    int parent[MAX_SIZE];

    Kruskal() {
        kruskal = NULL;
        for (int i = 0; i < MAX_SIZE; i++) {
            parent[i] = i;
        }
    }
    bool addData(char v1, char v2, int cost);
    void printData();
    void sortData();
    int getParent(int x);
    void unionParent(int a, int b);
    bool findParent(int a, int b);
    void kruskalAlgo();
};

/***********************************************************************************************************************
* fucntion: bool AdjacentList::addNode(char v1, char v2, int cost)
* description: 입력받은 데이터를 트리로 변환하는 함수
* variables: X
***********************************************************************************************************************/

bool AdjacentList::addNode(char v1, char v2, int cost) {
    Node *newNode;
    newNode = new Node(v1, v2, cost);

    if (newNode == NULL) return false;
    newNode->next = list[v1 - 'A'];
    list[v1 - 'A'] = newNode;

    newNode = new Node(v2, v1, cost);

    newNode->next = list[v2 - 'A'];
    list[v2 - 'A'] = newNode;

    return true;
}

/***********************************************************************************************************************
* fucntion: bool Kruskal::addData(char v1, char v2, int co)
* description: 시작 정점, 도착 정점, 두 정점 사이의 비용값을 노드에 추가하는 함수
* variables: X
***********************************************************************************************************************/

bool Kruskal::addData(char v1, char v2, int co) {
    Node *newNode;
    Node *temp = kruskal;
    newNode = new Node(v1, v2, co);

    if (newNode == NULL) return false;

    if (kruskal == NULL) kruskal = newNode;

    else {
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
    return true;
}

/***********************************************************************************************************************
* fucntion: void Kruskal::printData()
* description: 트리에 있는 데이터를 출력하는 함수
* variables:
 Node *now: 현재 생성되어 있는 트리
***********************************************************************************************************************/

void Kruskal::printData() {
    Node *now = kruskal;

    while (now != NULL) {
        cout << now->start << " " << now->cost << " " << now->end;
        cout << "   ";
        now = now->next;
    }
    cout << endl;
}

/***********************************************************************************************************************
* fucntion: void Kruskal::sortData()
* description: 정점 간의 비용을 기준으로 트리의 데이터를 정렬하는 함수
* variables:
 Node *temp: 데이터 손실을 방지하기 위해 임시로 선언한 노드
 Node *min: 데이터 정렬을 위해 최소 비용값을 저장하는 노드
***********************************************************************************************************************/

void Kruskal::sortData() {
    Node *now;
    Node *temp;
    Node *min = NULL;

    for (now = kruskal; now->next != NULL; now = now->next) {
        min = now;

        for (temp = now->next; temp != NULL; temp = temp->next) {
            if (min->cost > temp->cost)
                min = temp;
        }
        Node temp2(now->start, now->end, now->cost);

        now->start = min->start;
        now->end = min->end;
        now->cost = min->cost;

        min->start = temp2.start;
        min->end = temp2.end;
        min->cost = temp2.cost;
    }

}

/***********************************************************************************************************************
* fucntion: int Kruskal::getParent(int x)
* description: 부모 노드를 찾는 함수
* variables: X
***********************************************************************************************************************/

int Kruskal::getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

/***********************************************************************************************************************
* fucntion: void Kruskal::unionParent(int a, int b)
* description: 두 부모 노드를 합치는 함수
* variables: X
***********************************************************************************************************************/

void Kruskal::unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

/***********************************************************************************************************************
* fucntion: bool Kruskal::findParent(int a, int b)
* description: 같은 부모를 가지는지 확인하는 함수
* variables: X
***********************************************************************************************************************/

bool Kruskal::findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) return true;
    else return false;
}

/***********************************************************************************************************************
* fucntion: void Kruskal::kruskalAlgo()
* description: Kruskal 알고리즘을 통해 최소비용 신장트리를 생성하는 함수
* variables:
 int sum: 결과적으로 도출되는 최소비용을 저장하는 변수
***********************************************************************************************************************/

void Kruskal::kruskalAlgo() {
    int sum = 0;
    Node *now;
    int turn = 1;
    for (now = kruskal; now != NULL; now = now->next) {
        if (!findParent(now->start - 'A', now->end - 'A')) {
            sum += now->cost;
            cout << "Edge" << turn++ << ": " << now->start << " " << now->cost << " " << now->end << endl;
            unionParent(now->start - 'A', now->end - 'A');
        }
    }
    cout << endl << "4. Final cost for Kruskal is " << sum << endl;
}

/***********************************************************************************************************************
* fucntion: int main()
* description: 위 Algorithm에서 설명한 과정을 실행하는 main
* variables:
 char start: 시작 정점
 int weight: 정점 간의 비용
 char end: 도착 정점
***********************************************************************************************************************/

int main() {
    ifstream inStream;
    inStream.open("Hw7.txt");

    char start;
    int weight;
    char end;

    AdjacentList lp(6, 10);
    Kruskal kp;

    for (int i = 0; i < 10; i++) {
        inStream >> start >> weight >> end;
        lp.addNode(start, end, weight);
        kp.addData(start, end, weight);
    }
    inStream.close();

    cout << "1. Input Data: " << endl;
    kp.printData();
    cout << endl;

    cout << "2. Sorted Data: " << endl;
    kp.sortData();
    kp.printData();
    cout << endl;

    cout << "3. Minimum Spanning Tree: " << endl;
    kp.kruskalAlgo();
}