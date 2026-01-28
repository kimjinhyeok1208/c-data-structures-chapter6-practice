#include <stdio.h>
#define MAX_SIZE 5

typedef struct
{
	int data[MAX_SIZE];
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
	if ((q->rear + 1) % MAX_SIZE == q->front)
		return 1;
	else
		return 0;
}

void enQueue(Queue* q,int item)
{
	if (isFull(q))
	{
		printf("큐가 가득찼습니다.\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = item;
}

int deQueue(Queue* q)
{
	if (isEmpty(q))
	{
		printf("큐가 비었습니다\n");
		return -1;
	}
	q->front = (q->front + 1) % MAX_SIZE;
	return q->data[q->front];
}

void printQueue(Queue* q)
{
	int i = (q->front + 1) % MAX_SIZE;
	while (i != (q->rear + 1) % MAX_SIZE)
	{
		printf("%d ", q->data[i]);
		i = (i + 1) % MAX_SIZE;
	}
	printf("\n");
}


int main() {
	Queue q;
	initQueue(&q);

	printf("=== 원형 큐 테스트 ===\n");

	// 삽입 테스트
	enQueue(&q, 10);
	enQueue(&q, 20);
	enQueue(&q, 30);
	printf("큐 상태: ");
	printQueue(&q);

	// 삭제 테스트
	printf("deQueue: %d\n", deQueue(&q));
	printf("큐 상태: ");
	printQueue(&q);

	// 추가 삽입 (원형 확인)
	enQueue(&q, 40);
	enQueue(&q, 50);
	printf("큐 상태: ");
	printQueue(&q);

	// 포화 상태 테스트
	enQueue(&q, 60);   // 가득 찬 경우
	printf("큐 상태: ");
	printQueue(&q);

	// 전체 삭제
	while (!isEmpty(&q)) 
	{
		printf("deQueue: %d\n", deQueue(&q));
	}

	printf("큐가 비었는지 확인: %s\n",isEmpty(&q) ? "YES" : "NO");

	return 0;
}
