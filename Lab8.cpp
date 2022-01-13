//조규현 20191669 Lab8

#include <iostream>
#include <string>

using namespace std;

class Node {
private:
    char data;
    int prio;
    Node *left;
    Node *right;
    Node(char val)
    {
        data = val;
        prio = 4;
        left = 0;
        right = 0;
    }
    friend class Tree;
};

class Tree {
private:
    Node *root;
public:
    Node *head;
    Tree() { root = 0; }
    void Buildtree(string text);
    void Operand(Node *ptr);
    void Operator(Node *ptr);
    void inorder(Node *ptr);
    void postorder(Node *ptr);
    void preorder(Node *ptr);
    int evalTree(Node *ptr);
    void displayInorder();
    void displayPostorder();
    void displayPreorder();
    void displayEvalTree();
    void Treestructure(Node *ptr);
};

char prec[4][2] = { '*', 2, '/', 2, '+', 1, '-', 1 };

void Tree::Buildtree(string op)
{
    int len = op.size();
    Node *p;
    for (int i = 0; i < len; i++)
    {
        p = new Node(op[i]);
        for (int j = 0; j < 4; j++)
        {
            if (p->data == prec[j][0])
                p->prio = prec[j][1];
        }
        if (p->prio == 4)
            Operand(p);
        else
            Operator(p);
    }
}

void Tree::Operand(Node *ptr) {
    if (root == NULL)
        root = ptr;
    else
    {
        Node *p = root;
        while (p->right != NULL)
            p = p->right;
        p->right = ptr;
    }
}

void Tree::Operator(Node *ptr) {
    if (root->prio >= ptr->prio) {
        ptr->left = root;
        root = ptr;
    }
    else {
        ptr->left = root->right;
        root->right = ptr;
    }
}

void Tree::inorder(Node *ptr) {
    if (ptr) {
        inorder(ptr->left);
        cout << ptr->data;
        inorder(ptr->right);
    }
}

void Tree::postorder(Node *ptr) {
    if (ptr) {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->data;
    }
}

void Tree::preorder(Node *ptr) {
    if (ptr) {
        cout << ptr->data;
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
void Tree::Treestructure(Node *ptr) {
    if (ptr!=NULL) {
        if (!isdigit(ptr->data)) cout << "(";

        Treestructure(ptr->left);
        cout << ptr->data;
        Treestructure(ptr->right);

        if (!isdigit(ptr->data)) cout << ")";

    }
}

int Tree::evalTree(Node *ptr) {
    int value = 0, left, right;
    if (ptr != NULL) {
        if (ptr->data >= '0' && ptr->data <= '9')
            value = ptr->data - '0';
        else {
            left = evalTree(ptr->left);
            right = evalTree(ptr->right);
            switch (ptr->data) {
                case '+':
                    value = left + right;
                    break;
                case '-':
                    value = left - right;
                    break;
                case '*':
                    value = left * right;
                    break;
                case '/':
                    value = left / right;
                    break;
            }
        }
    }
    else
        cout << "Empty tree" << endl;

    return value;
}

void Tree::displayInorder() {
    cout << "Inorder: ";
    inorder(root);
}

void Tree::displayPostorder() {
    cout << "Postorder: ";
    postorder(root);
}

void Tree::displayPreorder() {
    cout << "Preorder: ";
    preorder(root);
}

void Tree::displayEvalTree() {
    cout << "Evaluation: ";
    cout << evalTree(root);
}

int main() {
    string str1;
    string str2;

    Tree tree1;
    cout << "Infix Expression1: ";
    cin >> str1;
    cout << endl;
    tree1.Buildtree(str1);
    tree1.displayInorder();
    cout << endl;
    tree1.displayPostorder();
    cout << endl;
    tree1.displayPreorder();
    cout << endl;
    tree1.displayEvalTree();
    cout << endl;

    cout << endl;

    Tree tree2;
    cout << "Infix Expression2: ";
    cin >> str2;
    cout << endl;
    tree2.Buildtree(str2);
    tree2.displayInorder();
    cout << endl;
    tree2.displayPostorder();
    cout << endl;
    tree2.displayPreorder();
    cout << endl;
}