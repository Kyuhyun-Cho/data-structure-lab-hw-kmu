//조규현 20191669 Lab11-1
#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 8;

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
    Node* graph[MAX];
    bool visited[MAX];
    Node* front;
    Node* rear;
public:
    Graph() :front(NULL), rear(NULL) {}
    void Graph_graph_init();
    void Graph_visited_init();
    void Graph_insert(int num1, int num2);
    void Graph_display();
    void dfs(int v);
};

void Graph::Graph_graph_init() {
    for (int i = 0; i < MAX; i++)
        graph[i] = NULL;
}

void Graph::Graph_visited_init() {
    for (int i = 0; i < MAX; i++)
        visited[i] = 0;
}

void Graph::Graph_insert(int num1, int num2) {
    if (graph[num1] == NULL) {
        Node* temp_1 = new Node(num1);
        graph[num1] = temp_1;
    }
    if (graph[num2] == NULL) {
        Node* temp_2 = new Node(num2);
        graph[num2] = temp_2;
    }

    Node* p = graph[num1];
    Node* temp1 = new Node(num2);
    while (p->next != NULL)
        p = p->next;
    p->next = temp1;

    p = graph[num2];
    Node* temp2 = new Node(num1);
    while (p->next != NULL)
        p = p->next;
    p->next = temp2;
}

void Graph::Graph_display() {
    for (int i = 0; i < MAX; i++) {
        if (graph[i] != NULL) {
            Node* p = graph[i];
            cout << "   V";
            while (p != NULL) {
                cout << p->vertex << " ";
                p = p->next;
            }
            cout << endl;
        }
    }
}

void Graph::dfs(int v) {
    Node* p;
    visited[v] = 1;
    cout << "V" << v << " ";

    for (p = graph[v]; p; p = p->next) {
        if (!visited[p->vertex])
            dfs(p->vertex);
    }
}

int main() {
    Graph g;
    g.Graph_graph_init();
    g.Graph_visited_init();
    ifstream inStream;
    inStream.open("Lab11_extra1.txt");
    int num1, num2;
    for (int i = 0; i < MAX; i++) {
        inStream >> num1 >> num2;
        g.Graph_insert(num1, num2);
    }

    cout << "1) Graph Data: " << endl;
    g.Graph_display();
    cout << endl;
    cout << "2) Depth First Search Output(starting from V0):\n" << "   ";
    g.dfs(0);
    cout << endl;
    inStream.close();
}
