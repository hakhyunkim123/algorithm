#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 51;
int map[MAX][MAX];
int N, M, ret = 1;

bool in_range(int x, int y) { return x>=0 && x<N && y>=0 && y<M; }

int find_square(int x, int y, int max_length) {
    int length = 1;
    int cur = map[x][y];
    for(int i = max_length; i>=ret; i--) {
        if(!in_range(x, y+i) || !in_range(x+i, y)) continue;
        if(cur == map[x][y+i] && cur == map[x+i][y] && cur == map[x+i][y+i]) {
            length = i+1;
            break;
        }
    }
    return length;
}

int main() {
    freopen("p1051_sample.txt", "r", stdin);

    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%1d", &map[i][j]);

    int max_length = min(N, M) - 1;
    for(int i=0; i<N; i++) 
        for(int j=0; j<M; j++) 
            ret = max(ret, find_square(i, j, max_length));

    printf("%d\n", ret*ret);
    return 0;
}