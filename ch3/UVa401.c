#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char alpha[] = "AEHIJLMOSTUVWXYZ12358";
const char reversed[] = "A3HILJMO2TUVWXY51SEZ8";

const char *output[] = {
    " -- is not a palindrome.",
    " -- is a regular palindrome.",
    " -- is a mirrored string.",
    " -- is a mirrored palindrome.",
};

int is_palindrome(char *s, int len) {
  for (int i = 0; i < (len + 1) / 2; i++) {
    if (s[i] != s[len - i - 1])
      return 0;
  }
  return 1;
}

int get_mirrored(char c) {
  for (int i = 0; i < 22; i++) {
    if (c == alpha[i])
      return reversed[i];
  }
  return 0;
}

int is_mirrored(char *s, int len) {
  for (int i = 0; i < (len + 1) / 2; i++) {
    int r = get_mirrored(s[i]);
    if (r != s[len - i - 1])
      return 0;
  }
  return 2;
}

#define LOCAL
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  char s[100];
  int first = 1;
  while (~scanf("%s", s)) {
    int len = strlen(s);
    int f1 = is_palindrome(s, len);
    int f2 = is_mirrored(s, len);
    printf("%s%s\n\n", s, output[f1 + f2]);
  }
  return 0;
}