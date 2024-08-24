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

    vector<double> times;

    const int sort_count = sorts.size();

    int vec_size;
    cout << "Enter the size of the list: ";
    cin >> vec_size;

    cout << "Generating list... ";
    vector<int> vec;
    for (int i = 1; i <= vec_size; i++) {
        vec.push_back(i);
    }
    cout << "Generated." << endl;

    cout << "Shuffling... ";
    unsigned seed = system_clock::now().time_since_epoch().count();
    shuffle(vec.begin(), vec.end(), default_random_engine(seed));
    cout << "Shuffled." << endl;

    if (vec_size <= 50) { 
        cout << "List: ";
        printVector(vec); 
    }

    vector<int> vec_copy;

    for (int i = 0; i < sort_count; i++) {
        vec_copy = vec;
        auto start = high_resolution_clock::now();
        sorts[i](vec_copy);
        auto stop = high_resolution_clock::now();
        double duration = duration_cast<nanoseconds>(stop-start).count();
        duration /= 1000;
        times.push_back(duration);
    }

    cout << "-------------------------" << endl;
    cout << "SORT TIMES for vector (size : " << vec_size << ")" << endl;
    for (int i = 0; i < sort_count; i++) {
        cout << "   " << names[i] << ": \t" << times[i] << "μs" << endl;
    }

    return 0;
}