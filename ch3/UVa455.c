#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOCAL
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int T;
  char s[100];
  scanf("%d", &T);
  int first = 1;
  while (T--) {
    if (!first)
      printf("\n");
    scanf("%s", s);
    int n = strlen(s);
    int t;
    for (t = 1; t < n; t++) {
      int f = 1;
      for (int i = 0; i < n; i++) {
        if (s[i] != s[(i + t) % n]) {
          f = 0;
          break;
        }
      }
      if (f)
        break;
    }
    printf("%d\n", t);
    if (first)
      first = 0;
  }

  return 0;
}