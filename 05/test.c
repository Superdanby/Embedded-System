#include <stdio.h>

int main(void)
{
	int i = 0;
	int j = 0;

	for(i = 0; i < 100; i++)
	{
		j = j + 1;
	}

	printf("j = %d\n", j);
	return 0;
}
