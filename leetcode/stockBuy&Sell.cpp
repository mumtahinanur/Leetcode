#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Initialize the buying price with the first day's price
        int maxProfit = 0, currProfit = 0, bestBuy = prices[0];

        // Traverse the array from the second day to the last day
        for (int i = 1; i < prices.size(); i++) {
            // If selling today gives a better profit, update the profit
            if (prices[i] > bestBuy) {
                currProfit = prices[i] - bestBuy;
                maxProfit = max(maxProfit, currProfit);
            }
            // If we find a lower price, update the buy value
            bestBuy = min(bestBuy, prices[i]);
        }
        return maxProfit;
    }
};

int main() {
   // Sample input
   vector<int> prices = {7, 1, 5, 3, 6, 4};

   Solution sol;
   int result = sol.maxProfit(prices);

   cout << "Maximum Profit: " << result << endl;

   return 0;
}