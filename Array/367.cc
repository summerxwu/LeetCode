#include <iostream>
using namespace std;

bool isPerfectSquare(int num) {
  if (num == 0) {
    return true;
  }
  int lft = 0;
  int rht = num;
  if (num > 4) {
    rht = num / 2;
  }

  int pivot = ((unsigned int)lft + (unsigned int)rht) >> 1;
  while (lft <= rht) {
    if ((long)pivot * pivot == num) {
      return true;
    }
    if ((long)pivot * pivot > num) {
      rht = pivot - 1;
    } else {
      lft = pivot + 1;
    }
    pivot = ((unsigned int)lft + (unsigned int)rht) >> 1;
  }
  return false;
}

int main() {
  int num;
  cin >> num;
  cout << (isPerfectSquare(num) ? "Yes" : "No");
  cout << endl;
  return 0;
}
