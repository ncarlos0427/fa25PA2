#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        data[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        if (size == 0) return -1;
        int minIndex = data[0];
        data[0] = data[size - 1];
        size--;
        if (size > 0) downheap(0, weightArr);
        return minIndex;
    }

    void upheap(int pos, int weightArr[]) {
        while (pos > 0) {
            int parent = (pos - 1) / 2;
            int childIdx = data[pos];
            int parentIdx = data[parent];

            if (weightArr[childIdx] >= weightArr[parentIdx]) break;

            int t = data[pos]; data [pos] = data[parent]; data [parent] = t;
            pos = parent;
        }
    }

    void downheap(int pos, int weightArr[]) {
        while (true) {
            int l = 2 * pos + 1;
            int r = 2 * pos + 2;
            int s = pos;

            if (l < size && data[l] < data[s]) s = l;
            if (r < size && data[r] < data[s]) s = r;
            if (s == pos) break;

            int temp = data[pos];

            data[pos] = data[s];
            data[s] = temp;

            pos = s;}
    }
};

#endif