#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[10][10];
void print_error(int num) {
  printf("Puzzle #%d:\n", num);
  printf("This puzzle has no final configuration.\n");
}
void print_puzzle(int num) {
  printf("Puzzle #%d:\n", num);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%s%c", j == 0 ? "" : " ", s[i][j]);
    }
    printf("\n");
  }
}

int check(int x, int y) { return x >= 0 && x < 5 && y >= 0 && y < 5; }

void swap(int x1, int y1, int x2, int y2) {
  int t = s[x1][y1];
  s[x1][y1] = s[x2][y2];
  s[x2][y2] = t;
}

enum DIR { A, B, L, R };
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
int operation(enum DIR op, int *x, int *y) {
  int tx = *x, ty = *y;
  int nx = tx + dir[op][0], ny = ty + dir[op][1];
  if (check(nx, ny)) {
    swap(tx, ty, nx, ny);
    *x = nx;
    *y = ny;
    return 0;
  }
  return 1;
}

#define LOCAL
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int num = 1;
  while (1) {

    int x = 0, y = 0;
    scanf("%c", &s[0][0]);
    if (s[0][0] == 'Z')
      break;
    if (num != 1)
      printf("\n");

    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (!i && !j)
          continue;
        scanf("%c", &s[i][j]);
        if (s[i][j] == ' ') {
          x = i, y = j;
        }
      }
      getchar();
    }

    // read operation
    int c = 0;
    int f = 1;
    while ((c = getchar()) != EOF) {
      if (c == '0')
        break;
      if (c == '\n' || !f)
        continue;
      switch (c) {
      case 'A':
        if (operation(A, &x, &y)) {
          f = 0;
        }
        break;
      case 'B':
        if (operation(B, &x, &y)) {
          f = 0;
        }
        break;
      case 'L':
        if (operation(L, &x, &y)) {
          f = 0;
        }
        break;
      case 'R':
        if (operation(R, &x, &y)) {
          f = 0;
        }
        break;
      default:
        f = 0;
        break;
      }
    }
    c = getchar();

    if (f)
      print_puzzle(num++);
    else
      print_error(num++);
    if (c == 'Z')
      break;
  }
  return 0;
}