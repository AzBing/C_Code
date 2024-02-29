#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"

TestQueue()
{
	Queue pq;
	QueueInit(&pq);
	QueuePush(&pq, 1);
	QueuePush(&pq, 2);
	QueuePush(&pq, 3);
	QueuePush(&pq, 4);
	QueuePush(&pq, 5);

	while (!QueueEmpty(&pq))
	{
		printf("%d ", QueueFront(&pq));
		QueuePop(&pq);
	}
	printf("\n");
	QueueDestroy(&pq);
}

int main()
{
	TestQueue();
	return 0;
}