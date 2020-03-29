/*
===================
	Practical 1
===================
Sahil Hadke
16

A book consists of chapters, chapters consist of sections and sections consist of subsections. Construct a tree and print the nodes.  Find the time and space requirements of your method.
*/
#include<iostream>
using namespace std;

class node{
public:
	string label;
	int child_count;
	node *child[10];
};

class BTree{
public:
	node *root;
	void create();
	void display();

	BTree(){
		root = NULL;
	}
};

void BTree::create(){
	cout<<endl<<endl<<endl;
	cout<<"CREATING"<<endl;
	root = new node;
	cout<<"Enter the name of book :";
	cin>>root->label;
	cout<<"Enter number of chapters in the book :";
	cin>>root->child_count;

	for(int i = 0; i < root->child_count; i++){
		root->child[i] = new node;
		cout<<"Enter the name of chapter "<<i+1<<" :";
		cin>>root->child[i]->label;
		cout<<"Enter the number of sections in chapter "<<i+1<<" :";
		cin>>root->child[i]->child_count;

		for(int j = 0; j < root->child[i]->child_count; j++){
			root->child[i]->child[j] = new node;
			cout<<"Enter the name of section "<<j+1<<" in chapter "<<i+1<<" :";
			cin>>root->child[i]->child[j]->label;
			cout<<"Enter the number of sub-section in section "<<j+1<<" of chapter "<<i+1<<" :";
			cin>>root->child[i]->child[j]->child_count;	

			for(int k = 0; k < root->child[i]->child[j]->child_count; k++){
				root->child[i]->child[j]->child[k] = new node;
				cout<<"Enter the name of sub-section "<<k+1<<" in section "<<j+1<<" :";
				cin>>root->child[i]->child[j]->child[k]->label;
			}
		}
	}
}

void BTree::display(){
	cout<<endl<<endl<<endl;
	cout<<"DISPLAYING"<<endl;

	//Name		
	cout<<"The name of book is :"<<root->label<<endl;
	
	//Chapters
	for(int i = 0; i < root->child_count; i++){
		cout<<i+1<<". "<<root->child[i]->label<<endl;

		//Sections
		for(int j = 0; j < root->child[i]->child_count; j++){
			cout<<" "<<j+1<<". "<<root->child[i]->child[j]->label<<endl;
			
			//Subsections
			for(int k = 0; k < root->child[i]->child[j]->child_count; k++){
				cout<<"  "<<k+1<<". "<<root->child[i]->child[j]->child[k]->label<<endl;
			}
		}
	}
};

int main(){
	
	int choice, while_condition = 1;
	BTree b;
	
	while(while_condition){
		
		cout<<"1. Create\n2. Display\n3. Exit"<<endl;
		cout<<"Enter your choice :";
		cin>>choice;

		switch(choice){
			case 1:
				b.create();
				break;
			case 2:
				b.display();
				break;
			default:
				while_condition = 0;
				break;
		}		
	}
	
	return 0;
}

















