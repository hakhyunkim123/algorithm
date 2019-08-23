#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 21;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char map[MAX][MAX];
bool visited[MAX][MAX];
bool al[26];
int R, C, ret=0;

bool in_range(int x, int y) { return x>=0 && x<R && y>=0 && y<C; } 

void dfs(int x, int y, int depth) {
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!in_range(nx, ny) || visited[nx][ny] || al[map[nx][ny] - 'A']) continue;
        visited[nx][ny] = true;
        al[map[nx][ny] - 'A'] = true;

        dfs(nx, ny, depth+1);

        visited[nx][ny] = false;
        al[map[nx][ny] - 'A'] = false;
    }
    ret = max(ret, depth);
}

int main() {
    //freopen("p1987_sample.txt", "r", stdin);
    cin >> R >> C;
    for(int i=0; i<R; i++) 
        for(int j=0; j<C; j++)
            cin >> map[i][j];

    memset(al, false, sizeof(al));
    memset(visited, false, sizeof(visited));

    al[map[0][0] - 'A'] = true;
    visited[0][0] = true;

    dfs(0, 0, 1);

    printf("%d\n", ret);
    return 0;
}