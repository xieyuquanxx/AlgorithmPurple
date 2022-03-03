#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOCAL
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int n, s[1050], g[1050];
  int game = 1;

  while (~scanf("%d", &n) && n) {
    printf("Game %d:\n", game++);

    for (int i = 0; i < n; i++) {
      scanf("%d", &s[i]);
    }
    while (1) {
      int A = 0, B = 0;
      for (int i = 0; i < n; i++) {
        scanf("%d", &g[i]);
        if (s[i] == g[i])
          A++;
      }
      if (g[0] == 0)
        break;
      for (int d = 1; d <= 9; ++d) {
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
          if (s[i] == d)
            c1++;
          if (g[i] == d)
            c2++;
        }
        if (c1 > c2)
          B += c2;
        else
          B += c1;
      }
      printf("    (%d,%d)\n", A, B - A);
    }
  }
  return 0;
}