#include "../include/my_sort.h"
#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

void print_ary(const int* ary, const int size) {
    for(int i=0; i<size; i++) printf("%d ", ary[i]);
    printf("\n");
}

void copy_ary(int* ary, const int* sample, const int size) {
    for(int i=0; i<size; i++) ary[i] = sample[i];
}

/**
 * time complexity : O(N^2)
 * space complexity : O(N)
 */
bool selection_sort(int* ary, const int size) {
    for(int i=0; i<size; i++) {
        int select_idx = i;
        for(int j=i+1; j<size; j++) 
            if(ary[select_idx] > ary[j]) select_idx = j; // fine min value.
        swap(ary[i], ary[select_idx]); 
    }
    return true;
}

/**
 * time complexity : O(N^2), 정렬되있다면 O(N)
 * space complexity : O(N)
 */ 
bool insertion_sort(int* ary, const int size) {
    for(int i=1; i<size; i++) { // 2번째 인덱스 부터 시작한다.
        int key = ary[i], j = i-1;  // 선택한 key부터 하위 인덱스로 비교한다.
        while(j>=0 && key < ary[j]) {
            ary[j+1] = ary[j];
            //swap(ary[j], ary[j+1]);
            j--;
        }
        ary[j+1] = key; // 해당 자리에 key값을 삽입한다. 
    }
    return true;
}

void self_test(int *sample, const int size) {
    time_t start, end;
    double time;
    int ary[size];

    printf("Selection sort test\n");
    printf("Array size: %d\n", size);
    copy_ary(ary, sample, size);
    start = clock();
    selection_sort(ary, size);
    end = clock();
    time = (double)(end - start)/1000;
    printf("time: %d\n", time);
    print_ary(ary, size);

    printf("Insertion sort sort test\n");
    printf("Array size: %d\n", size);
    copy_ary(ary, sample, size);
    start = clock();
    insertion_sort(ary, size);
    end = clock();
    time = (double)(end - start)/1000;
    printf("time: %d\n", time);
    print_ary(ary, size);
}