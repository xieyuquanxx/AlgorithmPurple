#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[500], b[500];

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define swap(a, b)                                                             \
  {                                                                            \
    int t = a;                                                                 \
    a = b;                                                                     \
    b = t;                                                                     \
  }

#define LOCAL

void solve(int alen, int blen) {
  int i;
  for (i = 0; i < alen; i++) {
    int j = 0;
    while (a[i + j] + b[j] < '2' + '2' && b[j]) {
      j++;
    }
    if (j == blen)
      break;
  }
  int result = max(i + blen, alen);
  for (i = 0; i < blen; i++) {
    int j = 0;
    while (b[i + j] + a[j] < '2' + '2' && a[j]) {
      j++;
    }
    if (j == alen)
      break;
  }
  result = min(result, max(i + alen, blen));
  printf("%d\n", result);
}

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  while (scanf("%s %s", a, b) == 2) {
    int alen = strlen(a), blen = strlen(b);
    solve(alen, blen);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
  }
  return 0;
}