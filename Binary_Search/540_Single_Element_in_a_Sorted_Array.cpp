class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int st = 0, end = n - 1;

        if (n == 1) { //single element array
            return arr[0];
        } 
        if (arr[0] != arr[1]) { //single element at 1st index
            return arr[0];
        }
        if (arr[n-1] != arr[n-2]) { //single element at last index
            return arr[n-1];
        }

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (arr[mid-1] != arr[mid] && arr[mid] != arr[mid+1]) { //found ans
                return arr[mid];
            }

            if (mid % 2 == 0) { //even elements both side
                if (arr[mid] == arr[mid-1]) { //left search space
                    end = mid - 1; 
                } else { //right search space
                    st = mid + 1;
                }
            } else { //odd elements both side
                if (arr[mid] == arr[mid-1]) { //right search space
                    st = mid + 1; 
                } else { //left search space
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};