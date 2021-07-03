#include<stdio.h>

int main() { //數必為整數
  int a, b, t; //使用者輸入兩隊比數和以及比數差輸出兩隊分數如果無此數輸出impossible
  float c, d;
  scanf("%d%d", & a, & b);
  c = (a + b) * 0.5;
  d = (a - b) * 0.5;
  int p = c;
  int q = d;
  c = c - p;
  d = d - q;
  if (c > 0 || d > 0) {
    printf("impossible");
  } else if (p < 0 || q < 0) {
    printf("impossible");
  } else if (p <= q) {
    t = p;
    p = q;
    q = t;
    printf("%d %d", p, q);
  } else {
    printf("%d %d", p, q);
  }

  return 0;
}