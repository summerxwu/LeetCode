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
  std::unordered_map<int, int> types;
  types[fruits[0]] = 1;

  while (r < fruits.size()) {
    int size = types.size();
    if (size > 2) {
      if (types[fruits[l]] == 1) {
        types.erase(fruits[l]);
      } else {
        types[fruits[l]] = types[fruits[l]] - 1;
      }
      l++;
      continue;
    }
    maxNums = (r - l + 1 > maxNums ? r - l + 1 : maxNums);
    r++;
    if(r == fruits.size()){
      break;
    }
    if(types.find(fruits[r]) != types.end()){
      types[fruits[r]] = types[fruits[r]] +1;
    }
    else{
      types[fruits[r]] = 1;
    }
  }
  return maxNums;
}
int main() {
  vector<int> nums = { 0, 1, 2, 2 };
  cout << totalFruit(nums) << endl;
  return 0;
}
