
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
    node* root;

    bst(){root = NULL;}
    void insert(string data, string syn);
};

void bst::insert(string data, string syn) {
    node* newNode = new node();
    newNode->data = data;
    newNode->syn = syn;
    if(root == NULL){
        root = newNode;
    } else{
        node* tempNode = new node();
        node* backTempNode = new node();
        tempNode = root;
        while (tempNode != NULL){
            backTempNode = tempNode;
            if(tempNode->data <= newNode->data){
                tempNode = tempNode->rightChild;
            } else{
                tempNode = tempNode->leftChild;
            }
        }
        newNode->parent = backTempNode;
        if(backTempNode->data <= newNode->data){
            backTempNode->rightChild = newNode;
        } else{
            backTempNode->leftChild = newNode;
        }
    }
}