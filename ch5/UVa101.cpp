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
const int MAXN = 32;
#define LOCAL

vector<int> pile[MAXN];
int n;

int find_pile(int block) {
  int p = -1;
  for (int i = 0; i < n && p == -1; i++) {
    for (int s = 0; s < pile[i].size(); s++) {
      if (pile[i][s] == block) {
        p = i;
        break;
      }
    }
  }
  return p;
}

void reset_block(int block) {
  int p = find_pile(block);
  int i;
  for (i = 0; i < pile[p].size() && pile[p][i] != block; i++)
    ;
  for (int k = i + 1; k < pile[p].size(); k++) {
    pile[pile[p][k]].push_back(pile[p][k]);
  }
  pile[p].resize(i + 1);
}

void push_blocks(int a, int b) {
  int p1 = find_pile(a), p2 = find_pile(b);
  if (p1 == p2)
    return;
  int k = 0;
  for (; k < pile[p1].size() && pile[p1][k] != a; k++)
    ;
  for (int kk = k; kk < pile[p1].size(); kk++) {
    pile[p2].push_back(pile[p1][kk]);
  }
  pile[p1].resize(k);
}

void print_piles() {
  for (int i = 0; i < n; i++) {
    printf("%d:", i);
    for (int j = 0; j < pile[i].size(); j++) {
      printf(" %d", pile[i][j]);
    }
    printf("\n");
  }
}

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> n;

  for (int i = 0; i < n; i++) {
    pile[i].push_back(i);
  }

  string op1, op2;
  int a, b;
  while (cin >> op1 && op1[0] != 'q') {
    cin >> a >> op2 >> b;
    if (a == b)
      continue;
    int p1 = find_pile(a), p2 = find_pile(b);
    if (p1 == p2)
      continue;
    if (op2 == "onto") {
      reset_block(b);
    }
    if (op1[0] == 'm') {
      reset_block(a);
    }
    push_blocks(a, b);
  }
  print_piles();

  return 0;
}