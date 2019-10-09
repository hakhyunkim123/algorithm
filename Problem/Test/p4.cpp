#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 50;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int N;
char map[MAX][MAX];

bool in_range(int x, int y) { return x>=0 && x<N && y>=0 && y<N; }

bool can_conquer(int bx, int by, int x, int y, int dir) {
    int company[26] = {0, };
    char my = map[bx][by];
    int my_cnt = 0;
    bool suc = false;
    if(map[x][y] == '0') {
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!in_range(nx, ny)) continue;

            if(map[nx][ny] == my) my_cnt++;
            company[map[nx][ny] - 'A']++;
        }
        suc = true;
    }
    else {
        int d = map[x][y] - '0';
        int mask[4] = {0, };
        int idx = 0;
        for(int i=0; i<4; i++) {
            mask[i] = d%2;
            if(d/2 == 0) break;
            d /= 2;
        }
        for(int i=0; i<4; i++) {
            if(!mask[i]) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(!in_range(nx, ny)) continue;
                if(bx == nx && by == ny)  {
                    suc = true;
                }
                if(map[nx][ny] == my) {
                    my_cnt++;
                }
                company[map[nx][ny] - 'A']++;
            }
        }
    }

    if(!suc) return false;
    for(int i=0; i<26; i++) 
        if(i != my - 'A' && company[i] >= my_cnt) {
            return false;
        }
        
    return true;
}

int main() {
    freopen("p4_sample.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) cin >> map[i][j];
  
    while(true) {
        queue< pair<int, int> > q;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++) {
                if(map[i][j] >= 'A' && map[i][j] <= 'Z') q.push({i, j});
            }

        bool end = false;
        vector<pair<char, pair<int, int>>> conquer_list;
        while(!q.empty()) {
            int cur_x = q.front().first;
            int cur_y = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int nx = cur_x + dx[i];
                int ny = cur_y + dy[i];
                if(in_range(nx, ny) && (map[nx][ny] >= '0' && map[nx][ny] <= '9')) {
                    if(can_conquer(cur_x, cur_y, nx, ny, i)) {
                        conquer_list.push_back({map[cur_x][cur_y], {nx, ny}});
                        end = true;
                    }
                }
            }
        }
        for(int i=0; i<conquer_list.size(); i++) {
            int x = conquer_list[i].second.first;
            int y = conquer_list[i].second.second;
            char company = conquer_list[i].first;
            map[x][y] = company;
        }
        if(!end) break; 

        printf("===============\n");
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }
        printf("===============\n");
    }
    return 0;
}