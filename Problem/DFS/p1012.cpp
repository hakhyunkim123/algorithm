#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 51;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int map[MAX][MAX];
bool visited[MAX][MAX];
int M, N;

bool in_range(int x, int y) { return x>=0 && x<N && y>=0 && y<M; }

void dfs(int x, int y) {
    visited[x][y] = true;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!in_range(nx, ny) || map[nx][ny] == 0 || visited[nx][ny]) continue;
        dfs(nx, ny);
    }
    return;
}

int main() {
    freopen("../Samples/p1012_sample.txt", "r", stdin);
    // input //
    int T, K;
    scanf("%d", &T);

    for(int tc = 0; tc < T; tc++) {
        // init //
        for(int i=0; i<MAX; i++) 
            for(int j=0; j<MAX; j++) map[i][j] = 0;
        memset(visited, false, sizeof(visited));

        // input //
        int K;
        scanf("%d %d %d", &M, &N, &K);
        for(int i=0; i<K; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            map[y][x] = 1;
        }

        int cnt = 0;
        for(int i=0; i<N; i++) 
            for(int j=0; j<M; j++) {
                if(map[i][j] == 1 && !visited[i][j]) {
                    cnt++;
                    dfs(i, j);
                }
            }
        printf("%d\n", cnt);
    }

    return 0;
}