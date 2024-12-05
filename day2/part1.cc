#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "bobo_utils.h"

int main() {

    std::vector<std::string> raw_data = readFile("input.txt");
    
    int result = 0;
    const int MAX_DISTANCE = 3;

    std::istringstream iss;
    for (const auto &s : raw_data) {
        std::vector<int> current;
        int n;
        iss.str(s);
        while(iss >> n) {
            current.push_back(n);
        }

        bool safe = true;
        std::size_t lt_count = 0;
        std::size_t gt_count = 0;
        for (std::size_t i = 1; i < current.size(); ++i) {
            if (current[i] < current[i-1]) {
                ++lt_count;
            } else if (current[i] > current[i-1]) {
                ++gt_count;
            }
            if (abs(current[i] - current[i-1]) > MAX_DISTANCE) {
                safe = false;
            }
        }

        if (lt_count != current.size()-1 && gt_count != current.size()-1) {
            safe = false;
        }

        if (safe) {
            ++result;
        }
        iss.clear();
    }
    std::cout << "Result: " << result << '\n';        
}
