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

const vector<function<void(vector<int>&)>> sorts = {selectionSort, insertionSort};
const vector<string> names = {"selection", "insertion"};

#endif