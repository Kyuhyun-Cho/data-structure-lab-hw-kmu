//조규현 20191669 Lab12
#include <iostream>
#include <string>

#define MaxVertices 50
#define MAX 6

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
        {100, 6, 1, 5, 100, 100},
        {6, 100, 4, 100, 3, 100},
        {1, 4, 100, 5, 6, 5},
        {5, 100, 5, 100, 100, 2},
        {100, 3, 6, 100, 100, 6},
        {100, 100, 5, 2, 6, 100}
};

string vertex[6] = {"v1", "v2", "v3", "v4", "v5", "v6"};

void Graph::initGraph() {
    for (int i = 0; i < MaxVertices; i++) {
        visited[i] = false;
    }
}

void Graph::displayGraph() {
    cout << "    v1  v2  v3  v4  v5  v6" << endl;
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
    for (int i = 0; i < 6; i++) {
        if (cost[v][i] < min && visited[i] != true) {
            min = cost[v][i];
            minidx = i;
        }
    }
    totalWeight += min;
    cout << v + 1 << "," << minidx + 1;
    visited[v] = true;
    if (countEdge < 4) {
        cout << " -> ";
    }
    else {
        cout << " (Total Weight: " << totalWeight << ")" << endl;
    }
    countEdge++;
    if (countEdge < 5) {
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