#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct pos {
    int x, y;
    pos(int mx, int my) { x = mx; y = my; }
    pos() {}
};

const int MAX = 51;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char map[MAX][MAX];
int R, C;

void print_map() {
    printf("=======================\n");
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) printf("%c ", map[i][j]);
        printf("\n");
    }
    printf("=======================\n");
}

bool in_range(int x, int y) { return x>=0 && x<R && y>=0 && y<C; }

int bfs(vector<pos> water, pos dochi, pos biber) {
    queue< pair<pos, int> > q;
    q.push({dochi, 0});
    for(int i=0; i<water.size(); i++) q.push({water[i], 0});

    int ret = -1;
    bool finish = false;
    while(!q.empty()) {
        pos cur = q.front().first;
        int cur_time = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(!in_range(nx, ny)) continue;

            if(map[cur.x][cur.y] == 'S') {
                if(map[nx][ny] == '.') {
                    map[nx][ny] = 'S';
                    q.push({pos(nx, ny), cur_time+1});
                }
                else if(map[nx][ny] == 'D') {
                    ret = cur_time + 1;
                    finish = true;
                    break;
                }
            }
            else if(map[cur.x][cur.y] == '*') {
                if(map[nx][ny] == '.' || map[nx][ny] == 'S') {
                    map[nx][ny] = '*';
                    q.push({pos(nx, ny), cur_time+1});
                }
            }
        }
        if(finish) break;
    }
    return ret;
}

int main() {
    freopen("../Samples/p3055_sample.txt", "r", stdin);
    cin >> R >> C;

    pos dochi, biber;
    vector<pos> water;
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++) {
            cin >> map[i][j];
            if(map[i][j] == '*') water.push_back(pos(i, j));
            else if(map[i][j] == 'D') biber = pos(i, j);
            else if(map[i][j] == 'S') dochi = pos(i, j);
        }

    int ret;
    ret = bfs(water, dochi, biber);

    if(ret == -1) cout << "KAKTUS" << endl;
    else cout << ret << endl;

    return 0;
}