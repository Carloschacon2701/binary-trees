#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include "tree.hpp"

using namespace std;


Node *createNode(string n){
	Node *new_node = new Node();
	
	new_node -> data = n;
	new_node -> left = NULL;
	new_node -> right = NULL;
	
	return new_node;
};


void showBinaryTree(Node *tree, int counter){
	if(tree == NULL){
		return;
	}else{
		showBinaryTree(tree -> right, counter + 1);
		for(int i=0; i < counter; i++){
			cout<< "   ";
		}
		
		cout<< tree -> data <<endl;
		
		showBinaryTree(tree -> left, counter + 1);
		
		
	}
}

//INSERT VALUES TO THE ABB
void insert(Node *&tree, string n){
	if (tree == NULL){
		Node *new_node = createNode(n);
		
		tree = new_node;
	}else{
		string rootValue = tree -> data;
		
		if(n.length() < rootValue.length()){
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
		cout<<tree ->data<<"-";	
	}
};


int calculateLeafNodes(Node *tree, string leafNames[20], int& loopCounter){
	
	if(tree == NULL){
		return 0;
	}else if(tree->right ==NULL && tree->left == NULL){
		leafNames[loopCounter++] = tree -> data;
		return 1;
	}else{
		int rightLeafs = calculateLeafNodes(tree -> right, leafNames, loopCounter );
		int leftLeafs = calculateLeafNodes(tree->left, leafNames, loopCounter);
		
		return rightLeafs + leftLeafs;
		
	}
}

int calculateHeight(Node *tree){
	if(tree == NULL){
		return 0;
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

bool isBalanced(Node* tree) {
    if (tree == NULL) {
        return true; 
    } else {
        int leftHeight = calculateHeight(tree->left);
        int rightHeight = calculateHeight(tree->right);

        if (abs(leftHeight - rightHeight) > 1) {
            return false; 
        }

        if (!isBalanced(tree->left) || !isBalanced(tree->right)) {
            return false; 
        }
        
        return true; 
    }
}

void printLeafNames(string leafNames[20], int leafs, int treeNumber){
	cout<<"Nodos Hojas del arbol " << treeNumber << ": ";
    for(int i=0; i< leafs; i++){
    	
        if(!leafNames[i].empty()){
          cout<< leafNames[i] << " ";
        }

    }
	cout<< "\n"<<endl;
}



