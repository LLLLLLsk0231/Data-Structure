#include <iostream>
using namespace std;

struct Node {
  int val;
  int id;
  Node *left=nullptr;
  Node *right=nullptr;
  Node *next=nullptr;
};

void connect(Node *tree){
    if (tree->left==nullptr) return;
    tree->left->next=tree->right;
    if (tree->next!=nullptr) tree->right->next=tree->next->left;
    connect(tree->left);
    connect(tree->right);
}

int main(){
   int n;
   cin>>n;
   Node *tree=new Node[n+1];
   for(int i=1;i<=n;i++){
    int left,right;
    left=right=0;
    cin>>tree[i].val>>left>>right;
    if(left!=0){
        tree[i].left=&tree[left];
    }
    if(right!=0){
        tree[i].right=&tree[right];
    }
    tree[i].id=i;
   }
   connect(&tree[1]);
   for(int i=1;i<=n;i++){
    if (tree[i].next!=nullptr) cout<<tree[i].next->id<<endl;
    else cout<<0<<endl; 
   }
   delete[] tree;
   return 0;
}
