#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* -------- brute force --------
int majorityElement(vector<int>& nums) {
  int n = nums.size();

  for (int val : nums) {
    int freq = 0;
    for (int el : nums) {
      if( val == el) {
          freq++;
      }
    }

    if (freq > n/2) {
      return val;
    }
  }
  return -1;
} */

int majorityElement(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return nums[0];

    sort(nums.begin(), nums.end());

    int freq = 1, ans = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i-1]) {
            freq++;
        }
        else {
            freq = 1;
            ans = nums[i];
        }

        if (freq > n/2) {
            return ans;
        }
    }
    return -1;
} 

// the best is moore's algorithm (leetcode 169)

int main()
{
  vector<int> nums = {2,2,1,1,1,2,2};

  cout << majorityElement(nums);

  return 0;
}