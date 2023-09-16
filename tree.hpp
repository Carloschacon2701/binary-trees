#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Node{
	string data;
	Node *left;
	Node *right;
};

void menu();
Node *createNode(string);
void insert(Node *&, string);
void printInPostOrden(Node *);
void showBinaryTree(Node *, int);
void printLeafNames(string[20], int, int);
int calculateHeight(Node *);
int calculateLeafNodes(Node *, string[20], int&);
bool isBalanced(Node*);


