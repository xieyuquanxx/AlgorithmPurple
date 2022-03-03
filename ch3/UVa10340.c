#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1000010], t[1000010];

#define LOCAL
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  while (~scanf("%s %s", s, t)) {
    int i = 0, j = 0;
    int slen = strlen(s), tlen = strlen(t);
    while (i < slen && j < tlen) {
      if (s[i] == t[j]) {
        i++, j++;
      } else {
        j++;
      }
    }
    if (i == slen && j <= tlen) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}