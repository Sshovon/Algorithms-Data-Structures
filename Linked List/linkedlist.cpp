#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

};

Node* head;

void print(){
    Node* temp = head ;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;


}




void Ins(int data,int pos){
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next=NULL;

    if(pos==1){
        temp1->next= head;
        head=temp1;
        return;
    }
    Node* temp2 = head;
    if(temp2==NULL){
            cout<<"Invalid Index. Try another value"<<endl;
            //take_Valid_In();
            return;
    }
    for(int i=1;i<=pos-2;i++){

        if(temp2->next==NULL ){
            cout<<"Invalid Index. Try another value"<<endl;
            return;
        }
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;


}




void del(int pos){

    Node* temp= head;
    if(head==NULL){
        cout<<"List already empty"<<endl;
        return;
    }
    if(pos==1){
        head=head->next;
        delete temp;
        return;
    }

    for(int i=1;i<=pos-2;i++){
        if(temp->next==NULL ){
            cout<<"Invalid Index. Try another value"<<endl;
            return;
        }
        temp=temp->next;

    }
    if(temp->next==NULL){
        cout<<"Invalid Index. Try another value"<<endl;
        return;
    }
    Node* temp1=temp->next;
    temp->next=temp->next->next;

    delete temp1;

}


int main()
{
   //head=NULL;
   int n,val,pos;
   while(cin>>n){
    if(n==1){
            cin>>val>>pos;
            Ins(val,pos);
            print();
    }else{
        cin>>pos;
        del(pos);
        print();
    }
   }

 }
