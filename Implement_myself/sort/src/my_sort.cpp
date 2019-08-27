#include "../include/my_sort.h"
#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>
#include <fstream>

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

bool bubble_sort(int* ary, const int size) {
    for(int i=0; i<size-1; i++) 
        for(int j=1; j<size-i; j++)  // 배열의 마지막 부분부터 정렬되므로 size-i만큼 순회.
            if(ary[j-1] > ary[j]) swap(ary[j-1], ary[j]);  
    return true;
}

void merge(int* ary, const int start, const int mid, const int end) {
    // set index //
    int i = start, j = mid+1, idx = 0;
    int ret[end - start + 1];

    while(i<=mid && j<=end) {
        if(ary[i] < ary[j]) ret[idx++] = ary[i++];
        // >=가 하나이상 있어야 된다.
        else if(ary[i] >= ary[j]) ret[idx++] = ary[j++];
    }
    // 남은 배열 처리
    while(i <= mid) ret[idx++] = ary[i++];
    while(j <= end) ret[idx++] = ary[j++];
        
    // copy to origin array
    int copy_idx = 0;
    for(int k=start; k<=end; k++) ary[k] = ret[copy_idx++];
}

void merge_sort_logic(int* ary, const int start, const int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        // divide //
        merge_sort_logic(ary, start, mid);
        merge_sort_logic(ary, mid+1, end);
        // conquer //
        merge(ary, start, mid, end);
    }
}

bool merge_sort(int* ary, const int size) {
    merge_sort_logic(ary, 0, size-1);
    return true;
}

void quick_sort_logic(int* ary, const int start, const int end) {
    if(start >= end) return;
    int pivot = ary[(start + end) / 2];
    int left = start, right = end;

    while(left <= right) {
        while(pivot > ary[left]) left++;
        while(pivot < ary[right]) right--;
        if(left<=right) {
            swap(ary[left], ary[right]);
            left++; right--;
        }
    }

    // while문을 빠져나오면 left가 right보다 1크다 그러므로
    // start ~ right, left ~ end로 나뉘어진다.
    quick_sort_logic(ary, start, right);
    quick_sort_logic(ary, left, end);
}

bool quick_sort(int* ary, const int size) {
    quick_sort_logic(ary, 0, size-1);
    return true;
}

/*
void self_test2(int *sample, const int size) {
    time_t start, end;
    double time;
    int ary[size];

    ofstream res_file("./result/result.txt");

    if(!res_file.is_open()) {
        printf("result file is not open.\n");
        return;
    }

    printf("Selection sort test\n");
    printf("Array size: %d\n", size);

    copy_ary(ary, sample, size);

    start = clock();
    selection_sort(ary, size);
    end = clock();

    time = (double)(end - start)/1000;
    printf("time: %d\n", time);
    print_ary(ary, size);
    printf("\n");

    printf("Insertion sort sort test\n");
    printf("Array size: %d\n", size);

    copy_ary(ary, sample, size);

    start = clock();
    insertion_sort(ary, size);
    end = clock();

    time = (double)(end - start)/1000;

    printf("time: %d\n", time);
    print_ary(ary, size);
    printf("\n");

    printf("Bubble sort test\n");
    printf("Array size: %d\n", size);

    copy_ary(ary, sample, size);

    start = clock();
    bubble_sort(ary, size);
    end = clock();

    time = (double)(end - start)/1000;

    printf("time: %d\n", time);
    print_ary(ary, size);
    printf("\n");

    printf("Merge sort test\n");
    printf("Array size: %d\n", size);

    copy_ary(ary, sample, size);

    start = clock();
    merge_sort(ary, size);
    end = clock();

    time = (double)(end - start)/1000;
    
    printf("time: %d\n", time);
    print_ary(ary, size);
    printf("\n");

    printf("Quick sort test\n");
    printf("Array size: %d\n", size);

    copy_ary(ary, sample, size);

    start = clock();
    quick_sort(ary, size);
    end = clock();

    time = (double)(end - start)/1000;
    
    printf("time: %d\n", time);
    print_ary(ary, size);
    printf("\n");

    ofstream res_file("./result/result.txt");
    if(res_file.is_open()) 
        for(int i=0; i<size; i++) res_file << ary[i] << " ";
    else 
        cout << "res file is not open." << endl;
    res_file.close();
}
*/

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
    printf("\n");

    printf("Insertion sort sort test\n");
    printf("Array size: %d\n", size);

    copy_ary(ary, sample, size);

    start = clock();
    insertion_sort(ary, size);
    end = clock();

    time = (double)(end - start)/1000;

    printf("time: %d\n", time);
    printf("\n");

    printf("Bubble sort test\n");
    printf("Array size: %d\n", size);

    copy_ary(ary, sample, size);

    start = clock();
    bubble_sort(ary, size);
    end = clock();

    time = (double)(end - start)/1000;

    printf("time: %d\n", time);
    printf("\n");

    printf("Merge sort test\n");
    printf("Array size: %d\n", size);

    copy_ary(ary, sample, size);

    start = clock();
    merge_sort(ary, size);
    end = clock();

    time = (double)(end - start)/1000;
    
    printf("time: %d\n", time);
    printf("\n");

    printf("Quick sort test\n");
    printf("Array size: %d\n", size);

    copy_ary(ary, sample, size);

    start = clock();
    quick_sort(ary, size);
    end = clock();

    time = (double)(end - start)/1000;
    
    printf("time: %d\n", time);
    printf("\n");

    ofstream res_file("./result/result.txt");
    if(res_file.is_open()) 
        for(int i=0; i<size; i++) res_file << ary[i] << " ";
    else 
        cout << "res file is not open." << endl;

    res_file.close();
}