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

char s[1010], t[1010];

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  while (scanf("%s%s", s, t) == 2) {
    int c1[26] = {0}, c2[26] = {0};
    int n = strlen(s), m = strlen(t);
    for (int i = 0; i < n; i++)
      c1[s[i] - 'A']++;
    for (int i = 0; i < m; i++)
      c2[t[i] - 'A']++;
    qsort(c1, 26, sizeof(int), cmp);
    qsort(c2, 26, sizeof(int), cmp);
    int f = 1;
    for (int i = 0; i < 26; i++) {
      if (c1[i] != c2[i]) {
        f = 0;
        break;
      }
    }
    printf("%s\n", f ? "YES" : "NO");
  }
  return 0;
}