#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double get_mole(char c) {
  double m = 0.0;
  switch (c) {
  case 'C':
    m = 12.01;
    break;
  case 'H':
    m = 1.008;
    break;
  case 'O':
    m = 16.00;
    break;
  case 'N':
    m = 14.01;
    break;
  }
  return m;
}

#define LOCAL
#define READ_CASE                                                              \
  int T;                                                                       \
  scanf("%d", &T)
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  READ_CASE;
  char s[100];
  while (T--) {
    scanf("%s", s);
    int n = strlen(s);
    int cnt = 0;
    char pre = s[0];
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
      if (s[i] >= 'A' && s[i] <= 'Z') {
        sum += get_mole(s[i]);
        pre = s[i];
      } else {
        int num = 0;
        int j = i;
        while (j < n && s[j] >= '0' && s[j] <= '9') {
          num = num * 10 + (s[j] - '0');
          j++;
        }
        i = j - 1;
        sum += (num - 1) * (get_mole(pre));
      }
    }
    printf("%.3f\n", sum);
  }

  return 0;
}