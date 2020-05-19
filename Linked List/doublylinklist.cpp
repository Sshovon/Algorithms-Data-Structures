#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node* next;
    Node* prev;

};

Node* head;

void InsHead(int data){
    Node* temp = new Node();
    temp->data= data;
    temp-> next = NULL;
    temp-> prev = NULL;

    if(head==NULL){
        head=temp;
        return;
    }
    head->prev = temp ;
    temp->next = head ;
    head= temp;


}

void InsTail(int data){
    Node* temp= new Node();
    temp->data= data;
    temp->next= NULL;
    temp->prev= NULL;

    if(head==NULL){
        head=temp;
        return;
    }
    Node* temp2=head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;
    temp->prev=temp2;

}

void print(){
    Node* temp = head;
    if(temp==NULL){
        cout<<"List empty."<<endl;
        return;
    }

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

}

void revPrint(){
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<endl;

}


int main()
{


}
