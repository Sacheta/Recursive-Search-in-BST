//program for simple execution of recursive insertion and DFS traversals of BST
#include<iostream>
using namespace std;

class node{  //node class
public:
    int data;
    node* right;
    node* left;

node(int n){  //paramerterized constructor
    data=n;
    right=nullptr;
    left=nullptr;
}

node(){  //default constructor
    data=0;
    right=nullptr;
    left=nullptr;
}

node *insertn(node *root,int h){  //recursive function to insert an element
    if(root==nullptr)  //when root is NULL
        return new node(h);
    if(root->data==h){  //if root->data matches the value to be inserted
        cout<<"Already present!"<<endl;
        return root;
    }
    if(root->data<h)  //if root->data is less than h, value is to inserted in right subtree
        root->right=insertn(root->right,h);
    if(root->data>h)  //if root->data is greater than h, value is to inserted in left subtree
        root->left=insertn(root->left,h);

    return root;
}

void inorder(node* root){  //recursive function to traverse tree in inorder fashion
    if(root==nullptr)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root){   //recursive function to traverse tree in preorder fashion
    if(root==nullptr)
        return;
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(node* root){    //recursive function to traverse tree in postorder fashion
    if(root==nullptr)
        return;
    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";
}

bool searchn(node *root,int h);

};

bool node::searchn(node *root,int h){  //recursive function to find a given node
    if(root==nullptr)  //if node's empty
        return 0;
    if(root->data==h)  //if node->data matches h
        return 1;
    if(root->data>h)  //if can be in leftsubtree
        return searchn(root->left,h);
    if(root->data<h)  //if can be in right subtree
        return searchn(root->right,h);
}

int main(){
    cout<<"Make selection: "<<endl;
    node* root=nullptr;
    cout<<"1. Insert a node"<<endl;
    cout<<"2. Display inorder"<<endl;
    cout<<"3. Display preorder"<<endl;
    cout<<"4. Display postorder"<<endl;
    cout<<"5. Search an element"<<endl;

    int n;
    while(cin>>n){
        switch(n){
        case 1:
            cout<<"Enter value to be inserted: ";
            int h;
            cin>>h;
            root=root->insertn(root,h);
            break;
        case 2:
            if(root==nullptr)
                cout<<"Empty!";
            else root->inorder(root);
            cout<<endl;
            break;
        case 3:
            if(root==nullptr)
                cout<<"Empty!";
            else
            root->preorder(root);
            cout<<endl;
            break;
        case 4:
            if(root==nullptr)
                cout<<"Empty!";
            else
            root->postorder(root);
            cout<<endl;
            break;
        case 5:
            cout<<"Enter element: ";
            int a;
            cin>>a;
            if(root->searchn(root,a ))
                cout<<"YES!"<<endl;
            else
                cout<<"NO!"<<endl;
            break;
        default:
            cout<<"Wrong selection!"<<endl;

        }
    }

}
