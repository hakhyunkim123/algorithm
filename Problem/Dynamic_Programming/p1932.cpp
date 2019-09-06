#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 501;
int map[MAX][MAX];
int cache[MAX][MAX];
int N;

int dp(int x, int y) {
    if(x == 1) return map[x][y];
    
    int& ret = cache[x][y];
    if(ret != -1) return ret;

    ret = 0;

    if(y==0) ret = map[x][y] + dp(x-1, y);
    else if(y==x-1) ret = map[x][y] + dp(x-1, y-1);
    else ret = map[x][y] + max(dp(x-1, y-1), dp(x-1, y));

    return ret;
}

int main() {
    //freopen("../Samples/p1932_sample.txt", "r", stdin);
    cin >> N;
    for(int i=1; i<=N; i++)
        for(int j=0; j<i; j++) cin >> map[i][j];

    memset(cache, -1, sizeof(cache));
    int ret = 0;
    for(int i=0; i<N; i++) ret = max(ret, dp(N, i)); 

    cout << ret << endl;

    return 0;
}