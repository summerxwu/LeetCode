#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
  size_t findBoundary(vector<int> &nums, int target, bool leftBond = true) {
    int left = 0;
    int right = nums.size() - 1;
    int pivot = ((unsigned int)left + (unsigned int)right) >> 1;
    while (left <= right) {
      int tmp = nums[pivot];
      if (tmp == target) {
        if (leftBond) {
          if(pivot ==0){
            return pivot;
          }
          if (nums[pivot - 1] == target) {
            right = pivot - 1;
            pivot = ((unsigned int)left + (unsigned int)right) >> 1;
            continue;
          } else {
            return pivot ;
          }
        } else {
          if(pivot == nums.size() -1){
            return pivot;
          }
          if (nums[pivot + 1] == target) {
            left = pivot + 1;
            pivot = ((unsigned int)left + (unsigned int)right) >> 1;
            continue;
          } else {
            return pivot ;
          }
        }
      }
      if (target < tmp) {
        right = pivot - 1;
      } else {
        left = pivot + 1;
      }
      pivot = ((unsigned int)left + (unsigned int)right) >> 1;
    }
    return -1;
  }

  vector<int> searchRange(vector<int> &nums, int target) {

    int lfb = findBoundary(nums, target, true);
    int rfb = findBoundary(nums, target, false);

    return { lfb, rfb };
  }
};

int main() {
  vector<int> nums = { 1 };
  int target = 1;
  Solution s;
  vector<int> result = s.searchRange(nums, target);

  cout << "[ " << result[0] << ", " << result[1] << " ]" << endl;
  return 0;
}
