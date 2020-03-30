/*
    Beginning with an empty binary search tree, Construct binary search tree by inserting the
    values in the order given. After constructing a binary tree -
    i. Insert new node
    ii. Find number of nodes in longest path
    iii. Minimum data value found in the tree
    iv. Change a tree so that the roles of the left and right pointers are swapped at
    every node
    v. Search a value
*/

#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *left, *right;

    node(int d = 0){
        data = d;
        left = right = NULL;
    }
};

class BST{
public:
    node *root;

    node *ins(node*, int);
    node *createNode(int);
    void inorder(node*);
    node *Search(node*, int);
    int min_value(node*);
    int depth(node*);
    void mirror(node*);

    BST(){
        root = NULL;
    }
};

void BST::mirror(node *temp){
    if(temp == NULL)
        return;
    else{
        node *temp2;
        mirror(temp->left);
        mirror(temp->right);
        temp2 = temp->left;
        temp->left = temp->right;
        temp->right = temp2;
    }
}

int BST::depth(node *temp){
    if(temp == NULL)
        return 0;
    else{
        return (max(depth(temp->left), depth(temp->right)) + 1);
    }
}

int BST::min_value(node *temp){
    if(temp == NULL)
    {
        return 0;
        cout<<"Empty Tree"<<endl;
    }
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}

node* BST::Search(node *temp, int key){
    if(temp == NULL || temp->data == key)
        return temp;
    else if(key < temp->data){
        Search(temp->left, key);
    }
    else{
        Search(temp->right, key);
    }
}

void BST::inorder(node *temp){
    if(temp != NULL){
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }
}

node* BST::createNode(int key){
    node *temp = new node(key);
    return temp;
}

node* BST::ins(node *temp, int key){

    if(temp == NULL)
        return createNode(key);
    else if(key < temp->data){
        temp->left = ins(temp->left, key);
    }
    else{
        temp->right = ins(temp->right, key);
    }

    return temp;
}

int main(){

    BST tree;

    tree.root = tree.ins(tree.root, 50);
    tree.ins(tree.root, 30);
    tree.ins(tree.root, 20);
    tree.ins(tree.root, 40);
    tree.ins(tree.root, 70);
    tree.ins(tree.root, 60);
    tree.ins(tree.root, 80);

    tree.inorder(tree.root);

    tree.mirror(tree.root);

    tree.inorder(tree.root);

    return 0;
}
