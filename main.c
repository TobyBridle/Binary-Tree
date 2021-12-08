#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(n) sizeof(n)/sizeof(n[1])
#define NODE_INITIAL_SIZE (sizeof(int) + sizeof(size_t))*4
struct Node {
  
  struct Node *left;
  struct Node *right;

  int value;
  size_t length;
};

int values[10] = { 1, 5, 23, 10, 8, 91, 6, 3, 100, 90};

int main()
{
  struct Node *base;
  base = malloc(NODE_INITIAL_SIZE);
  base->left = malloc(NODE_INITIAL_SIZE/4);
  base->right = malloc(NODE_INITIAL_SIZE/4);
  base->value = values[0];

  struct Node *current_node;
  current_node = malloc(NODE_INITIAL_SIZE);
  current_node->left = malloc(NODE_INITIAL_SIZE/4);
  current_node->right = malloc(NODE_INITIAL_SIZE/4);
  current_node = base;

  for(size_t i = 1; i < ARRAY_SIZE(values); ++i)
  {
    struct Node *n;
    n = malloc(NODE_INITIAL_SIZE);
    n->left = malloc(NODE_INITIAL_SIZE/4);
    n->right = malloc(NODE_INITIAL_SIZE/4);

    n->value = values[i];
    if(values[i] < values[i+1] || i == ARRAY_SIZE(values)-1)
      current_node->left = n;
    else
    {
      current_node->right = n;
    }
    if(i % 2 == 0) current_node = current_node->left;

  }

  printf("%d", base->left->left->left->left->left->value);

}
