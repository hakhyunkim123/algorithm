#pragma once
void print_ary(const int* ary, const int size);

void copy_ary(int* ary, const int* sample, const int size);

void self_test(int *sample, const int size);

bool selection_sort(int* ary, const int size);

bool insertion_sort(int* ary, const int size);

bool bubble_sort(int* ary, const int size);

bool merge_sort(int* ary, const int size);
void merge_sort_logic(int* ary, const int size, const int start, const int end);
void merge(int* ary, const int size, const int start, int const mid, const int end);

bool quick_sort(int* ary, const int size);
void quick_sort_logic(int* ary, const int start, const int end);
