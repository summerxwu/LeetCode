#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> func(vector<int> &nums) {

  vector<int> result(nums.size());
  int lft = 0;
  int rht = nums.size() - 1;
  int i = nums.size() - 1;
  while (lft <= rht) {
    if (abs(nums[lft]) >= abs(nums[rht])) {
      result[i] = nums[lft] * nums[lft];
      lft++;
    } else {
      result[i] = nums[rht] * nums[rht];
      rht--;
    }
    i--;
  }
  return result;
}

int main() {
  vector<int> input = {-7,-3,2,3,11};
  auto result = func(input);
  for(auto it : result){
    cout << it << ",";
  }
  cout << endl;
  return 0;
}
