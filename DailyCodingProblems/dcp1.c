/*
   Given a list of numbers and a number k, return whether any two
   numbers from the list add up to k.
*/

#include <assert.h>
#include <stdio.h>

int test(int k, int *vec, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (vec[i] + vec[j] == k)
        return 1;
    }
  }
  return 0;
}

int main(void) {
  int k = 17;
  int vec[] = {10, 15, 3, 7};
  assert(test(k, vec, 4) == 1);

  return 0;
}
