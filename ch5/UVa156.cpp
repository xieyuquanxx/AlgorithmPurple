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
#define LOCAL
const int maxn = 1e5 + 7;

void lower(string &s) {
  for (auto &c : s) {
    c = (char)tolower(c);
  }
}

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  string s;
  set<string> dict;
  vector<string> v, vs;
  while (cin >> s && s[0] != '#') {
    v.push_back(s);
    lower(s);
    sort(s.begin(), s.end());
    vs.push_back(s);
  }
  for (int i = 0; i < vs.size(); i++) {
    bool ok = false;
    for (int j = 0; j < vs.size(); j++) {
      if (i == j)
        continue;
      if (vs[i] == vs[j]) {
        ok = true;
        break;
      }
    }
    if (!ok)
      dict.insert(v[i]);
  }
  for (const auto &s : dict) {
    cout << s << endl;
  }
  return 0;
}