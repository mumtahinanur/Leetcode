#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> vec = {1, 2, 3, 4, 5};

  cout << "size = " << vec.size() << endl;

  vec.push_back(25);
  vec.push_back(76);

  cout << "after pushing\n";
  cout << "size = " << vec.size() << endl;

  vec.pop_back();
  vec.pop_back();

  cout << "after poping\n";
  cout << "size = " << vec.size() << endl;

  for (int val : vec) {
    cout << val << endl;
  }

  cout << "front = " << vec.front() << endl;
  cout << "back = " << vec.back() << endl;
  cout << "at index 2 = " << vec.at(2) << endl;

  return 0;
}