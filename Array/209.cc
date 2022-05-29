#include <iostream>
#include <vector>
using namespace std;
int rangeSumGE(vector<int> &nums, int &f, int &t, int &target) {
  int result = 0;
  for (int i = f; i <= t; i++) {
    result += nums[i];
  }
  return result >= target;
}
int func(vector<int> &nums, int target) {
  int lft = 0;
  int rht = 0;
  int lenght = nums.size() + 1;
  while (rht < nums.size()) {
    if (rangeSumGE(nums, lft, rht, target)) {
      if (rht - lft + 1 < lenght) {
        lenght = rht - lft + 1;
      }
      lft++;
      continue;
    }
//    if (rht + 1 >= nums.size()) {
//      lft++;
//      rht = lft;
//      continue;
//    }
    rht++;
  }
  return lenght == nums.size() + 1 ? 0 : lenght;
}
int main() {

  vector<int> nums = { 2,3,1,2,4,3};
  int target = 7;
  int ret = func(nums, target);
  cout << ret;
  cout << endl;
  return 0;
}
