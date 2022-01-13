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

bool AdjacentList::addNode(char v1, char v2, int cost) {
    Node *newNode;
    newNode = new Node(v1, v2, cost);

    if (newNode == NULL)
        return false;
    newNode->next = list[v1 - 'A'];
    list[v1 - 'A'] = newNode;

    newNode = new Node(v2, v1, cost);

    if (newNode == NULL) {
        free(list[v1 - 'A']);
        return false;
    }

    newNode->next = list[v2 - 'A'];
    list[v2 - 'A'] = newNode;

    return true;
}

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

void Kruskal::printData() {
    Node *now = kruskal;

    while (now != NULL) {
        cout << now->start << now->cost << now->end;
        cout << ", ";
        now = now->next;
    }
    cout << endl;
}

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

int Kruskal::getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void Kruskal::unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

bool Kruskal::findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) return true;
    else return false;
}

void Kruskal::kruskalAlgo() {
    int sum = 0;
    Node *now;
    int turn = 1;
    for (now = kruskal; now != NULL; now = now->next) {
        if (!findParent(now->start - 'A', now->end - 'A')) {
            sum += now->cost;
            cout << turn << ") " << "Edge" << turn++ << ": " << now->start << now->cost << now->end << endl;
            unionParent(now->start - 'A', now->end - 'A');
        }
    }
    cout << endl << "Total Cost: " << sum << endl;
}

int main() {
    ifstream inStream;
    inStream.open("Lab12-2.txt");

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

    cout << "Original Data: " << endl;
    kp.printData();
    cout << endl;

    cout << "Sorted Data: " << endl;
    kp.sortData();
    kp.printData();
    cout << endl;

    cout << "Kruskal's MST: " << endl;
    kp.kruskalAlgo();
}