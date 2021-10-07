#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokenizer.c"
#include "history.c"

#define MAX 50

void main(void){
  //Simple UI
  char userInput[MAX];
  List* history = init_history();
  char** tokens;
  
  printf("Welcome to my Tokenizer! \n Enter a phrase after '$'.\n Enter 'e' to exit or '!' to see your phrases so far\n");

  while(*userInput != 'e')
    {
      printf("$");
      fgets(userInput ,MAX, stdin);
      printf("\n");

      if(*userInput != 'e' && *userInput != '!')
	{
	  printf("The string you entered: %s", &userInput); //Test Echo
      
	  tokens = tokenize(userInput);

	  printf("The sting you entered Tokenized is:\n");

	  print_tokens(tokens);
	  
	  add_history(history, userInput);
	}
      if(*userInput == '!'){
	printf("Your Phrases so far:\n");
	print_history(history);
      }
  }
  free_tokens(tokens);
  free_history(history);
  //print_history(history);//checks if list is empty
  printf("Thank you for using my Tokenizer! GOODBYE!\n");
}
