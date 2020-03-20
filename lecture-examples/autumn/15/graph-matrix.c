#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

struct graph_t{
  int size;
  char ** edge_value; // node_count * node_count
};

typedef struct graph_t graph_t; // a graph is the start of a list of nodes

graph_t * init_graph(int size){
  graph_t * g = malloc(sizeof(graph_t));
  g->size = size;
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

void bfs(graph_t * g, int startId, void (*observer)(int id)){
  bool marked[g->size];
  memset(marked, 0, g->size * sizeof(bool));

  int simpleQueue[g->size]; // a very simple queue implementation as ringbuffer
  int qinsert = 0;
  int qdelete = 0;

  simpleQueue[qinsert] = startId;
  qinsert++;

  while(qinsert != qdelete){
    int cur = simpleQueue[qdelete];
    qdelete++;
    if(qdelete >= g->size) qdelete = 0;
    observer(cur);
    marked[cur] = true;
    // add new edges
    for(int v = 0; v < g->size; v++){
      if(g->edge_value[cur][v] && ! marked[v]){
        marked[v] = true;
        simpleQueue[qinsert] = v;
        qinsert++;
        if(qinsert >= g->size) qinsert = 0;
      }
    }
  }
}

void graph_printer(int id){
  printf("%d\n", id);
}


int main(){
  graph_t * graph = init_graph(4);

  node_add_edge(graph, 0, 1, 'b');
  node_add_edge(graph, 0, 3, 'a');
  node_add_edge(graph, 1, 2, 'c');
  node_add_edge(graph, 3, 2, '.');
  node_add_edge(graph, 3, 0, '.');

  printf("start from a\n");
  bfs(graph, 0, graph_printer);

  printf("start from .\n");
  bfs(graph, 3, graph_printer);

  return 0;
}
