#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include "tree.hpp"

//CODIGO REALIZADO POR CARLOS DANIEL CHACON MENDEZ
//CEDULA: C.I 30.201.599
//SECCION 1

using namespace std;

int main (){
	ifstream archive("arbol.txt");
	int treeNumber = 1;
	
	if(!archive){
		cout<< "Archivo no disponible, intenta nuevamente"<<endl;
		return 1;
	}
	
	string line;
	
	while(getline(archive, line)){
		Node *tree = NULL;
		bool firstIsNumber =true;
    	int counter = 0;
    	int height = 0;
    	int leafs =0;
    	int loopCounter= 0;
        string leafNames[20];
        istringstream iss(line);
        string word;


        
        while(iss>>word){
        	if(firstIsNumber){
        		firstIsNumber = false;
			}else{
				insert(tree, word);
	
			}

	    }
	    
    	showBinaryTree(tree, counter);
    	
	    cout<<"\n"<<endl;
	    
	    cout<< "Impresion en PostOrden: ";
	    printInPostOrden(tree);
	    
	    cout<<"\n"<<endl;

	
	    height = calculateHeight(tree) - 1;
		leafs = calculateLeafNodes(tree, leafNames, loopCounter);
	
		cout<<"\n Altura del arbol " << treeNumber << ": " << height << endl;
		cout<<"\n Numero de hojas del arbol " << treeNumber << ": " << leafs << endl;
		
		printLeafNames(leafNames, leafs, treeNumber);
		
		if(isBalanced(tree)){
			cout<< "El arbol " << treeNumber << " esta equilibrado"<<endl;
		}else{
			cout<< "El arbol " << treeNumber << " no esta equilibrado"<<endl;
		};
		
		
		cout<<" --------------------------------------------" <<endl;
		
		treeNumber ++;
		delete tree;
	
	}
	
	
	getch();
	return 0;
}




