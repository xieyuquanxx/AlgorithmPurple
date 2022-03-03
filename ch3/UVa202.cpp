#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[4000], md[4000];

#define LOCAL
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    printf("%d/%d = %d.", n, m, n / m);
    n %= m;
    int first = 0, T = 0, last = 0;
    memset(md, 0, sizeof(md));
    md[n] = 0;
    for (int i = 1; i <= 3000; i++) {
      n *= 10;
      a[i] = n / m;
      n %= m;
      if (md[n] != 0 && a[md[n]] == a[i]) {
        first = md[n];
        last = i - 1;
        break;
      }
      md[n] = i;
    }
    for (int i = 1; i < first; i++) {
      printf("%d", a[i]);
    }
    printf("(");
    int fina = last > 50 ? 50 : last;
    for (int i = first; i <= fina; i++) {
      printf("%d", a[i]);
    }
    if (last > 50) {
      printf("...");
    }
    printf(")\n");
    printf("   %d = number of digits in repeating cycle\n", last - first + 1);
    printf("\n");
  }
  return 0;
}

/*
分数｜小数展开｜重复循环｜循环长度
| 1/6 | 0.1(6) | 6 | 1 |
| 5/7 | 0.(714285) | 714285 | 6 |
| 1/250 | 0.004(0) | 0 | 1 |
| 300/31 | 9.(677419354838709) | 677419354838709 | 15 |
| 655/990 | 0.6(61) | 61 | 2 |

*/