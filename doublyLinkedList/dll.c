/**
 * Author: Jake Wachs
 * Date: 11/20/2017
 * 
 * Implementation file for dll.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dll.h"

struct node
{
	void *value;
	NODE *prev;
	NODE *next;
};

struct dll
{
	void (*display)(FILE *, void *);
	int size;
	NODE *head;
	NODE *tail;
};

/**
 * Instantiates new doubly linked list object
 * @d The display function for the void object, w/ file ptr & void ptr params
 */
DLL *newDLL(void (*d)(FILE *, void *))
{
	DLL *list = malloc(sizeof(DLL));
	
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->display = d;

	return list;
}

/**
 * Insert value into list at given index
 * @list The doubly linked list in which to insert the value
 * @index The index at which to insert the value in the list
 * @value The actual value to be inserted
 */
void insertDLL(DLL *list, int index, void *value)
{
	assert(index <= list->size);

	NODE *newNode = malloc(sizeof(NODE));
	newNode->value = value;

	/* If list is empty, insert new node as head */
	if (list->head == NULL)
	{
		newNode->prev = NULL;
		newNode->next = NULL;
		list->head = newNode;
		list->tail = newNode;
	}

	/* If list is not empty, insert new node at given index */
	else
	{
		/* Insert at head */
		if (index == 0)
		{
			newNode->next = list->head;
			list->head->prev = newNode;
			newNode->prev = NULL;
			list->head = newNode;
		}

		/* Insert at tail */
		else if (index == list->size)
		{
			list->tail->next = newNode;
			newNode->prev = list->tail;
			newNode->next = NULL;
			list->tail = newNode;
		}

		/* Insert at given index (from parameters) */
		else
		{
			int i;
			NODE *ptr = list->head;

			for (i = 0; i < index; i++)
				ptr = ptr->next;

			newNode->next = ptr;
			newNode->prev = ptr->prev;
			ptr->prev->next = newNode;
			ptr->prev = newNode;
		}
	}

	list->size += 1;
}

/**
 * Removes the element at the given index from the list
 * @list The list from which to remove an element
 * @index The index of the element to remove
 */
void removeDLL(DLL *list, int index)
{
	assert(index < list->size);

	int i;
	NODE *ptr = list->head;
	for (i = 0; i < index; i++)
		ptr = ptr->next;

	/* Remove head */
	if (ptr->prev == NULL)
	{
		if (ptr->next)
		{
			list->head = ptr->next;
			ptr->next = NULL;
			list->head->prev = NULL;
		}
		/* Only one element in list */
		else
		{
			list->head = NULL;
			list->tail = NULL;
		}
	}

	/* Remove tail */
	else if (ptr->next == NULL)
	{
		ptr->prev->next = NULL;
		list->tail = ptr->prev;
	}

	/* Remove element somewhere inside the list */
	else
	{
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
	}

	free(ptr);

	list->size -= 1;
}

/**
 * Get the element at the given index
 * @index The index to iterate to
 * @list The doubly linked list to traverse
 */
void *getElemAt(DLL *list, int index)
{
	assert(list->size > 0);

	int i;
	NODE *ptr = list->head;
	for (i = 0; i < index; i++)
	{
		ptr = ptr->next;
	}

	return ptr;
}

/**
 * Return the size of the doubly linked list
 * @list The list to get the size of
 */
int sizeDLL(DLL *list)
{
	return list->size;
}

/**
 * Display all elements in the doubly linked list
 * @fp The file in which to display the list
 * @list The list to display
 */
void displayDLL(FILE *fp, DLL *list)
{
	int i;
	for (i = 0; i < list->size; i++)
	{
		NODE *n = (NODE *) getElemAt(list, i);
		void *v2 = n->value;
		list->display(fp, v2);
	}
}