#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;


int totalFruit(vector<int> &fruits) {
  int l = 0;
  int r = 0;
  int maxNums = 0;
  if (fruits.size() <= 2) {
    return fruits.size();
  }
  std::unordered_map<int,int> types;
  types[fruits[0]] = fruits[0];
  
  while (r < fruits.size()) {
    int size = types.size();
    if (size > 2) {
      types.erase(fruits[l]);
      l++;
      continue;
    }
    maxNums = (r - l + 1 > maxNums ? r - l + 1 : maxNums);
    r++;
    types[fruits[r]] = fruits[r];
  }
  return maxNums;
}
int main() {
  vector<int> nums = { 0,1,2,2 };
  cout << totalFruit(nums) << endl;
  return 0;
}
