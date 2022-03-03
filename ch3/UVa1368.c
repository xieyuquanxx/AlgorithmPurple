#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[55][1010];
#define LOCAL
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }

    int hamming = 0;
    for (int j = 0; j < m; j++) {
      int dna[26] = {0};
      int max = 0;
      char max_c = 0;
      for (int i = 0; i < n; i++) {
        dna[s[i][j] - 'A']++;
        if (dna[s[i][j] - 'A'] > max) {
          max = dna[s[i][j] - 'A'];
          max_c = s[i][j];
        }
        if (dna[s[i][j] - 'A'] == max && s[i][j] < max_c) {
          max_c = s[i][j];
        }
      }
      hamming += n - max;
      printf("%c", max_c);
    }
    printf("\n%d\n", hamming);
  }
  return 0;
}