#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

Node* createnode(int key){
    ///Node* node=new Node();/// or can use malloc for allocating memory
    Node* node=(Node*)malloc(sizeof(node));
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    return node;
}
///there are mainly three methods of traversal pre-in-post
///using bfs method for searching in the binary tree
Node* searchnode(Node* root,int key){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        if(q.front()->key==key){
            return q.front();
        }
        if(q.front()->left!=NULL)
            q.push(q.front()->left);
        if(q.front()->right!=NULL)
            q.push(q.front()->right);
        q.pop();
    }
    return NULL;
}

///preorder traversal
void preorder(Node* root){
    cout<<root->key<<" ";
    if(root->left!=NULL)
        preorder(root->left);

    if(root->right!=NULL)
        preorder(root->right);

}

///postorder traversal
void postorder(Node* root){
    if(root->left!=NULL)
        postorder(root->left);
    if(root->right!=NULL)
        postorder(root->right);
    cout<<root->key<<" ";
}

void inorder(Node* root){
    if(root->left!=NULL)
        inorder(root->left);
    cout<<root->key<<" ";
    if(root->right!=NULL)
        inorder(root->right);
}


///Inserting in tree and maintaining balance in the tree
/// this works if the tree is not empty
void insertin(Node* root,int key){
    Node* newnode=createnode(key);

    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        if(q.front()->left==NULL){
            q.front()->left=newnode;
            return;
        }else
            q.push(q.front()->left);
        if(q.front()->right==NULL){
            q.front()->right=newnode;
            return;
        }else
            q.push(q.front()->right);

        q.pop();
    }



}



int main()
{

    Node* root= createnode(8);
    root->left=createnode(3);
    root->left->left=createnode(1);
    root->left->right=createnode(6);
    root->left->right->left=createnode(4);
    root->left->right->right=createnode(7);
    root->right=createnode(10);
    root->right->right=createnode(14);
    root->right->right->left=createnode(13);

    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    insertin(root,11);
    //cout<<searchnode(root,10)->left->key<<endl;
    inorder(root);
}
