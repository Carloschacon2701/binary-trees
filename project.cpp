#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

void menu();
Nodo *createNode(int);
void insert(Node *&, int);
void printInPostOrden(Node *);
int calculateHeight(Node *);

Node *tree = NULL;

int main (){
	
	getch();
	return 0;
}


//MENU 

//FUNCTIONS 
Node *createNode(int n){
	Node *new_node = new Node();
	
	new_node -> data = n;
	new_node -> left = NULL;
	new_node -> right = NULL;
};

//INSERT VALUES TO THE ABB
void insert(Node *&tree, int n){
	if (tree == NULL){
		Nodo *new_node = createNode(n);
		
		tree = new_node;
	}else{
		int rootValue = tree -> data;
		
		if(n < rootValue){
			insert(tree -> left, n);
		}else{
			insert(tree -> right, n);
		}
	}
};

void printInPostOrden(Node *tree){
	if(tree == NULL){
		return;
	}
	else{
		printInPostOrden(tree -> left);
		printInPostOrden(tree -> right);
		cout<<arbol ->dato<<"-";	
	}
};

int calculateHeight(Node *tree){
	if(tree -> NULL){
		return -1;
	}else{
		int leftHeight = calculateHeight(tree -> left);
		int rightHeight = calculateHeight(tree -> right);
		
		if(leftHeight > rightHeight){
			return leftHeight + 1;
		}else{
			return rightHeight + 1;
		}
		
	}
};


