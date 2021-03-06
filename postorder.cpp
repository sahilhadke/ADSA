#include<iostream>
#include<stack>
using namespace std;

class node{
public:
    char data;
    node *left, *right;

    node(char d){
        data = d;
        left = right = NULL;
    }
};

class BTree{
public:
    node *root;

    BTree(){
        root = NULL;
    }

    node* CreateNode(char d){
        node *newnode = new node(d);
        return newnode;
    }

    node *ins(node *temp, char d){
        if(temp == NULL){
            temp = CreateNode(d);
        }
        else{
            char choice;
            cout<<"The current node is "<<temp->data<<", do you want to insert to left or right?(L/R) :";
            cin>>choice;

            if(choice == 'L' || choice == 'l'){
                temp->left = ins(temp->left, d);
            }else{
                temp->right = ins(temp->right, d);
            }
        }
        return temp;
    }

    void inorder(node *temp){
        if(temp != NULL){
            inorder(temp->left);
            cout<<temp->data<<" ";
            inorder(temp->right);
        }
    }

    void preorder(node *temp){
        if(temp != NULL){
            cout<<temp->data<<" ";
            preorder(temp->left);
            preorder(temp->right);
        }
    }

    void postorder(node *temp){
        if(temp != NULL){
            postorder(temp->left);
            postorder(temp->right);
            cout<<temp->data<<" ";
        }
    }

    void inorderNoRec(node *temp);
    void preorderNoRec(node *temp);
    void postorderNoRec(node *temp);

};

void BTree::postorderNoRec(node *temp)
{
    stack<node*>s1;
    stack<node*>s2;

    if(temp == NULL)
        return;

    s1.push(temp);

    while(s1.empty() == false)
    {
        node *t = s1.top();

        s1.pop();

        s2.push(t);

        if(t->left != NULL)
            s1.push(t->left);
        if(t->right != NULL)
            s1.push(t->right);
    }

    while(s2.empty() == false)
    {
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}

void BTree::preorderNoRec(node *temp)
{
    if(temp == NULL)
        return;

    stack<node*> s;

    if(temp != NULL)
        s.push(temp);

    while(s.empty() == false)
    {
        node* t = s.top();
        s.pop();

        cout<<t->data<<" ";

        if(t->right != NULL)
            s.push(t->right);
        if(t->left != NULL)
            s.push(t->left);
    }
}

void BTree::inorderNoRec(node *temp)
{
    stack <node*> s;
    node *current = temp;

    while(current != NULL || s.empty() == false)
    {
        while(current != NULL)
        {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        cout<<current->data<<" ";

        current = current->right;
    }
}

int main(){

    BTree tree;

    int wc = 1;
    int choice;
    char d;
    while(wc){

        cout<<"1. Insert Node\n2. Display Preorder\n3. Display Inorder\n4. Display Postorder\n5. Exit"<<endl;
        cout<<"Enter your choice :";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter data to insert :";
                cin>>d;

                if(tree.root == NULL)
                    tree.root = tree.ins(tree.root, d);
                else
                    tree.ins(tree.root, d);

                cout<<"INSERT COMPLETE"<<endl;

                break;

            case 2:
                cout<<"DISPLAYING PREORDER"<<endl;
                tree.preorderNoRec(tree.root);
                cout<<endl<<endl;
                break;

            case 3:
                cout<<"DISPLAYING INORDER"<<endl;
                tree.inorderNoRec(tree.root);
                cout<<endl<<endl;
                break;

            case 4:
                cout<<"DISPLAYING POSTORDER"<<endl;
                tree.postorderNoRec(tree.root);
                cout<<endl<<endl;
                break;
            default:
                wc = 0;
                break;
        }
    }

    return 0;
}
