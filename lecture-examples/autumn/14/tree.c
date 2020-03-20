// dot -Tpdf test.dot -o out.pdf

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>

// Implementation for a (unbalanced) search-tree for uint32_t values

struct node_t{
  uint32_t value;
  struct node_t *left; // NULL if no left neighbor, left is smaller or equal
  struct node_t *right; // NULL if no left neighbor
};
typedef struct node_t node_t;

struct tree_t{
  uint32_t size;
  node_t head;
};

typedef struct tree_t tree_t;

tree_t * tree_init(){
  tree_t * t = malloc(sizeof(tree_t));
  memset(t, 0, sizeof(tree_t)); // initialize with 0
  return t;
}

// Recursive search
node_t * tree_searchI(node_t * node, uint32_t value){
  if(node == NULL) return NULL;
  if(value == node->value){
    return node;
  }else if(value < node->value){
    return tree_searchI(node->left, value);
  }
  return tree_searchI(node->right, value);
}


node_t * tree_search(tree_t * tree, uint32_t value){
  if(tree->size == 0){
    return NULL;
  }
  return tree_searchI(& tree->head, value);
}

void tree_insert(tree_t * tree, uint32_t value){
  tree->size++;
  if(tree->size == 1){
    tree->head.value = value;
    return;
  }
  node_t * new = malloc(sizeof(node_t));
  memset(new, 0, sizeof(node_t));
  new->value = value;

  // decide where to insert the new node
  // here we use an iterative search
  node_t * cur = & tree->head;
  node_t * parent = cur; // remember the parent
  while( cur != NULL ){ // stop when reaching the end
    parent = cur;
    if(value <= cur->value){
      cur = cur->left;
    }else{
      cur = cur->right;
    }
  }
  // now link the node on the correct position
  if(value <= parent->value){
    parent->left = new;
  }else{
    parent->right = new;
  }
}

void tree_traverse_inorderI(node_t * node, void (*observer)(node_t const* node)){
  if(node == NULL) return;
  tree_traverse_inorderI(node->left, observer);
  observer(node);
  tree_traverse_inorderI(node->right, observer);
}

void tree_traverse_inorder(tree_t * tree, void (*observer)(node_t const* node)){
  if(tree->size == 0){
    return;
  }
  tree_traverse_inorderI(& tree->head, observer);
}

void node_printer(node_t const*node){
  printf("%d\n", node->value);
}

int main(){
  tree_t * t = tree_init();
  tree_insert(t, 42);
  tree_insert(t, 4);
  tree_insert(t, 102);
  tree_insert(t, 20);
  tree_insert(t, 30);
  tree_insert(t, 12);
  tree_insert(t, 203);

  tree_traverse_inorder(t, node_printer);

  return 0;
}



void dot_printer(node_t const*node){
  if(node->left){
    printf("%d -> %d;\n", node->value, node->left->value);
  }else{
    printf("l%d [label=\"NULL\",shape=plaintext];\n", node->value);
    printf("%d -> l%d [style=dotted];\n", node->value, node->value);
  }
  if(node->right){
    printf("%d -> %d;\n", node->value, node->right->value);
  }else{
    printf("r%d [label=\"NULL\",shape=plaintext];\n", node->value);
    printf("%d -> r%d [style=dotted];\n", node->value, node->value);
  }
}
