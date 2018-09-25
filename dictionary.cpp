
# include <iostream>
# include <iomanip>
# include <string>
# include <math.h>
# include <fstream>

using namespace std;

class node {
public:
    string data;
    string syn;
    node *parent;
    node *leftChild;
    node *rightChild;

    node() {
        data = "0";
        syn = "0";
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }
};

class bst {
public:
    node *root;

    bst() { root = NULL; }

    void insert(string data, string);

    void display(node *, int);

    node *search1(string data);

    node *search2(string data);

    node *successor(node *currentNode);
};

void bst::insert(string data, string syn) {
    node *newNode = new node();
    newNode->data = data;
    newNode->syn = syn;
    if (root == NULL) {
        root = newNode;
    } else {
        node *tempNode = new node();
        node *backTempNode = new node();
        tempNode = root;
        while (tempNode != NULL) {
            backTempNode = tempNode;
            if (tempNode->data <= newNode->data) {
                tempNode = tempNode->rightChild;
            } else {
                tempNode = tempNode->leftChild;
            }
        }
        newNode->parent = backTempNode;
        if (backTempNode->data <= newNode->data) {
            backTempNode->rightChild = newNode;
        } else {
            backTempNode->leftChild = newNode;
        }
    }
}

void bst::display(node *Node, int level) {
    if (root == NULL) {
        cout << "Dictionary is empty.\n";
    } else {
        if (Node->rightChild = NULL) {
            display(Node->rightChild, level + 1);
        }
        if (Node != root) {
            for (int i = 0; i < level; i++) {
                cout << "     ";
            }
        } else {
            cout << "Root->";
        }
        cout << Node->data << ": " << Node->syn << endl;
        if (Node->leftChild != NULL) {
            display(Node->leftChild, level + 1);
        }
    }
}

node *bst::search1(string data) {
    node *tempNode = new node();
    tempNode = root;
    while (tempNode != NULL) {
        if (tempNode->data == data) {
            return tempNode;
        } else {
            if (tempNode->data <= data) {
                tempNode = tempNode->rightChild;
            } else {
                tempNode = tempNode->leftChild;
            }
        }
    }
    return NULL;
}

node *bst::search2(string syn) {
    node *tempNode = new node();
    tempNode = root;
    while (tempNode != NULL) {
        if (tempNode->syn == syn) {
            return tempNode;
        } else {
            if (tempNode->syn <= syn) {
                tempNode = tempNode->rightChild;
            } else {
                tempNode = tempNode->leftChild;
            }
        }
    }
    return NULL;
}

node *bst::successor(node *currentNode) {
    node *tempNode = new node();
    node *backTempNode = new node();
    tempNode = currentNode;
}