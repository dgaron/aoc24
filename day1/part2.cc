#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include "bobo_utils.h"

int main() {

    std::vector<std::string> raw_data = readFile("input.txt");

    std::vector<int> left(raw_data.size());
    std::vector<int> right(raw_data.size());

    std::istringstream iss;

    for (std::size_t i = 0; i < raw_data.size(); ++i) {
        iss.str(raw_data[i]);
        int a, b;
        while (iss >> a >> b) {
            left[i] = a;
            right[i] = b;
        }
        iss.clear();
    }
    
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    long result = 0;

    std::unordered_map<int, int> counts;
    for (std::size_t i = 0; i < right.size(); ++i) {
        ++counts[right[i]];
    }
    for (std::size_t i = 0; i < left.size(); ++i) {
        result += left[i] * counts[left[i]];
    }

    std::cout << "Result: " << result << '\n';
}