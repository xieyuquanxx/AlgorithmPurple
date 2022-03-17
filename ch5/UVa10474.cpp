#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define swap(a, b)                                                             \
  {                                                                            \
    int t = a;                                                                 \
    a = b;                                                                     \
    b = t;                                                                     \
  }
const int MAXN = 1e4 + 7;
#define LOCAL

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int n, q;
  int CASE = 1;
  while (scanf("%d%d", &n, &q) && n) {
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
      // cin >> vec[i];
      scanf("%d", &vec[i]);
    }
    sort(vec.begin(), vec.end());
    printf("CASE# %d:\n", CASE++);
    while (q--) {
      int num;
      scanf("%d", &num);
      int p = lower_bound(vec.begin(), vec.end(), num) - vec.begin();
      if (vec[p] == num)
        printf("%d found at %d\n", num, p + 1);
      else
        printf("%d not found\n", num);
    }
  }
  return 0;
}