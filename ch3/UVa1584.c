#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void char_circular(char *s, int n, int start, char *p) {
  for (int cnt = 0; cnt < n; cnt++) {
    p[cnt] = s[(start + cnt) % n];
  }
  p[n] = '\0';
}

#define LOCAL
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int T;
  char s[120], p[120], g[120];
  scanf("%d", &T);

  while (T--) {
    scanf("%s", s);
    int n = strlen(s);
    strcpy(p, s);
    for (int i = 0; i < n; i++) {
      if (s[i] > p[0])
        continue;
      char_circular(s, n, i, g);
      if (strcmp(g, p) < 0) {
        strcpy(p, g);
      }
    }
    printf("%s\n", p);
  }
  return 0;
}