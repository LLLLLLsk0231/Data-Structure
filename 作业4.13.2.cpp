#include <iostream>
using namespace std;

struct Node{
    int left;
    long long weight;
    int right;
};

void sum(Node *p,int root,long long *ans,int level=0){
     if (root==0) return;
     if (p[root].left==0&&p[root].right==0) {
        *ans+=level*p[root].weight;
        return;
     }
     sum(p,p[root].left,ans,level+1);
     sum(p,p[root].right,ans,level+1);

}

int main(){
    int n;
    cin>>n;
    long long ans=0;
    Node *tree=new Node[n+1];
    bool *is_child=new bool[n+1]();
    for(int i=1;i<=n;i++){
       cin>>tree[i].left>>tree[i].weight>>tree[i].right;
       if(tree[i].left!=0) is_child[tree[i].left]=true;
       if(tree[i].right!=0) is_child[tree[i].right]=true;
    }
    int root=1;
    for(int i=1;i<=n;i++){
        if(!is_child[i]){
            root=i;
            break;
        }
    }
    sum(tree,root,&ans);
    cout<<ans;
    
    delete []tree;
    delete []is_child;
    return 0;

}