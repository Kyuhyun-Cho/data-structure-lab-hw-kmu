//조규현 20191669 Lab13
#include <iostream>

using namespace std;

int check_smallest(int dist[], int n, bool found[]) {
    int i, min = INT_MAX, k;

    for (i = 0; i < n; i++) {
        if (dist[i] < min && !found[i]) {
            if (dist[i] != min) {
                min = dist[i];
                k = i;
            }
        }
    }
    return k;
}

void shortest_path(int v, int cost[6][6], int dist[], int n, bool found[]) {
    int i, u, w;
    for (i = 0; i < n; i++) {
        found[i] = false;
        dist[i] = cost[v][i];
    }
    found[v] = true;
    dist[v] = 0;
    cout << "Start from vertex 0: Distance -> ";
    for (i = 0; i < n - 1; i++) {
        for (int i = 0; i < n; i++) {
            cout << dist[i] << " ";
        }
        cout << endl;
        u = check_smallest(dist, n, found);
        found[u] = true;
        for (w = 0; w < n; w++) {
            if (!found[w]) {
                if (dist[u] + cost[u][w] < dist[w])
                    dist[w] = dist[u] + cost[u][w];
            }
        }
        cout << "Select Node: " << u <<  " Distance -> ";
    }
    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int dist[6] = { 0, };
    bool found[6];
    int dist2[6] = { 0, };
    bool found2[6];

    int matrix[6][6] = {
            {999,  20,  15, 999, 999, 999},
            {999, 999, 999, 999,  10,  30},
            {999,   4, 999, 999, 999,  10},
            {999, 999, 999, 999, 999, 999},
            {999, 999, 999,  15, 999, 999},
            {999, 999, 999,   4,  10, 999},
    };
    cout << "***** Adjacency Matrix *****" << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
    cout << "***** Shortest Path *****" << endl;
    shortest_path(0, matrix, dist, 6, found);

    cout << "\n\n\n";

    int matrix2[6][6] = {
            {999,  50,  10, 999,  45, 999},
            {999, 999,  15, 999,  10, 999},
            {20,  999, 999,  15, 999, 999},
            {999,  20, 999, 999,  35, 999},
            {999, 999, 999,  30, 999, 999},
            {999, 999, 999,   3, 999, 999},
    };
    cout << "***** Adjacency Matrix *****" << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++)
            cout << matrix2[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
    cout << "***** Shortest Path *****" << endl;
    shortest_path(0, matrix2, dist2, 6, found2);
}

/* 0   1   2   3   4   5
 0 999, 20,  25,  999, 999, 999
 1 999, 999, 999, 999, 10,  30
 2 999, 4,   999, 999, 999, 10
 3 999, 999, 999, 999, 999, 999
 4 999, 999, 999, 15,  999, 999
 5 999, 999, 999, 4,   10,  999