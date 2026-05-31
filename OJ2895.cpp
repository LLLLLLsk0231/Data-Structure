#include <iostream>
using namespace std;

const int N =505;
int g1[N][N], g2[N][N];
bool vis[N][N];

void dfs(int x,int y,bool &ok){
    vis[x][y]=true;
    if(g1[x][y]==0) {
        ok=false;
    }
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    for(int k=0;k<4;k++){
        int nx=x+dx[k];
        int ny=y+dy[k];
        if(nx>=0&&nx<N&&ny>=0&&ny<N&&!vis[nx][ny]&&g2[nx][ny]==1){
            dfs(nx,ny,ok);
        }
    }
}

int main(){
    int m, n;
    int ans=0;
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) cin >> g1[i][j];
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) cin >> g2[i][j];
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
             vis[i][j] = false;
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(g2[i][j]==1&&!vis[i][j]){
                bool ok=true;
                dfs(i,j,ok);
                if (ok) ans++;
            }
        }
    }

    cout << ans;
    return 0;
}
// const int N = 505;

// int m, n;
// int g1[N][N], g2[N][N];

// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};

// void dfs(int x, int y, bool &ok) {
//     g2[x][y] = 0;
//     if (g1[x][y] == 0) ok = false;

//     for (int k = 0; k < 4; k++) {
//         int nx = x + dx[k];
//         int ny = y + dy[k];
//         if (nx >= 0 && nx < m && ny >= 0 && ny < n && g2[nx][ny] == 1) {
//             dfs(nx, ny, ok);
//         }
//     }
// }

// int main() {
//     cin >> m >> n;

//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) cin >> g1[i][j];
//     }

//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) cin >> g2[i][j];
//     }

//     int ans = 0;
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             if (g2[i][j] == 1) {
//                 bool ok = true;
//                 dfs(i, j, ok);
//                 if (ok) ans++;
//             }
//         }
//     }

//     cout << ans;
//     return 0;
// }
