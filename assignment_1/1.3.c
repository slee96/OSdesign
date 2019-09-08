#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char *rmchar(char *string, char *character){
  printf("%c\n", string[0]);
  printf("%s\n", character);

  return "result";
}

int main(int argc, char *argv[]){
  printf("%s\n", rmchar(argv[1], argv[2]));
}
