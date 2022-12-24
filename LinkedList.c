#include <stdio.h>
#include <stdlib.h>
    
typedef struct queueNode
{
	double data;
	struct queueNode *nextPtr;
}QueueNode;
typedef QueueNode *QueueNodePtr;
void printQueue(QueueNodePtr currentPtr);
int isEmpty(QueueNodePtr headPtr);
double dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, double value);
void instructions(void);

int main(void)
{
	QueueNodePtr headPtr = NULL;
	QueueNodePtr tailPtr = NULL;
	double item;

	instructions();
	printf("%s", "? ");
	unsigned int choice;
	scanf("%u", &choice);

	while (choice != 3)
	{
		switch (choice)
		{
			case 1:
				printf("%s", "Enter a float number: ");
				scanf("\n%lf", &item);
				enqueue(&headPtr, &tailPtr, item);
				printQueue(headPtr);
				break;

			case 2:
				// if queue is not empty
				if (!isEmpty(headPtr))
				{
					item = dequeue(&headPtr, &tailPtr);
					printf("%lf has been dequeued.\n", item);
				}
				printQueue(headPtr);
				break;

			default:
				puts("Invalid choice.\n");
				instructions();
				break;
		}

		printf("%s", "? ");
		scanf("%u", &choice);
	}
	puts("End of run.");
}

// display program instructions to user
void instructions(void)
{
	printf("Enter your choice:\n"
		"   1 to add an item to the queue\n"
		"   2 to remove an item from the queue\n"
		"   3 to end\n");
}

// insert a node at queue tail
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, double value)
{
	QueueNodePtr newPtr = malloc(sizeof(QueueNode));

	if (newPtr != NULL)	// is space available 
	{ 
		newPtr->data = value;
		newPtr->nextPtr = NULL;

		// if empty, insert node at head
		if (isEmpty(*headPtr))
			*headPtr = newPtr;
		else
			(*tailPtr)->nextPtr = newPtr;

		*tailPtr = newPtr;
	}
	else
		printf("%lf not inserted. No memory available.\n", value);
}

// remove node from queue head
double dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{
	double value = (*headPtr)->data;
	QueueNodePtr tempPtr = *headPtr;
	*headPtr = (*headPtr)->nextPtr;

	// if queue is empty
	if (*headPtr == NULL)
		*tailPtr = NULL;
	free(tempPtr);
	return value;
}

int isEmpty(QueueNodePtr headPtr)
{
	return headPtr == NULL;
}

void printQueue(QueueNodePtr currentPtr)
{
	// if queue is empty
	if (currentPtr == NULL)
		puts("Queue is empty.\n");
	else
	{
		puts("The queue is:");

		while (currentPtr != NULL)
		{
			printf("%lf --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		puts("NULL\n");
	}
}