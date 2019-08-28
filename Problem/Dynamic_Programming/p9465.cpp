#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 100000;
int dx[4] = {-1, -1, 1, 1};
int dy[4] = {1, 2, 1, 2};
int map[2][MAX];
int cache[2][MAX];
int N;

bool in_range(int x, int y) { return x>=0 && x<2 && y>=0 && y<N; }

int dp(int x, int y, int last) {
    if(y == last) return map[x][y];

    int& ret = cache[x][y];
    if(ret != -1) return ret;

    ret = 0;

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(!in_range(nx, ny)) continue;
        ret = max(ret, dp(nx, ny, last) + map[x][y]);
    }

    return ret;
}

int main() {
    freopen("../Samples/p9465_sample.txt", "r", stdin);
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        memset(cache, -1, sizeof(cache));
        cin >> N;
        for(int i=0; i<2; i++)
            for(int j=0; j<N; j++) 
                cin >> map[i][j];

        int ret = max(dp(0, 0, N-1), dp(1, 0, N-1));
        cout << ret << endl;
    }
    return 0;
}