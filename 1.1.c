#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[]) {
  int k = atoi(argv[1]), p = atoi(argv[2]), q = atoi(argv[3]);
  int array[sizeof(q) + 1];
  int start = pow(10, k -1);

  for (int i = start; i < q; i++){
    int sum = 0;
    // J is less than the length of start (e.g. if start=100, length would be 3)
    int temp = i;
    for (int j = 0; j < sizeof(i) -1; j++){
      int didget = temp % 10;
      temp = temp / 10;
      sum += pow(didget, k);
      if ((sum == i) && (j == (sizeof(i) -2))){
        printf("%d\n", i);
      }
    }
  }
  return 0;
}
