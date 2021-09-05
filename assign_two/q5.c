#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct Queue {
    int first, last, size;
    unsigned capacity;
    int* arr;
};

int isEmpty(struct Queue* test)
{
	if(test->size == 0)
	{
		return 1;
	}
    	return 0;
}

int isFull(struct Queue* test)
{
	if(test->size == test->capacity)
	{
		return 1;
	}
    	return 0;
}

struct Queue* create(unsigned capacity)
{
    struct Queue* test = (struct Queue*)malloc(sizeof(struct Queue));
    test->capacity = capacity;
    test->first = 0;
    test->size = 0;
    test->last = capacity - 1;
    test->arr = (int*)malloc(test->capacity * sizeof(int));
    return test;
}

void Print(struct Queue* test)
{
	printf("Printing all elements of stack");
	for(int i = 0; i < test->size ;i++)
	{
		printf(" %d ", test->arr[i]);
	}
	printf("\n");
}

void add_to_queue(struct Queue* test, int value)
{
    if (isFull(test) == 1)
    {
    	printf("queue is full so cannot add a new value\n");
        return;
     }
    test->last = (test->last + 1)% test->capacity;
    test->arr[test->last] = value;
    test->size = test->size + 1;
    printf("%d is enqueued to test\n", value);
}

int remove_from_Queue(struct Queue* test)
{
    if (isEmpty(test) == 1)
    {
    	printf("queue is empty there is nothing to remove\n");
        return INT_MIN;
      }
    int value = test->arr[test->first];
    test->first = (test->first + 1)% test->capacity;
    test->size = test->size - 1;
    return value;
}
  
int first(struct Queue* test)
{
    if (isEmpty(test))
    {
    	printf("queue is empty so there is no front element\n");
        return INT_MIN;
    }
    return test->arr[test->first];
}

int last(struct Queue* test)
{
    if (isEmpty(test))
    {
    	printf("queue is empty so there is no rear element\n");
        return INT_MIN;
    }
    return test->arr[test->last];
}

int main()
{
	struct Queue* out = create(3);
	add_to_queue(out, 11);
	add_to_queue(out, 98);
	Print(out);
	add_to_queue(out, 89);
	Print(out);
	add_to_queue(out,100);
	printf("%d dequeued from the queue\n", remove_from_Queue(out));
	add_to_queue(out, 108);
	Print(out);
	printf("Front queue value is %d\n", first(out));
    	printf("Rear queue value is %d\n", last(out));
    	remove_from_Queue(out);
    	remove_from_Queue(out);
    	remove_from_Queue(out);
    	remove_from_Queue(out);
    	return 0;
}

 
