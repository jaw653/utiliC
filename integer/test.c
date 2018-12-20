#include <stdio.h>
#include <stdlib.h>

#include "integer.h"

int main(void)
{
	INTEGER *newInt = newINTEGER(5);
	displayINTEGER(stdout, newInt);
	printf("\n");
	return 0;
}
