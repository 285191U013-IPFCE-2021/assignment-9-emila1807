/*
 * Search an expression using DFS.
 */

#include <stdio.h>  /* scanf, printf */
#include <stdbool.h>  /* bool, true, false */
#include <stdlib.h> /* abort */
#include "dfs.h"

int main() {//Main function to create a tree and print the nodes
//The values are the ones from the test case provided
	stack* topp = malloc(sizeof(stack));

    node *groot = make_node (4,
					make_node (7,
							make_node (28,
								make_node (77,
									NULL,
									NULL),
								make_node (23,
									NULL,
									NULL)),
							make_node (86,
								make_node (3,
									NULL,
									NULL),
								make_node (9,
									NULL,
								NULL))),
					make_node (98,
							NULL,
							NULL));
    DFT(groot);
    return 0;
}

void DFT (node *root){//DFS Algorithm

  // Implement DFS
	// Hint: You can use print_node, print_tree and/or print_stack.

  stack *topp = NULL;
	node *temp_node;
  topp = push(topp, root);
	
    while(!isEmpty(topp)){
		temp_node = top(topp);//Add node to stack
    print_node(temp_node);//Print the temporary node
    topp = pop(topp);

		
      if(temp_node->rchild != NULL){//If there is a right child 
            topp = push(topp, temp_node->rchild);
            temp_node->rchild->visited = true;}
	
      if(temp_node->lchild != NULL){//If there is a left child
            topp = push(topp, temp_node->lchild);
            temp_node->lchild->visited = true;}
    }
}

void print_node (node * p) {
    if (p == NULL)
        printf ("NULL\n");
    else
        printf ("%d, ", p->num);
}

void print_stack (stack * topp) {
    struct stack *temp = topp;
	  printf("\n\n");

    while (temp != NULL){
        print_node (temp->node);
        printf ("\n");
        temp = temp->next;}

    printf ("====\n");

    return;//In this case we don't want the function to return a value
}

node* make_node (int num, node * left, node * right){//Make node function

    struct node *element = malloc(sizeof(node));
     element->num = num;
     element->visited = false;
     element->lchild = left;
     element->rchild = right;

    return element;//Returns the element
}

bool isEmpty (stack * topp){
    if (topp == NULL) 
        return true;
    else 
        return false;}

stack* pop (stack *topp){
	stack *temp = topp;
	topp = topp->next;
	free(temp);
	return topp;}

node *top (stack * topp){
	return topp->node;}

stack* push (stack *topp, node *node) {
    stack *new_stack = malloc(sizeof(stack));

	new_stack->next = topp;
    new_stack->node = node;

	return new_stack;}