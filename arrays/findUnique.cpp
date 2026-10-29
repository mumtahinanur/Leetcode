#include<bits/stdc++.h>
using namespace std;

int main()
{
  int arr[] = {1, 2, 3, 8, 1, 2, 3, 4};
  int size = sizeof(arr) / sizeof(arr[0]);

  cout << "Values that occur exactly once: ";
  
  for (int i = 0; i < size; i++) {
    int count = 0;
    for (int j = 0; j < size; j++) {
      if (arr[i] == arr[j]) {
        count++;
      }
    }

    if (count == 1) {
      cout << arr[i] << " ";
    }
  }
  cout << '\n';

  return 0;
}