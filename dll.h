/**
 * Author: Jake Wachs
 * Date: 11/20/2017
 * 
 * Header file for doubly linked list implementation
 */

#ifndef __DLL_INCLUDED__
#define __DLL_INCLUDED__

#include <stdio.h>

typedef struct node NODE;
typedef struct dll DLL;

extern DLL *newDLL(void (*d)(FILE *, void *));
extern void insertDLL(DLL *list, int index, void *value);
extern void removeDLL(DLL *list, int index);
extern void *getElemAt(int index, DLL *list);
extern int sizeDLL(DLL *list);
extern void displayDLL(FILE *, DLL *list);

#endif
