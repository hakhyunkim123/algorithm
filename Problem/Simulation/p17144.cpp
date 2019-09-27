#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

const int MAX = 50;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

struct air_fresher {
    int x, y;
    air_fresher() {}
    air_fresher(int x, int y) {
        this->x = x; this->y = y;
    }
};

struct dust {
    int x, y, size;
    dust() {}
    dust(int x, int y, int size) {
        this->x = x; this->y = y; this->size = size;
    }
};

int R, C, T;
int map[MAX][MAX];

bool in_range(int x, int y) { return x>=0 && x<R && y>=0 && y<C; }

void simulation(const vector<air_fresher> fresher) {
    queue<dust> q;
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++) 
            if(map[i][j] > 0) q.push(dust(i, j, map[i][j]));

    while(!q.empty()) {
        dust cur = q.front();
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(!in_range(nx, ny) || map[nx][ny] == -1) continue;
            map[nx][ny] += cur.size / 5;
            map[cur.x][cur.y] -= (cur.size/5);
        }
    }

    // 위 공기청정기
    int x, y, dir, reg;
    x = fresher[0].x, y = fresher[0].y;
    dir = 1, reg = 0;
    do {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(ny == C) dir = 2;
        else if(nx < 0) dir = 0;
        else if(ny < 0) dir = 3;

        x += dx[dir];
        y += dy[dir];

        int tmp = map[x][y];
        map[x][y] = reg;
        reg = tmp;
    } while(!(x == fresher[0].x && y == fresher[0].y));

    // 아래 공기청정기
    x = fresher[1].x, y = fresher[1].y;
    dir = 1, reg =0 ;
    do {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(ny == C) dir = 3;
        else if(nx == R) dir = 0;
        else if(ny < 0) dir = 2;

        x += dx[dir];
        y += dy[dir];

        int tmp = map[x][y];
        map[x][y] = reg;
        reg = tmp;
    } while(!(x == fresher[1].x && y == fresher[1].y));
}

int main() {
    freopen("../Samples/p17144_sample.txt", "r", stdin);

    scanf("%d %d %d", &R, &C, &T);

    vector<air_fresher> fresher;
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++) {
            cin >> map[i][j];
            if(map[i][j] == -1) fresher.push_back(air_fresher(i, j));
        }


    for(int t=0; t<T; t++) {
        simulation(fresher);
        for(int i=0; i<fresher.size(); i++) 
            map[fresher[i].x][fresher[i].y] = -1;
    }
    
    map[fresher[0].x][fresher[0].y] = 0;
    map[fresher[1].x][fresher[1].y] = 0;

    int ret = 0;
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++) ret += map[i][j];

    cout << ret << endl;

    return 0;
}