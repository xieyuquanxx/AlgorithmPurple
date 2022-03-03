#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOCAL
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int c, q = 1;
  while ((c = getchar()) != EOF) {
    if (c == '"') {
      printf("%s", q ? "``" : "''");
      q = !q;
    } else {
      putchar(c);
    }
  }
  return 0;
}