#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size() -1;
    int p = ((unsigned int)l +(unsigned int)r) >> 1;
    while (l<=r){
      int tv = nums[p];
      if (tv == target){
        return p;
      }
      if(tv < target){
        l = p +1;
      }
      else{
        r = p -1;
      }
      p = ((unsigned int)l +(unsigned int)r) >> 1;

    }
    return l;
  }
};

int main() {
  vector<int> nums = { 1, 3, 5, 6 };
  int target = 2;
  Solution s;
  int ret = s.searchInsert(nums, target);
  std::cout << "ret: " << ret << endl;
  return 0;
}
