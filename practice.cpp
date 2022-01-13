//조규현 20191669 Lab12
#include <iostream>
#include <string>

#define MaxVertices 50
#define MAX 7

using namespace std;

class Graph {
private:
    bool visited[MaxVertices];
    int countEdge = 0;
    int totalWeight = 0;
public:
    void initGraph();
    void displayGraph();
    void prim(int v);
};

int cost[MAX][MAX] = {
        {100, 100, 40, 100, 100, 30, 15},
        {100, 100, 17, 19, 10, 100, 100},
        {40, 17, 100, 20, 100, 100, 20},
        {100, 19, 20, 100, 100, 100, 100},
        {100, 10, 100, 100, 100, 14, 30},
        {30, 100, 100, 100, 14, 100, 12},
        {15, 100, 20, 100, 30, 12, 100},
};

string vertex[MAX] = {"A", "B", "C", "D", "E", "F", "G"};

void Graph::initGraph() {
    for (int i = 0; i < MaxVertices; i++) {
        visited[i] = false;
    }
}

void Graph::displayGraph() {
    cout << "    A  B  C  D  E  F  G" << endl;
    for (int i = 0; i < MAX; i++) {
        cout << vertex[i] << "	";
        for (int j = 0; j < MAX; j++) {
            cout << cost[i][j] << "	";
        }
        cout << endl;
    }
}

void Graph::prim(int v) {
    int min = 100;
    int minidx;
    for (int i = 0; i < MAX; i++) {
        if (cost[v][i] < min && visited[i] != true) {
            min = cost[v][i];
            minidx = i;
        }
    }
    totalWeight += min;
    cout << v + 1 << "," << minidx + 1;
    visited[v] = true;
    if (countEdge < 5) {
        cout << " -> ";
    }
    else {
        cout << " (Total Weight: " << totalWeight << ")" << endl;
    }
    countEdge++;
    if (countEdge < 6) {
        prim(minidx);
    }
}

int main() {
    Graph g;
    g.initGraph();

    cout << "1) Weighted Graph" << endl;
    g.displayGraph();
    cout << endl;

    cout << "2) Minimal Spanning Tree " << endl;
    g.prim(0);
}