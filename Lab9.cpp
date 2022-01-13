//조규현 20191669 Lab9

#include<iostream>
#include<string>

using namespace std;

class Node {
private:
    int data;
    Node* right;
    Node* left;
    friend class Tree;
};

class Tree {
public:
    Node* root;
    int first = 0;
    int count = 0;

public:
    Tree() { root = NULL; }
    Node* insert_(Node* p, int data);
    Node* delete_BST(Node* ptr, int data);
    void search_(int data);
    Node* search_BST(Node* ptr, int data);
    Node* find_max(Node* ptr);
    void drawTree() { drawTree_BST(root, 1); };
    void drawTree_BST(Node* ptr, int level);
    int leaves(Node* p, int count);
    int Nonleaves(Node* p, int count);
    void Numofnodes();
    bool printlevel(Node* ptr, int level);
    void levelorder();
};

void Tree::levelorder() {
    int level = 1;
    Node* temp = root;
    if (root == NULL) cout << "Tree is Empty" << endl;
    else {
        while (printlevel(temp, level)) level++;
        cout << endl;
    }
}


bool Tree::printlevel(Node* ptr, int level) {
    if (ptr == NULL) {
        return false;
    }
    if (level == 1) {
        cout << ptr->data << " ";
        return true;
    }
    else {
        bool left = printlevel(ptr->left, level - 1);
        bool right = printlevel(ptr->right, level - 1);
        return (left || right);
    }
}

void Tree::Numofnodes() {
    cout << "Number of leaves: " << leaves(root, count) << " ";
    cout << "Number of Nonleaves: " << Nonleaves(root, count) << endl;
}

int Tree::leaves(Node* p, int count) {
    count = 0;
    if (p != NULL) {
        if (p->left == NULL && p->right == NULL) count++;
        else {
            count = leaves(p->left, count) + leaves(p->right, count);
        }
    }
    else count = 0;
    return count;
}

int Tree::Nonleaves(Node* p, int count) {
    count = 0;
    if (p != NULL) {
        if (p->left == NULL && p->right == NULL) count = 0;
        else count = Nonleaves(p->left, count) + Nonleaves(p->right, count) + 1;
    }
    else count = 0;
    return count;
}



void Tree::drawTree_BST(Node* ptr, int level) {
    if (ptr != 0 && level <= 7) {
        drawTree_BST(ptr->right, level + 1);

        for (int i = 1; i <= (level - 1); i++) cout << "      ";
        cout << ptr->data;

        if (ptr->left != 0 && ptr->right != 0) cout << " <" << endl;
        else if (ptr->right != 0) cout << " <" << endl;
        else if (ptr->left != 0) cout << " <" << endl;
        else cout << endl;

        drawTree_BST(ptr->left, level + 1);
    }
}

Node* Tree::find_max(Node* ptr) {
    if (ptr == NULL) return NULL;
    else if (ptr->right == NULL) return ptr;
    else return find_max(ptr);
}

Node* Tree::delete_BST(Node* ptr, int key) {
    if (ptr != NULL) {
        if (key < ptr->data)
            ptr->left = delete_BST(ptr->left, key);
        else if (key > ptr->data)
            ptr->right = delete_BST(ptr->right, key);
        else if ((ptr->left == NULL) && (ptr->right == NULL))
            ptr = NULL;
        else if (ptr->left == NULL) {
            Node* p = ptr;
            ptr = ptr->right;
            delete(p);
        }
        else if (ptr->right == NULL) {
            Node* p = ptr;
            ptr = ptr->left;
            delete(p);
        }
        else {
            Node* temp = find_max(ptr->left);
            ptr->data = temp->data;
            ptr->left = delete_BST(ptr->left, ptr->data);
        }
    }
    return ptr;
}

void Tree::search_(int data) {
    Node* ptr = root;
    if (search_BST(ptr, data) != NULL) cout << "Found" << endl;
    else cout << "Not Found" << endl;
}

Node* Tree::search_BST(Node* ptr, int data) {
    if (ptr == NULL) return ptr;
    else {
        if (data == ptr->data) return ptr;
        else if (data < ptr->data) ptr = search_BST(ptr->left, data);
        else if (data > ptr->data) ptr = search_BST(ptr->right, data);
    }
    return ptr;
}

Node* Tree::insert_(Node* ptr, int data) {
    Node* temp = NULL;
    if (ptr == NULL && first == 0) {
        temp = new Node();
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
        first = 1;
        return temp;
    }
    else if (ptr == NULL) {
        temp = new Node();
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    else if (data < ptr->data) ptr->left = insert_(ptr->left, data);
    else if (data > ptr->data) ptr->right = insert_(ptr->right, data);
    return ptr;
}

int main() {
    Tree bsttree;
    int num;
    int t;

    while (true) {
        cout << "1.Insert 2.Delete 3.Search 4.Traverse 5.NumofNodes 6.Print 7.Quit: ";
        cin >> t;

        switch (t) {
            case 1: {
                cout << "Enter number to insert: ";
                cin >> num;
                Node* p = bsttree.root;
                bsttree.insert_(p, num);
                break;
            }
            case 2: {
                Node* p = bsttree.root;
                if (p == NULL) {
                    cout << "Tree is "
                            "Empty" << endl;
                }
                else {
                    cout << "Enter number to delete: ";
                    cin >> num;
                    bsttree.delete_BST(p, num);
                }
                break;
            }
            case 3: {
                cout << "Enter number to search: ";
                cin >> num;
                bsttree.search_(num);
                break;
            }
            case 4: {
                Node* p = bsttree.root;
                bsttree.levelorder();
                break;
            }
            case 5: {
                Node* p = bsttree.root;
                bsttree.Numofnodes();
                break;
            }
            case 6: {
                Node* p = bsttree.root;
                if (p == NULL) {
                    cout << "Tree is Empty" << endl;
                }
                else {
                    bsttree.drawTree();
                }
                break;
            }
            case 7: {
                return 0;
            }
        }
    }
}