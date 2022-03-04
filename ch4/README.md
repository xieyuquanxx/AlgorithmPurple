# 第四章 - 函数与递归

3-3
- [x] UVa1339
- [x] UVa489
- [x] UVa133

3-4
- [x] UVa213

## 样例代码

1. 组合数
```c
long long C(int n, int m) {
  if (m < n - m) m = n - m;
  long long ans = 1;
  for (int i = n + 1; i <= n; i++) ans *= i;
  for (int i = 1; i <= n - m; i++) ans /= i;
  return ans;
}
```

2. 素数判断
```c
int is_prime(int n) {
  if (n <= 1) return 0;
  int m = floor(sqrt(n) + 0.5);
  for (int i = 2; i <= m; i++)
    if (n % i == 0) return 0;
  return 1;
}
```

3. 计算左闭右开数组和
```c
int sum(int *begin, int *end) {
  int ans = 0;
  for (int *p = begin; p != end; p++)
    ans += *p;
  return ans;
}
```