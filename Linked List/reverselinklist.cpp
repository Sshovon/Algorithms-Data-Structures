#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head;


void print(){
    Node* node= head;
    while(node!=NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<endl;
}

void Ins(int data,int pos){
    Node* temp = new Node();
    temp->data=data;
    temp->next=NULL;

    if(pos==1){
        temp->next=head;
        head=temp;
        return;
    }
    Node* temp2=head;
    if(temp2==NULL){
        cout<<"Invalid Index"<<endl;
        delete temp;
        return;

    }
    for(int i=1;i<=pos-2;i++){
        if(temp2->next==NULL){
            cout<<"Invalid Index"<<endl;
            delete temp;
            return;
        }
        temp2=temp2->next;
    }
    temp->next=temp2->next;
    temp2->next=temp;

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

void RevTheList(){
    Node* current=head;
    Node* prev=NULL;
    Node* next;
    if(head==NULL){
        cout<<"List Empty."<<endl;
        return;
    }
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;

}

void RevListRecursion(Node* current){
     if(current->next==NULL){
        head=current;
        return;
     }
     RevListRecursion(current->next);
     Node* nex = current->next;
     nex->next=current;
     current->next=NULL;
}

int main()
{
    int n,val,pos;
   while(cin>>n){
    if(n==1){
            cin>>val>>pos;
            Ins(val,pos);
            print();
    }else if(n==2){
        cin>>pos;
        del(pos);
        print();
    }else if(n==3){
        RevListRecursion(head);
        print();
    }
   }


}
