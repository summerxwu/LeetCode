#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int> &nums) {
  int lf = 0;
  int rt = 0;
  while (rt < nums.size()) {
    if (nums[lf] != nums[rt]) {
      lf++;
      nums[lf] = nums[rt];
    }
    rt++;
  }
  return lf+1;
}

int main(){
  vector<int> input = {1,1,2};
  int ret = removeDuplicates(input);
  for(int i = 0;i<ret;i++){
    cout<<input[i] <<",";
  }
  cout << endl;
  return 0;
}
