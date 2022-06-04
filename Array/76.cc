#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool allexists(unordered_map<char, int> &m) {
  auto it = m.begin();
  while (it != m.end()) {
    if (it->second > 0) {
      return false;
    }
    it++;
  }
  return true;
}

void sub(unordered_map<char, int> &m, char t) {
  auto iter = m.find(t);
  if (iter != m.end()) {
    int rlt = iter->second;
    if (rlt > 0) {
      iter->second = rlt - 1;
    } else {
      iter->second = 0;
    }
  }
  return;
}

void add(unordered_map<char, int> &m, char t) {
  auto iter = m.find(t);
  if (iter != m.end()) {
    int rlt = iter->second;
    iter->second = rlt + 1;
  }
  return;
}

string minWindow(string s, string t) {
  unordered_map<char, int> checker;
  int l = 0;
  int r = 0;
  int min = 1000000;
  string sb = "";
  // init the checker
  for (int i = 0; i < t.size(); i++) {
    checker[t[i]] = 0;
  }

  for (int i = 0; i < t.size(); i++) {
    add(checker, t[i]);
  }
  sub(checker, s[0]);
  while (r < s.size()) {
    if (allexists(checker)) {
      min = r - l + 1 < min ? r - l + 1 : min;
      sb = s.substr(l, min);
      for (int i = 0; i < t.size(); i++) {
        add(checker, t[i]);
      }
      l++;
      if (r < l) {
        r = l;
      }
      sub(checker, s[l]);
      continue;
    }
    r++;
    if (r >= s.size()) {
      break;
    }
    sub(checker, s[r]);
  }
  return sb;
}
int main() {
  string s = "ADOBECODEBANC", t = "ABC";
  cout << minWindow(s, t);
  cout << endl;
  return 0;
}
