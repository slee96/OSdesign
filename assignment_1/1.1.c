#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[]) {
  // Decalre variables k, p, q
  int k = atoi(argv[1]), p = atoi(argv[2]), q = atoi(argv[3]);
  // Find the starting point 10^k-1
  int start = pow(10, k -1);

  for (int i = start; i < q; i++){
    // Reset sum & temp each itteration
    int sum = 0;
    int temp = i;
    for (int j = 0; j < k; j++){
      // Get the last number in the integer
      int diget = temp % 10;
      temp = temp / 10;
      // Append the last number to the power of k
      sum += pow(diget, k);
      //If the sum equals i, and its the last itteration 
      if ( (sum == i) && (j == (k - 1)) ) {
        printf("%d\n", i);
      }
    }
  }
  return 0;
}
