#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H
#include <vector>
#include <functional>
#include <string>

using namespace std;

void printVector(const vector<int>& vec);

void insertionSort(vector<int>& vec);
void selectionSort(vector<int>& vec);
void mergeSort(vector<int>& vec);
void heapSort(vector<int>& vec);
void quickSort(vector<int>& vec);
void bubbleSort(vector<int>& vec);

void heapify(std::vector<int>& arr, int n, int i); // for heapSort
int partition(std::vector<int>& arr, int low, int high); // for quickSort

const vector<function<void(vector<int>&)>> sorts = {selectionSort, insertionSort, mergeSort, heapSort, quickSort, bubbleSort};
const vector<string> names = {"selection", "insertion", "merge", "heap", "quick", "bubble"};

#endif