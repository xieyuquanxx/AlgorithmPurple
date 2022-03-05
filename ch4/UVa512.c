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
#define MAX 55

int a[MAX + 5][MAX + 5];
int n, m;

int temp_row[MAX + 5], temp_col[MAX + 5];
// 注意哈希函数!!
#define HASH(i, j) (i * 100 + j)
void init() {
  memset(a, 0, sizeof(a));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[i][j] = HASH(i, j);
    }
  }
}

void query(int r, int c) {
  int num = HASH(r, c);
  printf("Cell data in (%d,%d) ", r, c);
  int f = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == num) {
        printf("moved to (%d,%d)", i, j);
        f = 1;
        break;
      }
    }
    if (f)
      break;
  }
  if (!f) {
    printf("GONE");
  }
  printf("\n");
}

void swap_cell(int r1, int c1, int r2, int c2) {
  // EX r1 c1 r2 c2
  swap(a[r1][c1], a[r2][c2]);
}

void delete_row(int pr, int r) {
  // printf("%d\n", r);
  // DR r
  for (int i = r + 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[i - 1][j] = a[i][j];
    }
  }
  for (int i = pr + 1; i <= MAX; i++)
    temp_row[i]--;
  for (int j = 1; j <= m; j++)
    a[n][j] = 0;
  n--;
}

void insert_row(int pr, int r) {
  // printf("%d\n", r);
  // IR r
  for (int i = n; i >= r; --i) {
    for (int j = 1; j <= m; j++) {
      a[i + 1][j] = a[i][j];
    }
  }
  for (int i = pr; i <= MAX; i++)
    temp_row[i]++;
  for (int j = 1; j <= m; j++)
    a[r][j] = 0;
  n++;
}

void delete_col(int pc, int c) {
  // printf("%d\n", c);
  // DC r
  for (int i = 1; i <= n; i++) {
    for (int j = c + 1; j <= m; j++) {
      a[i][j - 1] = a[i][j];
    }
  }
  for (int j = pc + 1; j <= MAX; j++)
    temp_col[j]--;
  for (int i = 1; i <= n; i++)
    a[i][m] = 0;
  m--;
}

void insert_col(int pc, int c) {
  // IC r
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= c; j--) {
      a[i][j + 1] = a[i][j];
    }
  }
  for (int j = pc; j <= MAX; j++)
    temp_col[j]++;
  for (int i = 1; i <= n; i++)
    a[i][c] = 0;
  m++;
}

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int game = 1;
  while (scanf("%d%d", &n, &m) == 2) {
    if (!n && !m)
      break;
    if (game != 1)
      printf("\n");
    printf("Spreadsheet #%d\n", game++);

    init();
    int T;
    scanf("%d", &T);
    char op[3];

    while (T--) {
      scanf("%s", op);
      if (op[0] == 'E') {
        int r1, c1, r2, c2;
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        swap_cell(r1, c1, r2, c2);
      } else {
        for (int i = 1; i <= MAX; i++)
          temp_row[i] = i;
        for (int i = 1; i <= MAX; i++)
          temp_col[i] = i;
        int num, obj;
        scanf("%d", &num);

        while (num--) {
          scanf("%d", &obj);
          // printf("%d %d\n", obj, temp_row[obj]);
          if (op[0] == 'D') {
            if (op[1] == 'R') {
              delete_row(obj, temp_row[obj]);
            } else {
              delete_col(obj, temp_col[obj]);
            }
          } else if (op[0] == 'I') {
            if (op[1] == 'R') {
              insert_row(obj, temp_row[obj]);
            } else {
              insert_col(obj, temp_col[obj]);
            }
          }
        }
      }
    }
    scanf("%d", &T);
    while (T--) {
      int r, c;
      scanf("%d%d", &r, &c);
      query(r, c);
    }
  }
  return 0;
}