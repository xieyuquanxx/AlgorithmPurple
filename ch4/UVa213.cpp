#include <cstring>
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
#define all1(n) ((1 << n) - 1)

int a[10][1 << 10];
char data[1010];
int len;
void encode() {
  int l = 1, v = 0;
  for (int i = 0; i < len; i++) {
    a[l][v] = data[i];
    v++;
    if (v == all1(l)) {
      v = 0;
      l++;
    }
  }
}

int read_char() {
  int c;
  while (1) {
    c = getchar();
    if (c == EOF)
      return -1;
    if (c == '\n' || c == '\r')
      continue;
    break;
  }
  return c;
}

int readn(int n) {
  int c;
  int v = 0;
  while (n) {
    c = read_char();
    v = v * 2 + (c - '0');
    n--;
  }
  return v;
}

int read_line() {
  int c;
  int k = 0;
  while (1) {
    c = getchar();
    if (c == EOF)
      return -1;
    if (c == '\n' || c == '\r') {
      data[k] = '\0';
      len = k;
      return 0;
    }
    data[k++] = c;
  }
}

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  while (read_line() != -1) {
    // 读取空行
    if (len == 0)
      continue;
    memset(a, 0, sizeof(a));
    encode();
    int key;
    while ((key = readn(3)) != 0) {
      int t;
      while ((t = readn(key)) != all1(key)) {
        printf("%c", a[key][t]);
      }
    }
    printf("\n");
  }
  return 0;
}