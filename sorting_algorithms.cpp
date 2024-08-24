#include "sorting_algorithms.h"
#include <iostream>

using namespace std;

void printVector(const vector<int>& vec) {
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

void insertionSort(vector<int>& vec) {
    for (int i = 1; i < vec.size(); i++) {
        int curr_idx = i-1;
        int value = vec[i];
        while (curr_idx >= 0 && value < vec[curr_idx]) {
            vec[curr_idx+1] = vec[curr_idx];
            curr_idx--;
        }
        vec[curr_idx+1] = value;
    }
}

void selectionSort(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        int curr_min = i;
        for (int j = i+1; j < vec.size(); j++) {
            if (vec[j] < vec[curr_min]) {
                curr_min = j;
            }
        }
        swap(vec[i], vec[curr_min]);
    }
}

void merge(vector<int> vec, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftVec(n1);
    vector<int> rightVec(n2);

    for (int i = 0; i < n1; i++) {
        leftVec[i] = vec[left+i];
    }
    for (int i = 0; i < n2; i++) {
        rightVec[i] = vec[mid+1+i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftVec[i] <= rightVec[j]) {
            vec[k] = leftVec[i];
            i++;
        } else {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }
}

void mergeSort(vector<int>& vec, int left, int right) {
    if (left < right) {
        int mid = left + (right-left) / 2;
        mergeSort(vec, left, mid);
        mergeSort(vec, mid+1, right);
        merge(vec, left, mid, right);
    }
}

void heapSort(vector<int>& vec) {
    return;
}

