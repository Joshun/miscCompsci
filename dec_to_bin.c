#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUES 50

typedef struct {
	int values[MAX_VALUES];
	int num;
} num_index;

void add_num(int value, num_index *list)
{
	if( (list->num + 1) > MAX_VALUES ) {
		printf("Error: too large\n");
		exit(EXIT_FAILURE);
	}
	list->values[list->num] = value;
	list->num++;
}

void list_nums(num_index *list)
{
	int i;
	for(i=list->num - 1; i>-1; i--) {
		printf("%d ", list->values[i]);
	}
	printf("\n");
}

int process_next(int *last)
{
	int orig = *last;
	int remainder = orig % 2;
	*last = orig / 2;
	printf("%d / %d = %d (R=%d)\n", orig, 2, *last, remainder); 
	return remainder;
}

int main(int argc, char **argv)
{
	int dec = 0;
	int working_divisor = 0;
	num_index binary_result;
	
	printf("Enter number (base 10): ");
	fscanf(stdin, "%d", &dec);
	
	working_divisor = dec;
	
	while(working_divisor != 0) {
		add_num(process_next(&working_divisor), &binary_result);
		//printf("%d ", process_next(&working_divisor));
	}
	list_nums(&binary_result);
	
	return 0;	
}
