#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

};

Node* createnode(int data){
    Node* node= new Node();
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}
Node* Insert(Node* root,int data){
 if(root == NULL){
    //cout<<"I m groot"<<endl;
    return createnode(data);

 }
 else if(data<=root->data)
    root->left=Insert(root->left,data);
 else
    root->right=Insert(root->right,data);
}

bool Search(Node* root,int key){
    if(root==NULL)
        return false;
    if(root->data==key)
        return true;
    if(key<root->data)
        return Search(root->left,key);
    else
        return Search(root->right,key);

}

Node* FindMin(Node* root){
    if(root->left==NULL)
        return root;
    return FindMin(root->left);
}

Node* Delete(Node* root,int data){
    if(root==NULL)
        return root;
    else if(data<root->data)
        root->left= Delete(root->left,data);
    else if(data>root->data)
        root->right=Delete(root->right,data);
    else{
        ///No child in the expected node
        if(root->left==NULL && root->right==NULL){
            delete root;///delete is used in c++ to deallocate data like free()in c
            root=NULL;
        }///only one child
        else if(root->left==NULL){
            Node* temp=root;
            root=root->right;
            delete temp;

        }///one child
        else if(root->right==NULL){
            Node* temp=root;
            root=root->left;
            delete temp;
        }///two child
        ///find the minimum value in the right subtree/maximum in the left subtree
        ///& replace
        else{
            Node* temp=FindMin(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);
        }
    }
    return root;
}



int main()
{

    Node* root=NULL;
    root=Insert(root,15);
    root=Insert(root,10);
    root=Insert(root,20);
    root=Insert(root,25);
    root=Insert(root,8);
    root=Insert(root,12);
    root=Insert(root,7);

    //root=Delete(root,7);

    cout<<FindMin(root)->data;
}
