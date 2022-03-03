#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
char puzzle[15][15];
int num[15][15];

#define LOCAL
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int game = 1;
  while (~scanf("%d", &n) && n) {
    scanf("%d", &m);
    getchar();
    memset(num, 0, sizeof(num));
    int count = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%c", &puzzle[i][j]);
        if (puzzle[i][j] == '*')
          continue;
        if ((i == 0) || (j == 0) || (j - 1 >= 0 && puzzle[i][j - 1] == '*') ||
            (i - 1 >= 0 && puzzle[i - 1][j] == '*')) {
          num[i][j] = count++;
        }
      }
      getchar();
    }
    if (game != 1)
      printf("\n");
    printf("puzzle #%d:\n", game++);
    printf("Across\n");
    for (int i = 0; i < n; i++) {
      int j = 0;
      while (j < m) {
        if (puzzle[i][j] == '*') {
          j++;
          continue;
        }
        printf("%3d.", num[i][j]);
        while (j < m && puzzle[i][j] != '*') {
          printf("%c", puzzle[i][j]);
          j++;
        }
        printf("\n");
      }
    }
    printf("Down\n");
    for (int i = 0; i < n; i++) {
      int j = 0;
      while (j < m) {
        if (puzzle[i][j] == '*') {
          j++;
          continue;
        }
        printf("%3d.", num[i][j]);
        int t = i;
        while (t < n && puzzle[t][j] != '*') {
          printf("%c", puzzle[t][j]);
          puzzle[t][j] = '*';
          t++;
        }
        printf("\n");
      }
    }
  }
  return 0;
}