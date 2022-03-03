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
int slen, tlen;
int left, fail;

void solve(char ch) {
  int f = 1;
  for (int i = 0; i < slen; i++) {
    if (s[i] == ch) {
      s[i] = ' ';
      left--;
      f = 0;
    }
  }
  if (f)
    fail++;
}

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int game;
  while (scanf("%d", &game) == 1 && game != -1) {
    scanf("%s%s", s, t);
    /*
ab
aaaaaaaaab
    */

    slen = strlen(s), tlen = strlen(t);
    left = slen;
    fail = 0;
    for (int i = 0; i < tlen; i++) {
      solve(t[i]);
      if (left <= 0 || fail >= 7)
        break;
    }
    printf("Round %d\n", game);
    if (left <= 0 && fail < 7) {
      printf("You win.\n");
    } else if (left > 0 && fail >= 7) {
      printf("You lose.\n");
    } else {
      printf("You chickened out.\n");
    }

    // printf("%s\n%s\n", s, t);
  }
  return 0;
}