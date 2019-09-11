#include <stdio.h>
#include <string.h>

char *rmchr(char *string, char *character){
  // create int to store the value of the string length
  int length = strlen(string);
  // for loop to iterate through the string
  for (int i = 0; i < length;){
    // If statement to remoed character from the string at index[i] if its the same as the character to search for
    if (character[0] == string[i]){
      // set counter equal to the index of found character
      int counter = i;
      while(string[counter] != '\0'){
        // shift the string starting at counter
        string[counter] = string[counter + 1];
        counter++;
      }
    }else{
      i++;
    }
  }
  return string;
}

int main(int argc, char *argv[]){
  printf("%s\n", rmchr(argv[1], argv[2]));
}
