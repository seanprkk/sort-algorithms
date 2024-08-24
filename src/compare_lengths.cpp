#include "sorting_algorithms.h"
#include <iostream>
#include <vector>
#include <functional>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int main() {

    vector<int> sizes = {10, 50, 100, 500, 1000, 5000, 10000, 50000};
    vector<vector<int>> lists;
    vector<double> times;

    const int sort_count = sorts.size();

    cout << "Generating shuffled lists... ";
    for (int size : sizes) {
        vector<int> curr = {};
        for (int i = 0; i < size; i++) {
            curr.push_back(i);
        }
        unsigned seed = system_clock::now().time_since_epoch().count();
        shuffle(curr.begin(), curr.end(), default_random_engine(seed));
        lists.push_back(curr);
    }
    cout << "Generated." << endl;

    // UP TO HERE: REQUEST USER INPUT ON WHICH SORT TO USE, TIME SORTS FOR VARIOUS SIZES, DISPLAY RESULTS
    // maybe convert results to csv or json file to read, manipulate and visualize in r/python/sql?

    int sort_index;
    cout << "-------------------------" << endl;
    cout << "Choose a sort type." << endl;
    for (int i = 0; i < sort_count; i++) {
        cout << "  " << i+1 << " ) " << names[i] << endl;
    }
    cout << "Enter the index: ";
    cin >> sort_index;
    sort_index--;

    vector<int> vec_copy;

    for (vector<int> list : lists) {
        vec_copy = list;
        auto start = high_resolution_clock::now();
        sorts[sort_index](vec_copy);
        auto stop = high_resolution_clock::now();
        double duration = duration_cast<nanoseconds>(stop-start).count();
        duration /= 1000;
        times.push_back(duration);
    }

    cout << "-------------------------" << endl;
    cout << "SORT TIMES by size (algorithm : " << names[sort_index] << ")" << endl;
    for (int i = 0; i < sizes.size(); i++) {
        cout << "   " << sizes[i] << ":   \t" << times[i] << "μs" << endl;
    }

    return 0;
}