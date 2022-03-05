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
#define MAX 10

int a[MAX][MAX][MAX][MAX];
int n;

int check_row(int i, int j, int size) {
  for (int p = j; p < j + size; p++) {
    if (!a[i][i][p][p + 1])
      return 0;
  }
  return 1;
}

int check_col(int i, int j, int size) {
  for (int p = i; p < i + size; p++) {
    if (!a[p][p + 1][j][j])
      return 0;
  }
  return 1;
}

int check(int i, int j, int size) {
  if (i + size > n || j + size > n)
    return 0;
  return check_row(i, j, size) && check_row(i + size, j, size) &&
         check_col(i, j, size) && check_col(i, j + size, size);
}

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int game = 1;
  while (scanf("%d", &n) == 1) {
    memset(a, 0, sizeof(a));
    if (game != 1)
      printf("\n**********************************\n\n");
    printf("Problem #%d\n\n", game);

    int m, x, y;
    scanf("%d", &m);
    char p[2];
    while (m--) {
      scanf("%s%d%d", p, &x, &y);

      if (p[0] == 'H') {
        a[x][x][y][y + 1] = 1;
      } else {
        a[y][y + 1][x][x] = 1;
      }
    }
    int has = 0;
    for (int size = 1; size <= n; size++) {
      int count = 0;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (check(i, j, size)) {
            if (!has)
              has = 1;
            count++;
          }
        }
      }
      if (count)
        printf("%d square (s) of size %d\n", count, size);
    }
    if (!has)
      printf("No completed squares can be found.\n");

    game++;
  }
  return 0;
}