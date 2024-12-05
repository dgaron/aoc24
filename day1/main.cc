#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

#include "bobo_utils.h"

int count_appearances(const std::vector<int> &v, int target) {
    int result = 0;
    for (auto n : v) {
        if (n == target) {
            ++result;
        }
    }
    return result;
}

int main() {

    std::vector<std::string> raw_data = readFile("input.txt");

    std::vector<int> left(raw_data.size());
    std::vector<int> right(raw_data.size());

    std::istringstream iss;

    int a,b;

    for (std::size_t i = 0; i < raw_data.size(); ++i) {
        iss.str(raw_data[i]);
        while (iss) {
            iss >> a;
            left[i] = a;
            iss >> b;
            right[i] = b;
        }
        iss.clear();
    }

    // Part One
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    long result = 0;
    for (std::size_t i = 0; i < left.size(); ++i) {
        result += abs(left[i] - right[i]);
    }

    std::cout << "The result for part one is: " << result << '\n';

    // Part Two
    result = 0;
    std::map<int, int> counts;
    for (std::size_t i = 0; i < left.size(); ++i) {
        if (auto search = counts.find(left[i]); search == counts.end()) {
            counts[left[i]] = count_appearances(right, left[i]); 
        }
        result += left[i] * counts[left[i]];
    }

    std::cout << "The result for part two is: " << result << '\n';
}