#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 26;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int map[MAX][MAX];
bool visited[MAX][MAX];
int N;
vector<int> ret;

// starting time : 13:58

bool in_range(int x, int y) {
    return x>=0 && x<N && y>=0 && y<N;
}

bool compare(int x, int y) {
    return x < y;
}

int bfs(int x, int y) {
    queue<pair<int ,int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;

    int cnt = 1;
    while(!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;

        q.pop();

        for(int i=0; i<4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if(!in_range(nx, ny)) continue;

            if(map[nx][ny] == 1 && visited[nx][ny] == false) {
                cnt++;
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
    return cnt;
}

void init() {
    memset(visited, false, sizeof(visited));
}

int main(){
    freopen("../Samples/p2667_sample.txt", "r", stdin);

    init();
    scanf("%d", &N);

    for(int i=0; i<N; i++) 
        for(int j=0; j<N; j++) {
            scanf("%1d", &map[i][j]);
        }

    vector<int> ret;
    for(int i=0; i<N; i++) 
        for(int j=0; j<N; j++) {
            if(map[i][j] == 1 && !visited[i][j]) {
                int cnt = bfs(i, j);
                ret.push_back(cnt);
            }
        }
    
    sort(ret.begin(), ret.end());

    printf("%d\n", ret.size());
    for(int i=0; i<ret.size(); i++) printf("%d\n", ret[i]);
    
}