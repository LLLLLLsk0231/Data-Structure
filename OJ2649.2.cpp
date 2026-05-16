#include <iostream>
using namespace std;

struct Node{
    int val=0;
    int left;
    int right;
};
bool find_this_child(Node* current, int target, Node* tree) {
    if (current->val == 0) return false;
    if (current->val == target) return true;
    return find_this_child(&tree[current->left], target, tree) || find_this_child(&tree[current->right], target, tree);
}
int main(){
    int n,x,y;
    int ans=1;
    cin>>n>>x>>y;
    Node *tree=new Node[n+1];
    for(int i=1;i<=n;i++){
        cin>>tree[i].left>>tree[i].right; 
        tree[i].val=i;
    }
    for (int i=1;i<=x;i++){
      if(find_this_child(&tree[i],x, tree)&&find_this_child(&tree[i],y, tree)) ans=i;
    } 
    cout<<ans;
    delete []tree;
    return 0;
}