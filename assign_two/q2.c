#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
struct DesStack {
    int stkptr;
    unsigned size;
    int* stackarr;
};
int ISEMPTY(struct DesStack* test)
{
    if(test->stkptr == test->size -1)
	{
		printf("stack is empty nothing to pop\n");
		return 1;
	}
	return 0;
}

int ISFULL(struct DesStack* test)
{
    
	if(test->stkptr == -1)
	{
		printf("stack is full cannot push\n");
		return 1;
	}
	return 0;	
}

struct DesStack* create(unsigned size)
{
    struct DesStack* test = (struct DesStack*)malloc(sizeof(struct DesStack));
    test->size = size;
    test->stkptr = size-1;
    test->stackarr = (int*)malloc(test->size * sizeof(int));
    return test;
}

void Print(struct DesStack* test)
{
	printf("Printing all elements of stack");
	for(int i = test->size-1; i >=0;i--)
	{
		printf(" %d ", test->stackarr[i]);
	}
	printf("\n");
}

void push(struct DesStack* test, int value)
{
    if (ISFULL(test) == 1)
    {
        return;
    }
    test->stackarr[test->stkptr--] = value;
    printf("%d pushed to test\n", value);
}

int pop(struct DesStack* test)
{
    if (ISEMPTY(test))
        return INT_MIN;
    return test->stackarr[++test->stkptr];
}
int main()
{
	struct DesStack* out = create(3);
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
