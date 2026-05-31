#include <iostream>
using namespace std;

struct Vertex{
    int val;
    Vertex *next=nullptr;
};

void dfs(Vertex *v,int s, bool *visited, int t, bool &ok){
    visited[s]=true;
    if(s==t) {
        ok=true;
        return;
    }
    Vertex *temp=v[s].next;
    while(temp!=nullptr){   
        if(!visited[temp->val]){
            dfs(v, temp->val, visited, t, ok);
        }
        temp=temp->next;
    }
}
int main(){
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    Vertex *v=new Vertex[n+1];
    for(int i=1;i<=n;i++){
        v[i].val=i;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        Vertex *temp=new Vertex;
        temp->val=b;
        temp->next=v[a].next;
        v[a].next=temp;
    }
    bool *visited=new bool[n+1];
    bool ok=false;
    for(int i=1;i<=n;i++){  
        visited[i]=false;
    }

    dfs(v, s, visited, t, ok);
    if(ok) cout << "True";
    else cout << "False";
    
    for(int i=1;i<=n;i++){
        Vertex *temp=v[i].next;
        while(temp!=nullptr){
            Vertex *toDelete=temp;
            temp=temp->next;
            delete toDelete;
        }
    }
    delete[] v;
    delete[] visited;
    return 0;
}