#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 51;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int map[MAX][MAX];
int N, M, r, c, d, ret=1;

bool in_range(int x, int y) { return x>=0 && x<N && y>=0 && y<M; }
bool can_clean(int x, int y) { return map[x][y] == 0; }

void simulation() {
    while(true) {
        bool suc = false;
        int nx=r, ny=c, nd=d;
        for(int i=0; i<4; i++) {
            // update next direction.
            if(nd==0) nd = 3;
            else nd = nd-1;
            // update next position.
            nx = r + dx[nd];
            ny = c + dy[nd];

            if(can_clean(nx, ny)) {
                map[nx][ny] = 2; // cleaning.
                d = nd; r = nx; c = ny; // update direction and position.
                suc = true;
                ret++;
                break;
            }
        }
        if(!suc) {
            // get back position.
            nd = (d + 2) % 4;
            nx = r + dx[nd];
            ny = c + dy[nd];
            if(map[nx][ny] != 1) {
                // go back.
                r = nx; c = ny;
            }
            else break;
        }
    }
}

int main() {
    //freopen("../Samples/p14503_sample.txt", "r", stdin);

    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &r, &c, &d);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) 
            scanf("%d", &map[i][j]);
    
    map[r][c] = 2;
    simulation();

    printf("%d\n", ret);

    return 0;
}