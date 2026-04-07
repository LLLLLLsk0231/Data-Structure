#include <iostream>
using namespace std;

struct Node{
    int val;
    int left;
    int right;
};
   
void dfs(int u,int current_num,Node *tree,int &total_num){
     current_num=current_num*10+tree[u].val;
     if(tree[u].left==0&&tree[u].right==0){
        total_num+=current_num;
        return;
     }

     if(tree[u].left!=0){
        dfs(tree[u].left,current_num,tree,total_num);
     }

     if(tree[u].right!=0){
        dfs(tree[u].right,current_num,tree,total_num);
     }
     return;
}

int main(){
    int n;
    cin>>n;
    Node *tree=new Node[n+1];
    for(int i=1;i<=n;i++){
        cin>>tree[i].val>>tree[i].left>>tree[i].right;
    }
    int total_num=0;
    dfs(1,0,tree,total_num);
    cout<<total_num;
    delete[] tree;
    return 0;
}