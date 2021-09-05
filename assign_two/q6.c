#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#define max 5

int arr[max];
int front = -1, rear = -1;
int isFull() 
{
  if ((front == rear + 1) || (front == 0 && rear == max - 1)) 
  {
  	return 1;
  }
  	return 0;
}

int isEmpty() 
{
  if (front == -1) 
  {
  	return 1;
  }
  return 0;
}

void add_to_queue(int element) 
{
  	if (isFull() == 1)
  	{
    		printf(" Queue is full! cannot insert any element \n");
   	}
  	else 
  	{
    		if (front == -1) front = 0;
    		rear = (rear + 1) % max;
    		arr[rear] = element;
    		printf(" %d is inserted into queue \n", element);
  	}
}


int remove_from_Queue() 
{
  	int element;
  	if (isEmpty()) 
  	{
    		printf("Queue is empty nothing to remove\n");
    		return (-1);
  	} 
  	else 
  	{
    		element = arr[front];
    		if (front == rear) 
    		{
      			front = -1;
      			rear = -1;
    		} 
    
    		else 
    		{
      			front = (front + 1) % max;
    		}
    		printf("Deleted element  %d \n", element);
    		return (element);
  	}
}

void PrintQueue() 
{
  	int i;
  	if (isEmpty() == 1)
   	 { 
   	 	printf(" Empty Queue\n");
   	 }
  	else 
  	{
    		
    		printf(" Items in the queue are ");
    		for (i = front; i != rear; i = (i + 1) % max) 
    		{
      			printf("%d ", arr[i]);
    		}
    		printf("%d\n ", arr[i]);
    		printf("Front element %d \n", front);
    		printf("Rear element is %d \n", rear);
  	}
}

int main() 
{

  remove_from_Queue();
  add_to_queue(1);
  add_to_queue(2);
  add_to_queue(3);
  add_to_queue(4);
  add_to_queue(5);
  add_to_queue(6);
  PrintQueue();
  remove_from_Queue();
  PrintQueue();
  add_to_queue(7);
  PrintQueue();
  add_to_queue(8);
  remove_from_Queue();
  remove_from_Queue();
  remove_from_Queue();
  remove_from_Queue();
  remove_from_Queue();
  remove_from_Queue();
  remove_from_Queue();
  return 0;
}


