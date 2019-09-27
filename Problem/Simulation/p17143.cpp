#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct shark {
    int x, y, speed, dir, size;
    shark() {}
    shark(int x, int y, int speed, int dir, int size) {
        this->x = x; this->y = y; this->speed = speed;
        this->dir = dir; this->size = size;
    }
};

const int MAX = 100;

vector<shark> map[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int R, C, M;

int fishing(int index) {
    int ret = 0;

    for(int i=0; i<R; i++) 
        if(map[i][index].size() == 1) {
            ret = map[i][index][0].size;
            map[i][index].clear();
            break;
        }

    return ret;
}

void move_shark(shark& s) {
    for(int i=0; i<s.speed; i++) {
        if(s.dir == 0 || s.dir == 1) {
            int nx = s.x + dx[s.dir];
            if(!(nx >= 0 && nx < R)) s.dir = 1 - s.dir;
            s.x += dx[s.dir];
        }
        else {
            int ny = s.y + dy[s.dir];
            if(!(ny >= 0 && ny < C)) s.dir = 5 - s.dir;
            s.y += dy[s.dir];
        }
    }
}

bool move_and_eat() {
    bool finish = false;
    int M = 0;
    vector<shark> sharks; 
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            if(map[i][j].size() != 0) {
                sharks.push_back(map[i][j][0]);
                map[i][j].clear();
                M++;
            }
    
    if(M == 0) return finish = true;

    for(int i=0; i<sharks.size(); i++) {
        shark cur = sharks[i];
        for(int i=0; i<cur.speed; i++) {
            if(cur.dir == 0 || cur.dir == 1) {
                int nx = cur.x + dx[cur.dir];
                if(!(nx >= 0 && nx < R)) cur.dir = 1 - cur.dir;
                cur.x += dx[cur.dir];
            }
            else {
                int ny = cur.y + dy[cur.dir];
                if(!(ny >= 0 && ny < C)) cur.dir = 5 - cur.dir;
                cur.y += dy[cur.dir];
            }
        }

        int nx = cur.x, ny = cur.y;
        if((map[nx][ny].size() != 0) && (cur.size > map[nx][ny][0].size)) {
                map[nx][ny].clear();
                map[nx][ny].push_back(cur);
        }
        else if(map[nx][ny].empty()) map[nx][ny].push_back(cur);
    }

    return finish;
}

int main() {
    //freopen("../Samples/p17143_sample.txt", "r", stdin);

    cin >> R >> C >> M;
    for(int i=0; i<M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        map[r-1][c-1].push_back(shark(r-1, c-1, s, d-1, z));
    }

    int ret = 0;
    for(int i=0; i<C; i++) {
        ret += fishing(i);
        if(move_and_eat()) break;
    }

    cout << ret << endl;

    return 0;
}
