#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<string> commonChars(vector<string> &words) {
    vector<string> result;
    int hashset[26] = {0};
    for(int i = 0;i<26;i++){
      hashset[i] = 100;
    }
    for (int i = 0; i < words.size(); i++) {
      int orig[26] = { 0 };
      for (int j = 0; j < words[i].size(); j++) {
        orig[words[i][j] - 'a']++;
      }
      // update hashset
      for (int k = 0; k < 26; k++) {
        int t1 = orig[k];
        int t2 = hashset[k];
        hashset[k] = std::min(t1, t2);
      }
    }
    // print
    for (int i = 0; i < 26; i++) {
      if (hashset[i] != 0) {
        result.push_back("a" + i);
      }
    }
    return result;
  }
};

int main() {
  vector<string> words = { "bella", "label", "roller" };
  Solution st;
  auto rlt = st.commonChars(words);
  for (int i = 0; i < rlt.size(); i++) {
    cout << rlt[i] << endl;
  }
  return false;
}
