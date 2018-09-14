
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

};