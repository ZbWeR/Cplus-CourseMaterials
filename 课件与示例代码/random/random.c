#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(int argc, char *argv[])
{
	int max, num;
	if(argc!=3)
	{
		printf("Usage: %s max num\n", argv[0]);
		return 1;
	}

	max=atoi(argv[1]);
	num=atoi(argv[2]);

	random(max, num);

	return(0);
}


