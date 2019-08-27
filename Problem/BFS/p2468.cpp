#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

struct pos {
    int x, y;
    pos(int mx, int my) {x = mx; y = my;}
    pos() {}
};

const int MAX = 100;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N;
int map[MAX][MAX];
bool visited[MAX][MAX];

bool in_range(int x, int y) { return x>=0 && x<N && y>=0 && y<N; }

void bfs(int x, int y, int height) {
    queue<pos> q;
    q.push(pos(x, y));
    visited[x][y] = true;

    while(!q.empty()) {
        pos cur = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            pos n;
            n.x = cur.x + dx[i];
            n.y = cur.y + dy[i];
            if(!in_range(n.x, n.y) || visited[n.x][n.y]) continue;
            if(map[n.x][n.y] > height) {
                visited[n.x][n.y] = true;
                q.push(n);
            }
        }
    }
}

int main() {
    freopen("../Samples/p2468_sample.txt", "r", stdin);
    scanf("%d", &N);

    int max_height = 0, min_height = 101;
    for(int i=0; i<N; i++) 
        for(int j=0; j<N; j++) {
            scanf("%d", &map[i][j]);
            max_height = max(max_height, map[i][j]);
            min_height = min(min_height, map[i][j]);
        }
    
    int ret = 1;
    for(int h=min_height; h<max_height; h++) {
        memset(visited, false, sizeof(visited));
        int cnt = 0;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++) {
                if(!visited[i][j] && map[i][j] > h) {
                    bfs(i, j, h);
                    cnt++;
                }
            }
        ret = max(ret, cnt);
    }

    printf("%d\n", ret);

    return 0;
}