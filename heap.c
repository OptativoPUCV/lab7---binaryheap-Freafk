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
  
  if(pq->size==0)return NULL;
  return pq->heapArray[0].data;
}





void upHeap(Heap *pq,int index){
  int indexPadre;
  if(index%2==0){
    indexPadre=index/2;
  }
  else{
    indexPadre=(index-1)/2;
  }
  if(pq->heapArray[index].priority>pq->heapArray[indexPadre].priority){
    heapElem aux=pq->heapArray[indexPadre];
    pq->heapArray[indexPadre]=pq->heapArray[index];
    pq->heapArray[index]=aux;
    upHeap(pq,indexPadre);
  }
}





void heap_push(Heap* pq, void* data, int priority){
  heapElem node={data,priority};
  if(pq->size==pq->capac){
    pq->heapArray=realloc(pq->heapArray,sizeof(pq->heapArray)*2);
  }
  int index=pq->size;
  pq->heapArray[index]=node;

  upHeap(pq,index);
  pq->size++;
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
