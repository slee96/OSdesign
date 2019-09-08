#include <stdio.h>
#include <string.h>

char *rmchr(char *string, char *characters){
  // for loop to itterate throught the string's
  for (int i = 0; i < strlen(string); i++){
    for (int j = 0; j < strlen(characters); j++){
      // If statement to remoed character from the string at index[i] if its the same as the character to search for
      if (characters[j] == string[i]){
        // set counter equal to the index of found character
        int counter = i;
        j = 0;
        i--;
        while(string[counter] != '\0'){
          // shift the string starting at counter
          string[counter] = string[counter + 1];
          counter++;
        }
      }
    }
  }
  return string;
}

int main(int argc, char *argv[]){
  printf("%s\n", rmchr(argv[1], argv[2]));
}
