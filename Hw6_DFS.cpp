/***********************************************************************************************************************
* Name: 조규현
* Student ID: 20191669
* Program: Hw#6

* Description: 주어진 Graph를 Adjacency list로 표현하고 Depth First Search 과정을 출력한다.

* Algorithm: 1. 정점과 다음 정점의 대한 정보가 담겨있는 graph 배열을 생성해준다.
             2. 방문기록에 관한 정보가 담겨있는 visited 배열을 생성해준다.
             3. 주어진 입력데이터를 graph 배열에 담아준다.
             4. 데이터가 담긴 graph 배열과 visited 배열을 통해 해당 graph를 재귀적으로 Depth First Search 해준다.
             5. graph 데이터를 Adjacency list로 표현한다.
             6. Depth First Search 한 과정을 출력한다.

* Variables:
 const int MAX_1: Graph1의 행열 사이즈에 해당하는 상수
 const int MAX_2: Graph2의 행열 사이즈에 해당하는 상수
 (이하 함수명 및 변수명에 붙은 _1, _2은 각각 Graph1, Graph2에 적용되는 함수 및 변수)
 int vertex: 정점
 Node* next: 다음 정점에 대한 정보
 Node* graph: 입력데이터 값을 담는 배열
 bool visited: 방문기록에 대한 정보가 담겨있는 배열
***********************************************************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_1 = 10;
const int MAX_2 = 8;

class Node {
private:
    int vertex;
    Node* next;
public:
    Node(int num) :vertex(num), next(NULL) {}
    friend class Graph;
};

class Graph {
private:
    Node* graph_1[MAX_1];
    bool visited_1[MAX_1];
    Node* graph_2[MAX_2];
    bool visited_2[MAX_2];
public:
    Graph() {}
    void Graph_graph_init();
    void Graph_visited_init();
    void Graph_insert_1(int num1, int num2);
    void Graph_display_1();
    void Graph_insert_2(int num1, int num2);
    void Graph_display_2();
    void dfs_1(int v);
    void dfs_2(int v);
};

/***********************************************************************************************************************
* fucntion: void Graph::Graph_graph_init()
* description: 각 사이즈에 맞는 graph 배열 생성자에 해당한다.
* variables: X
***********************************************************************************************************************/

void Graph::Graph_graph_init() {
    for (int i = 0; i < MAX_1; i++)
        graph_1[i] = NULL;
    for (int i = 0; i < MAX_2; i++)
        graph_2[i] = NULL;
}

/***********************************************************************************************************************
* fucntion: void Graph::Graph_visited_init()
* description: visited 배열 생성자에 해당한다.
* variables: X
***********************************************************************************************************************/

void Graph::Graph_visited_init() {
    for (int i = 0; i < MAX_1; i++)
        visited_1[i] = 0;
    for (int i = 0; i < MAX_2; i++)
        visited_2[i] = 0;
}

/***********************************************************************************************************************
* fucntion: void Graph::Graph_insert(int num1, int num2)
* description: 입력데이터를 각 graph 배열에 담는다.
* variables:
 Node* temp_1, Node* temp_2, Node* temp1, Node* temp2: 데이터 삽입을 위해 선언한 노드
***********************************************************************************************************************/

void Graph::Graph_insert_1(int num1, int num2) {
    if (graph_1[num1] == NULL) {
        Node* temp_1 = new Node(num1);
        graph_1[num1] = temp_1;
    }
    if (graph_1[num2] == NULL) {
        Node* temp_2 = new Node(num2);
        graph_1[num2] = temp_2;
    }

    Node* p = graph_1[num1];
    Node* temp1 = new Node(num2);
    while (p->next != NULL)
        p = p->next;
    p->next = temp1;

    p = graph_1[num2];
    Node* temp2 = new Node(num1);
    while (p->next != NULL)
        p = p->next;
    p->next = temp2;
}

void Graph::Graph_insert_2(int num1, int num2) {
    if (graph_2[num1] == NULL) {
        Node* temp_1 = new Node(num1);
        graph_2[num1] = temp_1;
    }
    if (graph_2[num2] == NULL) {
        Node* temp_2 = new Node(num2);
        graph_2[num2] = temp_2;
    }

    Node* p = graph_2[num1];
    Node* temp1 = new Node(num2);
    while (p->next != NULL)
        p = p->next;
    p->next = temp1;

    p = graph_2[num2];
    Node* temp2 = new Node(num1);
    while (p->next != NULL)
        p = p->next;
    p->next = temp2;
}

/***********************************************************************************************************************
* fucntion: void Graph::Graph_display()
* description: 데이터가 삽입된 graph 배열을 Adjacency list로 출력한다.
* variables: X
***********************************************************************************************************************/

void Graph::Graph_display_1() {
    for (int i = 0; i < MAX_1; i++) {
        if (graph_1[i] != NULL) {
            Node* p = graph_1[i];
            cout << "   V";
            while (p != NULL) {
                cout << p->vertex << " ";
                p = p->next;
            }
            cout << endl;
        }
    }
}

void Graph::Graph_display_2() {
    for (int i = 0; i < MAX_2; i++) {
        if (graph_2[i] != NULL) {
            Node* p = graph_2[i];
            cout << "   V";
            while (p != NULL) {
                cout << p->vertex << " ";
                p = p->next;
            }
            cout << endl;
        }
    }
}

/***********************************************************************************************************************
* fucntion: void Graph::dfs(int v)
* description: 데이터가 삽입된 graph 배열과 방문기록이 담겨있는 visited 배열을 통해 재귀적으로 Depth Fisrt Search를 진행한다.
* variables:
 int v: 시작 정점을 가리키는 변수
***********************************************************************************************************************/

void Graph::dfs_1(int v) {
    Node* p;
    visited_1[v] = 1;
    cout << "V" << v << " ";

    for (p = graph_1[v]; p; p = p->next) {
        if (!visited_1[p->vertex])
            dfs_1(p->vertex);
    }
}

void Graph::dfs_2(int v) {
    Node* p;
    visited_2[v] = 1;
    cout << "V" << v << " ";

    for (p = graph_2[v]; p; p = p->next) {
        if (!visited_2[p->vertex])
            dfs_2(p->vertex);
    }
}

/***********************************************************************************************************************
* fucntion: int main()
* description: 위 Algorithm에서 설명한 과정을 각 Graph1, Graph2에서 진행한다.
* variables:
 int num1, int num2: 연결되어있는 두 정점을 표현하는 변수
***********************************************************************************************************************/

int main() {
    Graph g1;
    g1.Graph_graph_init();
    g1.Graph_visited_init();
    ifstream inStream;
    inStream.open("Hw6.txt");
    int num1, num2;
    for (int i = 0; i < MAX_1; i++) {
        inStream >> num1 >> num2;
        g1.Graph_insert_1(num1, num2);
    }

    cout << "1) Graph Data 1: " << endl;
    g1.Graph_display_1();
    cout << endl;
    cout << "2) Output:\n" << "   ";
    g1.dfs_1(0);
    cout << endl;
    cout << endl;

    Graph g2;
    g2.Graph_graph_init();
    g2.Graph_visited_init();
    for (int i = 0; i < MAX_2; i++) {
        inStream >> num1 >> num2;
        g2.Graph_insert_2(num1, num2);
    }

    cout << "1) Graph Data 2: " << endl;
    g2.Graph_display_2();
    cout << endl;
    cout << "2) Output:\n" << "   ";
    g2.dfs_2(0);
    cout << endl;

    inStream.close();
}
