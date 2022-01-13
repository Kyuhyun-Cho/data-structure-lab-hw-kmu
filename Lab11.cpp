//조규현 20191669 Lab11
#include<iostream>
#define MAX_1 8
#define MAX_2 6

using namespace std;

static int graphFull_1[MAX_1][MAX_1] = {
        {0,1,1,0,0,0,0,0},
        {1,0,0,1,1,0,0,0},
        {1,0,0,0,0,1,1,0},
        {0,1,0,0,0,0,0,1},
        {0,1,0,0,0,0,0,1},
        {0,0,1,0,0,0,0,1},
        {0,0,1,0,0,0,0,1},
        {0,0,0,1,1,1,1,0}
};

static int graphFull_2[MAX_2][MAX_2] = {
        {0,1,1,0,0,0},
        {1,0,1,1,0,0},
        {1,1,0,0,0,1},
        {0,1,0,0,1,1},
        {0,0,0,1,0,1},
        {0,0,1,1,1,0},

};

class node {
private:
    int num;
    node* next;
    friend class Graph;
public:
    node(int data): num(data), next(0) {}
};

class Graph {
private:
    node* graph_1[MAX_1];
    int graphArr_1[MAX_1][MAX_1];
    bool visit_1[MAX_1];

    node* graph_2[MAX_2];
    int graphArr_2[MAX_2][MAX_2];
    bool visit_2[MAX_2];

    node *front;
    node *rear;
public:
    Graph();
    void initGraph_1();
    void printAdMatrix_1() const;
    void insertMatrix_1();
    void insertGraphM_1(int num1, int num2);
    void bfs_1(int num);

    void initGraph_2();
    void printAdMatrix_2() const;
    void insertMatrix_2();
    void insertGraphM_2(int num1, int num2);
    void bfs_2(int num);

    void enqueue(int num);
    int dequeue();

};

Graph::Graph():front(0), rear(0) {
    initGraph_1();
    initGraph_2();
}

void Graph::initGraph_1() {
    for (int a = 0; a < MAX_1; a++) {
        graph_1[a] = 0;
        visit_1[a] = false;

        for (int b = 0; b < MAX_1; b++)
            graphArr_1[a][b] = 0;
    }
}

void Graph::initGraph_2() {
    for (int a = 0; a < MAX_2; a++) {
        graph_2[a] = 0;
        visit_2[a] = false;

        for (int b = 0; b < MAX_2; b++)
            graphArr_2[a][b] = 0;
    }
}

void Graph::insertGraphM_1(int num1, int num2) {
    node* temp = new node(num2);

    if (graph_1[num1] == 0) {
        graph_1[num1] = temp;
    }
    else {
        node* p = graph_1[num1];
        node* q;

        while (p != 0 && p->num < num2) {
            q = p;
            p = p->next;
        }
        q->next = temp;
        temp->next = p;
    }
}

void Graph::insertGraphM_2(int num1, int num2) {
    node* temp = new node(num2);

    if (graph_2[num1] == 0) {
        graph_2[num1] = temp;
    }
    else {
        node* p = graph_2[num1];
        node* q;

        while (p != 0 && p->num < num2) {
            q = p;
            p = p->next;
        }
        q->next = temp;
        temp->next = p;
    }
}

void Graph::printAdMatrix_1() const {
    cout << "    ";
    for (int a = 0; a < MAX_1; a++)
        cout << 'v' << a << " ";
    cout << endl;
    for (int b = 0; b < MAX_1; b++) {
        cout << 'v' << b << "  ";
        for (int c = 0; c < MAX_1; c++) {
            cout << graphFull_1[b][c] << "  ";
        }
        cout << endl;
    }
}

void Graph::printAdMatrix_2() const {
    cout << "    ";
    for (int a = 0; a < MAX_2; a++)
        cout << 'v' << a << " ";
    cout << endl;
    for (int b = 0; b < MAX_2; b++) {
        cout << 'v' << b << "  ";
        for (int c = 0; c < MAX_2; c++) {
            cout << graphFull_2[b][c] << "  ";
        }
        cout << endl;
    }
}

void Graph::insertMatrix_1() {
    for (int a = 0; a < MAX_1; a++)
        for (int b = 0; b < MAX_1; b++) {
            if (graphFull_1[a][b]) {
                insertGraphM_1(a, b);
                graphArr_1[a][b] = graphFull_1[a][b];
            }
        }
}

void Graph::insertMatrix_2() {
    for (int a = 0; a < MAX_2; a++)
        for (int b = 0; b < MAX_2; b++) {
            if (graphFull_2[a][b]) {
                insertGraphM_2(a, b);
                graphArr_2[a][b] = graphFull_2[a][b];
            }
        }
}

void Graph::bfs_1(int num) {
    enqueue(num);
    cout << num << " ";
    visit_1[num] = true;

    while (front) {
        num = dequeue();
        int col = 0;
        for (int p = graphArr_1[num][col]; col < MAX_1; p = col++) {
            if ((!visit_1[col]) && (graphArr_1[num][col])) {
                enqueue(col);
                visit_1[col] = true;
                cout << col << " ";
            }
        }
    }
    cout << endl;
    for (int a = 0; a < MAX_1; a++)
        visit_1[a] = false;
}

void Graph::bfs_2(int num) {
    enqueue(num);
    cout << num << " ";
    visit_2[num] = true;

    while (front) {
        num = dequeue();
        int col = 0;
        for (int p = graphArr_2[num][col]; col < MAX_2; p = col++) {
            if ((!visit_2[col]) && (graphArr_2[num][col])) {
                enqueue(col);
                visit_2[col] = true;
                cout << col << " ";
            }
        }
    }
    cout << endl;
    for (int a = 0; a < MAX_2; a++)
        visit_2[a] = false;
}

void Graph::enqueue(int num) {
    node* temp = new node(num);
    if (front == 0) {
        front = temp;
        rear = front;
    }
    else {
        rear->next = temp;
        rear = temp;
    }
}

int Graph::dequeue() {
    if (front) {
        node* p = front;
        int data = p->num;

        if (front == rear) {
            front = 0;
            rear = 0;
        }
        else {
            front = front->next;
        }

        delete p;

        return data;
    }
    else
        return 0;
}

int main() {
    Graph g1;
    g1.insertMatrix_1();

    cout << "***** Adjacent Matrix *****" << endl;
    g1.printAdMatrix_1();

    cout << endl;

    cout << "Breadth First Search -> ";
    g1.bfs_1(0);

    cout << endl;
    cout << endl;

    Graph g2;
    g2.insertMatrix_2();

    cout << "** Adjacent Matrix **" << endl;
    g2.printAdMatrix_2();

    cout << endl;

    cout << "Breadth First Search -> ";
    g2.bfs_2(0);
}