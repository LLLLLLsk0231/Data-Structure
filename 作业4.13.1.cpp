#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *right=nullptr;
    Node *left=nullptr;
};
bool find_this_child(Node* current, int target) {
    if (current == nullptr) return false;
    if (current->val == target) return true;
    return find_this_child(current->left, target) || find_this_child(current->right, target);
}
int main(){
    int n,x,y;
    int ans=1;
    cin>>n>>x>>y;
    Node *tree=new Node[n+1];
    for(int i=1;i<=n;i++){
        int left,right;
        tree[i].val=i;
        cin>>left>>right;
        if (left!=0) tree[i].left=&tree[left];
        if (right!=0) tree[i].right=&tree[right]; 
    }
    for (int i=1;i<=x;i++){
      if(find_this_child(&tree[i],x)&&find_this_child(&tree[i],y)) ans=i;
    } 
    cout<<ans;
    delete []tree;
    return 0;

}