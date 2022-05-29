#include <iostream>
#include <vector>
using namespace std;
void moveZeroes(vector<int> &nums){
  int lft = 0;
  int rht = 0;
  while(rht < nums.size()){
    if(nums[rht] != 0){
      nums[lft] = nums[rht];
      lft ++;
    }
    rht ++;
  }
  while(lft < nums.size()){
    nums[lft]=0;
    lft++;
  }
}

int main(){
  vector<int> input = {1,0,2,0,4,5,2,0};
  moveZeroes(input);
  for(int i = 0;i<input.size();i++){
    cout<< input[i] << ",";
  }
  cout<<endl;
  return 0;
}
