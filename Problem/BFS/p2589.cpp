#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct pos {
    int x, y, depth;
    pos() {}
    pos(int mx, int my, int md) {x=mx; y=my; depth=md;}
};

const int MAX = 50;
char map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int L, W;

bool in_range(int x, int y) { return x>=0 && x<L && y>=0 && y<W; }

int bfs(int x, int y) {
    queue<pos> q;
    q.push(pos(x, y, 0)); 

    memset(visited, false, sizeof(visited));
    visited[x][y] = true;

    int ret = 0;
    while(!q.empty()) {
        int cx = q.front().x;
        int cy = q.front().y;
        int cd = q.front().depth;
        q.pop();
        ret = max(ret, cd);

        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(in_range(nx, ny) && map[nx][ny] == 'L' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push(pos(nx, ny, cd+1));
            }
        }
    }
    return ret;
}

int main() {
    freopen("../Samples/p2589_sample.txt", "r", stdin);
    cin >> L >> W;
    for(int i=0; i<L; i++) 
        for(int j=0; j<W; j++) cin >> map[i][j];
        
    int ret = 0;
    for(int i=0; i<L; i++) 
        for(int j=0; j<W; j++) 
            if(map[i][j] == 'L') 
                ret = max(ret, bfs(i, j));
            
    cout << ret << endl;
    return 0;
}