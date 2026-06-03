 #include <iostream>
using namespace std;

const int N = 1001;
char g[N][N];
int dist[N][N];
bool vis[N][N] = {false};

void bfs(int x, int y, int n, int m, int &ans) {
    int qx[N * N], qy[N * N];
    int head = 0, tail = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    qx[tail] = x;
    qy[tail] = y;
    tail++;
    vis[x][y] = true;
    dist[x][y] = 0;

    while (head < tail) {
        int cx = qx[head];
        int cy = qy[head];
        head++;

        if (g[cx][cy] == 'A') {
            ans = dist[cx][cy];
            return;
        }

        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                !vis[nx][ny] && g[nx][ny] != '#') {
                vis[nx][ny] = true;
                dist[nx][ny] = dist[cx][cy] + 1;
                qx[tail] = nx;
                qy[tail] = ny;
                tail++;
            }
        }
    }
}

int main() {
    int n, m;
    int x = -1, y = -1;
    int ans = -1;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            dist[i][j] = -1;
            if (g[i][j] == 'S') {
                x = i;
                y = j;
            }
        }
    }

    bfs(x, y, n, m, ans);
    cout << ans;

    return 0;
}

