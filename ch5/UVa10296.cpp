#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define LOCAL
const int maxn = 1e5 + 7;

map<set<int>, int> mp;
map<int, set<int>> hh;
stack<int> s;
int counter = 0;

void init() {
  mp.clear();
  hh.clear();
  while (!s.empty())
    s.pop();
  counter = 0;
}

int get_set_id(set<int> _set) {
  if (mp.count(_set))
    return mp[_set];
  mp[_set] = counter;
  hh[counter++] = _set;
  return mp[_set];
}

void push_set(set<int> _set) { s.push(get_set_id(_set)); }

int stack_top_set_size() { return (int)hh[s.top()].size(); }

void dup_set() { s.push(s.top()); }

void add_set() {
  auto s1 = s.top();
  s.pop();
  auto s2 = s.top();
  s.pop();

  set<int> s3 = hh[s2];
  s3.insert(get_set_id(hh[s1]));

  push_set(s3);
}

void union_set() {
  auto s1 = s.top();
  s.pop();
  auto s2 = s.top();
  s.pop();

  auto set1 = hh[s1];
  auto set2 = hh[s2];
  set<int> set3;
  set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
            inserter(set3, set3.begin()));
  push_set(set3);
}

void intersection_set() {
  auto s1 = s.top();
  s.pop();
  auto s2 = s.top();
  s.pop();

  auto set1 = hh[s1];
  auto set2 = hh[s2];
  set<int> set3;
  set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                   inserter(set3, set3.begin()));
  push_set(set3);
}

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int T;
  cin >> T;
  while (T--) {
    init();

    int N;
    cin >> N;
    while (N--) {
      string op;
      cin >> op;
      if (op[0] == 'P') {
        push_set(set<int>{});
      } else if (op[0] == 'D') {
        dup_set();
      } else if (op[0] == 'U') {
        union_set();
      } else if (op[0] == 'I') {
        intersection_set();
      } else if (op[0] == 'A') {
        add_set();
      }
      printf("%d\n", stack_top_set_size());
    }
    printf("***\n");
  }
  return 0;
}