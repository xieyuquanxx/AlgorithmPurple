#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOCAL

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int n, cnt = 0;
  scanf("%d", &n);
  while (n > 1) {
    if (n & 1)
      n = 3 * n + 1;
    else
      n /= 2;
    cnt++;
  }
  printf("%d\n", cnt);

  return 0;
}