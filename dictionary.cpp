//Name:		BST dictionary
//Author:	Soran Ghadri
//Date:		December 2015

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

	node(){
		data = '0';
		syn = '0';
		parent = NULL;
		leftChild = NULL;
		rightChild = NULL;
	}
};

class bst {
public:
	node* root;

	bst(){ root = NULL; }
	void insert(string data, string);
	void display(node*, int);
	node* search1(string data);
	node* search2(string syn);
	void bst::deletion(node *z);
	void bst::transplant(node* u, node* v);
	node* bst::successor(node* currentNode);

};

void bst::insert(string data, string syn)
{
	node* newNode = new node();
	newNode->data = data;
	newNode->syn = syn;
	if (root == NULL)
	{
		root = newNode;
	}
	else
	{
		node* tempNode = new node();
		node* backTempNode = new node();
		tempNode = root;

		while (tempNode != NULL)
		{
			backTempNode = tempNode;
			if (tempNode->data <= newNode->data)
			{
				tempNode = tempNode->rightChild;
			}
			else
			{
				tempNode = tempNode->leftChild;
			}
		}

		newNode->parent = backTempNode;
		if (backTempNode->data <= newNode->data)	{
			backTempNode->rightChild = newNode;
		}
		else
		{
			backTempNode->leftChild = newNode;
		}
	}
}

void bst::display(node *Node, int level)
{
	if (root == NULL)
	{
		cout << "Dictionary is empty." << endl;
	}
	else
	{
		if (Node->rightChild != NULL)
		{
			display(Node->rightChild, level + 1);
		}

		if (Node != root)
		{
			for (int i = 0; i < level + 1; i++)
			{
				cout << "      ";
			}
		}
		else
		{
			cout << "Root->";
		}

		cout << Node->data << ":" << Node->syn << endl;

		if (Node->leftChild != NULL)
		{
			display(Node->leftChild, level + 1);
		}
	}

}

node* bst::search1(string Data)
{
	node* tempNode = new node();
	tempNode = root;
	while (tempNode != NULL)
	{
		if (tempNode->data == Data)
		{
			return tempNode;
		}
		else
		{
			if (tempNode->data <= Data)
			{
				tempNode = tempNode->rightChild;
			}
			else
			{
				tempNode = tempNode->leftChild;
			}
		}
	}
	return NULL;
}

node* bst::search2(string syn)
{
	node* tempNode = new node();
	tempNode = root;
	while (tempNode != NULL)
	{
		if (tempNode->syn == syn)
		{
			return tempNode;
		}
		else
		{
			if (tempNode->syn <= syn)
			{
				tempNode = tempNode->rightChild;
			}
			else
			{
				tempNode = tempNode->leftChild;
			}
		}
	}
	return NULL;
}


node* bst::successor(node* currentNode)
{
	node* tempNode = new node();
	node* backTempNode = new node();
	tempNode = currentNode;

	if (tempNode->rightChild != NULL)
	{
		tempNode = tempNode->rightChild;
		while (tempNode != NULL)
		{
			backTempNode = tempNode;
			tempNode = tempNode->leftChild;
		}
		return backTempNode;
	}
	else
	{
		backTempNode = tempNode;
		tempNode = tempNode->parent;
		while (tempNode != NULL && tempNode->rightChild == backTempNode)
		{
			backTempNode = tempNode;
			tempNode = tempNode->parent;
		}
		return tempNode;
	}
}


void bst::transplant(node* u, node* v)
{
	if (u->parent == NULL)
	{
		root = v;
	}
	else
	{
		if (u == u->parent->leftChild)
		{
			u->parent->leftChild = v;
		}
		else
		{
			u->parent->rightChild = v;
		}
	}
	if (v != NULL)
	{
		v->parent = u->parent;
	}
}


void bst::deletion(node *z)
{
	if (z->leftChild == NULL)
	{
		transplant(z, z->rightChild);
	}
	else
	{
		if (z->rightChild == NULL)
		{
			transplant(z, z->leftChild);
		}
		else
		{
			node* succesor = new node();
			succesor = successor(z);
			if (succesor->parent != z)
			{
				transplant(succesor, succesor->rightChild);
				succesor->rightChild = z->rightChild;
				succesor->rightChild->parent = succesor;
			}
			transplant(z, succesor);
			succesor->leftChild = z->leftChild;
			succesor->leftChild->parent = succesor;
		}
	}
	delete z;
}



void menu()
{
	char ch;
	string inttemp;
	string p;
	node *temp = new node();
	bst myTree;
	int select;
	do
	{
		system("CLS");
		cout << "0. Exit" << endl;
		cout << "1. Insert" << endl;
		cout << "2. Display" << endl;
		cout << "3. English Search" << endl;
		cout << "4. Persion Search" << endl;
		cout << "5. Delete" << endl;
		cout << endl << "Enter your selection:" << endl;
		cin >> select;
		system("CLS");

		switch (select)
		{
		case 0:
		{
			break;
		}
		case 1:
		{
			do
			{
				string data;
				string syn;
				cout << "Enter the word (English,Pesion meaning): ";
				cin >> data >> syn;
				myTree.insert(data, syn);
				cout << endl << "Do you want another word? [y or n]" << endl;
				cin >> ch;
			} while (ch != 'n');
			break;
		}
		case 2:
		{
			myTree.display(myTree.root, 0);
			cout << endl << "Press 0 to continue!" << endl;
			cin >> ch;
			break;
		}
		case 3:
		{
			cout << "Enter English word:";
			cin >> inttemp;
			temp = myTree.search1(inttemp);
			if (temp != NULL)
			{
				cout << temp->data << ": " << temp->syn << endl;
			}
			else
			{
				cout << "It isn't in Dictionary!" << endl;
			}

			cout << endl << "Press 0 to continue!" << endl;
			cin >> ch;
			break;
		}
		case 4:{
			cout << "Enter Persion word:";
			cin >> p;
			temp = myTree.search2(p);
			if (temp != NULL)
			{
				cout << temp->syn << ": " << temp->data << endl;
			}
			else
			{
				cout << "It isn't in Dictionary!" << endl;
			}

			cout << endl << "Press 0 to continue!" << endl;
			cin >> ch;
			break;
		}
		case 5:{
			cout << "Enter the word that you want delete: ";
			cin >> inttemp;
			temp = myTree.search1(inttemp);
			if (temp == NULL)
			{
				cout << inttemp << " isn't in Dictionary" << endl;
			}
			else
			{
				myTree.deletion(temp);
				cout << inttemp << " removed from Dictionary." << endl;
			}
			cout << endl << "Press 0 to continue!" << endl;
			cin >> ch;
			break;
		}
		default:
			break;
		}

	} while (select != 0);
}

int main()
{

	menu();
	return 0;
}