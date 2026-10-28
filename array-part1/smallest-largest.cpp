#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int nums[] = {5, 15, 22, 1, -15, -24};
    int size = 6;

    int sIndex = 0;
    int lIndex = 0;

    for (int i = 1; i < size; ++i) {
        if (nums[i] < nums[sIndex])  {
            sIndex = i;
        }
        if (nums[i] > nums[lIndex]) {
            lIndex = i;
        }
    }

    cout << "smallest = " << nums[sIndex] << '\n';
    cout << "smallest at index " << sIndex << '\n';
    cout << "largest = " << nums[lIndex] << '\n';
    cout << "largest at index " << lIndex << "\n\n";

    swap(nums[sIndex], nums[lIndex]);

    cout << "array after swapping the max and min\n";

    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}