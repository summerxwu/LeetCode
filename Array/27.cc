#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int val) {
  int pr = 0;
  int lf = 0;
  while (lf < nums.size()) {
    if (nums[lf] != val) {
      nums[pr] = nums[lf];
      pr++;
    }
    lf++;
  }
  return pr;
}
int main() {
  vector<int> input = { 2, 3, 3, 4, 4, 4, 5, 5, 6, 7, 8 };
  int ret = removeElement(input, 4);
  for (int i = 0; i < ret; i++) {
    cout << input[i] << ",";
  }
  cout << endl;
  return 0;
}
