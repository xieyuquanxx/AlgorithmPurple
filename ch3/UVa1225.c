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
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    int a[10] = {0};
    for (int i = 1; i <= n; i++) {
      int t = i;
      while (t) {
        a[t % 10]++;
        t /= 10;
      }
    }
    for (int i = 0; i < 10; i++) {
      if (i != 0)
        printf(" ");
      printf("%d", a[i]);
    }
    printf("\n");
  }
  return 0;
}