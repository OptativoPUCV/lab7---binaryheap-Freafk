#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  
  
  return pq->heapArray[1].data ;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

   
}

Heap* createHeap(){
  Heap *local=malloc(sizeof(Heap));
  if(local==NULL){
    printf("No se pudo asignar memoria al Heap");
    exit(1);
  }
  local->heapArray=malloc(sizeof(heapElem)*3);
  local->size=0;
  local->capac=3;

   return local;
}
