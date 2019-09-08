#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char *rmchr(char *string, char *character){
  // create int to store the value of the string length
  int length = strlen(string);
  // for loop to itterate throught the string
  for (int i = 0; i < length; i++){
    // If statement to remoed character from the string at index[i] if its the same as the character to search for
    if (character[0] == string[i]){
      // Code to remove caracter to come
      
    }
  }
  return string;
}

int main(int argc, char *argv[]){
  printf("%s\n", rmchr(argv[1], argv[2]));
}
