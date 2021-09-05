#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
struct AscStack {
    int stkptr;
    unsigned size;
    int* stackarr;
};
int ISEMPTY(struct AscStack* test)
{
    if(test->stkptr == -1)
	{
		printf("stack is empty nothing to pop\n");
		return 1;
	}
	return 0;
}

int ISFULL(struct AscStack* test)
{
    
	if(test->stkptr == test->size -1)
	{
		printf("stack is full cannot push\n");
		return 1;
	}
	return 0;	
}

struct AscStack* create(unsigned size)
{
    struct AscStack* test = (struct AscStack*)malloc(sizeof(struct AscStack));
    test->size = size;
    test->stkptr = -1;
    test->stackarr = (int*)malloc(test->size * sizeof(int));
    return test;
}

void Print(struct AscStack* test)
{
	printf("Printing all elements of stack");
	for(int i = 0; i <test->size;i++)
	{
		printf(" %d ", test->stackarr[i]);
	}
	printf("\n");
}


void push(struct AscStack* test, int value)
{
    if (ISFULL(test) == 1)
    {
        return;
    }
    test->stackarr[++test->stkptr] = value;
    printf("%d pushed to test\n", value);
}

int pop(struct AscStack* test)
{
    if (ISEMPTY(test))
        return INT_MIN;
    return test->stackarr[test->stkptr--];
}
int main()
{
	struct AscStack* out = create(3);
	push(out, 35);
	push(out, 56);
	Print(out);
	push(out, 78);
	Print(out);
	printf("stack pointer is pointed at %d\n",out->stkptr);
	push(out, 89);
	push(out, 100);
	printf("%d is popped from stack\n",pop(out));
	push(out,99);
	Print(out);
	pop(out);
	pop(out);
	pop(out);
	pop(out);
	printf("stack pointer is pointed at %d\n",out->stkptr);
	return 0;
}
