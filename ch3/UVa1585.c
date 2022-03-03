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
  char s[100];
  while (T--) {
    int cnt = 0, ans = 0;
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
      if (s[i] == 'O') {
        ans += ++cnt;
      } else {
        cnt = 0;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}