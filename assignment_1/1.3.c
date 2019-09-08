#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char *rmchr(char *string, char *character){
  // create int to store the value of the string length
  int length = strlen(string);
  // for loop to itterate throught the string
  for (int i = 0; i < length; i++){
    // If the character to remove is equal character at index[i] remove the character
    if (character[0] == string[i]){
      // Code to remove caracter to come
      
    }
  }
  return string;
}

int main(int argc, char *argv[]){
  printf("%s\n", rmchr(argv[1], argv[2]));
}
