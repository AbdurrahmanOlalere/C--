#include <iostream>
#include "RWC_solution.h"  // Include the header file for your solution class

void runTest(const std::vector<std::vector<int>>& accounts, int expected) {
    Solution solution;
    int result = solution.maximumWealth(accounts);
    if (result == expected) {
        std::cout << "Pass\n";
    } else {
        std::cout << "Fail: Expected " << expected << ", Got " << result << "\n";
    }
}

int main() {
    // Test cases
    runTest({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 24);
    runTest({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}}, 33);

    // Add more test cases as needed

    return 0;
}