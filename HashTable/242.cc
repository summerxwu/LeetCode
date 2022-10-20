#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
  bool isAnagram(string &s, string &t) {
    if (s.size() != t.size()) {
      return false;
    }
    int set[26] = { 0 };
    for (int i = 0; i < s.size(); i++) {
      set[s[i] - 'a']++;
    }
    for (int i = 0; i < t.size(); i++) {
      set[t[i] - 'a']--;
    }
    for(int i = 0;i<26;i++){
      if(set[i] != 0){
        return false;
      }
    }
    return true;
  }
};

int main() {
  string s = "adfadf";
  string t = "foowei";
  Solution sl;

  cout << sl.isAnagram(s, t) << endl;
  return 0;
}
