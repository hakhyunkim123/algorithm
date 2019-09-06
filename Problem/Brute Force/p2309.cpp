#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list, ans;

bool compare(int x, int y) { return x<y; }

bool set(int idx, int sum, vector<int>& ret) {
    if(sum > 100) return false;
    if(ret.size() == 7) {
        if(sum == 100) {
            for(int i=0; i<ret.size(); i++) ans.push_back(ret[i]);
            return true;
        }
        else return false;
    }

    bool suc = false;
    for(int i=idx+1; i<9; i++) {
        ret.push_back(list[i]);
        suc = set(i, sum + list[i], ret);
        if(suc) break;
        ret.pop_back();
    }

    return suc;
}

int main() {
    freopen("../Samples/p2309_sample.txt", "r", stdin);

    for(int i=0; i<9; i++) {
        int p;
        cin >> p;
        list.push_back(p);
    }

    vector<int> ret;
    for(int i=0; i<3; i++) {
        ret.clear();
        ret.push_back(list[i]);
        if(set(i, list[i], ret)) break;
    }

    sort(ans.begin(), ans.end(), compare);

    for(int i=0; i<ans.size(); i++) cout << ans[i] << endl;

    return 0;
}