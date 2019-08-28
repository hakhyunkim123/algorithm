#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1001;
int cache[MAX];

long long dp(int length) {
    if(length == 1) return 1;
    if(length == 2) return 2;

    int& ret = cache[length];
    if(ret != -1) return ret;

    ret = 0;
    return ret = (dp(length-1) + dp(length-2)) % 10007;
}

int main() {
    //freopen("../Samples/p11726_sample.txt", "r", stdin);
    
    int n;
    scanf("%d", &n);

    memset(cache, -1, sizeof(cache));
    long long ret = dp(n);
    printf("%d\n", ret);

    return 0;
}