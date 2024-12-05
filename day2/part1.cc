#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "bobo_utils.h"

#define MAX_DISTANCE 3

bool is_level_safe(const std::vector<int>& level) {
    bool safe = true;
    bool increasing = true;
    bool decreasing = true;
    for (std::size_t i = 0; i < level.size()-1; ++i) {
        if (level[i] < level[i+1]) {
            decreasing = false;
        } else if (level[i] > level[i+1]) {
            increasing = false;
        } else if (level[i] == level[i+1]) {
            return false;
        }
        if (abs(level[i] - level[i+1]) > MAX_DISTANCE) {
            safe = false;
        }
    }
    safe &= (increasing ^ decreasing);
    return safe;
}

int main() {

    std::vector<std::string> raw_data = readFile("input.txt");
    
    int result = 0;

    std::istringstream iss;
    for (const auto &s : raw_data) {
        std::vector<int> current_level;
        int n;
        iss.str(s);
        while(iss >> n) {
            current_level.push_back(n);
        }

        bool safe = is_level_safe(current_level);
        // result += safe; is too ugly
        if (safe) {
            ++result;
        }
        iss.clear();
    }
    std::cout << "Result: " << result << '\n';        
}
