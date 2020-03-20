#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// this basically is our graph-matrix implementation with some modification
struct graph_t{
  int size;
  bool  * terminates; // new member, does the FSA terminate?
  char ** edge_value; // node_count * node_count
};

typedef struct graph_t graph_t; // a graph is the start of a list of nodes

graph_t * init_graph(int size){
  graph_t * g = malloc(sizeof(graph_t));
  g->size = size;
  g->terminates = malloc(sizeof(bool)*size);
  memset(g->terminates, 0, sizeof(bool) * size);
  g->edge_value = malloc(sizeof(void*)*size);
  // initialize rows
  for(int i=0; i < size; i++){
    g->edge_value[i] = malloc(sizeof(char) * size);
    memset(g->edge_value[i], 0, sizeof(char) * size);
  }
  return g;
}

void graph_node_terminates(graph_t * g, int id){
  g->terminates[id] = true;
}

void node_add_edge(graph_t * g, int u, int v, char value){
  g->edge_value[u][v] = value;
}

// This is the relevant function for performing the graph matching
bool graph_matches(graph_t * g, int u, char const * str){
  char c = str[0]; // attempt to match first character
  if( c == 0 ) return g->terminates[u];
  printf("Checking %c on id: %d\n", c, u);

  for(int v = 0; v < g->size; v++){
    char ev = g->edge_value[u][v];
    if(ev == c || ev == '.') {
      if(graph_matches(g, v, str+1)){
        return true;
      }
    }
  }
  return false;
}


int main(){
  graph_t * graph = init_graph(4);
  graph_node_terminates(graph, 2);
  graph_node_terminates(graph, 3);

  node_add_edge(graph, 0, 1, 'b');
  node_add_edge(graph, 0, 3, 'a');
  node_add_edge(graph, 1, 2, 'c');
  node_add_edge(graph, 3, 2, '.');
  node_add_edge(graph, 3, 0, '.');


  printf("Does the expression match the graph: %d\n", graph_matches(graph, 0, "abbbc"));
  printf("Does the expression match the graph: %d\n", graph_matches(graph, 0, "abbc"));

  return 0;
}
