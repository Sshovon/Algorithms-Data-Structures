#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    int height;
    Node* left;
    Node* right;


};

Node* newNode(int key){
    //Node* node= new Node();
    Node* node=(Node*)malloc(sizeof(node));
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return node;

}
///we need this function to handle null node case
int height(Node* node){
    if(node==NULL)
        return 0;
    return node->height;
}


int get_bf(Node* node){
    if(node==NULL)
        return 0;
    return height(node->left)-height(node->right);
}


Node* rightRotate(Node* y){
    Node* x=y->left;
    Node* t2=y->left->right;

    ///rotation
    x->right=y; /// Y takes place of YLR
    y->left=t2; /// YLR takes place in YR

    y->height=1+max(height(y->left),height(y->right));
    x->height=1+max(height(x->left),height(x->right));

    return x; ///new parent node

}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* t2= x->right->left;


    ///rotation
    y->left=x; /// x takes place of  xRL
    x->right=t2; ///xRL takes place of xR

    y->height=1+max(height(y->left),height(y->right));
    x->height=1+max(height(x->left),height(x->right));

    return y; ///new parent node

}


Node* insertNode(Node* node,int key){
    if(node==NULL){
        return newNode(key);
    }
    if(key<node->key)
        node->left=insertNode(node->left,key);
    else if(key>node->key)
        node->right=insertNode(node->right,key);
    else
        return node; ///for equal key which are node allowed in bst

    node->height=1+max(height(node->left),height(node->right));


    int bf=get_bf(node);

    ///left-left case

    if(bf>1 && key<node->left->key)
        return rightRotate(node);

    ///right-right case
    if(bf<-1 && key>node->right->key)
        return leftRotate(node);

    ///left-right case
    if(bf>1 && key>node->left->key){
        node->left=leftRotate(node->left);///left rotate taking the left of the node / middle value
        return rightRotate(node);///right rotate taking the node
    }
    if(bf<-1 && key<node->right->key){
        node->right=rightRotate(node->right);///right rotate taking the right of the node / middle value
        return leftRotate(node); ///left rotate taking the node
    }
    return node;

}

Node* minVal(Node* node){
    if(node->left==NULL)
        return node;
    return minVal(node->left);

}
///same as bst
Node* deleteNode(Node* root,int key){
    if(root==NULL)
        return root;
    if(key<root->key)
        root->left=deleteNode(root->left,key);
    else if(key>root->key)
        root->right=deleteNode(root->right,key);
    else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
        }else if(root->left==NULL){
            Node* temp=root;
            root=root->right;
            delete temp;
        }else if(root->right==NULL){
            Node* temp=root;
            root=root->left;
            delete temp;
        }else{
            Node* miniOnRight=minVal(root->right);
            root->key=miniOnRight->key; ///be careful replacing just value not the pointer
            root->right=deleteNode(root->right,miniOnRight->key);
        }

        ///important case
        if(root==NULL)
            return root;
        ///updating  height of the ancestors of the deleted node
        root->height=1+max(height(root->left),height(root->right));
        int bf=get_bf(root);
        if(bf>1 && key<root->left->key)
        return rightRotate(root);

        ///right-right case
        if(bf<-1 && key>root->right->key)
            return leftRotate(root);

        ///left-right case
        if(bf>1 && key>root->left->key){
            root->left=leftRotate(root->left);///left rotate taking the left of the node / middle value
            return rightRotate(root);///right rotate taking the node
        }
        if(bf<-1 && key<root->right->key){
            root->right=rightRotate(root->right);///right rotate taking the right of the node / middle value
            return leftRotate(root); ///left rotate taking the node
        }
        return root;

    }
}
void preOrderTraversal(Node* node){
    if(node==NULL)
        return;
    cout<<node->key<<" ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

void postOrderTraversal(Node* node){
    if(node==NULL)
        return;
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout<<node->key<<" ";

}

void inOrderTraversal(Node* node){
    if(node==NULL)
        return;
    inOrderTraversal(node->left);
    cout<<node->key<<" ";
    inOrderTraversal(node->right);

}

int main()
{

    Node* root=NULL; ///initialize the root

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    //cout<<root->key;

    preOrderTraversal(root);
    cout<<endl;
    inOrderTraversal(root);
    cout<<endl;
    postOrderTraversal(root);
    cout<<endl;

    deleteNode(root,30);
    preOrderTraversal(root);
    cout<<endl;

    inOrderTraversal(root);
    cout<<endl;
    postOrderTraversal(root);
    cout<<endl;

}
