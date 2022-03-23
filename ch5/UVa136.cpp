#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define LOCAL
const int maxn = 1e5 + 7;

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  set<long long> q;
  q.insert(1);
  int fac[3] = {2, 3, 5};
  int cnt = 0;
  auto it = q.begin();
  while (cnt < 1500 - 1) {
    for (int i = 0; i < 3; i++) {
      q.insert(*it * fac[i]);
    }
    it++;
    cnt++;
  }
  cout << "The 1500'th ugly number is " << *it << ".\n";
  return 0;
}