#include <stdio.h>
#include <std

unsigned long long upower(unsigned i, unsigned N) {
  unsigned long long power = 1;
  if (i <= 1) return i;
  while (N-- > 0) {
    unsigned long long power_before = power;
    power *= i;
    if (power < power_before) {
      printf("Overflow\n");
      return 0;
    }
  }
  return power;
}

void prime() {
  unsigned i, N;
  scanf("%u", &N);
  for (i = 2; i < N; i++) {
    if ((upower(i, N - 1) % N) != 1) {
      printf("not prime");
      return;
    }
  }
  printf("prime");
  return;
}