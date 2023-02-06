#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random(int max, int num)
{
	int i, r;
	srand(time(NULL));

	for(i=0; i<num; i++) {
		r=rand();
		r=r%max;
		r=r+1;
		printf("%d ", r);
	}

	printf("\n");
}
