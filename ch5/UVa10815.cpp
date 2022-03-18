#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define swap(a, b)                                                             \
  {                                                                            \
    int t = a;                                                                 \
    (a) = b;                                                                   \
    (b) = t;                                                                   \
  }
const int maxn = 1e5 + 7;
#define LOCAL

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  set<string> dict;
  string s;
  while (cin >> s) {
    string p;
    for (int i = 0; i < s.size(); i++) {
      if (isalpha(s[i])) {
        p.push_back(tolower(s[i]));
      } else {
        if (!p.empty())
          dict.insert(p);
        p.clear();
      }
    }
    if (!p.empty())
      dict.insert(p);
  }
  for (const auto &it : dict) {
    cout << it << endl;
  }
  return 0;
}