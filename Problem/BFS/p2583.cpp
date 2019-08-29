#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int M, N, K;

bool in_range(int x, int y) { return x>=0 && x<M && y>=0 && y<N; }
bool compare(int x, int y) { return x < y; }

int bfs(int x, int y) {
    queue< pair<int, int> > q;
    q.push({x, y});
    visited[x][y] = true;

    int area = 0;
    while(!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        area++;
        for(int i=0; i<4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if(!in_range(nx, ny) || visited[nx][ny] || map[nx][ny] == 1) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    return area;
}

void make_rec(int x1, int y1, int x2, int y2) {
    int x = M - y1 - 1;
    int y = x1;
    int lx = M - y2;
    int ly = x2 - 1;

    for(int i=lx; i<=x; i++)
        for(int j=y; j<=ly; j++)
            map[i][j] = 1;
}

int main() {
    freopen("../Samples/p2583_sample.txt", "r", stdin);
    scanf("%d %d %d", &M, &N, &K);
    for(int i=0; i<K; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        make_rec(x1, y1, x2, y2);
    }

    memset(visited, false, sizeof(visited));
    vector<int> ret;
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++) {
            if(!visited[i][j] && map[i][j] == 0) {
                ret.push_back(bfs(i, j));
            }
        }

    sort(ret.begin(), ret.end(), compare);

    printf("%d\n", ret.size());
    for(int i=0; i<ret.size(); i++) printf("%d ", ret[i]);
    printf("\n");
    
    return 0;
}