#include <iostream>
using namespace std;

struct EdgeNode{
    int adjvex;
    EdgeNode *next=nullptr;
EdgeNode(int m):adjvex(m){}
};

struct VertexNode{
    int data;
    EdgeNode *firstedge=nullptr;
};

void dfs(VertexNode *vertex,int i,int *vis){
    vis[i]=1;
    EdgeNode *p=vertex[i].firstedge;
    while(p!=nullptr){
        int k=p->adjvex;
        if (vis[k]==0) dfs(vertex,k,vis);
        p=p->next;
    }
    
}

int main(){
    int n,m;
    cin>>n>>m;
    VertexNode *vertex=new VertexNode[n+1];
    int *vis=new int[n+1];
    for(int i=1;i<=n;i++){
        vertex[i].data=i;
        vis[i]=0;
    }
    for(int j=0;j<m;j++){
        int u,v;
        cin>>u>>v;
        EdgeNode *newedge=new EdgeNode(v);
        newedge->next=vertex[u].firstedge;
        vertex[u].firstedge=newedge;
        if(u!=v){
        EdgeNode *newedge=new EdgeNode(u);
        newedge->next=vertex[v].firstedge;
        vertex[v].firstedge=newedge;
        }
        }
    int ans=0;
    for(int i=1;i<=n;i++){
        if (vis[i]==0) {
            ans++;
            dfs(vertex,i,vis);
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        EdgeNode *p=vertex[i].firstedge;
        while(p!=nullptr){
            EdgeNode *tmp=p;
            p=p->next;
            delete tmp;
        }    
    }    
    delete []vertex;
    delete []vis;
    return 0;
}