#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "bobo_utils.h"

#define MAX_DISTANCE 3

bool is_report_safe(const std::vector<int>& report) {
    bool safe = true;
    bool increasing = true;
    bool decreasing = true;
    for (std::size_t i = 0; i < report.size()-1; ++i) {
        if (report[i] < report[i+1]) {
            decreasing = false;
        } else if (report[i] > report[i+1]) {
            increasing = false;
        } else if (report[i] == report[i+1]) {
            return false;
        }
        if (abs(report[i] - report[i+1]) > MAX_DISTANCE) {
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
        std::vector<int> current_report;
        int n;
        iss.str(s);
        while(iss >> n) {
            current_report.push_back(n);
        }

        bool safe = is_report_safe(current_report);
        // result += safe; is too ugly
        if (safe) {
            ++result;
        }
        iss.clear();
    }
    std::cout << "Result: " << result << '\n';        
}
