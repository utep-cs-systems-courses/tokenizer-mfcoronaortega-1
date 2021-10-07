#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if((c == ' ') || (c== '\t') || (c == '\n'))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int non_space_char(char c)
{
  return(space_char(c) || c == '\0') ? 0 :1;
  //if(!space_char(c) || (c == '\0'))
  //{
  //  return 1;
  //}
  //else
  //{
  //  return 0;
  //}
}

char *word_start(char *str)
{
  if(*str == '\0') //if its the end or no words, return zero pointer
    {
      return 0;
    }
  while(space_char(*str))// skip white space
    {
      str++;//keep going
    }
    return str;//RETURNS the beginning of the next word
}

char *word_end(char *str)
{
  //printf("START WORD END METHOD\n");
  while(non_space_char(*str)) //skip NON whitespace
    {
      //printf("IN WHILE: %s\n", str);
      str++;
    }
  //return the beggining of the end of a word
  return str;
}

int count_words(char *str)
{
  //printf("COUNT WORDS\n");
  int word_count = 0;

  while(*str != '\0')//while not empty or \0
    {
      //printf("START WHILE\n");
      //printf("test str BEFORE word start: %s\n",str);
      str = word_start(str);//using start and end to go through words
      //printf("test str AFTER word start and BEFORE word end: %s\n", str);
      str = word_end(str);
      //printf("test str AFTER word end: %s\n", str);

      word_count++;//add words
    }
  
  return word_count;
}

 char *copy_str(char *inStr, short len)
 {
   int index;
   char *array_copy;

   //allocate memory for string copy using malloc this is enough space to hold one word
   array_copy = (char *)malloc(sizeof(char) * (len+1));

   for(index = 0; index <len; index++)
     {
       array_copy[index] = inStr[index];
     }

   array_copy[index]= '\0';//terminating word

   return array_copy;//returns the copy of the array
 }

char **tokenize(char* str)
{
  //printf("TOKENIZE 1\n");

  int total_word_ct = count_words(str);

  //printf("TOKENIZE 2\n");

  char **tokens;
  tokens = (char **)malloc(sizeof(char*) * (++total_word_ct)); //allocatess words plus 1 for \0

  //printf("TOKENIZE 3\n");
  
  int index;
  int difference = 0;

  for(index =0; index<total_word_ct-1; index++)
    {
      str= word_start(str);
      difference = word_end(str) - str;//difference in length
      tokens[index] = copy_str(str, difference);

      str = word_end(str);//pointer to the next word
    }

  tokens[index] = '\0'; //terminating array

  return tokens;
}

void print_tokens(char **tokens)
{
  int i;
  char* current;
  for(i = 0; tokens[i] != NULL; i++)//nested loop to itterate through list of arrays
    {
      current = get_token(tokens, i);
      printf("Token at [%d]: %s", i,current);
      printf("\n");
    }
}

char *get_token(char **tokens, int id){
  return tokens[id];
}

void free_tokens(char **tokens){
  int i;
  for(i = 0;tokens[i] != NULL; i++){
    free(tokens[i]);
  }
  free(tokens);
}

