#include <stdio.h>
#define MAX 10

typedef struct
{
	int id;
	int pages;
}PrintJob;

typedef struct
{
	PrintJob data[MAX];
	int front, rear;
}Queue;


void initQueue(Queue* q)
{
	q->front = q->rear = 0;
}

int isEmpty(Queue* q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

int isFull(Queue* q)
{
	if ((q->rear + 1) % MAX == q->front)
		return 1;
	else
		return 0;
}

void enQueue(Queue* q, PrintJob job) 
{
	if (isFull(q)) 
	{
		printf("대기열이 가득 찼습니다\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX;
	q->data[q->rear] = job;
	printf("문서 %d (%d페이지) 대기\n", job.id, job.pages);
}

PrintJob deQueue(Queue* q)
{
	PrintJob empty = { -1.0 };
	if (isEmpty(q)) return empty;

	q->front = (q->front + 1) % MAX;
	return q->data[q->front];
}


int main()
{
	Queue q;
	initQueue(&q);

	enQueue(&q, (PrintJob) { 1, 5 });
	enQueue(&q, (PrintJob) { 2, 10 });
	enQueue(&q, (PrintJob) { 3, 3 });

	while (!isEmpty(&q)) 
	{
		PrintJob job = deQueue(&q);
		printf("출력 중: 문서 %d (%d페이지)\n", job.id, job.pages);
	}

	return 0;
}