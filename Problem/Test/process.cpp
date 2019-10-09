#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool in_range(int x, int y, int N) { return x>=0 && x<N && y>=0 && y<N; }


vector<string> read_string_by_getline() {
    vector<string> list;

    while(true) {
        string in_string;
        getline(cin, in_string);
        if(in_string.empty()) break;
        list.push_back(in_string);
    }

    return list;
}

vector<string> my_string_tokenizer2() {
    vector<string> line = read_string_by_getline();
    // Process last word of line.
    // We split words using " " character. But, Last character is not " ". 
    // So, Add " " in last index of line.
    for(int i=0; i<line.size(); i++) line[i] += " "; 

    vector<string> words;
    for(int i=0; i<line.size(); i++) {
        int index = 0;
        for(int j = 0; j < line[i].length(); j++) 
            if(line[i][j] == ' ') {
                words.push_back(line[i].substr(index, j - index));
                index = j + 1;
            }
    }

    return words;
}

vector<string> my_string_tokenizer(vector<string> list) {
    vector<string> words;
    for(int i=0; i<list.size(); i++) {
        int index = 0;
        for(int j = 0; j < list[i].length(); j++) {
            if(list[i][j] == ' ') {
                words.push_back(list[i].substr(index, j - index));
                index = j + 1;
            }
        }
        // We split words using " " character. But, Last character is not " "
        // So, we have to process Last word individually.
        words.push_back(list[i].substr(index, list[i].length() - index));
    }
    return words;
}


vector<int> mask_lower(int num) {
    vector<int> list;
    int index = 0;
    while(true) {
        list.push_back(num%2);
        if(num/2 == 0) break;
        num /= 2;
    }

    reverse(list.begin(), list.end());
    return list;
}

vector<int> mask_upper(int num) {
    vector<int> list;
    int index = 0, tmp = num;
    while(true) {
        if(tmp/2 == 0) break;
        tmp /= 2;
        index++;
    }

    for(int i = index; i>=0; i--) {
        int cur = pow(2, i);
        printf("cur: %d, num: %d\n", cur, num);
        if(num - cur >= 0) {
            list.push_back(cur);
            num -= cur;
        }
    }

    return list;
}

void map_char_to_int() {
    int N;
    cin >> N;

    char map[50][50];

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
            if(map[i][j] >= 'A' && map[i][j] <= 'Z') printf("%c --> (%d, %d)\n", map[i][j], i, j);
        }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) printf("%c ", map[i][j]);
        printf("\n");
    }
}

int main() {
    freopen("sample.txt", "r", stdin);

    map_char_to_int();

    /*vector<int> ret = mask_upper(11);
    for(int i=0; i<ret.size(); i++) printf("%d ", ret[i]);
    printf("\n");*/

    return 0;
}