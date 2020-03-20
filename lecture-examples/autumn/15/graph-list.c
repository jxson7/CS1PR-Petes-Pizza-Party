#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>

// Graph implemented using adjecancy list

typedef struct node_t node_t;

struct list_elem_t{
  node_t * elem;
  struct list_elem_t *next; // the next element, NULL if none
};

typedef struct list_elem_t list_elem_t;

list_elem_t * list_init(){
  list_elem_t * l = malloc(sizeof(list_elem_t));
  memset(l, 0, sizeof(list_elem_t)); // initialize with 0
  return l;
}

list_elem_t * list_push(list_elem_t * list, node_t * elem){
  assert(list != NULL);
  list_elem_t * l = malloc(sizeof(list_elem_t));
  l->elem = elem;
  l->next = list->next;
  list->next = l;
  return l;
}

struct node_t{
  char value;
  list_elem_t * out_edges;

  struct node_t * next; // a graph has one list of nodes
  bool marker;
};

typedef struct node_t graph_t; // a graph is the start of a list of nodes

node_t * graph_add_node(graph_t ** graph, uint32_t value){
  node_t * node = malloc(sizeof(node_t));
  memset(node, 0, sizeof(node_t));
  node->out_edges = list_init();
  node->value = value;
  if(graph != NULL){
    node->next = *graph;
  }
  *graph = node;
  return node;
}

void node_add_edge(node_t * src, node_t *tgt){
  list_push(src->out_edges, tgt);
}

void dfs_I(node_t * node, void (*observer)(node_t const* node, int32_t distance), int distance){
  if(node->marker) return;
  node->marker = true;
  observer(node, distance);
  for(list_elem_t * cur = node->out_edges->next; cur != NULL ; cur = cur->next){
    node_t * next = cur->elem;
    dfs_I(next, observer, distance + 1);
  }
}

void dfs(graph_t * g, node_t * start, void (*observer)(node_t const* node, int32_t distance)){
  // set all markers to false
  for(node_t * cur = g; cur != NULL ; cur = cur->next){
    cur->marker = false;
  }
  dfs_I(start, observer, 0);
}

void graph_printer(node_t const* node, int32_t distance){
  printf("%d - %c\n", distance, node->value);
}


int main(){
  graph_t * graph = NULL;
  node_t * a = graph_add_node(& graph, 'a');
  node_t * b = graph_add_node(& graph, 'b');
  node_t * c = graph_add_node(& graph, 'c');
  node_t * d = graph_add_node(& graph, '.');

  node_add_edge(a, b);
  node_add_edge(a, d);
  node_add_edge(b, c);
  node_add_edge(d, c);
  node_add_edge(d, a);

  printf("Start: a\n");
  dfs(graph, a, graph_printer);

  printf("Start: d\n");
  dfs(graph, d, graph_printer);

  return 0;
}
