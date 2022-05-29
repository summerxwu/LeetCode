#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int lh = 0;
    int rh = nums.size() - 1;
    // maybe overflow
    int pivot = ((unsigned int)lh + (unsigned int)rh) >> 1;
    while (lh <= rh) {
      if (nums[pivot] == target) {
        return pivot;
      }
      if (nums[pivot] < target) {
        lh = pivot + 1;
      } else {
        rh = pivot - 1;
      }
      pivot = ((unsigned int)lh + (unsigned int)rh) >> 1;

    }
    return -1;
  }
};
int main() {
  std::vector<int> a = { -1, 0, 3, 5, 9, 12 };
  int target = 12;
  Solution s;
  int ret = s.search(a, target);
  printf("ret : %d\n", ret);
  return 0;
}
