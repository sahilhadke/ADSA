/*
    ====================
    GROUP A ASSIGNMENT 2
    ====================
        Sahil Hadke
            16
    ====================
    QUESTION :  Beginning with an empty binary search tree, Construct binary search tree by inserting the
                values in the order given. After constructing a binary tree -
                i.   Insert new node
                ii.  Find number of nodes in longest path
                iii. Minimum data value found in the tree
                iv.  Change a tree so that the roles of the left and right pointers are swapped at
                     every node
                v.   Search a value
*/

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;
    Node(int d = 0){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class BST{
public:
    Node *root, *temp;

    BST(){
        root = NULL;
        temp = root;
    }

    Node* insert_data(int, Node*);
    void inorder_rec(Node*);
    void preorder_rec(Node*);
    void postorder_rec(Node*);
    void minNode(Node*);
    void maxNode(Node*);
    int depth(Node*);
    int Search(Node*, int);
    void invertTree(Node*);
};

void BST::invertTree(Node *r){
    if(r == NULL)
        return;

    Node* temp;
    invertTree(r->left);
    invertTree(r->right);

    temp = r->right;
    r->right = r->left;
    r->left = temp;
}

int BST::Search(Node *r, int d){
    if(r == NULL){
        return 0;
    }

    if(r->data == d){
        return 1;
    }

    if(d < r->data)
        return Search(r->left, d);
    return Search(r->right, d);
}

int BST::depth(Node *r){
    if(r == NULL)
    {
        return 0;
    }

    int ldepth = depth(r->left);
    int rdepth = depth(r->right);

    if(ldepth > rdepth)
        return ldepth+1;
    return rdepth+1;
}

Node* BST::insert_data(int d, Node *rt){
    if(rt == NULL){
        return new Node(d);
    }

    if(d > rt->data){
        rt->right = insert_data(d, rt->right);
    }
    else{
        rt->left = insert_data(d, rt->left);
    }

    return rt;
}

void BST::inorder_rec(Node *r){
    if(r == NULL){
        return;
    }

    inorder_rec(r->left);
    cout<<r->data<<endl;
    inorder_rec(r->right);
}

void BST::preorder_rec(Node *r){
    if(r == NULL){
        return;
    }

    cout<<r->data<<endl;
    preorder_rec(r->left);
    preorder_rec(r->right);
}

void BST::postorder_rec(Node *r){
    if(r == NULL){
        return;
    }

    postorder_rec(r->left);
    postorder_rec(r->right);
    cout<<r->data<<endl;
}

void BST::minNode(Node *r){

    if(r == NULL){
        cout<<"EMPTY TREE"<<endl;
        return;
    }

    if(r->left == NULL){
        cout<<"Minimum Value is :"<<r->data;
        return;
    }

    if(r->left != NULL)
    {
        minNode(r->left);
    }
}

void BST::maxNode(Node *r){

    if(r == NULL){
        cout<<"EMPTY TREE"<<endl;
        return;
    }

    if(r->right == NULL){
        cout<<"Maximum Value is :"<<r->data;
        return;
    }

    if(r->right != NULL)
    {
        maxNode(r->right);
    }
}

int main(){

    BST tree;

    tree.root = tree.insert_data(4, tree.root);
    tree.root = tree.insert_data(2, tree.root);
    tree.root = tree.insert_data(8, tree.root);
    tree.root = tree.insert_data(1, tree.root);
    tree.root = tree.insert_data(5, tree.root);


    tree.postorder_rec(tree.root);

    tree.invertTree(tree.root);

    cout<<endl;

    tree.postorder_rec(tree.root);

    return 0;
}
