class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1, end = arr.size() - 2;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid;
            } else if (arr[mid] > arr[mid - 1]) { //mid is in the increasing slop
                st = mid + 1;
            } else { //mid is in the decreasing slop
                end = mid - 1;
            }
        }
        return -1;
    }
};