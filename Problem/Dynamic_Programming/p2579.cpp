#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 301;
int N;
int stairs[MAX];
int ret[MAX][2];

int main() {
    //freopen("p2579_sample.txt", "r", stdin);
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &stairs[i]);
    
    ret[0][0] = 0;
    ret[0][1] = 0;
    ret[1][0] = stairs[1];
    ret[1][1] = stairs[0];
    ret[2][0] = stairs[1]+stairs[2];
    ret[2][1] = stairs[2];

    for(int i=3; i<=N; i++) {
        ret[i][0] = ret[i-1][1] + stairs[i];
        ret[i][1] = max(ret[i-2][0] + stairs[i], ret[i-2][1] + stairs[i]);
    }

    printf("%d\n", max(ret[N][0], ret[N][1]));
}