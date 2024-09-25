#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int val;
  struct node* next;
} list_node;

void addNode(int add, list_node** head) { // does this work when head is not initially defined?
  list_node* new = (list_node*)malloc(sizeof(list_node));
  new -> val = add;
  new -> next = NULL;

  if (*head == NULL) {
    *head = new;
    return;
  }

  new->val = add;
  new->next = *head;
  *head = new;
}

void delNode(int del, list_node** head) {
  list_node* temp = *head;
  list_node* prev = NULL;

  if (temp != NULL && temp->val == del) {
    *head = temp->next;
    free(temp);
    return;
  }

  while (temp != NULL && temp->val != del) {
      prev = temp;
      temp = temp->next;
  }

  if (temp == NULL) {
    return;
  }

  prev->next = temp->next;
  free(temp);

}

void replNode(int repl, list_node** head) {
  list_node* temp = *head;

  if (temp != NULL && temp->val == repl) {
    return;
  }

  int store = temp->val;

  while (temp != NULL && temp->val != repl) {
      temp = temp->next;
  }

  if (temp == NULL) {
    return;
  }

  (*head)->val = repl;
  temp->val = store;
}

// void printList(list_node* head) {
//   printf("[ ");
//   while(head != NULL) {
//     printf("%d ",head->val);
//     head = head->next;
//   }
//   printf("]\n");
// }

int main(int argc, char * * argv)
{
  char command[8];
  list_node* head = NULL;
  int ins = 0;

  printf("1\n");
  return 0;

  while(1) {
    // fgets(input,sizeof(input),stdin);
    // sscanf(input,"%s %d",command,&ins);
    scanf("%s %d",command,&ins);

    if(strcmp("open",command) == 0) {
      addNode(ins, &head);
    }
    else if (strcmp("switch",command) == 0) {
      replNode(ins, &head);
    }
    else if (strcmp("close",command) == 0) {
      delNode(ins, &head);
    }

    if(head != NULL){
      printf("%d\n",head->val);
    } 
    else {
      return 0;
    }
  }
}
