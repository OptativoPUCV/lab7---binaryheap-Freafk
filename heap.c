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
  if(index==0)return;
  if(index<=2){
    indexPadre=0;
  }
  else if(index%2==0){
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
  
  if(pq->size>=pq->capac-1){
    pq->capac=((pq->capac)*2)+1;
    pq->heapArray=realloc(pq->heapArray,sizeof(heapElem)*(((pq->capac)*2)+1));
  }
  
  int index=pq->size;
  pq->heapArray[index]=node;
  upHeap(pq,index);
  pq->size++;
}

void downHeap(Heap *pq,int index){

  int leftIndex=index*2;
  int rightIndex=(index*2)+1;
  if(!leftIndex && !rightIndex)return;
  
  if(pq->heapArray[leftIndex].priority<pq->heapArray[rightIndex].priority){
      if((pq->heapArray[index].priority<pq->heapArray[leftIndex].priority)){
        heapElem aux=pq->heapArray[leftIndex];
        pq->heapArray[leftIndex]=pq->heapArray[index];
        pq->heapArray[index]=aux;
        downHeap(pq, leftIndex);
      }
  }
  else{
      if((pq->heapArray[index].priority<pq->heapArray[rightIndex].priority)){
        heapElem aux=pq->heapArray[rightIndex];
        pq->heapArray[rightIndex]=pq->heapArray[index];
        pq->heapArray[index]=aux;
        downHeap(pq, rightIndex);
      }
  }
  
  
}

void heap_pop(Heap* pq){
  for(int i =0; i<pq->size;i++){
    printf("%d, ",pq->heapArray[i].priority);
  }
  heapElem ultimo=pq->heapArray[pq->size];
  pq->heapArray[0]=ultimo;
  pq->heapArray[pq->size]=pq->heapArray[pq->size+1];
  pq->size--;
  downHeap(pq,0);
  for(int i =0; i<pq->size;i++){
    printf("%d, ",pq->heapArray[i].priority);
  }
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
