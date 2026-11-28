class Solution {
public:
    // Helper function to check if it's possible to split the array into at most k subarrays
    // such that the maximum sum of any subarray does not exceed 'largestSum'.
    bool isValid(vector<int>& nums, int k, int n, int largestSum) {
        int subArr = 1;   // Count of subarrays needed
        int currentSum = 0; // Running sum of the current subarray

        for (int i = 0; i < n; i++) {
            // If any single element exceeds the proposed limit, this split is impossible.
            if (nums[i] > largestSum) {
                return false;
            }

            // Try to add the current element to the existing subarray.
            if (currentSum + nums[i] <= largestSum) {
                currentSum += nums[i];
            } else {
                // Otherwise, start a new subarray.
                subArr++;
                currentSum = nums[i];
            }
        }
        // Return true if we needed k or fewer subarrays within the constraint.
        return subArr <= k;
    }

    // Main function to find the minimum possible value of the largest sum among k subarrays.
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int totalSum = 0;

        // Calculate the total sum to determine the upper bound of our binary search.
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        // Binary search range for the answer:
        // Lower bound: 0 (or max(nums) for optimization)
        // Upper bound: totalSum (when k=1, the whole array is one subarray)
        int low = 0, high = totalSum;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If the current candidate 'mid' is valid, try to find a smaller maximum sum.
            if (isValid(nums, k, n, mid)) {
                ans = mid;      // Record a potentially optimal answer
                high = mid - 1; // Search left half for a smaller valid sum
            } else {
                // If 'mid' is too small (requires more than k subarrays), increase the limit.
                low = mid + 1;
            }
        }
        return ans;
    }
};