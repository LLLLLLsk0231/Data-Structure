#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *left=nullptr;
    Node *right=nullptr;
};

void pre_order(Node *p){
   if(p!=nullptr){
    cout<<p->val<<' ';
    pre_order(p->left);
    pre_order(p->right);
   }
}
int main(){
    int n;
    cin>>n;
    Node *tree=new Node[n+1];
    for(int i=1;i<=n;i++){
        int right,left;
        cin>>tree[i].val>>left>>right;
        if(left!=0) tree[i].left=&tree[left];
        if(right!=0) tree[i].right=&tree[right]; 
    }
    pre_order(&tree[1]);

}