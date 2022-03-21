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
const int maxn = 1e3 + 7;

queue<int> team[maxn];
queue<int> tid;
int n;
map<int, int> team_id;

void init() {
  team_id.clear();
  while (!tid.empty())
    tid.pop();
  for (int i = 0; i < n; i++) {
    while (!team[i].empty())
      team[i].pop();
  }
}

void enqueue(int id) {
  int tmid = team_id[id];
  if (team[tmid].empty()) {
    tid.push(tmid);
    team[tmid].push(id);
  } else {
    team[tmid].push(id);
  }
}

void dequeue() {
  int tmid = tid.front();
  if (team[tmid].empty())
    return;
  printf("%d\n", team[tmid].front());
  team[tmid].pop();
  if (team[tmid].empty()) {
    if (tid.empty())
      return;
    tid.pop();
  }
}

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int game = 1;
  while (scanf("%d", &n) == 1 && n) {
    init();
    printf("Scenario #%d\n", game++);
    for (int t = 0; t < n; t++) {
      int num, id;
      scanf("%d", &num);
      while (num--) {
        scanf("%d", &id);
        team_id[id] = t;
      }
    }

    string op;
    int t;
    while (cin >> op && op[0] != 'S') {

      if (op[0] == 'E') {
        scanf("%d", &t);
        enqueue(t);
      } else if (op[0] == 'D') {
        dequeue();
      }
    }

    printf("\n");
  }
  return 0;
}