#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define swap(a, b)                                                             \
  {                                                                            \
    int t = a;                                                                 \
    a = b;                                                                     \
    b = t;                                                                     \
  }
#define LOCAL
#define next_p(i)                                                              \
  {                                                                            \
    i++;                                                                       \
    if (i % (n + 1) == 0)                                                      \
      i = 1;                                                                   \
  }
#define next_n(j)                                                              \
  {                                                                            \
    j--;                                                                       \
    if (j == 0)                                                                \
      j = n;                                                                   \
  }

int a[30];

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int n, k, m;
  while (scanf("%d%d%d", &n, &k, &m) == 3) {
    if (!n && !k && !m)
      break;
    for (int i = 1; i <= n; i++)
      a[i] = 1;
    int left = n;
    int i = 1, j = n;

    while (left) {
      if (left != n)
        printf(",");
      int c1 = 1, c2 = 1;
      while (c1 <= k) {
        if (a[i]) {
          c1++;
        }
        if (c1 > k)
          break;
        next_p(i);
      }
      while (c2 <= m) {
        if (a[j]) {
          c2++;
        }
        if (c2 > m)
          break;
        next_n(j);
      }
      printf("%3d", i);
      left--;
      if (i != j) {
        printf("%3d", j);
        left--;
      }
      a[i] = a[j] = 0;
      next_p(i);
      next_n(j);
    }
    printf("\n");
  }

  return 0;
}