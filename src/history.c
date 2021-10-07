#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

//Initialize a linked list
List* init_history()
{
  List *history_list = (List*)malloc(sizeof(List));
  history_list->root = NULL;
  return history_list;
}

void add_history(List *list, char *str)
{
  //creating new node
  Item *node = (Item*)malloc(sizeof(Item));
  node->str = copy_str(str,strlen(str));
  node->next = NULL;

  //checking if its the first item in the list
  if (list->root == NULL)
    {
      list->root = node;
      node->id = 1;
      //printf("EMPTY LIST: \nTest new node: node->id = %d node->str = %s\n",node->id,node->str);
    }
  else//Enters here if there are elements in the list already
    {
      //printf("ELSE STATEMENT\n");
      Item *temp = list->root;//temp variable to traverse from start of list
      int index = temp->id;
      while(temp->next != NULL) //traverses to the end of the list, may be skipped
	{
	  //printf("Test while in else node->str: %s\n", temp->str)
	  temp = temp->next;
	  index = temp->id;
	}
      //HERE TEMP->NEXT IS NULL
      temp->next = node;
      node->id = index + 1;
      //printf("test non-empty node-> id = %d\n", node->id);
      //printf("test non-empty node-> str = %s\n", node->str);
    }
}

char *get_history(List *list, int id)
{
  Item *temp = list->root;
  if(temp == NULL)
    {
      printf("No History\n");
      return 0;
    }
  while(temp != NULL)
    {
      if(temp->id == id)
	{
	  return temp->str;
	}
      temp = temp->next;
    }
}

void print_history(List *list)
{
  Item *temp = list->root;
  if(temp == NULL)
    {
      printf("list is empty");
    }
  while(temp != NULL)
    {
      printf("[%d] %s\n", temp->id, temp->str);
      temp = temp->next;
    }
}
 
void free_history(List *list)
{
  Item *head = list->root;
  Item *temp;
  while(head != NULL)
    {
      temp = head;
      head = head->next;;
      //printf("To be freed: %s", temp->str);
      free(temp->str);
      free(temp);
    }
}

