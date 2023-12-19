# include <vector>
# include <utility>
# include "RWC_solution.h"

int maximumWealth(const std::vector<std::vector<int>>& accounts) {
    std::vector<std::pair<int, int>> unrankArrSums;
    int sum = 0;
    for (int i=0; i < accounts.size();i++) {
        sum = 0;
        for (int j=0; i < accounts[i].size();j++) {
            sum+= accounts[i][j];
        }
        
        unrankArrSums.push_back({sum,i});
    }
    for (int i = 0; i < unrankArrSums.size() - 1; i++) {
        for (int j = 0; j < unrankArrSums.size() - i - 1; j++) {
            if (unrankArrSums[j].first < unrankArrSums[j+1].first ) {
                std::swap(unrankArrSums[j], unrankArrSums[j+1]);
            }
        }
    }
    return unrankArrSums[0].first;
}

