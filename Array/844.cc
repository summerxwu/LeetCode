#include <iostream>
#include <string>
using namespace std;
string backspaceString(string s) {
  int lft = 0;
  int rht = 0;
  while (rht < s.size()) {
    if (s[rht] != '#') {
      s[lft] = s[rht];
      lft++;
    } else {
      lft = lft - 1 < 0 ? 0 : lft - 1;
    }
    rht++;
  }
  return s.substr(0, lft);
}
bool backspaceCompare(string s, string t) {
  return backspaceString(s) == backspaceString(t);
}
int main() {
  string s = "abcd#ef##";
  cout << backspaceString(s);
  cout << endl;
  return 0;
}
