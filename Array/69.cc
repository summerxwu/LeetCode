#include <iostream>
using namespace std;

int sqrt1(int x) {
  if (x < 2) {
    return x;
  }
  return sqrt1(x >> 2) << 1;
}

int sqrt2(int x) {
  if (x < 2)
    return x;

  int left = sqrt2(x >> 2) << 1;
  int right = left + 1;
  return (long)right * right > x ? left : right;
}

int sqrt(int &x) {
  int lft = 1;
  int rht = x;

  if (x == 0) {
    return 0;
  }
  if (x >= 6) {
    rht = x / 2;
  }
  int pivot = ((unsigned int)lft + (unsigned int)rht) >> 1;
  while (lft <= rht) {

    if ((long)pivot * pivot <= x && (long)(pivot + 1) * (pivot + 1) > x) {
      return pivot;
    }

    if ((long)pivot * pivot > x) {
      rht = pivot - 1;
    } else {
      lft = pivot + 1;
    }
    pivot = ((unsigned int)lft + (unsigned int)rht) >> 1;
  }
  return pivot;
}

int main() {
  int x = 0;
  cin >> x;
  cout << sqrt1(x) << endl;
}
