class Solution {
public:
    bool isValid(vector<int>& nums, int k, int n, int largestSum) {
        int subArr = 1, sum = 0;

        for (int i = 0; i < n; i ++) {
            if (nums[i] > largestSum) {
                return false;
            }

            if (sum + nums[i] <= largestSum) {
                sum += nums[i];
            } else {
                subArr++;
                sum = nums[i];
            }
        }
        return subArr > k ? false : true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        int st = 0, end = sum;
        int ans = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (isValid(nums, k, n, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};