#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1001;

int N;
int list[MAX][3];
int cache[MAX][3];

int dp(int x, int y) {
    if(x == 0) return list[x][y];
    
    int& ret = cache[x][y];
    if(ret != -1) return ret;
    
    ret = INT_MAX;

    if(y == 0) ret = list[x][y] + min(dp(x-1, y+1), dp(x-1, y+2));
    else if(y == 1) ret = list[x][y] + min(dp(x-1, y-1), dp(x-1, y+1));
    else ret = list[x][y] + min(dp(x-1, y-1), dp(x-1, y-2));

    return ret;
} 

int main() {
    freopen("../Samples/p1149_sample.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) 
        for(int j=0; j<3; j++) cin >> list[i][j];

    memset(cache, -1, sizeof(cache));
    int ret = INT_MAX;
    for(int i=0; i<3; i++) ret = min(ret, dp(N-1, i));

    cout << ret << endl;
    return 0;
}