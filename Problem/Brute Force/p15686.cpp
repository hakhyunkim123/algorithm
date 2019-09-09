#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

struct pos {
    int x, y;
    pos(int mx, int my) { x=mx; y=my; }
    pos() {}
};

const int INF = INT_MAX;

vector<pos> home, chicken;
int M, N, ret = INF;

int get_distance(const vector<pos> selected) {
    int sum = 0;
    for(int i=0; i<home.size(); i++) {
        int dis = INF;
        for(int j=0; j<selected.size(); j++) 
            dis = min(dis, abs(home[i].x - selected[j].x) + 
                            abs(home[i].y - selected[j].y));
        sum += dis;
    }
    return sum;
}

void select(int idx, int size, vector<pos>& selected) {
    if(size == M) {
        ret = min(ret, get_distance(selected));
        return;
    }
    for(int i=idx+1; i<chicken.size(); i++) {
        selected.push_back(chicken[i]);
        select(i, size+1, selected);
        selected.pop_back();
    }
    return;
}

int main() {
    freopen("../Samples/p15686_sample.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    int p;
    for(int i=0; i<N; i++) 
        for(int j=0; j<N; j++) {
            scanf("%d", &p);
            if(p == 1) home.push_back(pos(i, j));
            else if(p == 2) chicken.push_back(pos(i, j));
        }

    for(int i=0; i<=chicken.size() - M; i++) {
        vector<pos> selected;
        selected.push_back(chicken[i]);
        select(i, 1, selected);
    }

    printf("%d\n", ret);
    return 0;
}