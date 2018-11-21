/**
 * Author: Jake Wachs
 * Date: 11/20/2017
 * 
 * Test file for doubly linked list implementation
 */

#include <stdio.h>
#include <stdlib.h>

#include "dll.h"

struct page
{
	int pageNum;
	int frameNum;
};
typedef struct page PAGE;


/* Display function for the page structure */
static void displayPAGE(FILE *, void *);


int main(void)
{
	int i;
	PAGE *testPage;

	/* Instantiating new doubly linked list object */
	DLL *testList = newDLL(displayPAGE);


	printf("Inserting 5 page structures to list...\n");

	/* Initializing some PAGE structures and inserting them to DLL */
	for (i = 0; i < 5; i++)
	{
		testPage = malloc(sizeof(PAGE));
		testPage->pageNum = i;
		testPage->frameNum = i+5;

		insertDLL(testList, i, testPage);
	}	

	/* Displaying doubly linked list */
	displayDLL(stdout, testList);
	printf("size of DLL is: %d\n", sizeDLL(testList));

	/* Testing the remove function */
	printf("\nRemoving four pages...\n");
	for (i = 0; i < 4; i++)
		removeDLL(testList, 0);

	displayDLL(stdout, testList);
	printf("size of DLL is: %d\n", sizeDLL(testList));

	return 0;
}

/**
 * Display function to accompany the PAGE structure; needed to display a structure
 * as well as initialize a DLL
 * @fp File to print to
 * @v Value to display, a void pointer to the structure that must be typecasted
 */
static void displayPAGE(FILE *fp, void *v)
{
	PAGE *p = (PAGE *)v;
	int pNum = (int) p->pageNum;
	int fNum = (int) p->frameNum;
	fprintf(fp, "pageNum: %d, frameNum: %d\n", pNum, fNum);
}