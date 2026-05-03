#include <iostream>
using namespace std;

struct EdgeNode{
    int adjvex;
    EdgeNode *next=nullptr;
};

struct VertexNode{
    int data;
    EdgeNode *firstedge=nullptr;
};

int main(){
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    VertexNode *vertex=new VertexNode[n+1];
    int *vis=new int[n+1];
    int *que=new int[n+1];
    int *dist=new int[n+1];

    for(int i=1;i<=n;i++){
        vertex[i].data=i;
        dist[i]=-1;
        vis[i]=0;
    }

    for(int j=1;j<=m;j++){
        int u,v;
        cin>>u>>v;
        if (u==v) continue;

        EdgeNode *tmp1=new EdgeNode;
        tmp1->adjvex=v;
        tmp1->next=vertex[u].firstedge;
        vertex[u].firstedge=tmp1;

        EdgeNode *tmp2=new EdgeNode;
        tmp2->adjvex=u;
        tmp2->next=vertex[v].firstedge;
        vertex[v].firstedge=tmp2;
    }

    int front=0,rear=0;
    que[rear++]=s;
    vis[s]=1;
    dist[s]=0;
    while (front<rear){
        int u=que[front++];
        if(u==t) break;
        EdgeNode *p=vertex[u].firstedge;
        while(p!=nullptr){
            int v=p->adjvex;
            if(vis[v]==0){
                vis[v]=1;
                dist[v]=dist[u]+1;
                que[rear++]=v;
            }
            p=p->next;
        }
    }
    cout<<dist[t]<<endl;
    for(int i=1;i<=n;i++){
        EdgeNode *p=vertex[i].firstedge;
        while(p!=nullptr){
            EdgeNode *tmp=p;
            p=p->next;
            delete tmp;
        }
    }
    
    delete[] vertex;
    delete[] vis;
    delete[] dist;
    delete[] que;

    return 0;
}