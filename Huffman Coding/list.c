#include "functions.h"

//Push a node onto the stack
void push(listNode *head, listNode *node) {
   node->next = head->next;
   head->next = node;
   int size = (unsigned long)(head->tree) + 1;
   head->tree = (treeNode *)((unsigned long)size);
}

//Pop a node off the stack
listNode *pop(listNode *head) {
   listNode *node = head->next;
   if (node != NULL) { //stack has at least 1 member
      head->next = node->next;
      node->next = NULL;
      int size = (unsigned long)(head->tree) - 1;
      head->tree = (treeNode *)((unsigned long)size);
   }
   return node;
}

//Find the size of the stack
int stackSize(listNode *head) {
   return (unsigned long)(head->tree);
}

//Construct a node on the stack
listNode *constructNode(treeNode *tree) {
   listNode *node = (listNode *)malloc(sizeof(listNode));
   if (node = NULL) {
      fprintf(stderr, "ERROR 01: Memory allocation unsuccessful");
      return NULL;
   }
   
   //Constructing node
   node->tree = tree;
   node->next = NULL;
   
   return node;
}

//Deconstruct a node on the stack
void nodeDeconstruct(listNode *node) {
   if (node != NULL) {
      deconstructTree(node->tree);
      free(node);
   }
}