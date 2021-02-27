#include <stdio.h>

#define _pin(x, y) int p##x##y = (1 << P##x##y);

_pin(B, 7)
_pin(B, 6)
_pin(B, 5)
_pin(B, 4)
_pin(B, 3)
_pin(B, 2)
_pin(B, 1)
_pin(B, 0)

_pin(D, 6)
_pin(D, 5)
_pin(D, 4)

int main() {
  return 0;
}