#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *left=nullptr;
    Node *right=nullptr;
};

void insert(Node *&root,int x){
    if(root==nullptr){
        root=new Node;
        root->data=x;
        return;
    }
    if(x<root->data){
        insert(root->left,x);
    }else insert(root->right,x);
}
int main(){
    int n,k;
    cin>>n>>k;
    Node *root=nullptr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insert(root,x);
    }
    Node *cur=root;
    while(cur!=nullptr){
        if(k==cur->data){
            cout<<cur->data;
            break;
        }
        if(k<cur->data){
            cout<<cur->data<<' ';
            cur=cur->left;
        }else {
            cout<<cur->data<<' ';
            cur=cur->right;
        }
    }
    if(cur==nullptr){
        cout<<"-1";
    }
}
