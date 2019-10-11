#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

void map_selfTest() {
    map<string, int, greater<string>> m;

    m.insert({"kim", 100});
    printf("%s --> %d\n", "kim", m.find("kim")->second);

    m.insert({"kim", 50});
    printf("%s count --> %d\n", "kim", m.count("kim"));
    printf("%s --> %d\n", "kim", m.find("kim")->second);

    printf("%d\n", m.count("kim"));

    m.insert({"Lee", 50});
    for(auto it = m.begin(); it != m.end(); it++) {
        printf("key: %s, value: %d\n", it->first.c_str(), it->second);
    }
}

void multiMap_selfTest() {
    multimap<string, int, greater<string>> mm;
    mm.insert({"kim", 100});
    mm.insert({"kim", 50});

    printf("count --> %d\n", mm.count("kim"));

    mm.insert({"Lee", 50});
    mm.insert({"kim", 150});

    printf("%s value: %d, count: %d\n", "kim", mm.find("kim")->second, mm.count("kim"));

    for(auto it = mm.begin(); it != mm.end(); it++) {
        printf("key: %s, value: %d\n", it->first.c_str(), it->second);
    }

    for(auto it = mm.lower_bound("kim"); it != mm.upper_bound("kim"); it++) 
        printf("[bound]key: %s, value: %d\n", it->first.c_str(), it->second);
}

int main() {
    //multiMap_selfTest();
    map_selfTest();
    return 0;
}