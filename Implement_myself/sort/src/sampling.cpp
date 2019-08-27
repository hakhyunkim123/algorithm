#include "../include/sampling.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <string>

using namespace std;

//const string PATH = "C:\Users\hyun\Google 드라이브\programming\Implement_myself\sort\samples";

void print_file_is_not_open() { printf("file is not open..\n"); }

bool sampling(const int size) {
    ofstream file("./samples/sample.txt");
    if(!file.is_open()) {
        print_file_is_not_open();
        return false;
    }
    else {
        srand((unsigned int)time(NULL));
        for(int i=0; i<size; i++) {
            file << rand() % size << " ";
        }
    }
    file.close();
    return true;
}

bool sample_reading(int* ary, const int size) {
    ifstream file("./samples/sample.txt");

    if(!file.is_open()) {
        print_file_is_not_open();
        return false;
    }
    else {
        int idx = 0;
        while(!file.eof()) {
            file >> ary[idx];
            idx++;
        }
        printf("[Array size: %d] Sample reading success!\n", idx-1);
    }

    file.close();
    return true;
}

bool old_sampling(const int size) {
    freopen("sample.txt", "w", stdout);

    int ary[size];

    srand((unsigned int)time(NULL));
    for(int i=0; i<size; i++) {
        int num = rand() % size;
        ary[i] = num;
    }

    for(int i=0; i<size; i++) printf("%d ", ary[i]);

    return true;
}