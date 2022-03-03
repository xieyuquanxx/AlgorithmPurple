#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int digit(int x) {
  int sum = 0;
  for (; x; x /= 10)
    sum += x % 10;
  return sum;
}

#define SIZE 100005
int a[SIZE];
void table() {
  for (int i = 1; i < SIZE; i++) {
    int m = i + digit(i);
    if (!a[m] || a[m] > i)
      a[m] = i;
  }
}

#define LOCAL
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  table();
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", a[n]);
  }
  return 0;
}