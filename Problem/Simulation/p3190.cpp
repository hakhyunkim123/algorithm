#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 101;
int map[MAX][MAX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int N, M, L;
queue< pair<int, char> > order;
queue< pair<int, int> > snake;

void print_map() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)  printf("%d ", map[i][j]);
        printf("\n");
    }
}

bool in_range(int x, int y) { return x>=0 && x<N && y>=0 && y<N; }
bool can_move(int x, int y) { return in_range(x, y) && map[x][y] != 2; }

int main() {
    //freopen("../Samples/p3190_sample.txt", "r", stdin);
    scanf("%d", &N);
    scanf("%d", &M);
    for(int i=0; i<M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        map[x-1][y-1] = 1;
    }
    scanf("%d", &L);
    for(int i=0; i<L; i++) {
        int sec; char dir;
        scanf("%d%*[ \n\t]%c", &sec, &dir);
        order.push({sec, dir});
    }

    int dir_idx = 0;
    pair<int, char> cur_order = order.front();
    int cx = 0, cy = 0;
    order.pop();
    snake.push({cx, cy});
    map[cx][cy] = 2;
    int time = 0;

    while(true) {
        time++;
        // move snake
        int nx = cx + dx[dir_idx];
        int ny = cy + dy[dir_idx];
        //printf("time: %d, order time: %d\n", time, cur_order.first);
        //printf("cur: (%d, %d)\tnext: (%d, %d)\n", cx, cy, nx, ny);
        if(!can_move(nx, ny)) {
            //printf("(%d %d) stop!\n", nx, ny);
            break;
        }
        // update snake, eat apple
        if(map[nx][ny] != 1) {
            map[snake.front().first][snake.front().second] = 0;
            snake.pop();
        }
        snake.push({nx, ny});
        map[nx][ny] = 2;

        cx = nx; cy = ny;

        // update direction
        if(time == cur_order.first) {
            //printf("change dir!\n");
            if(cur_order.second == 'D') dir_idx = (dir_idx+1)%4;
            else if(cur_order.second == 'L') {
                if(dir_idx == 0) dir_idx = 3;
                else dir_idx = dir_idx - 1;
            }
            cur_order = order.front();
            order.pop();
        }
        //print_map();
        //int stop;
        //cin >> stop;
    }
    printf("%d\n", time);
    return 0;
}