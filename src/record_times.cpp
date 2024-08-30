#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <functional>
#include <map>
#include "include/json.hpp"
#include "sorting_algorithms.h"

using json = nlohmann::json;
using namespace std;
using namespace std::chrono;

int main() {
    vector<int> sizes = {10, 50, 100, 500, 1000, 5000, 10000, 50000};
    map<string, map<int, double>> timingData;

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

    for (int i = 0; i < sort_count; i++) {

        function<void(vector<int>&)> algorithm = sorts[i];
        string name = names[i];
        vector<int> vec_copy;

        for (vector<int> list : lists) {
            vec_copy = list;
            int size = list.size();
            auto start = high_resolution_clock::now();
            algorithm(vec_copy);
            auto stop = high_resolution_clock::now();
            double duration = duration_cast<nanoseconds>(stop-start).count();
            duration /= 1000;
            timingData[name][size] = duration;
        }
    }
    
    //write to json
    json jsonData;
    for (const auto& [sortType, sizes] : timingData) {
        for (const auto& [size, time] : sizes) {
            jsonData[sortType][to_string(size)] = time;
        }
    }
    //save to json file
    std::ofstream outFile("timing_data.json");
    outFile << jsonData.dump(4); // pretty-print with 4 spaces
    outFile.close();
    cout << "Data saved to timing_data.json" << endl;
    
    return 0;
}