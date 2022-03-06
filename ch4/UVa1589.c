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
#define is_qizi(x, y) (board[x][y] == 2)
#define is_black(x, y) (x == bx && y == by)
#define MAX 20

int board[MAX][MAX]; // 2 qizi
int atk[MAX][MAX];
char qizi[MAX][MAX];
int bx, by, gx, gy;

typedef struct Qizi {
  char name;
  int x, y;
} Qizi;

const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 4个方向
const int house_dir[8][2] = {{-1, 2}, {1, 2},  {1, -2},  {-1, -2},
                             {2, 1},  {2, -1}, {-2, -1}, {-2, 1}}; // 马8个方向
int check_board(int x, int y) { return x >= 1 && x <= 10 && y >= 1 && y <= 9; }
int check_general(int x, int y) { return x >= 1 && x <= 3 && y >= 4 && y <= 6; }
int check_general_eat() {
  if (by == gy) {
    int k;
    for (k = bx + 1; check_board(k, by) && !is_qizi(k, by); k++)
      ;
    if (k == gx)
      return 1;
  }
  return 0;
}
int check_safe() {
  // check whether can eat general
  if (check_general_eat())
    return 1;
  // check whether can move 4 directions to live
  for (int i = 0; i < 4; i++) {
    int nx = bx + dir[i][0], ny = by + dir[i][1];
    if (check_general(nx, ny) && !atk[nx][ny]) {
      return 1;
    }
  }
  return 0;
}

void attack2(char name, int x, int y) {
  if (name == 'G') { // 将
    gx = x, gy = y;
    if (check_general_eat())
      return;
    for (int k = x - 1; check_board(k, y); k--) {
      if (check_general(k, y)) {
        atk[k][y] = 1;
      }
      if (is_qizi(k, y)) {
        break;
      }
    }
  } else if (name == 'R') { // 车
    for (int i = 0; i < 4; i++) {
      for (int nx = x + dir[i][0], ny = y + dir[i][1];;
           nx += dir[i][0], ny += dir[i][1]) {
        if (!check_board(nx, ny)) {
          break;
        }

        if (check_general(nx, ny)) {
          if (!is_qizi(nx, ny)) {
            atk[nx][ny] = 1;
          } else {
            if (is_black(nx, ny)) {
              atk[nx][ny] = 1;
            } else {
              atk[nx][ny] = 1;
              break;
            }
          }
        } else {
          if (is_qizi(nx, ny))
            break;
        }
      }
    }
  } else if (name == 'C') {
    for (int i = 0; i < 4; i++) {
      for (int nx = x + dir[i][0], ny = y + dir[i][1];;
           nx += dir[i][0], ny += dir[i][1]) {
        if (!check_board(nx, ny)) {
          break;
        }
        int over = 0;
        if (is_qizi(nx, ny) && !is_black(nx, ny)) {
          for (int nx2 = nx + dir[i][0], ny2 = ny + dir[i][1];;
               nx2 += dir[i][0], ny2 += dir[i][1]) {
            if (!check_board(nx2, ny2)) {
              over = 1;
              break;
            }

            if (check_general(nx2, ny2)) {
              if (is_qizi(nx2, ny2)) {
                if (!is_black(nx2, ny2)) {
                  over = 1;
                  break;
                } else {
                  atk[nx2][ny2] = 1;
                }
              } else {
                atk[nx2][ny2] = 1;
              }
            } else {
              if (is_qizi(nx2, ny2)) {
                over = 1;
                break;
              }
            }
          }
        }
        if (over)
          break;
      }
    }
  } else if (name == 'H') {
    for (int i = 0; i < 4; i++) {
      int hlx = x + dir[i][0], hly = y + dir[i][1];
      if (!check_board(hlx, hly) || is_qizi(hlx, hly)) {
        continue;
      }
      int xx = x + house_dir[i * 2][0], yy = y + house_dir[i * 2][1];
      if (check_general(xx, yy)) {
        atk[xx][yy] = 1;
      }
      xx = x + house_dir[i * 2 + 1][0], yy = y + house_dir[i * 2 + 1][1];
      if (check_general(xx, yy)) {
        atk[xx][yy] = 1;
      }
    }
  }
}

void print_board() {
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 9; j++) {
      if (is_qizi(i, j)) {
        printf("%c ", qizi[i][j]);
      } else {
        printf("%d ", atk[i][j]);
      }
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 9; j++) {
      printf("%d ", atk[i][j]);
    }
    printf("\n");
  }
}

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int n;

  while (scanf("%d%d%d", &n, &bx, &by) == 3) {
    if (!n && !bx && !by)
      break;
    Qizi qizis[10];
    memset(board, 0, sizeof(board));
    memset(atk, 0, sizeof(atk));
    memset(qizi, 0, sizeof(qizi));

    board[bx][by] = 2;

    qizi[bx][by] = 'B';

    char nn[10];
    int x, y;
    for (int i = 0; i < n; i++) {
      scanf("%s%d%d", nn, &qizis[i].x, &qizis[i].y);
      board[qizis[i].x][qizis[i].y] = 2;
      qizi[qizis[i].x][qizis[i].y] = nn[0];
      qizis[i].name = nn[0];
    }
    for (int i = 0; i < n; i++) {
      attack2(qizis[i].name, qizis[i].x, qizis[i].y);
    }

    if (check_safe())
      printf("NO\n");
    else
      printf("YES\n");
    // print_board();
  }
  return 0;
}