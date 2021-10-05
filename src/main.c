#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokenizer.c"

#define MAX 50

void main(void){
  //Simple UI
  char userInput[MAX];
  
  printf("Welcome to my Tokenizer! \n Enter a phrase after '$' or enter 'e' to exit.\n");

  while(*userInput != 'e')
    {
      printf("$");
      fgets(userInput ,MAX, stdin);
      printf("\n");

      if(*userInput != 'e' && *userInput != '!')
	{
	  printf("The string you entered: %s", &userInput); //Test Echo
      
	  char **tokens = tokenize(userInput);

	  printf("The sting you entered Tokenized is:\n");

	  print_tokens(tokens);
	  free_tokens(tokens);
	}
  }
  printf("Thank you for using my Tokenizer! GOODBYE!\n");
}
