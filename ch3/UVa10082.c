#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOCAL
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  char table[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

  int c;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n')
      putchar(c);
    else {
      int i = 0;
      for (; table[i] != c; i++)
        ;
      putchar(table[i - 1]);
    }
  }
  return 0;
}