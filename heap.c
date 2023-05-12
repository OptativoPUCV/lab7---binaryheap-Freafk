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

void* heap_top(Heap* monticulo){
    if (monticulo->size == 0){
        return NULL;
    }
    else{
        return monticulo->heapArray[0].data;
    }
}

void heap_push(Heap* monticulo, void* data, int prioridad){
    if (monticulo->size == monticulo->capac){
        monticulo->capac *= 2;
        monticulo->heapArray = realloc(monticulo->heapArray, monticulo->capac * sizeof(heapElem));
    }
    
    int indice = monticulo->size;
    monticulo->heapArray[indice].data = data;
    monticulo->heapArray[indice].priority = prioridad;
    monticulo->size++;

    while (indice != 0 && monticulo->heapArray[(indice - 1) / 2].priority < monticulo->heapArray[indice].priority){
        heapElem temp = monticulo->heapArray[(indice - 1) / 2];
        monticulo->heapArray[(indice - 1) / 2] = monticulo->heapArray[indice];
        monticulo->heapArray[indice] = temp;
        indice = (indice - 1) / 2;
    }
}

void heap_pop(Heap* monticulo){
    if (monticulo->size == 0){
        return;
    }

    monticulo->heapArray[0] = monticulo->heapArray[monticulo->size - 1];
    monticulo->size--;
    
    int indice = 0;
    while (1){
        int hijoIzquierdo = 2 * indice + 1;
        int hijoDerecho = 2 * indice + 2;
        int mayor = indice;
        
        if (hijoIzquierdo < monticulo->size && monticulo->heapArray[hijoIzquierdo].priority > monticulo->heapArray[mayor].priority){
            mayor = hijoIzquierdo;
        }
        if (hijoDerecho < monticulo->size && monticulo->heapArray[hijoDerecho].priority > monticulo->heapArray[mayor].priority){
            mayor = hijoDerecho;
        }
        if (mayor == indice){
            break;
        }
        
        heapElem temp = monticulo->heapArray[indice];
        monticulo->heapArray[indice] = monticulo->heapArray[mayor];
        monticulo->heapArray[mayor] = temp;
        indice = mayor;
    }
}

Heap* createHeap(){
    Heap* monticulo = malloc(sizeof(Heap));
    monticulo->size = 0;
    monticulo->capac = 10;
    monticulo->heapArray = malloc(monticulo->capac * sizeof(heapElem));
   
   return monticulo;
}
