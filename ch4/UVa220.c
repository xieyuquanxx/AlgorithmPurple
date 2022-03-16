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

#define in_board(x, y) (x >= 1 && x <= 8 && y >= 1 && y <= 8)
#define diff_disk(x) (x == 'W' ? 'B' : 'W')
#define switch_player(p) (p = p == 'W' ? 'B' : 'W')
#define eat_disk(disk)                                                         \
  {                                                                            \
    if (disk == 'W') {                                                         \
      white--, black++;                                                        \
    } else {                                                                   \
      white++, black--;                                                        \
    }                                                                          \
  }
#define LOCAL

char board[15][15];
char player;
int white, black;

void print_board() {
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}
const int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                       {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

int check_eat(int r, int c, int d) {
  int nx = r + dir[d][0], ny = c + dir[d][1];
  int cnt = 0;
  while (in_board(nx, ny) && board[nx][ny] == diff_disk(player)) {
    nx += dir[d][0];
    ny += dir[d][1];
    cnt++;
  }
  return in_board(nx, ny) && board[nx][ny] == player && cnt;
}

void check_legal_move(int *f) {
  int is_first = 1;
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      if (board[i][j] != '-')
        continue;
      int ok = 0;
      for (int d = 0; d < 8; d++) {
        board[i][j] = player;
        if (check_eat(i, j, d)) {
          board[i][j] = '-';
          ok = 1;
          break;
        }
        board[i][j] = '-';
      }
      if (ok) {
        if (f == NULL) {
          if (!is_first)
            printf(" ");
          printf("(%d,%d)", i, j);
        }
        if (is_first)
          is_first = 0;
      }
    }
  }
  if (f == NULL) {
    if (is_first)
      printf("No legal move.");
    printf("\n");
  } else {
    *f = !is_first;
  }
}

void place(int r, int c) {
  board[r][c] = player;
  if (player == 'W')
    white++;
  else
    black++;
  for (int d = 0; d < 8; d++) {
    if (check_eat(r, c, d)) {

      int nx = r + dir[d][0], ny = c + dir[d][1];
      while (in_board(nx, ny) && board[nx][ny] == diff_disk(player)) {
        eat_disk(diff_disk(player));
        board[nx][ny] = player;
        nx += dir[d][0];
        ny += dir[d][1];
      }
    }
  }
}

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  int fis = 1;
  while (T--) {
    if (!fis)
      printf("\n");
    white = black = 0;
    memset(board, 0, sizeof(board));

    getchar();
    for (int i = 1; i <= 8; i++) {
      for (int j = 1; j <= 8; j++) {
        scanf("%c", &board[i][j]);
        if (board[i][j] == 'B')
          black++;
        else if (board[i][j] == 'W')
          white++;
      }
      getchar();
    }
    scanf("%c", &player);

    // printf("Player: %c\n", player);

    int op;
    while ((op = getchar()) != EOF) {
      if (op == 'Q')
        break;
      if (op == '\n' || op == '\r')
        continue;
      if (op == 'L') {
        check_legal_move(NULL);
      } else if (op == 'M') {
        char a, b;
        scanf("%c%c", &a, &b);
        int r = a - '0', c = b - '0';
        // printf("M%d%d\n", r, c);

        int f = 0;
        check_legal_move(&f);
        if (!f) {
          switch_player(player);
        }

        // printf("Player: %c (%d, %d)\n", player, r, c);
        place(r, c);
        printf("Black -%3d White -%3d\n", black, white);
        switch_player(player);
        // print_board();
      }
    }

    print_board();
    if (fis)
      fis = 0;
  }
  return 0;
}